################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/EEPROM/CEEProm.cpp 

OBJS += \
./Core/Inc/EEPROM/CEEProm.o 

CPP_DEPS += \
./Core/Inc/EEPROM/CEEProm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/EEPROM/%.o Core/Inc/EEPROM/%.su Core/Inc/EEPROM/%.cyclo: ../Core/Inc/EEPROM/%.cpp Core/Inc/EEPROM/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-EEPROM

clean-Core-2f-Inc-2f-EEPROM:
	-$(RM) ./Core/Inc/EEPROM/CEEProm.cyclo ./Core/Inc/EEPROM/CEEProm.d ./Core/Inc/EEPROM/CEEProm.o ./Core/Inc/EEPROM/CEEProm.su

.PHONY: clean-Core-2f-Inc-2f-EEPROM

