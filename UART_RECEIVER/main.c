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
#include "HLCD_interface.h"





int main(void)
{


	hlcd_init();
	mdio_setPinstatus(PORTD, PIN0, INPUT_FLOAT);
	uart_init();

	while(1)
	{u8_t au8_data =0;

		while(! au8_data)
		{
		au8_data = uart_receive();

		}
		hlcd_displayCharacter(au8_data);
	}


	return 0;
}

