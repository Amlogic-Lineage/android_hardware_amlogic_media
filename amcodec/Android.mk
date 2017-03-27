LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

AMADEC_PATH:=$(TOP)/hardware/amlogic/LibAudio/amadec/

LOCAL_SRC_FILES := \
	codec/codec_ctrl.c \
	codec/codec_h_ctrl.c \
	codec/codec_msg.c \
	audio_ctl/audio_ctrl.c \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
					$(LOCAL_PATH)/codec \
					$(LOCAL_PATH)/audio_ctl \
					$(AMADEC_PATH)/include \
					$(LOCAL_PATH)/../amavutils/include \
										
LOCAL_ARM_MODE := arm
LOCAL_STATIC_LIBRARIES := libamadec
LOCAL_MODULE:= libamcodec

include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	codec/codec_ctrl.c \
	codec/codec_h_ctrl.c \
	codec/codec_msg.c \
	audio_ctl/audio_ctrl.c \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
	$(LOCAL_PATH)/codec \
	$(LOCAL_PATH)/audio_ctl \
	$(AMADEC_PATH)//include \
	$(LOCAL_PATH)/../amavutils/include \



LOCAL_SHARED_LIBRARIES = libutils libmedia libz libbinder libdl libcutils libc libamavutils
LOCAL_SHARED_LIBRARIES += libamadec


LOCAL_ARM_MODE := arm
LOCAL_MODULE:= libamcodec
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

