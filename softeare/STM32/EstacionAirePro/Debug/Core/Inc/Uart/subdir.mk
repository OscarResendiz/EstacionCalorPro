################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Uart/Uart.cpp 

OBJS += \
./Core/Inc/Uart/Uart.o 

CPP_DEPS += \
./Core/Inc/Uart/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Uart/%.o Core/Inc/Uart/%.su Core/Inc/Uart/%.cyclo: ../Core/Inc/Uart/%.cpp Core/Inc/Uart/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Uart

clean-Core-2f-Inc-2f-Uart:
	-$(RM) ./Core/Inc/Uart/Uart.cyclo ./Core/Inc/Uart/Uart.d ./Core/Inc/Uart/Uart.o ./Core/Inc/Uart/Uart.su

.PHONY: clean-Core-2f-Inc-2f-Uart

