#ifndef TSYNC_CTL_H
#define TSYNC_CTL_H

#ifdef  __cplusplus
extern "C" {
#endif
int media_set_tsync_enable(u32 enable);
int media_set_tsync_discontinue(u32 discontinue);
int media_set_tsync_vpause_flag(u32 val);
int media_set_tsync_pts_video(u32 val);
int media_set_tsync_pts_audio(u32 val);
int media_set_tsync_dobly_av_sync(u32 val);
int media_set_tsync_pts_pcrscr(u32 val);
int media_set_tsync_even_strt(char* buf);
int media_set_tsync_mode(u32 val);
int media_set_tsync_pcr_recover(u32 val);
int media_set_tsync_debug_pts_checkin(u32 val);
int media_set_tsync_debug_pts_checkout(u32 val);
int media_set_tsync_debug_video_pts(u32 val);
int media_set_tsync_debug_audio_pts(u32 val);
int media_set_tsync_av_threshold_min(u32 val);
int media_set_tsync_av_threshold_max(u32 val);
int media_set_tsync_last_checkin_apts(u32 val);
int media_set_tsync_firstvpts(u32 val);
int media_set_tsync_slowsync_enable(u32 val);
int media_set_tsync_startsync_mode(u32 val);
int media_set_tsync_firstapts(u32 val);
int media_set_tsync_checkin_firstvpts(u32 val);
#ifdef  __cplusplus
}
#endif

#endif

