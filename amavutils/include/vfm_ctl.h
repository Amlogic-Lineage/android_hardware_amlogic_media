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



#ifndef VFM_CTL_H
#define VFM_CTL_H
#ifdef  __cplusplus
extern "C" {
#endif
/*val --"rm default" or "add default decoder ...." */
int media_set_vfm_map(const char* val);
int media_get_vfm_map(char* val,int size);
/* name --"default"; val -- "default decoder ..."*/
int media_rm_vfm_map(const char* name,const char* val);
int media_add_vfm_map(const char* name,const char* val);

#ifdef  __cplusplus
}
#endif
#endif

