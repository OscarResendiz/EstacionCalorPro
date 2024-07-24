################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/ControlVelocidadAire/ControlVelocidadAire.cpp 

OBJS += \
./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.o 

CPP_DEPS += \
./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ControlVelocidadAire/%.o Core/Inc/ControlVelocidadAire/%.su Core/Inc/ControlVelocidadAire/%.cyclo: ../Core/Inc/ControlVelocidadAire/%.cpp Core/Inc/ControlVelocidadAire/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ControlVelocidadAire

clean-Core-2f-Inc-2f-ControlVelocidadAire:
	-$(RM) ./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.cyclo ./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.d ./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.o ./Core/Inc/ControlVelocidadAire/ControlVelocidadAire.su

.PHONY: clean-Core-2f-Inc-2f-ControlVelocidadAire

