################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Boton/CManejadorBoton.cpp \
../Core/Inc/Boton/CManejadorEventosBoton.cpp 

OBJS += \
./Core/Inc/Boton/CManejadorBoton.o \
./Core/Inc/Boton/CManejadorEventosBoton.o 

CPP_DEPS += \
./Core/Inc/Boton/CManejadorBoton.d \
./Core/Inc/Boton/CManejadorEventosBoton.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Boton/%.o Core/Inc/Boton/%.su Core/Inc/Boton/%.cyclo: ../Core/Inc/Boton/%.cpp Core/Inc/Boton/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Boton

clean-Core-2f-Inc-2f-Boton:
	-$(RM) ./Core/Inc/Boton/CManejadorBoton.cyclo ./Core/Inc/Boton/CManejadorBoton.d ./Core/Inc/Boton/CManejadorBoton.o ./Core/Inc/Boton/CManejadorBoton.su ./Core/Inc/Boton/CManejadorEventosBoton.cyclo ./Core/Inc/Boton/CManejadorEventosBoton.d ./Core/Inc/Boton/CManejadorEventosBoton.o ./Core/Inc/Boton/CManejadorEventosBoton.su

.PHONY: clean-Core-2f-Inc-2f-Boton

