################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Max6675/Max6675.cpp 

OBJS += \
./Core/Inc/Max6675/Max6675.o 

CPP_DEPS += \
./Core/Inc/Max6675/Max6675.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Max6675/%.o Core/Inc/Max6675/%.su Core/Inc/Max6675/%.cyclo: ../Core/Inc/Max6675/%.cpp Core/Inc/Max6675/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Max6675

clean-Core-2f-Inc-2f-Max6675:
	-$(RM) ./Core/Inc/Max6675/Max6675.cyclo ./Core/Inc/Max6675/Max6675.d ./Core/Inc/Max6675/Max6675.o ./Core/Inc/Max6675/Max6675.su

.PHONY: clean-Core-2f-Inc-2f-Max6675

