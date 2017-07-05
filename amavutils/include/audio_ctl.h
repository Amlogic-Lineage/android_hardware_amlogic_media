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



#ifndef AUDIO_CTL_H
#define AUDIO_CTL_H

#ifdef  __cplusplus
extern "C" {
#endif
int media_set_adec_format(int format);
int media_get_adec_format();
int media_set_adec_samplerate(int rate);
int media_get_adec_samplerate();
int media_set_adec_channum(int num);
int media_get_adec_channum();
int media_set_adec_pts(int pts);
int media_get_adec_pts();
int media_set_adec_datawidth(int width);
int media_get_adec_datawidth();
int media_get_audio_digital_output_mode();

#ifdef  __cplusplus
}
#endif

#endif