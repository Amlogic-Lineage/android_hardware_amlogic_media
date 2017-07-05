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
#include "common_ctl.h"
#include <audio_ctl.h>

#ifdef  __cplusplus
extern "C" {
#endif
/*adec*/
int media_set_adec_format(int format)
{
	return media_set_ctl("media.adec.format",format);
}

int media_get_adec_format()
{
    return media_get_ctl("media.adec.format");
}

int media_set_adec_samplerate(int rate)
{
	return media_set_ctl("media.adec.samplerate",rate);
}

int media_get_adec_samplerate()
{
    return media_get_ctl("media.adec.samplerate");
}

int media_set_adec_channum(int num)
{
	return media_set_ctl("media.adec.channum",num);
}

int media_get_adec_channum()
{
    return media_get_ctl("media.adec.channum");
}

int media_set_adec_pts(int pts)
{
	return media_set_ctl("media.adec.pts",pts);
}

int media_get_adec_pts()
{
    return media_get_ctl("media.adec.pts");
}

int media_set_adec_datawidth(int width)
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