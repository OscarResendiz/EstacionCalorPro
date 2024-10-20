################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Calefactor/Calefactor.cpp 

OBJS += \
./Core/Inc/Calefactor/Calefactor.o 

CPP_DEPS += \
./Core/Inc/Calefactor/Calefactor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Calefactor/%.o Core/Inc/Calefactor/%.su Core/Inc/Calefactor/%.cyclo: ../Core/Inc/Calefactor/%.cpp Core/Inc/Calefactor/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Calefactor

clean-Core-2f-Inc-2f-Calefactor:
	-$(RM) ./Core/Inc/Calefactor/Calefactor.cyclo ./Core/Inc/Calefactor/Calefactor.d ./Core/Inc/Calefactor/Calefactor.o ./Core/Inc/Calefactor/Calefactor.su

.PHONY: clean-Core-2f-Inc-2f-Calefactor

