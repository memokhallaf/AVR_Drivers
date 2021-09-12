/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "MGIE_interface.h"
#include "HLCD_interface.h"

int main(void)
{
	u8_t data = 0;
	/*mosi is o/p*/
	mdio_setPinstatus(PORTB, PIN5, OUTPUT);
	/*miso is i/p*/
	mdio_setPinstatus(PORTB, PIN6, INPUT_FLOAT);
	/*sck is o/p*/
	mdio_setPinstatus(PORTB, PIN7, OUTPUT);
	/*ss is o/p*/
	mdio_setPinstatus(PORTB,PIN4, OUTPUT);
	//mdio_setPinstatus(PORTA,(PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7), OUTPUT);
	mspi_InitMaster();
	hlcd_init();
	mGIE_EnableGie();
	while(1)
	{


		data =  mspi_tran('a');
		if(data)
		{
			hlcd_displayCharacter(data);
			data = 0;
		}

	}
	return 0;
}




