/*
 * UART_program.c
 *
 *  Created on: Sep 1, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MUART_interface.h"
#include "MUART_private.h"


void uart_init(void)
{
	/*ENABLE TRANSMITTER AND RECEIVER*/
	UCSRB = (0x18);
	/*8-bit_no parity_ 1 stop bit_Asyncrouns*/
	UCSRC = (0x86);
	/*9600 baud rate*/
	UBRRL = (0x33);

}

void uart_send(u8_t au8_data)
{
	/*check over UDR is empty or not*/
	while(! (UCSRA & (0x20)));//(0x20) -> UDRE BIT
	UDR = au8_data;

}

u8_t uart_receive(void)
{
	/*check over new data */
	while(! (UCSRA & (0x80)));//(0x80) -> RXC BIT
	return UDR;
}
