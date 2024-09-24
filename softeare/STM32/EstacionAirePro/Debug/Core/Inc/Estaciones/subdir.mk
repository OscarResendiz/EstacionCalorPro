################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Estaciones/CEstacionBase.cpp \
../Core/Inc/Estaciones/CestacionBaku601.cpp 

OBJS += \
./Core/Inc/Estaciones/CEstacionBase.o \
./Core/Inc/Estaciones/CestacionBaku601.o 

CPP_DEPS += \
./Core/Inc/Estaciones/CEstacionBase.d \
./Core/Inc/Estaciones/CestacionBaku601.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Estaciones/%.o Core/Inc/Estaciones/%.su Core/Inc/Estaciones/%.cyclo: ../Core/Inc/Estaciones/%.cpp Core/Inc/Estaciones/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Estaciones

clean-Core-2f-Inc-2f-Estaciones:
	-$(RM) ./Core/Inc/Estaciones/CEstacionBase.cyclo ./Core/Inc/Estaciones/CEstacionBase.d ./Core/Inc/Estaciones/CEstacionBase.o ./Core/Inc/Estaciones/CEstacionBase.su ./Core/Inc/Estaciones/CestacionBaku601.cyclo ./Core/Inc/Estaciones/CestacionBaku601.d ./Core/Inc/Estaciones/CestacionBaku601.o ./Core/Inc/Estaciones/CestacionBaku601.su

.PHONY: clean-Core-2f-Inc-2f-Estaciones

