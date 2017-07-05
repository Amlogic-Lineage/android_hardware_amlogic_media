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



#ifndef SUB_CTL_H
#define SUB_CTL_H

#ifdef  __cplusplus
extern "C" {
#endif

int media_set_subtitle_fps(int fps);
int media_set_subtitle_total(int total);
int media_set_subtitle_enable(int enable);
int media_set_subtitle_index(int index);
int media_set_subtitle_width(int width);
int media_set_subtitle_height(int height);
int media_set_subtitle_type(int type);
int media_set_subtitle_curr(int num);
int media_set_subtitle_startpts(int startpts);
int media_set_subtitle_reset(int res);
int media_set_subtitle_size(int size);
int media_set_subtitle_subtype(int type);
#ifdef  __cplusplus
}
#endif

#endif