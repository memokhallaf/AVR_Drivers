/*
 * main.c
 *
 *  Created on: Sep 3, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MTWI_interface.h"
#include "MGIE_interface.h"

int main (void)
{
	u8_t DATA = 0;

	mdio_setPinstatus(PORTA, (PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7), OUTPUT);


	mtwi_MasterInit(0b11010000);

	mtwi_SendStart();
	mtwi_SendSlaveAddressWithWrite(0b11010000);
	mtwi_MasterWriteDataByte(0b11110000);
	mtim_SendStopCondition();


	mtwi_SendStart();
	mtwi_SendSlaveAddressWithRead(0b11010000);
	DATA = mtwi_MasterReadDataByte();
	mtim_SendStopCondition();

	MDIO_PORTA = DATA;
	while(1);
	return 0;
}
