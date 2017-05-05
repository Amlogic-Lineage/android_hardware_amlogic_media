#ifndef AUDIO_CTL_H
#define AUDIO_CTL_H

#ifdef  __cplusplus
extern "C" {
#endif
int media_set_adec_format(u32 format);
int media_get_adec_format();
int media_set_adec_samplerate(u32 rate);
int media_get_adec_samplerate();
int media_set_adec_channum(u32 num);
int media_get_adec_channum();
int media_set_adec_pts(u32 pts);
int media_get_adec_pts();
int media_set_adec_datawidth(u32 width);
int media_get_adec_datawidth();
int media_get_audio_digital_output_mode();

#ifdef  __cplusplus
}
#endif

#endif