################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
UART_RECEIVER.lss \

FLASH_IMAGE += \
UART_RECEIVER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART_RECEIVER.elf secondary-outputs

# Tool invocations
UART_RECEIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_RECEIVER.map -mmcu=atmega32 -o "UART_RECEIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_RECEIVER.lss: UART_RECEIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_RECEIVER.elf  >"UART_RECEIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_RECEIVER.hex: UART_RECEIVER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_RECEIVER.elf  "UART_RECEIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_RECEIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 UART_RECEIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART_RECEIVER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
