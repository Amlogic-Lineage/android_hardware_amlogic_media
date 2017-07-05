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



#ifndef MEDIA_CONFIG_API___
#define MEDIA_CONFIG_API___
int media_config_list(char *val, int len);
int media_set_cmd_str(const char *cmd, const char *val);
int media_get_cmd_str(const char *cmd, char *val, int len);
int media_decoder_set_cmd_str(const char *cmd, const char *val);
int media_decoder_get_cmd_str(const char *cmd, char *val, int len);
int media_parser_set_cmd_str(const char *cmd, const char *val);
int media_parser_get_cmd_str(const char *cmd, char *val, int len);
int media_video_set_cmd_str(const char *cmd, const char *val);
int media_video_get_cmd_str(const char *cmd, char *val, int len);
int media_sync_set_cmd_str(const char *cmd, const char *val);
int media_sync_get_cmd_str(const char *cmd, char *val, int len);
int media_codecmm_set_cmd_str(const char *cmd, const char *val);
int media_codecmm_get_cmd_str(const char *cmd, char *val, int len);
int media_audio_set_cmd_str(const char *cmd, const char *val);
int media_audio_get_cmd_str(const char *cmd, char *val, int len);
#endif

