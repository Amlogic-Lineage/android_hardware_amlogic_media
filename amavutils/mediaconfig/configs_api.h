/*
 * Copyright (C) 2010 Amlogic Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#ifndef AMLOGIC_MEDIA_CONFIG_API__
#define AMLOGIC_MEDIA_CONFIG_API__
#include <linux/ioctl.h>
#define MAX_ITEM_NAME 128
#define MAX_PREFIX_NAME 128
#define MAX_VALUE_NAME  256
struct media_config_io_str {
	union{
		int subcmd;
		int ret;
	};
	union {
		int para[10];
		char cmd_path[MAX_PREFIX_NAME + MAX_ITEM_NAME + 4];
	};
	union {
		char val[MAX_VALUE_NAME];
		char *ptr;
	};
};


#define AML_CONFIG  'C'
#define MEDIA_CONFIG_SET_CMD_STR _IOW((AML_CONFIG), 0x1,\
				struct media_config_io_str)
#define MEDIA_CONFIG_GET_CMD_STR _IOWR((AML_CONFIG), 0x2,\
				struct media_config_io_str)

#endif


