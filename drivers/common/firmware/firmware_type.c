#include "firmware_type.h"

static const struct type_name_s type_name[] = {
	{VIDEO_DEC_MPEG12, "mpeg12"},
	{VIDEO_DEC_MPEG4_3, "divx311"},
	{VIDEO_DEC_MPEG4_4, "divx4x"},
	{VIDEO_DEC_MPEG4_5, "xvid"},
	{VIDEO_DEC_H263, "h263"},
	{VIDEO_DEC_MJPEG, "mjpeg"},
	{VIDEO_DEC_REAL, "real"},
	{VIDEO_DEC_VC1, "vc1"},
	{VIDEO_DEC_AVS, "avs"},
	{VIDEO_DEC_H264, "h264"},
	{VIDEO_DEC_H264_MULTI, "h264_multi"},
	{VIDEO_DEC_HEVC, "hevc"},
	{VIDEO_DEC_VP9, "vp9"},
	{VIDEO_ENC_H264, "h264_enc"},
	{VIDEO_ENC_JPEG, "jpeg_enc"},
	{FIRMWARE_MAX, "unknown"},
};


const char *get_firmware_type_name(enum firmware_type_e type)
{
	const char *name = "unknown";
	int i, size = ARRAY_SIZE(type_name);

	for (i = 0; i < size; i++) {
		if (type == type_name[i].type)
			name = type_name[i].name;
	}

	return name;
}
EXPORT_SYMBOL(get_firmware_type_name);

enum firmware_type_e get_firmware_type(const char *name)
{
	enum firmware_type_e type = FIRMWARE_MAX;
	int i, size = ARRAY_SIZE(type_name);

	for (i = 0; i < size; i++) {
		if (!strcmp(name, type_name[i].name))
			type = type_name[i].type;
	}

	return type;
}
EXPORT_SYMBOL(get_firmware_type);

