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



#ifndef TSYNC_CTL_H
#define TSYNC_CTL_H

#ifdef  __cplusplus
extern "C" {
#endif
int media_set_tsync_enable(int enable);
int media_set_tsync_discontinue(int discontinue);
int media_set_tsync_vpause_flag(int val);
int media_set_tsync_pts_video(int val);
int media_set_tsync_pts_audio(int val);
int media_set_tsync_dobly_av_sync(int val);
int media_set_tsync_pts_pcrscr(int val);
int media_set_tsync_even_strt(char* buf);
int media_set_tsync_mode(int val);
int media_set_tsync_pcr_recover(int val);
int media_set_tsync_debug_pts_checkin(int val);
int media_set_tsync_debug_pts_checkout(int val);
int media_set_tsync_debug_video_pts(int val);
int media_set_tsync_debug_audio_pts(int val);
int media_set_tsync_av_threshold_min(int val);
int media_set_tsync_av_threshold_max(int val);
int media_set_tsync_last_checkin_apts(int val);
int media_set_tsync_firstvpts(int val);
int media_set_tsync_slowsync_enable(int val);
int media_set_tsync_startsync_mode(int val);
int media_set_tsync_firstapts(int val);
int media_set_tsync_checkin_firstvpts(int val);
#ifdef  __cplusplus
}
#endif

#endif

