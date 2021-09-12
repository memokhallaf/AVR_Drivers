/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MTIMER0_interface.h"
void func(void);
int main(void)
{
	mdio_setPinstatus(PORTA,PIN0,OUTPUT);

	mtimer_init();
	mtimer0_CallBack(func);
	mGIE_EnableGie();
	while(1);
	return 0;
}

void func(void)
{

	 mdio_togglePinValue(PORTA,PIN0);

	return;
}
