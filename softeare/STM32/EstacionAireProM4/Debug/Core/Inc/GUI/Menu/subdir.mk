################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/Menu/CManejadorEventoMenu.cpp \
../Core/Inc/GUI/Menu/CMenu.cpp \
../Core/Inc/GUI/Menu/CMenuItem.cpp 

OBJS += \
./Core/Inc/GUI/Menu/CManejadorEventoMenu.o \
./Core/Inc/GUI/Menu/CMenu.o \
./Core/Inc/GUI/Menu/CMenuItem.o 

CPP_DEPS += \
./Core/Inc/GUI/Menu/CManejadorEventoMenu.d \
./Core/Inc/GUI/Menu/CMenu.d \
./Core/Inc/GUI/Menu/CMenuItem.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/Menu/%.o Core/Inc/GUI/Menu/%.su Core/Inc/GUI/Menu/%.cyclo: ../Core/Inc/GUI/Menu/%.cpp Core/Inc/GUI/Menu/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI-2f-Menu

clean-Core-2f-Inc-2f-GUI-2f-Menu:
	-$(RM) ./Core/Inc/GUI/Menu/CManejadorEventoMenu.cyclo ./Core/Inc/GUI/Menu/CManejadorEventoMenu.d ./Core/Inc/GUI/Menu/CManejadorEventoMenu.o ./Core/Inc/GUI/Menu/CManejadorEventoMenu.su ./Core/Inc/GUI/Menu/CMenu.cyclo ./Core/Inc/GUI/Menu/CMenu.d ./Core/Inc/GUI/Menu/CMenu.o ./Core/Inc/GUI/Menu/CMenu.su ./Core/Inc/GUI/Menu/CMenuItem.cyclo ./Core/Inc/GUI/Menu/CMenuItem.d ./Core/Inc/GUI/Menu/CMenuItem.o ./Core/Inc/GUI/Menu/CMenuItem.su

.PHONY: clean-Core-2f-Inc-2f-GUI-2f-Menu

