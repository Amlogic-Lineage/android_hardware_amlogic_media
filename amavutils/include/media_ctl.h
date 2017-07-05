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



#ifndef MEDIA_CTL_H
#define MEDIA_CTL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <cutils/log.h>
#include <../mediaconfig/media_config.h>
#include <amports/amstream.h>
#include "../mediactl/common_ctl.h"
#ifdef  __cplusplus
extern "C" {
#endif

typedef struct{
    const char *device;
	const char *path;
    int(*mediactl_setval)(const char* path, int val);
	int(*mediactl_getval)(const char* path);
	int(*mediactl_setstr)(const char* path, char* val);
	int(*mediactl_getstr)(const char* path, char* buf,int size);
}MediaCtlPool;

int mediactl_set_str_func(const char* path, char* val);
int mediactl_get_str_func(const char* path, char* valstr, int size);
int mediactl_set_int_func(const char* path, int val);
int mediactl_get_int_func(const char* path);

#ifdef  __cplusplus
}
#endif
#endif
