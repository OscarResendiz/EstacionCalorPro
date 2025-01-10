################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.cpp 

OBJS += \
./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.o 

CPP_DEPS += \
./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/%.o Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/%.su Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/%.cyclo: ../Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/%.cpp Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-SensorTemperatura-2f-InterfaceSensorTemperatura

clean-Core-2f-Inc-2f-SensorTemperatura-2f-InterfaceSensorTemperatura:
	-$(RM) ./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.cyclo ./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.d ./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.o ./Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/InterfaceSensorTemperatura.su

.PHONY: clean-Core-2f-Inc-2f-SensorTemperatura-2f-InterfaceSensorTemperatura

