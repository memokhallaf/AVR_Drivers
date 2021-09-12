/*
 * MSPI_program.c
 *
 *  Created on: Sep 2, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

void mspi_InitMaster(void)
{

	/*ENABLE SPI AS MASTER*/
	SPCR = (0xD1);
	return;
}

void mspi_InitSlave(void)
{

	/*AS  SLAVE*/
	SPCR = (0xC0);
	return;
}

u8_t mspi_tran(u8_t au8_data)
{
	u8_t data_1 =0;
	SPDR = au8_data;
	while(! (GET_BIT(SPSR, 7)));
	data_1 = SPDR;
	return data_1;
}

//(SPSR & (0x80))
