################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDIO_programe.c \
../MEX_INT_programme.c \
../MGIE_programe.c \
../main.c 

OBJS += \
./MDIO_programe.o \
./MEX_INT_programme.o \
./MGIE_programe.o \
./main.o 

C_DEPS += \
./MDIO_programe.d \
./MEX_INT_programme.d \
./MGIE_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


