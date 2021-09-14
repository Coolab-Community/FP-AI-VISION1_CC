################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Middlewares/ST/STM32_AI_Utilities/Src/ai_utilities.c 

OBJS += \
./Middlewares/STM32_AI_Utilities/ai_utilities.o 

C_DEPS += \
./Middlewares/STM32_AI_Utilities/ai_utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_AI_Utilities/ai_utilities.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Middlewares/ST/STM32_AI_Utilities/Src/ai_utilities.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/STM32_AI_Utilities/ai_utilities.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

