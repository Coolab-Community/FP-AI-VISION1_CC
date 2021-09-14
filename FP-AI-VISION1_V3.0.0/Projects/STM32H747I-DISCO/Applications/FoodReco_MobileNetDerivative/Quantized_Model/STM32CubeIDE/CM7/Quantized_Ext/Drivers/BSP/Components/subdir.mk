################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/mt25tl01g/mt25tl01g.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/otm8009a/otm8009a.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/otm8009a/otm8009a_reg.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov5640/ov5640.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov5640/ov5640_reg.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov9655/ov9655.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov9655/ov9655_reg.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/wm8994/wm8994.c \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/wm8994/wm8994_reg.c 

OBJS += \
./Drivers/BSP/Components/mt25tl01g.o \
./Drivers/BSP/Components/otm8009a.o \
./Drivers/BSP/Components/otm8009a_reg.o \
./Drivers/BSP/Components/ov5640.o \
./Drivers/BSP/Components/ov5640_reg.o \
./Drivers/BSP/Components/ov9655.o \
./Drivers/BSP/Components/ov9655_reg.o \
./Drivers/BSP/Components/wm8994.o \
./Drivers/BSP/Components/wm8994_reg.o 

C_DEPS += \
./Drivers/BSP/Components/mt25tl01g.d \
./Drivers/BSP/Components/otm8009a.d \
./Drivers/BSP/Components/otm8009a_reg.d \
./Drivers/BSP/Components/ov5640.d \
./Drivers/BSP/Components/ov5640_reg.d \
./Drivers/BSP/Components/ov9655.d \
./Drivers/BSP/Components/ov9655_reg.d \
./Drivers/BSP/Components/wm8994.d \
./Drivers/BSP/Components/wm8994_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/mt25tl01g.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/mt25tl01g/mt25tl01g.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/mt25tl01g.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/otm8009a.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/otm8009a/otm8009a.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/otm8009a.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/otm8009a_reg.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/otm8009a/otm8009a_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/otm8009a_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ov5640.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov5640/ov5640.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ov5640.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ov5640_reg.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov5640/ov5640_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ov5640_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ov9655.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov9655/ov9655.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ov9655.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ov9655_reg.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/ov9655/ov9655_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ov9655_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/wm8994.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/wm8994/wm8994.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/wm8994.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/wm8994_reg.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Drivers/BSP/Components/wm8994/wm8994_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM '-DMEMORY_SCHEME=1' '-DCAMERA_CAPTURE_RES=1' '-DRESIZING_ALGO=1' '-DPIXEL_FMT_CONV=1' -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Drivers/BSP/Components/wm8994 -I../../../../../../../../Drivers/BSP/Components/mt25tl01g -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/CPU -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_Image/Inc -I../../../../../../../../Middlewares/ST/STM32_Fs -I../../../../../../../../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/wm8994_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

