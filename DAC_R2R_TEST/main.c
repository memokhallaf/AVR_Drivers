/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"

#define F_CPU 8000000UL
#include "util/delay.h"

int main(void)
{
	u8_t i = 0;

	mdio_setPinstatus(PORTD, (PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7), OUTPUT);

	while(1)
	{
		for( i=0; i < 255 ; i++)
		{
			MDIO_PORTD = i;
			_delay_ms(100);

		}
	}
	return 0;
}
