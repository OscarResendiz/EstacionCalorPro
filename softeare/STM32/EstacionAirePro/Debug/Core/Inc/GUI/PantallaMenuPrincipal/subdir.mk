################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.cpp 

OBJS += \
./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.o 

CPP_DEPS += \
./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/PantallaMenuPrincipal/%.o Core/Inc/GUI/PantallaMenuPrincipal/%.su Core/Inc/GUI/PantallaMenuPrincipal/%.cyclo: ../Core/Inc/GUI/PantallaMenuPrincipal/%.cpp Core/Inc/GUI/PantallaMenuPrincipal/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI-2f-PantallaMenuPrincipal

clean-Core-2f-Inc-2f-GUI-2f-PantallaMenuPrincipal:
	-$(RM) ./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.cyclo ./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.d ./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.o ./Core/Inc/GUI/PantallaMenuPrincipal/CMenuPrincipal.su

.PHONY: clean-Core-2f-Inc-2f-GUI-2f-PantallaMenuPrincipal

