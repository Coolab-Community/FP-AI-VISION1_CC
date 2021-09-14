################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_cm4.s \
D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_stm32h747xx.s 

OBJS += \
./Application/STM32CubeIDE/startup_cm4.o \
./Application/STM32CubeIDE/startup_stm32h747xx.o 

S_DEPS += \
./Application/STM32CubeIDE/startup_cm4.d \
./Application/STM32CubeIDE/startup_stm32h747xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/STM32CubeIDE/startup_cm4.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_cm4.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Application/STM32CubeIDE/startup_cm4.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Application/STM32CubeIDE/startup_stm32h747xx.o: D:/OneDrive/STM32_AI/workspace/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_stm32h747xx.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Application/STM32CubeIDE/startup_stm32h747xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

