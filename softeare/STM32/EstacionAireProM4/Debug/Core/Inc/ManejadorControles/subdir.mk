################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/ManejadorControles/CManejadorControles.cpp \
../Core/Inc/ManejadorControles/CManejadorEventosControles.cpp 

OBJS += \
./Core/Inc/ManejadorControles/CManejadorControles.o \
./Core/Inc/ManejadorControles/CManejadorEventosControles.o 

CPP_DEPS += \
./Core/Inc/ManejadorControles/CManejadorControles.d \
./Core/Inc/ManejadorControles/CManejadorEventosControles.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ManejadorControles/%.o Core/Inc/ManejadorControles/%.su Core/Inc/ManejadorControles/%.cyclo: ../Core/Inc/ManejadorControles/%.cpp Core/Inc/ManejadorControles/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ManejadorControles

clean-Core-2f-Inc-2f-ManejadorControles:
	-$(RM) ./Core/Inc/ManejadorControles/CManejadorControles.cyclo ./Core/Inc/ManejadorControles/CManejadorControles.d ./Core/Inc/ManejadorControles/CManejadorControles.o ./Core/Inc/ManejadorControles/CManejadorControles.su ./Core/Inc/ManejadorControles/CManejadorEventosControles.cyclo ./Core/Inc/ManejadorControles/CManejadorEventosControles.d ./Core/Inc/ManejadorControles/CManejadorEventosControles.o ./Core/Inc/ManejadorControles/CManejadorEventosControles.su

.PHONY: clean-Core-2f-Inc-2f-ManejadorControles

