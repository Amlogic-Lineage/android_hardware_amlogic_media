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
#include <video_ctl.h>

#ifdef  __cplusplus
extern "C" {
#endif
int media_set_vfm_map(const char* val)
{
    return media_set_vfm_map_str(val);
}
int media_get_vfm_map(char* val, int size)
{
    media_get_vfm_map_str(val,size);
	return 0;
}

int media_rm_vfm_map(const char* name, const char* val)
{
	return media_rm_vfm_map_str(name,val);
}

int media_add_vfm_map(const char* name, const char* val)
{
	return media_add_vfm_map_str(name, val);
}

#ifdef  __cplusplus
}
#endif

