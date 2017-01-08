
ARCH ?= arm64
TOOLS := aarch64-linux-gnu-
CONFIGS := CONFIG_AMLOGIC_MEDIA_VDEC_H264=m \
	CONFIG_AMLOGIC_MEDIA_VDEC_H265=m

define copy-media-modules
$(foreach m, $(shell find $(strip $(1)) -name "*.ko"),\
	$(shell cp $(m) $(strip $(2)) -rfa))
endef

ifneq (,$(ANDROID_BUILD_TOP))
KDIR := $(OUT)/obj/KERNEL_OBJ/

MEDIA_DRIVERS := $(ANDROID_BUILD_TOP)/hardware/amlogic/media/drivers
ifeq (,$(wildcard $(MEDIA_DRIVERS)))
$(error No find the dir of drivers.)
endif

INCLUDE := $(MEDIA_DRIVERS)/include
ifeq (,$(wildcard $(INCLUDE)))
$(error No find the dir of include.)
endif

define media-modules
	$(MAKE) -C $(KDIR) M=$(MEDIA_DRIVERS) ARCH=$(ARCH) \
	CROSS_COMPILE=$(TOOLS) $(CONFIGS) \
	EXTRA_CFLAGS+=-I$(INCLUDE)
endef

else
KDIR := $(PWD)/kernel
ifeq (,$(wildcard $(KDIR)))
$(error No find the dir of kernel.)
endif

MEDIA_DRIVERS := $(PWD)/media/drivers
ifeq (,$(wildcard $(MEDIA_DRIVERS)))
$(error No find the dir of drivers.)
endif

INCLUDE := $(MEDIA_DRIVERS)/include
ifeq (,$(wildcard $(INCLUDE)))
$(error No find the dir of include.)
endif

MODS_OUT ?= $(MEDIA_DRIVERS)/../modules
TOOLS := /opt/gcc-linaro-5.3-2016.02-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-

modules:
	$(MAKE) -C $(KDIR) M=$(MEDIA_DRIVERS) ARCH=$(ARCH) \
	CROSS_COMPILE=$(TOOLS) $(CONFIGS) \
	EXTRA_CFLAGS+=-I$(INCLUDE)

copy-modules:
	@echo "start copying media modules."
	$(call copy-media-modules, $(MEDIA_DRIVERS), $(MODS_OUT))

all: modules copy-modules

clean:
	$(MAKE) -C $(KDIR) M=$(MEDIA_DRIVERS) ARCH=$(ARCH) clean

endif
