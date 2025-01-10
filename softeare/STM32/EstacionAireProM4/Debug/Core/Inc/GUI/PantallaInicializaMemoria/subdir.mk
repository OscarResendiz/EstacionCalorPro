################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.cpp 

OBJS += \
./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.o 

CPP_DEPS += \
./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/PantallaInicializaMemoria/%.o Core/Inc/GUI/PantallaInicializaMemoria/%.su Core/Inc/GUI/PantallaInicializaMemoria/%.cyclo: ../Core/Inc/GUI/PantallaInicializaMemoria/%.cpp Core/Inc/GUI/PantallaInicializaMemoria/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI-2f-PantallaInicializaMemoria

clean-Core-2f-Inc-2f-GUI-2f-PantallaInicializaMemoria:
	-$(RM) ./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.cyclo ./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.d ./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.o ./Core/Inc/GUI/PantallaInicializaMemoria/CPantallaInicializaMemoria.su

.PHONY: clean-Core-2f-Inc-2f-GUI-2f-PantallaInicializaMemoria

