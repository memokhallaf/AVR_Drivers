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
DAC_R2R_TEST.lss \

FLASH_IMAGE += \
DAC_R2R_TEST.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DAC_R2R_TEST.elf secondary-outputs

# Tool invocations
DAC_R2R_TEST.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DAC_R2R_TEST.map -mmcu=atmega32 -o "DAC_R2R_TEST.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DAC_R2R_TEST.lss: DAC_R2R_TEST.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DAC_R2R_TEST.elf  >"DAC_R2R_TEST.lss"
	@echo 'Finished building: $@'
	@echo ' '

DAC_R2R_TEST.hex: DAC_R2R_TEST.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DAC_R2R_TEST.elf  "DAC_R2R_TEST.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DAC_R2R_TEST.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DAC_R2R_TEST.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DAC_R2R_TEST.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
