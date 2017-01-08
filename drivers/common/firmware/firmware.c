/*
 * drivers/amlogic/media/common/firmware/firmware.c
 *
 * Copyright (C) 2016 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>

#include <linux/amlogic/media/utils/vformat.h>
#include <linux/amlogic/media/old_cpu_version.h>
#include "../../stream_input/amports/amports_priv.h"
#include "../../frame_provider/decoder/utils/vdec.h"
#include "firmware.h"
#include "../chips/chips.h"
#include "linux/string.h"
#include <linux/amlogic/media/utils/log.h>
#include <linux/firmware.h>
#include <linux/amlogic/major.h>
#include <linux/cdev.h>
#include <linux/crc32.h>

#define CLASS_NAME "firmware_codec"
#define DEV_NAME "firmware_vdec"
#define DIR "video"
#define FRIMWARE_SIZE (30*1024) /*30k*/
#define PACK_SIZE (512*1024)
#define BUFF_SIZE (512*1024)

#define PACK ('P' << 24 | 'A' << 16 | 'C' << 8 | 'K')
#define CODE ('C' << 24 | 'O' << 16 | 'D' << 8 | 'E')

static DEFINE_MUTEX(mutex);

struct firmware_mgr_s {
	struct list_head head;
	spinlock_t lock;
};

struct firmware_info_s {
	struct list_head node;
	char path[64];
	char firmware_name[32];
	struct firmware_s *data;
};

struct ucode_info_s {
	int cpu_version;
	const char *name;
};

struct firmware_header_s {
	int magic;
	int checksum;
	char version[32];
	char author[32];
	char date[32];
	char commit[16];
	int data_size;
	unsigned int time;
	char reserved[32];
};

struct firmware_s {
	union {
		struct firmware_header_s header;
		char buf[256];
	};
	char data[0];
};

struct package_header_s {
	int magic;
	int size;
	int checksum;
	char reserved[128];
};

struct package_s {
	union {
		struct package_header_s header;
		char buf[256];
	};
	char data[0];
};

struct info_header_s {
	char name[32];
	char format[32];
	char cpu[32];
	int length;
};

struct package_info_s {
	union {
		struct info_header_s header;
		char buf[256];
	};
	char data[0];
};

static  struct ucode_info_s ucode_info[] = {
#include "firmware_info.h"
};

struct firmware_dev_s {
	struct cdev cdev;
	struct device *dev;
	dev_t dev_no;
};

static const struct file_operations firmware_fops = {
	.owner = THIS_MODULE
};

struct firmware_mgr_s *g_mgr;
struct firmware_dev_s *g_dev;

static u32 debug = 0;

static int request_firmware_from_sys(const char *file_name,
		char *buf, int size)
{
	int ret = -1;
	const struct firmware *firmware;

	pr_info("Try load %s  ...\n", file_name);

	ret = request_firmware(&firmware, file_name, g_dev->dev);
	if (ret < 0) {
		pr_info("Error : %d can't load the %s.\n", ret, file_name);
		goto err;
	}

	if (firmware->size > size) {
		pr_info("Not enough memory size for ucode.\n");
		ret = -ENOMEM;
		goto release;
	}

	memcpy(buf, (char *)firmware->data, firmware->size);

	pr_info("Load mcode size : %zd, Name : %s.\n",
		firmware->size, file_name);
	ret = firmware->size;
release:
	release_firmware(firmware);
err:
	return ret;
}

int request_decoder_firmware_on_sys(enum vformat_e type,
	const char *file_name, char *buf, int size)
{
	int ret;

	ret = get_firmware_data(file_name, buf);
	if (ret < 0)
		pr_info("Get firmware fail.\n");

	if (ret > size) {
		pr_info("Not enough memory.\n");
		return -ENOMEM;
	}

	return ret;
}
int get_decoder_firmware_data(enum vformat_e type,
	const char *file_name, char *buf, int size)
{
	int ret;

	ret = request_decoder_firmware_on_sys(type, file_name, buf, size);
	if (ret < 0)
		pr_info("get_decoder_firmware_data %s for format %d failed!\n",
				file_name, type);

	return ret;
}
EXPORT_SYMBOL(get_decoder_firmware_data);

static unsigned long firmware_mgr_lock(struct firmware_mgr_s *mgr)
{
	unsigned long flags;

	spin_lock_irqsave(&mgr->lock, flags);
	return flags;
}

static void firmware_mgr_unlock(struct firmware_mgr_s *mgr, unsigned long flags)
{
	spin_unlock_irqrestore(&mgr->lock, flags);
}

static void add_info(struct firmware_info_s *info)
{
	unsigned long flags;
	struct firmware_mgr_s *mgr = g_mgr;

	flags = firmware_mgr_lock(mgr);
	list_add(&info->node, &mgr->head);
	firmware_mgr_unlock(mgr, flags);
}

static void del_info(struct firmware_info_s *info)
{
	unsigned long flags;
	struct firmware_mgr_s *mgr = g_mgr;

	flags = firmware_mgr_lock(mgr);
	list_del(&info->node);
	kfree(info);
	firmware_mgr_unlock(mgr, flags);
}

static void walk_firmware_info(void)
{
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info;

	if (list_empty(&mgr->head)) {
		pr_info("the info list is empty.\n");
		return ;
	}

	list_for_each_entry(info, &mgr->head, node) {
		if (IS_ERR_OR_NULL(info->data))
			continue;

		pr_info("path : %s.\n", info->path);
		pr_info("name : %s.\n", info->firmware_name);
		pr_info("version : %s.\n", info->data->header.version);
		pr_info("checksum : 0x%x.\n", info->data->header.checksum);
		pr_info("data size : %d.\n", info->data->header.data_size);
		pr_info("author : %s.\n", info->data->header.author);
		pr_info("date : %s.\n", info->data->header.date);
		pr_info("commit : %s.\n\n", info->data->header.commit);
	}
}

static ssize_t info_show(struct class *class,
			struct class_attribute *attr, char *buf)
{
	char *pbuf = buf;
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info;

	if (list_empty(&mgr->head)) {
		pbuf += sprintf(pbuf, "No firmware.\n");
		goto out;
	}

	list_for_each_entry(info, &mgr->head, node) {
		if (IS_ERR_OR_NULL(info->data))
			continue;

		pr_info( "%10s : %s\n", "name",
				info->firmware_name);
		pr_info( "%10s : %d\n", "size",
				info->data->header.data_size);
		pr_info( "%10s : %s\n", "version",
				info->data->header.version);
		pr_info( "%10s : 0x%x\n", "checksum",
				info->data->header.checksum);
		pr_info( "%10s : %s\n", "commit",
				info->data->header.commit);
		pr_info( "%10s : %s\n", "author",
				info->data->header.author);
		pr_info( "%10s : %s\n\n", "date",
				info->data->header.date);
	}
out:
	return pbuf - buf;
}

static int set_firmware_info(void)
{
	int ret = 0, i, len;
	struct firmware_info_s *info;
	int info_size = ARRAY_SIZE(ucode_info);
	int cpu_version = get_cpu_type();
	const char *name;
	char *path = __getname();

	if (IS_ERR_OR_NULL(path))
		return -ENOMEM;

	for (i = 0; i < info_size; i++) {
		if (cpu_version != ucode_info[i].cpu_version)
			continue;

		name = ucode_info[i].name;
		if (IS_ERR_OR_NULL(name))
			break;

		len = snprintf(path, PATH_MAX, "%s/%s", DIR,
			ucode_info[i].name);
		if (len >= PATH_MAX)
			continue;

		info = kzalloc(sizeof(struct firmware_info_s), GFP_KERNEL);
		if (IS_ERR_OR_NULL(info)) {
			__putname(path);
			return -ENOMEM;
		}

		strcpy(info->path, path);
		strcpy(info->firmware_name, name);
		info->data = NULL;

		add_info(info);
	}

	__putname(path);

	return ret;
}

static int firmware_probe(char *buf)
{
	int magic = 0;

	memcpy(&magic, buf, sizeof(int));
	return magic;
}

static int checksum(struct firmware_s *firmware)
{
	unsigned int crc;

	crc = crc32_le(~0U, firmware->data, firmware->header.data_size);

	if (debug)
		pr_info("firmware crc result : 0x%x\n", crc ^ ~0U);

	return firmware->header.checksum != (crc ^ ~0U) ? 0 : 1;
}

static int check_repeat(struct firmware_s *data, const char *name)
{
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info;

	if (list_empty(&mgr->head)) {
		pr_info("the info list is empty.\n");
		return 0;
	}

	list_for_each_entry(info, &mgr->head, node) {
		struct firmware_s *tmp;

		if (strcmp(info->firmware_name, name))
			continue;

		if (IS_ERR_OR_NULL(info->data)) {
			pr_info("the data is null.\n");
			info->data = data;

			return 1;
		}

		if (info->data->header.time >= data->header.time) {
			pr_info("the data is old.\n");
			kfree(data);

			return 1;
		}

		pr_info("the data is new.\n");
		tmp = info->data;
		info->data = data;
		kfree(tmp);

		return 1;
	}

	return 0;
}

static int firmware_parse_package(char *buf, int size)
{
	int ret = 0;
	struct package_s *pack;
	struct package_info_s *pack_info;
	struct firmware_info_s *info;
	struct firmware_s *data;
	char *pack_data;
	const char *cpu;
	int info_len, len;
	char *path = __getname();

	if (IS_ERR_OR_NULL(path))
		return -ENOMEM;

	pack = vmalloc(PACK_SIZE);
	if (IS_ERR_OR_NULL(pack)) {
		__putname(path);
		return -ENOMEM;
	}

	memset(pack, 0, PACK_SIZE);
	memcpy(pack, buf, size);

	pack_data = pack->data;
	pack_info = (struct package_info_s *)pack_data;
	info_len = sizeof(struct package_info_s);

	for (;;) {
		if (!pack_info->header.length)
			break;

		cpu = get_cpu_type_name();
		if (strcmp(cpu, pack_info->header.cpu))
			continue;

		len = snprintf(path, PATH_MAX, "%s/%s", DIR,
			pack_info->header.name);
		if (len >= PATH_MAX)
			continue;

		info = kzalloc(sizeof(struct firmware_info_s), GFP_KERNEL);
		if (IS_ERR_OR_NULL(info)) {
			ret = -ENOMEM;
			goto out;
		}

		data = kzalloc(FRIMWARE_SIZE, GFP_KERNEL);
		if (IS_ERR_OR_NULL(data)) {
			kfree(info);
			ret = -ENOMEM;
			goto out;
		}

		strcpy(info->path, path);
		strcpy(info->firmware_name, pack_info->header.name);

		len = pack_info->header.length;
		memcpy(data, pack_info->data, len);

		pack_data += (pack_info->header.length + info_len);
		pack_info = (struct package_info_s *)pack_data;

		if (!checksum(data)) {
			pr_info("check sum fail !\n");
			kfree(data);
			kfree(info);
			goto out;
		}

		if (check_repeat(data, info->firmware_name)) {
			kfree(info);
			continue;
		}

		info->data = data;
		add_info(info);
	}
out:
	__putname(path);
	vfree(pack);

	return ret;
}

static int firmware_parse_code(struct firmware_info_s *info,
	char *buf, int size)
{
	info->data = kzalloc(FRIMWARE_SIZE, GFP_KERNEL);
	if (IS_ERR_OR_NULL(info->data))
		return -ENOMEM;

	memcpy(info->data, buf, size);

	if (!checksum(info->data)) {
		pr_info("check sum fail !\n");
		kfree(info->data);
		return -1;
	}

	return 0;
}

static int get_firmware_from_sys(const char *path,
	char *buf, int size)
{
	int len = 0;

	len = request_firmware_from_sys(path, buf, size);
	if (len < 0)
		pr_info("get data from fsys fail.\n");

	return len;
}

static int set_firmware_data(void)
{
	int magic = 0;
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info, *temp;
	char *buf;
	int size;

	if (list_empty(&mgr->head)) {
		pr_info("the info list is empty.\n");
		return 0;
	}

	buf = vmalloc(BUFF_SIZE);
	if (IS_ERR_OR_NULL(buf))
		return -ENOMEM;

	list_for_each_entry_safe(info, temp, &mgr->head, node) {
		size = get_firmware_from_sys(info->path, buf, BUFF_SIZE);
		magic = firmware_probe(buf);

		switch (magic) {
		case PACK:
			firmware_parse_package(buf, size);
			del_info(info);
			break;

		case CODE:
			firmware_parse_code(info, buf, size);
			break;

		default:
			del_info(info);
			pr_info("invaild type.\n");
		}

		memset(buf, 0, BUFF_SIZE);
	}

	if (debug)
		walk_firmware_info();

	vfree(buf);

	return 0;
}

int get_firmware_data(const char *name, char *buf)
{
	int data_len, ret = -1;
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info;
	char *firmware_name = __getname();

	if (IS_ERR_OR_NULL(firmware_name))
		return -ENOMEM;

	strcat(firmware_name, name);
	strcat(firmware_name, ".bin");

	if (list_empty(&mgr->head)) {
		pr_info("the info list is empty.\n");
		return 0;
	}

	list_for_each_entry(info, &mgr->head, node) {
		if (strcmp(firmware_name, info->firmware_name))
			continue;

		data_len = info->data->header.data_size;
		memcpy(buf, info->data->data, data_len);
		ret = data_len;

		break;
	}

	__putname(firmware_name);

	return ret;
}
EXPORT_SYMBOL(get_firmware_data);

static int firmware_pre_load(void)
{
	int ret = -1;

	ret = set_firmware_info();
	if (ret < 0) {
		pr_info("Get path fail.\n");
		goto err;
	}

	ret = set_firmware_data();
	if (ret < 0) {
		pr_info("Set data fail.\n");
		goto err;
	}
err:
	return ret;
}

static int firmware_mgr_init(void)
{
	g_mgr = kzalloc(sizeof(struct firmware_mgr_s), GFP_KERNEL);
	if (IS_ERR_OR_NULL(g_mgr))
		return -ENOMEM;

	INIT_LIST_HEAD(&g_mgr->head);
	spin_lock_init(&g_mgr->lock);

	return 0;
}

static struct class_attribute firmware_class_attrs[] = {
	__ATTR_RO(info),
	__ATTR_NULL
};

static struct class firmware_class = {
	.name = CLASS_NAME,
	.class_attrs = firmware_class_attrs,
};

static int firmware_driver_init(void)
{
	int ret = -1;

	g_dev = kzalloc(sizeof(struct firmware_dev_s), GFP_KERNEL);
	if (IS_ERR_OR_NULL(g_dev))
		return -ENOMEM;

	g_dev->dev_no = MKDEV(AMSTREAM_MAJOR, 100);

	ret = register_chrdev_region(g_dev->dev_no, 1, DEV_NAME);
	if (ret < 0) {
		pr_info("Can't get major number %d.\n", AMSTREAM_MAJOR);
		goto err;
	}

	cdev_init(&g_dev->cdev, &firmware_fops);
	g_dev->cdev.owner = THIS_MODULE;

	ret = cdev_add(&g_dev->cdev, g_dev->dev_no, 1);
	if (ret) {
		pr_info("Error %d adding cdev fail.\n", ret);
		goto err;
	}

	ret = class_register(&firmware_class);
	if (ret < 0) {
		pr_info("Failed in creating class.\n");
		goto err;
	}

	g_dev->dev = device_create(&firmware_class, NULL,
		g_dev->dev_no, NULL, DEV_NAME);
	if (IS_ERR_OR_NULL(g_dev->dev)) {
		pr_info("Create device failed.\n");
		ret = -ENODEV;
		goto err;
	}

	pr_info("Registered firmware driver success.\n");
err:
	return ret;
}

static void firmware_info_clean(void)
{
	struct firmware_mgr_s *mgr = g_mgr;
	struct firmware_info_s *info;
	unsigned long flags;

	flags = firmware_mgr_lock(mgr);
	while (!list_empty(&mgr->head)) {
		info = list_entry(mgr->head.next,
			struct firmware_info_s, node);
		list_del(&info->node);
		kfree(info->data);
		kfree(info);
	}
	firmware_mgr_unlock(mgr, flags);
}

static void firmware_mgr_clean(void)
{
	struct firmware_mgr_s *mgr = g_mgr;

	kfree(mgr);
}

static void firmware_driver_exit(void)
{
	cdev_del(&g_dev->cdev);
	device_destroy(&firmware_class, g_dev->dev_no);
	class_unregister(&firmware_class);
	unregister_chrdev_region(g_dev->dev_no, 1);
	kfree(g_dev);

	pr_info("Firmware driver cleaned up.\n");
}

static int __init firmware_module_init(void)
{
	int ret = -1;

	ret = firmware_driver_init();
	if (ret) {
		pr_info("Error %d firmware driver init fail.\n", ret);
		goto err;
	}

	ret = firmware_mgr_init();
	if (ret) {
		pr_info("Error %d firmware mgr init fail.\n", ret);
		goto err;
	}

	ret = firmware_pre_load();
	if (ret) {
		pr_info("Error %d firmware pre load fail.\n", ret);
		goto err;
	}
err:
	return ret;
}

static void __exit firmware_module_exit(void)
{
	firmware_info_clean();
	firmware_mgr_clean();
	firmware_driver_exit();
}

module_param(debug, uint, 0664);

module_init(firmware_module_init);
module_exit(firmware_module_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nanxin Qin <nanxin.qin@amlogic.com>");
