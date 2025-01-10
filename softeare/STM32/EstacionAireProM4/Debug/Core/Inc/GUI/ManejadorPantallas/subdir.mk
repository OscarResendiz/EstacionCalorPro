################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.cpp 

OBJS += \
./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.o 

CPP_DEPS += \
./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/ManejadorPantallas/%.o Core/Inc/GUI/ManejadorPantallas/%.su Core/Inc/GUI/ManejadorPantallas/%.cyclo: ../Core/Inc/GUI/ManejadorPantallas/%.cpp Core/Inc/GUI/ManejadorPantallas/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI-2f-ManejadorPantallas

clean-Core-2f-Inc-2f-GUI-2f-ManejadorPantallas:
	-$(RM) ./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.cyclo ./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.d ./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.o ./Core/Inc/GUI/ManejadorPantallas/CManejadorPantallas.su

.PHONY: clean-Core-2f-Inc-2f-GUI-2f-ManejadorPantallas

