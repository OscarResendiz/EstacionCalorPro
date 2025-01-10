################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Delays/delays.cpp 

OBJS += \
./Core/Inc/Delays/delays.o 

CPP_DEPS += \
./Core/Inc/Delays/delays.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Delays/%.o Core/Inc/Delays/%.su Core/Inc/Delays/%.cyclo: ../Core/Inc/Delays/%.cpp Core/Inc/Delays/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Delays

clean-Core-2f-Inc-2f-Delays:
	-$(RM) ./Core/Inc/Delays/delays.cyclo ./Core/Inc/Delays/delays.d ./Core/Inc/Delays/delays.o ./Core/Inc/Delays/delays.su

.PHONY: clean-Core-2f-Inc-2f-Delays

