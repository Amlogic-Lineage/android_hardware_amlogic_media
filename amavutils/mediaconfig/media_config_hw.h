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



#ifndef MEDIA_CONFIG_HW___
#define MEDIA_CONFIG_HW___
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <cutils/log.h>
#include <sys/ioctl.h>
#include <cutils/properties.h>
int media_config_open(const char *path, int flags);
int media_config_close(int fd);
int media_config_set_str(int fd, const char *cmd, const char *val);
int media_config_get_str(int fd, const char *cmd, char *val, int len);
int media_config_list_cmd(int fd, char *val, int len);
#endif

