################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/EPROM/CEprom.cpp 

OBJS += \
./Core/Inc/EPROM/CEprom.o 

CPP_DEPS += \
./Core/Inc/EPROM/CEprom.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/EPROM/%.o Core/Inc/EPROM/%.su Core/Inc/EPROM/%.cyclo: ../Core/Inc/EPROM/%.cpp Core/Inc/EPROM/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-EPROM

clean-Core-2f-Inc-2f-EPROM:
	-$(RM) ./Core/Inc/EPROM/CEprom.cyclo ./Core/Inc/EPROM/CEprom.d ./Core/Inc/EPROM/CEprom.o ./Core/Inc/EPROM/CEprom.su

.PHONY: clean-Core-2f-Inc-2f-EPROM

