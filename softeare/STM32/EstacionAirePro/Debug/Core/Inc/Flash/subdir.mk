################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Flash/CFlash.cpp 

OBJS += \
./Core/Inc/Flash/CFlash.o 

CPP_DEPS += \
./Core/Inc/Flash/CFlash.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Flash/%.o Core/Inc/Flash/%.su Core/Inc/Flash/%.cyclo: ../Core/Inc/Flash/%.cpp Core/Inc/Flash/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Flash

clean-Core-2f-Inc-2f-Flash:
	-$(RM) ./Core/Inc/Flash/CFlash.cyclo ./Core/Inc/Flash/CFlash.d ./Core/Inc/Flash/CFlash.o ./Core/Inc/Flash/CFlash.su

.PHONY: clean-Core-2f-Inc-2f-Flash

