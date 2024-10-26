################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Inc/Uart/subdir.mk
-include Core/Inc/Timer/subdir.mk
-include Core/Inc/SensorTemperatura/Max6675/subdir.mk
-include Core/Inc/SensorTemperatura/InterfaceSensorTemperatura/subdir.mk
-include Core/Inc/SensorTemperatura/subdir.mk
-include Core/Inc/SensorMagnetico/subdir.mk
-include Core/Inc/PWM/subdir.mk
-include Core/Inc/ManejadorControles/subdir.mk
-include Core/Inc/ILI9341/subdir.mk
-include Core/Inc/GUI/PantallaMenuPrincipal/subdir.mk
-include Core/Inc/GUI/PantallaMemoria/subdir.mk
-include Core/Inc/GUI/PantallaManual/subdir.mk
-include Core/Inc/GUI/PantallaCalibracion/subdir.mk
-include Core/Inc/GUI/Menu/subdir.mk
-include Core/Inc/GUI/ManejadorPantallas/subdir.mk
-include Core/Inc/GUI/ConfigurarPantallaMemoria/subdir.mk
-include Core/Inc/GUI/subdir.mk
-include Core/Inc/Estaciones/subdir.mk
-include Core/Inc/Encoder/subdir.mk
-include Core/Inc/Delays/subdir.mk
-include Core/Inc/ControlVelocidadAire/subdir.mk
-include Core/Inc/Calefactor/subdir.mk
-include Core/Inc/Boton/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := EstacionAireProM4
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
EstacionAireProM4.elf \

MAP_FILES += \
EstacionAireProM4.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
EstacionAireProM4.list \


# All Target
all: main-build

# Main-build Target
main-build: EstacionAireProM4.elf secondary-outputs

# Tool invocations
EstacionAireProM4.elf EstacionAireProM4.map: $(OBJS) $(USER_OBJS) D:\RepositoriosGit\EstacionCalorPro\softeare\STM32\EstacionAireProM4\STM32F411CEUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "EstacionAireProM4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\RepositoriosGit\EstacionCalorPro\softeare\STM32\EstacionAireProM4\STM32F411CEUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="EstacionAireProM4.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

EstacionAireProM4.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "EstacionAireProM4.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) EstacionAireProM4.elf EstacionAireProM4.list EstacionAireProM4.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
