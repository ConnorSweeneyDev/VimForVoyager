# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx/stm32_isr.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/GD/GD32F303/hal_lld.c \
               $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx/hal_efl_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS_CONTRIB)/os/hal/ports/GD/GD32F303 \
               $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx/hal_adc_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx/hal_adc_lld.c
endif

# Drivers compatible with the platform.
include $(CHIBIOS)/os/hal/ports/STM32/LLD/CANv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/DACv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/DMAv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/GPIOv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/GD/GD32F303/I2Cv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/RTCv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/SDIOv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/SPIv1/driver_v2.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/SYSTICKv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/TIMv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/USBv1/driver.mk
include $(CHIBIOS)/os/hal/ports/STM32/LLD/xWDGv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
