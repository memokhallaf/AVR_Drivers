/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: memom
 */
/******************************************************/
/*						INCLUDES					*/
/*****************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER0.private.h"
#include "MTIMER0_interface.h"
#include "MGIE_interface.h"
#include "MDIO_interface.h"



void fun(void);

/***********************************************************/
/*						MAIN FUNC							*/
/***********************************************************/
int main(void)
{
	mdio_setPinstatus(PORTA,PIN0,OUTPUT);
	mtimer0_CallBack( fun );
	mtimer_init();
	mGIE_EnableGie();


	while(1);
	return 0;
}


void fun(void)
{
	static u16_t count  =0 ;

	static u8_t i = 0;
	count++;
	if(count == 6000)
	{
		i ^= 1;
		mdio_setPinValue(PORTA,PIN0,i);
		TCNT0 = 192;
		count = 0;
	}


	return;
}
