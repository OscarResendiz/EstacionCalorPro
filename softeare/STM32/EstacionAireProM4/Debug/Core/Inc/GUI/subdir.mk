################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/GUI/CComponenteBaseTft.cpp \
../Core/Inc/GUI/CEtiquetaTft.cpp \
../Core/Inc/GUI/CPantallaBase.cpp \
../Core/Inc/GUI/CRectanguloTft.cpp 

OBJS += \
./Core/Inc/GUI/CComponenteBaseTft.o \
./Core/Inc/GUI/CEtiquetaTft.o \
./Core/Inc/GUI/CPantallaBase.o \
./Core/Inc/GUI/CRectanguloTft.o 

CPP_DEPS += \
./Core/Inc/GUI/CComponenteBaseTft.d \
./Core/Inc/GUI/CEtiquetaTft.d \
./Core/Inc/GUI/CPantallaBase.d \
./Core/Inc/GUI/CRectanguloTft.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/GUI/%.o Core/Inc/GUI/%.su Core/Inc/GUI/%.cyclo: ../Core/Inc/GUI/%.cpp Core/Inc/GUI/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-GUI

clean-Core-2f-Inc-2f-GUI:
	-$(RM) ./Core/Inc/GUI/CComponenteBaseTft.cyclo ./Core/Inc/GUI/CComponenteBaseTft.d ./Core/Inc/GUI/CComponenteBaseTft.o ./Core/Inc/GUI/CComponenteBaseTft.su ./Core/Inc/GUI/CEtiquetaTft.cyclo ./Core/Inc/GUI/CEtiquetaTft.d ./Core/Inc/GUI/CEtiquetaTft.o ./Core/Inc/GUI/CEtiquetaTft.su ./Core/Inc/GUI/CPantallaBase.cyclo ./Core/Inc/GUI/CPantallaBase.d ./Core/Inc/GUI/CPantallaBase.o ./Core/Inc/GUI/CPantallaBase.su ./Core/Inc/GUI/CRectanguloTft.cyclo ./Core/Inc/GUI/CRectanguloTft.d ./Core/Inc/GUI/CRectanguloTft.o ./Core/Inc/GUI/CRectanguloTft.su

.PHONY: clean-Core-2f-Inc-2f-GUI

