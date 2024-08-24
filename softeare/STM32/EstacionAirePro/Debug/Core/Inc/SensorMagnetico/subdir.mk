################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.cpp \
../Core/Inc/SensorMagnetico/SensorMagnetico.cpp 

OBJS += \
./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.o \
./Core/Inc/SensorMagnetico/SensorMagnetico.o 

CPP_DEPS += \
./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.d \
./Core/Inc/SensorMagnetico/SensorMagnetico.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/SensorMagnetico/%.o Core/Inc/SensorMagnetico/%.su Core/Inc/SensorMagnetico/%.cyclo: ../Core/Inc/SensorMagnetico/%.cpp Core/Inc/SensorMagnetico/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-SensorMagnetico

clean-Core-2f-Inc-2f-SensorMagnetico:
	-$(RM) ./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.cyclo ./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.d ./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.o ./Core/Inc/SensorMagnetico/CManejadorEventoSensorMagnetico.su ./Core/Inc/SensorMagnetico/SensorMagnetico.cyclo ./Core/Inc/SensorMagnetico/SensorMagnetico.d ./Core/Inc/SensorMagnetico/SensorMagnetico.o ./Core/Inc/SensorMagnetico/SensorMagnetico.su

.PHONY: clean-Core-2f-Inc-2f-SensorMagnetico

