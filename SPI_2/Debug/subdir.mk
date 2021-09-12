################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HLCD_Programe.c \
../MDIO_programe.c \
../MGIE_programe.c \
../MSPI_program.c \
../main.c 

OBJS += \
./HLCD_Programe.o \
./MDIO_programe.o \
./MGIE_programe.o \
./MSPI_program.o \
./main.o 

C_DEPS += \
./HLCD_Programe.d \
./MDIO_programe.d \
./MGIE_programe.d \
./MSPI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


