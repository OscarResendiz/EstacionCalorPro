################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Timer/Timer.cpp 

OBJS += \
./Core/Inc/Timer/Timer.o 

CPP_DEPS += \
./Core/Inc/Timer/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Timer/%.o Core/Inc/Timer/%.su Core/Inc/Timer/%.cyclo: ../Core/Inc/Timer/%.cpp Core/Inc/Timer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Timer

clean-Core-2f-Inc-2f-Timer:
	-$(RM) ./Core/Inc/Timer/Timer.cyclo ./Core/Inc/Timer/Timer.d ./Core/Inc/Timer/Timer.o ./Core/Inc/Timer/Timer.su

.PHONY: clean-Core-2f-Inc-2f-Timer

