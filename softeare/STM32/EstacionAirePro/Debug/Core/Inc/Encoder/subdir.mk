################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Encoder/CEncoder.cpp \
../Core/Inc/Encoder/CManejadorEventosEncoder.cpp 

OBJS += \
./Core/Inc/Encoder/CEncoder.o \
./Core/Inc/Encoder/CManejadorEventosEncoder.o 

CPP_DEPS += \
./Core/Inc/Encoder/CEncoder.d \
./Core/Inc/Encoder/CManejadorEventosEncoder.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Encoder/%.o Core/Inc/Encoder/%.su Core/Inc/Encoder/%.cyclo: ../Core/Inc/Encoder/%.cpp Core/Inc/Encoder/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Encoder

clean-Core-2f-Inc-2f-Encoder:
	-$(RM) ./Core/Inc/Encoder/CEncoder.cyclo ./Core/Inc/Encoder/CEncoder.d ./Core/Inc/Encoder/CEncoder.o ./Core/Inc/Encoder/CEncoder.su ./Core/Inc/Encoder/CManejadorEventosEncoder.cyclo ./Core/Inc/Encoder/CManejadorEventosEncoder.d ./Core/Inc/Encoder/CManejadorEventosEncoder.o ./Core/Inc/Encoder/CManejadorEventosEncoder.su

.PHONY: clean-Core-2f-Inc-2f-Encoder

