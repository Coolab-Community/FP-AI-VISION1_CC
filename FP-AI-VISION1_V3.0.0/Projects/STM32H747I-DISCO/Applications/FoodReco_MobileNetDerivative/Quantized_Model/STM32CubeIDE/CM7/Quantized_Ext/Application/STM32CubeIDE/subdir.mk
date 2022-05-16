################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_cm4.s \
C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_stm32h747xx.s 

OBJS += \
./Application/STM32CubeIDE/startup_cm4.o \
./Application/STM32CubeIDE/startup_stm32h747xx.o 

S_DEPS += \
./Application/STM32CubeIDE/startup_cm4.d \
./Application/STM32CubeIDE/startup_stm32h747xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/STM32CubeIDE/startup_cm4.o: C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_cm4.s Application/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Application/STM32CubeIDE/startup_stm32h747xx.o: C:/Users/Gothmog/Desktop/STAGE_PROGS/FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/startup_stm32h747xx.s Application/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-STM32CubeIDE

clean-Application-2f-STM32CubeIDE:
	-$(RM) ./Application/STM32CubeIDE/startup_cm4.d ./Application/STM32CubeIDE/startup_cm4.o ./Application/STM32CubeIDE/startup_stm32h747xx.d ./Application/STM32CubeIDE/startup_stm32h747xx.o

.PHONY: clean-Application-2f-STM32CubeIDE

