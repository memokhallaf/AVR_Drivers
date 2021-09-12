/*
 * main.c
 *
 *  Created on: Sep 1, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MUART_interface.h"




int main(void)
{
	mdio_setPinstatus(PORTC, PIN0 ,INPUT_PULLUP );
	mdio_setPinstatus(PORTC, PIN2 ,INPUT_PULLUP );
	mdio_setPinstatus(PORTD, PIN1, OUTPUT);
	uart_init();

	while(1)
	{

		while( mdio_getPinValue(PORTC,PIN0));
			uart_send('1');

		while( mdio_getPinValue(PORTC,PIN2));
			uart_send('2');
	}

	return 0;
}

