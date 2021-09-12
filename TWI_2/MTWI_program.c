/*
 * MTWI_program.c
 *
 *  Created on: Sep 3, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "Mem_Map32.h"
#include "MTWI_interface.h"

void mtwi_MasterInit(u8_t au8_SlaveAddress)
{
	/**/
	TWBR = (0x47);
	/**/
	TWSR = (0x00);
	/**/
	TWDR = 3;
	/**/
	if(au8_SlaveAddress != 0)
	{
		TWAR = (au8_SlaveAddress << 1);
	}
	/**/
	TWCR = (0x04);
	return;
}

void mtwi_SlaveInit(u8_t au8_SlaveAddress)
{
	/**/
	TWCR = (0x04);
	/**/
	TWAR = (au8_SlaveAddress << 1);
	/**/
	TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWEA));
	return;

}

void mtwi_SendStart(void)
{
	/**/
	TWCR = ((1<<TWINT) | (1<<TWSTA) |(1<<TWEN));
	/**/
	while((TWCR & (1<<TWINT)) ==0);
	return;
}

void mtwi_SendRepeatedStart(void)
{
	/**/
		TWCR = ((1<<TWINT) | (1<<TWSTA) |(1<<TWEN));
		/**/
		while((TWCR & (1<<TWINT)) ==0);
	return;
}

void mtwi_SendSlaveAddressWithWrite(u8_t au8_SlaveAddress)
{
	/**/
	TWCR = ((1<<TWINT) |(1<<TWEN));

	/**/
	TWDR = (au8_SlaveAddress << 1);
	CLEAR_BIT(TWDR,0);

	/**/
	while((TWCR & (1<<TWINT)) ==0);
	return;
}

void mtwi_SendSlaveAddressWithRead(u8_t au8_SlaveAddress)
{
	/**/
		TWCR = ((1<<TWINT) |(1<<TWEN));

		/**/
		TWDR = ((au8_SlaveAddress << 1) | 1);
		SET_BIT(TWDR,0);

		/**/
		while((TWCR & (1<<TWINT)) ==0);
	return;
}

void mtwi_MasterWriteDataByte(u8_t au8_DataByte)
{
	/**/
	TWDR = au8_DataByte;
	/**/
	SET_BIT(TWCR, 7);
	/**/
			while((TWCR & (1<<TWINT)) ==0);
	return;
}

u8_t mtwi_MasterReadDataByte(void)
{
	/**/
	SET_BIT(TWCR, 7);
	/**/
	while((TWCR & (1<<TWINT)) ==0);
	return TWDR;
}

void mtim_SendStopCondition(void)
{
	/**/
	TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWSTO));
	return;
}
