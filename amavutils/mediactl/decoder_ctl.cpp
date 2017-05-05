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
#include <common_ctl.h>
#include <decoder_ctl.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define CTRL_PRINT ALOGD

int media_set_decoder_stat(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.stat",val);
}

int media_get_decoder_stat()
{
    return media_decoder_get_ctl("media.decoder.h264.stat");
}

int media_set_decoder_error_recovery_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.error_recovery_mode",val);
}

int media_get_decoder_error_recovery_mode()
{
    return media_decoder_get_ctl("media.decoder.h264.error_recovery_mode");
}

int media_set_decoder_sync_outside(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.sync_outside",val);
}

int media_get_decoder_sync_outside()
{
    return media_decoder_get_ctl("media.decoder.h264.sync_outside");
}

int media_set_decoder_dec_control(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.dec_control",val);
}

int media_get_decoder_dec_control()
{
    return media_decoder_get_ctl("media.decoder.h264.dec_control");
}

int media_set_decoder_fatal_error_reset(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.fatal_error_reset",val);
}

int media_get_decoder_fatal_error_reset()
{
    return media_decoder_get_ctl("media.decoder.h264.fatal_error_reset");
}

int media_set_decoder_max_refer_buf(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.max_refer_buf",val);
}

int media_get_decoder_max_refer_buf()
{
    return media_decoder_get_ctl("media.decoder.h264.max_refer_buf");
}

int media_set_decoder_ucode_type(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.ucode_type",val);
}

int media_get_decoder_ucode_type()
{
    return media_decoder_get_ctl("media.decoder.h264.ucode_type");
}

int media_set_decoder_debugfirmware(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.debugfirmware",val);
}

int media_get_decoder_debugfirmware()
{
    return media_decoder_get_ctl("media.decoder.h264.debugfirmware");
}

int media_set_decoder_fixed_frame_rate_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.fixed_frame_rate_val",val);
}

int media_get_decoder_fixed_frame_rate_val()
{
    return media_decoder_get_ctl("media.decoder.h264.fixed_frame_rate_val");
}

int media_set_decoder_decoder_debug_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.decoder_debug_val",val);
}

int media_get_decoder_decoder_debug_val()
{
    return media_decoder_get_ctl("media.decoder.h264.decoder_debug_val");
}

int media_set_decoder_dpb_size_adj(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.dpb_size_adj",val);
}

int media_get_decoder_dpb_size_adj()
{
    return media_decoder_get_ctl("media.decoder.h264.dpb_size_adj");
}

int media_set_decoder_decoder_force_reset(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.decoder_force_reset",val);
}

int media_get_decoder_decoder_force_reset()
{
    return media_decoder_get_ctl("media.decoder.h264.decoder_force_reset");
}

int media_set_decoder_no_idr_error_max(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.no_idr_error_max",val);
}

int media_get_decoder_no_idr_error_max()
{
    return media_decoder_get_ctl("media.decoder.h264.no_idr_error_max");
}

int media_set_decoder_enable_switch_fense(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h264.enable_switch_fense",val);
}

int media_get_decoder_enable_switch_fense()
{
    return media_decoder_get_ctl("media.decoder.h264.enable_switch_fense");
}

int media_set_decoder_debug_trace_num(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vdec.debug_trace_num",val);
}

int media_get_decoder_debug_trace_num()
{
    return media_decoder_get_ctl("media.decoder.vdec.debug_trace_num");
}

int media_set_decoder_hevc_max_reset_count(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vdec.hevc_max_reset_count",val);
}

int media_get_decoder_hevc_max_reset_count()
{
    return media_decoder_get_ctl("media.decoder.vdec.hevc_max_reset_count");
}

int media_set_decoder_clk_config(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vdec.clk_config",val);
}

int media_get_decoder_clk_config()
{
    return media_decoder_get_ctl("media.decoder.vdec.clk_config");
}

int media_set_decoder_step_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vdec.step_mode",val);
}

int media_get_decoder_step_mode()
{
    return media_decoder_get_ctl("media.decoder.vdec.step_mode");
}
int media_set_decoder_mpeg12_stat(u32 val)
{
	return media_decoder_set_ctl("media.decoder.mpeg12.stat",val);
}

int media_get_decoder_mpeg12_stat()
{
    return media_decoder_get_ctl("media.decoder.mpeg12.stat");
}

int media_set_decoder_mpeg12_dec_control(u32 val)
{
	return media_decoder_set_ctl("media.decoder.mpeg12.dec_control",val);
}

int media_get_decoder_mpeg12_dec_control()
{
    return media_decoder_get_ctl("media.decoder.mpeg12.dec_control");
}

int media_set_decoder_mpeg12_error_frame_skip_level(u32 val)
{
	return media_decoder_set_ctl("media.decoder.mpeg12.error_frame_skip_level",val);
}

int media_get_decoder_mpeg12_error_frame_skip_level()
{
    return media_decoder_get_ctl("media.decoder.mpeg12.error_frame_skip_level");
}

int media_set_decoder_mpeg4_stat(u32 val)
{
	return media_decoder_set_ctl("media.decoder.mpeg4.stat",val);
}

int media_get_decoder_mpeg4_stat()
{
    return media_decoder_get_ctl("media.decoder.mpeg4.stat");
}

int media_set_decoder_h265_use_cma(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.use_cma",val);
}

int media_get_decoder_h265_use_cma()
{
    return media_decoder_get_ctl("media.decoder.h265.use_cma");
}

int media_set_decoder_h265_bit_depth_luma(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.bit_depth_luma",val);
}

int media_get_decoder_h265_bit_depth_luma()
{
    return media_decoder_get_ctl("media.decoder.h265.bit_depth_luma");
}

int media_set_decoder_h265_video_signal_type(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.video_signal_type",val);
}

int media_get_decoder_h265_video_signal_type()
{
    return media_decoder_get_ctl("media.decoder.h265.video_signal_type");
}

int media_set_decoder_h265_dbg_nal_skip_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dbg_nal_skip_val",val);
}

int media_get_decoder_h265_dbg_nal_skip_val()
{
    return media_decoder_get_ctl("media.decoder.h265.dbg_nal_skip_val");
}

int media_set_decoder_h265_dbg_nal_skip_count(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dbg_nal_skip_count",val);
}

int media_get_decoder_h265_dbg_nal_skip_count()
{
    return media_decoder_get_ctl("media.decoder.h265.dbg_nal_skip_count");
}

int media_set_decoder_h265_radr(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.radr",val);
}

int media_get_decoder_h265_radr()
{
    return media_decoder_get_ctl("media.decoder.h265.radr");
}

int media_set_decoder_h265_rval(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.rval",val);
}

int media_get_decoder_h265_rval()
{
    return media_decoder_get_ctl("media.decoder.h265.rval");
}

int media_set_decoder_h265_dbg_cmd(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dbg_cmd",val);
}

int media_get_decoder_h265_dbg_cmd()
{
    return media_decoder_get_ctl("media.decoder.h265.dbg_cmd");
}

int media_set_decoder_h265_dbg_skip_decode_index(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dbg_skip_decode_index",val);
}

int media_get_decoder_h265_dbg_skip_decode_index()
{
    return media_decoder_get_ctl("media.decoder.h265.dbg_skip_decode_index");
}

int media_set_decoder_h265_endian(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.endian",val);
}

int media_get_decoder_h265_endian()
{
    return media_decoder_get_ctl("media.decoder.h265.endian");
}

int media_set_decoder_h265_step(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.step",val);
}

int media_get_decoder_h265_step()
{
    return media_decoder_get_ctl("media.decoder.h265.step");
}

int media_set_decoder_h265_decode_stop_pos(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.decode_stop_pos",val);
}

int media_get_decoder_h265_decode_stop_pos()
{
    return media_decoder_get_ctl("media.decoder.h265.decode_stop_pos");
}

int media_set_decoder_h265_decode_pic_begin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.decode_pic_begin",val);
}

int media_get_decoder_h265_decode_pic_begin()
{
    return media_decoder_get_ctl("media.decoder.h265.decode_pic_begin");
}

int media_set_decoder_h265_slice_parse_begin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.slice_parse_begin",val);
}

int media_get_decoder_h265_slice_parse_begin()
{
    return media_decoder_get_ctl("media.decoder.h265.slice_parse_begin");
}

int media_set_decoder_h265_nal_skip_policy(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.nal_skip_policy",val);
}

int media_get_decoder_h265_nal_skip_policy()
{
    return media_decoder_get_ctl("media.decoder.h265.nal_skip_policy");
}

int media_set_decoder_h265_i_only_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.i_only_val",val);
}

int media_get_decoder_h265_i_only_val()
{
    return media_decoder_get_ctl("media.decoder.h265.i_only_val");
}

int media_set_decoder_h265_error_handle_policy(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.error_handle_policy",val);
}

int media_get_decoder_h265_error_handle_policy()
{
    return media_decoder_get_ctl("media.decoder.h265.error_handle_policy");
}

int media_set_decoder_h265_error_handle_threshold(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.error_handle_threshold",val);
}

int media_get_decoder_h265_error_handle_threshold()
{
    return media_decoder_get_ctl("media.decoder.h265.error_handle_threshold");
}

int media_set_decoder_h265_handle_nal_skip_threshold(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.error_handle_nal_skip_threshold",val);
}

int media_get_decoder_h265_handle_nal_skip_threshold()
{
    return media_decoder_get_ctl("media.decoder.h265.error_handle_nal_skip_threshold");
}

int media_set_decoder_h265_error_handle_system_threshold(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.error_handle_system_threshold",val);
}

int media_get_decoder_h265_error_handle_system_threshold()
{
    return media_decoder_get_ctl("media.decoder.h265.error_handle_system_threshold");
}

int media_set_decoder_h265_error_skip_nal_count(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.error_skip_nal_count",val);
}

int media_get_decoder_h265_error_skip_nal_count()
{
    return media_decoder_get_ctl("media.decoder.h265.error_skip_nal_count");
}

int media_set_decoder_h265_debug(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.debug",val);
}

int media_get_decoder_h265_debug()
{
    return media_decoder_get_ctl("media.decoder.h265.debug");
}

int media_set_decoder_h265_debug_mask(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.debug_mask",val);
}

int media_get_decoder_h265_debug_mask()
{
    return media_decoder_get_ctl("media.decoder.h265.debug_mask");
}

int media_set_decoder_h265_buffer_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.buffer_mode",val);
}

int media_get_decoder_h265_buffer_mode()
{
    return media_decoder_get_ctl("media.decoder.h265.buffer_mode");
}

int media_set_decoder_h265_double_write_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.double_write_mode",val);
}

int media_get_decoder_h265_double_write_mode()
{
    return media_decoder_get_ctl("media.decoder.h265.double_write_mode");
}

int media_set_decoder_h265_buf_alloc_width(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.buf_alloc_width",val);
}

int media_get_decoder_h265_buf_alloc_width()
{
    return media_decoder_get_ctl("media.decoder.h265.buf_alloc_width");
}

int media_set_decoder_h265_buf_alloc_height(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.buf_alloc_height",val);
}

int media_get_decoder_h265_buf_alloc_height()
{
    return media_decoder_get_ctl("media.decoder.h265.buf_alloc_height");
}

int media_set_decoder_h265_dynamic_buf_num_margin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dynamic_buf_num_margin",val);
}

int media_get_decoder_h265_dynamic_buf_num_margin()
{
    return media_decoder_get_ctl("media.decoder.h265.dynamic_buf_num_margin");
}

int media_set_decoder_h265_max_buf_num(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.max_buf_num",val);
}

int media_get_decoder_h265_max_buf_num()
{
    return media_decoder_get_ctl("media.decoder.h265.max_buf_num");
}

int media_set_decoder_h265_buf_alloc_size(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.buf_alloc_size",val);
}

int media_get_decoder_h265_buf_alloc_size()
{
    return media_decoder_get_ctl("media.decoder.h265.buf_alloc_size");
}

int media_set_decoder_h265_buffer_mode_dbg(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.buffer_mode_dbg",val);
}

int media_get_decoder_h265_buffer_mode_dbg()
{
    return media_decoder_get_ctl("media.decoder.h265.buffer_mode_dbg");
}

int media_set_decoder_h265_mem_map_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.mem_map_mode",val);
}

int media_get_decoder_h265_mem_map_mode()
{
    return media_decoder_get_ctl("media.decoder.h265.mem_map_mode");
}

int media_set_decoder_h265_enable_mem_saving(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.enable_mem_saving",val);
}

int media_get_decoder_h265_enable_mem_saving()
{
    return media_decoder_get_ctl("media.decoder.h265.enable_mem_saving");
}

int media_set_decoder_h265_force_w_h(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.force_w_h",val);
}

int media_get_decoder_h265_force_w_h()
{
    return media_decoder_get_ctl("media.decoder.h265.force_w_h");
}

int media_set_decoder_h265_force_fps(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.force_fps",val);
}

int media_get_decoder_h265_force_fps()
{
    return media_decoder_get_ctl("media.decoder.h265.force_fps");
}

int media_set_decoder_h265_max_decoding_time(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.max_decoding_time",val);
}

int media_get_decoder_h265_max_decoding_time()
{
    return media_decoder_get_ctl("media.decoder.h265.max_decoding_time");
}

int media_set_decoder_h265_prefix_aux_buf_size(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.prefix_aux_buf_size",val);
}

int media_get_decoder_h265_prefix_aux_buf_size()
{
    return media_decoder_get_ctl("media.decoder.h265.prefix_aux_buf_size");
}

int media_set_decoder_h265_suffix_aux_buf_size(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.suffix_aux_buf_size",val);
}

int media_get_decoder_h265_suffix_aux_buf_size()
{
    return media_decoder_get_ctl("media.decoder.h265.suffix_aux_buf_size");
}

int media_set_decoder_h265_interlace_enable(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.interlace_enable",val);
}

int media_get_decoder_h265_interlace_enable()
{
    return media_decoder_get_ctl("media.decoder.h265.interlace_enable");
}

int media_set_decoder_h265_pts_unstable(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.pts_unstable",val);
}

int media_get_decoder_h265_pts_unstable()
{
    return media_decoder_get_ctl("media.decoder.h265.pts_unstable");
}

int media_set_decoder_h265_parser_sei_enable(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.parser_sei_enable",val);
}

int media_get_decoder_h265_parser_sei_enable()
{
    return media_decoder_get_ctl("media.decoder.h265.parser_sei_enable");
}

int media_set_decoder_h265_start_decode_buf_level(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.start_decode_buf_level",val);
}

int media_get_decoder_h265_start_decode_buf_level()
{
    return media_decoder_get_ctl("media.decoder.h265.start_decode_buf_level");
}

int media_set_decoder_h265_decode_timeout_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.decode_timeout_val",val);
}

int media_get_decoder_h265_decode_timeout_val()
{
    return media_decoder_get_ctl("media.decoder.h265.decode_timeout_val");
}

int media_set_decoder_h265_parser_dolby_vision_enable(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.parser_dolby_vision_enable",val);
}

int media_get_decoder_h265_parser_dolby_vision_enable()
{
    return media_decoder_get_ctl("media.decoder.h265.parser_dolby_vision_enable");
}

int media_set_decoder_h265_dv_toggle_prov_name(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dv_toggle_prov_name",val);
}

int media_get_decoder_h265_dv_toggle_prov_name()
{
    return media_decoder_get_ctl("media.decoder.h265.dv_toggle_prov_name");
}

int media_set_decoder_h265_dv_debug(u32 val)
{
	return media_decoder_set_ctl("media.decoder.h265.dv_debug",val);
}

int media_get_decoder_h265_dv_debug()
{
    return media_decoder_get_ctl("media.decoder.h265.dv_debug");
}

int media_set_decoder_vp9_bit_depth_luma(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.bit_depth_luma",val);
}

int media_get_decoder_vp9_bit_depth_luma()
{
    return media_decoder_get_ctl("media.decoder.vp9.bit_depth_luma");
}

int media_set_decoder_vp9_bit_depth_chroma(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.bit_depth_chroma",val);
}

int media_get_decoder_vp9_bit_depth_chroma()
{
    return media_decoder_get_ctl("media.decoder.vp9.bit_depth_chroma");
}

int media_set_decoder_vp9_frame_width(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.frame_width",val);
}

int media_get_decoder_vp9_frame_width()
{
    return media_decoder_get_ctl("media.decoder.vp9.frame_width");
}

int media_set_decoder_vp9_frame_height(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.frame_height",val);
}

int media_get_decoder_vp9_frame_height()
{
    return media_decoder_get_ctl("media.decoder.vp9.frame_height");
}

int media_set_decoder_vp9_debug(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.debug",val);
}

int media_get_decoder_vp9_debug()
{
    return media_decoder_get_ctl("media.decoder.vp9.debug");
}

int media_set_decoder_vp9_radr(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.radr",val);
}

int media_get_decoder_vp9_radr()
{
    return media_decoder_get_ctl("media.decoder.vp9.radr");
}

int media_set_decoder_vp9_rval(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.rval",val);
}

int media_get_decoder_vp9_rval()
{
    return media_decoder_get_ctl("media.decoder.vp9.rval");
}

int media_set_decoder_vp9_pop_shorts(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.pop_shorts",val);
}

int media_get_decoder_vp9_pop_shorts()
{
    return media_decoder_get_ctl("media.decoder.vp9.pop_shorts");
}

int media_set_decoder_vp9_dbg_cmd(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.dbg_cmd",val);
}

int media_get_decoder_vp9_dbg_cmd()
{
    return media_decoder_get_ctl("media.decoder.vp9.dbg_cmd");
}

int media_set_decoder_vp9_dbg_skip_decode_index(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.dbg_skip_decode_index",val);
}

int media_get_decoder_vp9_dbg_skip_decode_index()
{
    return media_decoder_get_ctl("media.decoder.vp9.dbg_skip_decode_index");
}

int media_set_decoder_vp9_endian(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.endian",val);
}

int media_get_decoder_vp9_endian()
{
    return media_decoder_get_ctl("media.decoder.vp9.endian");
}

int media_set_decoder_vp9_step(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.step",val);
}

int media_get_decoder_vp9_step()
{
    return media_decoder_get_ctl("media.decoder.vp9.step");
}

int media_set_decoder_vp9_decode_stop_pos(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.decode_stop_pos",val);
}

int media_get_decoder_vp9_decode_stop_pos()
{
    return media_decoder_get_ctl("media.decoder.vp9.decode_stop_pos");
}

int media_set_decoder_vp9_decode_pic_begin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.decode_pic_begin",val);
}

int media_get_decoder_vp9_decode_pic_begin()
{
    return media_decoder_get_ctl("media.decoder.vp9.decode_pic_begin");
}

int media_set_decoder_vp9_slice_parse_begin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.i_only_val",val);
}

int media_get_decoder_vp9_slice_parse_begin()
{
    return media_decoder_get_ctl("media.decoder.vp9.i_only_val");
}

int media_set_decoder_vp9_error_handle_policy(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.error_handle_policy",val);
}

int media_get_decoder_vp9_error_handle_policy()
{
    return media_decoder_get_ctl("media.decoder.vp9.error_handle_policy");
}

int media_set_decoder_vp9_buf_alloc_width(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.buf_alloc_width",val);
}

int media_get_decoder_vp9_buf_alloc_width()
{
    return media_decoder_get_ctl("media.decoder.vp9.buf_alloc_width");
}

int media_set_decoder_vp9_buf_alloc_depth(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.buf_alloc_depth",val);
}

int media_get_decoder_vp9_buf_alloc_depth()
{
    return media_decoder_get_ctl("media.decoder.vp9.buf_alloc_depth");
}

int media_set_decoder_vp9_buf_alloc_size(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.buf_alloc_size",val);
}

int media_get_decoder_vp9_buf_alloc_size()
{
    return media_decoder_get_ctl("media.decoder.vp9.buf_alloc_size");
}

int media_set_decoder_vp9_buffer_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.buffer_mode",val);
}

int media_get_decoder_vp9_buffer_mode()
{
    return media_decoder_get_ctl("media.decoder.vp9.buffer_mode");
}

int media_set_decoder_vp9_buffer_mode_dbg(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.buffer_mode_dbg",val);
}

int media_get_decoder_vp9_buffer_mode_dbg()
{
    return media_decoder_get_ctl("media.decoder.vp9.buffer_mode_dbg");
}

int media_set_decoder_vp9_max_buf_num(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.max_buf_num",val);
}

int media_get_decoder_vp9_max_buf_num()
{
    return media_decoder_get_ctl("media.decoder.vp9.max_buf_num");
}

int media_set_decoder_vp9_dynamic_buf_num_margin(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.dynamic_buf_num_margin",val);
}

int media_get_decoder_vp9_dynamic_buf_num_margin()
{
    return media_decoder_get_ctl("media.decoder.vp9.dynamic_buf_num_margin");
}

int media_set_decoder_vp9_mem_map_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.mem_map_mode",val);
}

int media_get_decoder_vp9_mem_map_mode()
{
    return media_decoder_get_ctl("media.decoder.vp9.mem_map_mode");
}

int media_set_decoder_vp9_double_write_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.double_write_mode",val);
}

int media_get_decoder_vp9_double_write_mode()
{
    return media_decoder_get_ctl("media.decoder.vp9.double_write_mode");
}

int media_set_decoder_vp9_enable_mem_saving(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.enable_mem_saving",val);
}

int media_get_decoder_vp9_enable_mem_saving()
{
    return media_decoder_get_ctl("media.decoder.vp9.enable_mem_saving");
}

int media_set_decoder_vp9_force_w_h(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.force_w_h",val);
}

int media_get_decoder_vp9_force_w_h()
{
    return media_decoder_get_ctl("media.decoder.vp9.force_w_h");
}

int media_set_decoder_vp9_force_fps(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.force_fps",val);
}

int media_get_decoder_vp9_force_fps()
{
    return media_decoder_get_ctl("media.decoder.vp9.force_fps");
}

int media_set_decoder_vp9_max_decoding_time(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.max_decoding_time",val);
}

int media_get_decoder_vp9_max_decoding_time()
{
    return media_decoder_get_ctl("media.decoder.vp9.max_decoding_time");
}

int media_set_decoder_vp9_on_no_keyframe_skiped(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.on_no_keyframe_skiped",val);
}

int media_get_decoder_vp9_on_no_keyframe_skiped()
{
    return media_decoder_get_ctl("media.decoder.vp9.on_no_keyframe_skiped");
}

int media_set_decoder_vp9_start_decode_buf_level(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.start_decode_buf_level",val);
}

int media_get_decoder_vp9_start_decode_buf_level()
{
    return media_decoder_get_ctl("media.decoder.vp9.start_decode_buf_level");
}

int media_set_decoder_vp9_decode_timeout_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.vp9.decode_timeout_val",val);
}

int media_get_decoder_vp9_decode_timeout_val()
{
    return media_decoder_get_ctl("media.decoder.vp9.decode_timeout_val");
}

int media_set_decoder_avs_stat(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.stat",val);
}

int media_get_decoder_avs_stat()
{
    return media_decoder_get_ctl("media.decoder.avs.stat");
}

int media_set_decoder_avs_debug_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.debug_val",val);
}

int media_get_decoder_avs_debug_val()
{
    return media_decoder_get_ctl("media.decoder.avs.debug_val");
}

int media_set_decoder_avs_error_recovery_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.error_recovery_mode",val);
}

int media_get_decoder_avs_error_recovery_mode()
{
    return media_decoder_get_ctl("media.decoder.avs.error_recovery_mode");
}

int media_set_decoder_avs_pic_type(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.pic_type",val);
}

int media_get_decoder_avs_pic_type()
{
    return media_decoder_get_ctl("media.decoder.avs.pic_type");
}

int media_set_decoder_avs_radr(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.radr",val);
}

int media_get_decoder_avs_radr()
{
    return media_decoder_get_ctl("media.decoder.avs.radr");
}

int media_set_decoder_avs_vf_buf_num(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.vf_buf_num",val);
}

int media_get_decoder_avs_vf_buf_num()
{
    return media_decoder_get_ctl("media.decoder.avs.vf_buf_num");
}

int media_set_decoder_avs_vf_buf_num_used(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.vf_buf_num_used",val);
}

int media_get_decoder_avs_vf_buf_num_used()
{
    return media_decoder_get_ctl("media.decoder.avs.vf_buf_num_used");
}

int media_set_decoder_avs_canvas_base(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.canvas_base",val);
}

int media_get_decoder_avs_canvas_base()
{
    return media_decoder_get_ctl("media.decoder.avs.canvas_base");
}

int media_set_decoder_avs_work_buf_size(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.work_buf_size",val);
}

int media_get_decoder_avs_work_buf_size()
{
    return media_decoder_get_ctl("media.decoder.avs.work_buf_size");
}

int media_set_decoder_avs_firmware_sel(u32 val)
{
	return media_decoder_set_ctl("media.decoder.avs.firmware_sel",val);
}

int media_get_decoder_avs_firmware_sel()
{
    return media_decoder_get_ctl("media.decoder.avs.firmware_sel");
}

int media_set_decoder_jpeg_debug_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.jpeg.debug_val",val);
}

int media_get_decoder_jpeg_debug_val()
{
    return media_decoder_get_ctl("media.decoder.jpeg.debug_val");
}

int media_set_decoder_jpeg_dump_file_val(u32 val)
{
	return media_decoder_set_ctl("media.decoder.jpeg.dump_file_val",val);
}

int media_get_decoder_jpeg_dump_file_val()
{
    return media_decoder_get_ctl("media.decoder.jpeg.dump_file_val");
}

int media_set_decoder_jpeg_p2p_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.jpeg.p2p_mode",val);
}

int media_get_decoder_jpeg_p2p_mode()
{
    return media_decoder_get_ctl("media.decoder.jpeg.p2p_mode");
}

int media_set_decoder_jpeg_output_format_mode(u32 val)
{
	return media_decoder_set_ctl("media.decoder.jpeg.output_format_mode",val);
}

int media_get_decoder_jpeg_output_format_mode()
{
    return media_decoder_get_ctl("media.decoder.jpeg.output_format_mode");
}
#ifdef  __cplusplus
}
#endif