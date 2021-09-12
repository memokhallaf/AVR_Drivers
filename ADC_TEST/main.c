/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"


#define F_CPU 8000000UL
#include "util/delay.h"

int main(void)
{
	u16_t x = 0;
	madc_init();

	mdio_setPinstatus(PORTD,PIN0,OUTPUT);
	mdio_setPinstatus(PORTD,PIN1,OUTPUT);
	mdio_setPinstatus(PORTD,PIN2,OUTPUT);
	mdio_setPinstatus(PORTD,PIN3,OUTPUT);
	mdio_setPinstatus(PORTD,PIN4,OUTPUT);
	mdio_setPinstatus(PORTD,PIN5,OUTPUT);
	mdio_setPinstatus(PORTD,PIN6,OUTPUT);
	mdio_setPinstatus(PORTD,PIN7,OUTPUT);


	mdio_setPinstatus(PORTA,PIN0,INPUT_FLOAT);
	while(1)
	{

		x = madc_ReadAnalogPolling(0);
		MDIO_PORTD = x;
		_delay_ms(100);


	}
	return 0;
}
