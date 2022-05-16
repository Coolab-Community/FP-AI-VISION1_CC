################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Middlewares/ST/STM32_Image/Src/img_preprocess.c 

OBJS += \
./Middlewares/STM32_Image/img_preprocess.o 

C_DEPS += \
./Middlewares/STM32_Image/img_preprocess.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_Image/img_preprocess.o: C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Middlewares/ST/STM32_Image/Src/img_preprocess.c Middlewares/STM32_Image/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=1 -DCAMERA_CAPTURE_RES=1 -DRESIZING_ALGO=1 -DPIXEL_FMT_CONV=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STM32_Image

clean-Middlewares-2f-STM32_Image:
	-$(RM) ./Middlewares/STM32_Image/img_preprocess.d ./Middlewares/STM32_Image/img_preprocess.o ./Middlewares/STM32_Image/img_preprocess.su

.PHONY: clean-Middlewares-2f-STM32_Image

