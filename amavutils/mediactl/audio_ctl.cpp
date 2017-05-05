#define LOG_TAG "media_ctl"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <cutils/log.h>
#include <amports/amstream.h>
#include <common_ctl.h>
#include <audio_ctl.h>

#ifdef  __cplusplus
extern "C" {
#endif
/*adec*/
int media_set_adec_format(u32 format)
{
	return media_set_ctl("media.adec.format",format);
}

int media_get_adec_format()
{
    return media_get_ctl("media.adec.format");
}

int media_set_adec_samplerate(u32 rate)
{
	return media_set_ctl("media.adec.samplerate",rate);
}

int media_get_adec_samplerate()
{
    return media_get_ctl("media.adec.samplerate");
}

int media_set_adec_channum(u32 num)
{
	return media_set_ctl("media.adec.channum",num);
}

int media_get_adec_channum()
{
    return media_get_ctl("media.adec.channum");
}

int media_set_adec_pts(u32 pts)
{
	return media_set_ctl("media.adec.pts",pts);
}

int media_get_adec_pts()
{
    return media_get_ctl("media.adec.pts");
}

int media_set_adec_datawidth(u32 width)
{
    return media_set_ctl("media.adec.datawidth",width);
}

int media_get_adec_datawidth()
{
    return media_get_ctl("media.adec.datawidth");
}

int media_get_audio_digital_output_mode()
{
	return media_get_ctl("media.audio.audiodsp.digital_raw");
}
#ifdef  __cplusplus
}
#endif