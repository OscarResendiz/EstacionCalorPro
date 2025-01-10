################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/ILI9341/ILI9341_GFX.cpp \
../Core/Inc/ILI9341/ILI9341_STM32_Driver.cpp 

OBJS += \
./Core/Inc/ILI9341/ILI9341_GFX.o \
./Core/Inc/ILI9341/ILI9341_STM32_Driver.o 

CPP_DEPS += \
./Core/Inc/ILI9341/ILI9341_GFX.d \
./Core/Inc/ILI9341/ILI9341_STM32_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ILI9341/%.o Core/Inc/ILI9341/%.su Core/Inc/ILI9341/%.cyclo: ../Core/Inc/ILI9341/%.cpp Core/Inc/ILI9341/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ILI9341

clean-Core-2f-Inc-2f-ILI9341:
	-$(RM) ./Core/Inc/ILI9341/ILI9341_GFX.cyclo ./Core/Inc/ILI9341/ILI9341_GFX.d ./Core/Inc/ILI9341/ILI9341_GFX.o ./Core/Inc/ILI9341/ILI9341_GFX.su ./Core/Inc/ILI9341/ILI9341_STM32_Driver.cyclo ./Core/Inc/ILI9341/ILI9341_STM32_Driver.d ./Core/Inc/ILI9341/ILI9341_STM32_Driver.o ./Core/Inc/ILI9341/ILI9341_STM32_Driver.su

.PHONY: clean-Core-2f-Inc-2f-ILI9341

