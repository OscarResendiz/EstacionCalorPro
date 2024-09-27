################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.cpp 

OBJS += \
./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.o 

CPP_DEPS += \
./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/ConfigurarPantallaMemoria/%.o Core/Inc/GUI/ConfigurarPantallaMemoria/%.su Core/Inc/GUI/ConfigurarPantallaMemoria/%.cyclo: ../Core/Inc/GUI/ConfigurarPantallaMemoria/%.cpp Core/Inc/GUI/ConfigurarPantallaMemoria/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI-2f-ConfigurarPantallaMemoria

clean-Core-2f-Inc-2f-GUI-2f-ConfigurarPantallaMemoria:
	-$(RM) ./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.cyclo ./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.d ./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.o ./Core/Inc/GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.su

.PHONY: clean-Core-2f-Inc-2f-GUI-2f-ConfigurarPantallaMemoria

