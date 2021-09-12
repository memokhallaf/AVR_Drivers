/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MEX_INT_interface.h"
#include "MTIMER0_interface.h"
#include "HLCD_interface.h"

void func(void);

u16_t P_T;
u16_t T_ON;

int main (void)
{
	mdio_setPinstatus(PORTB,PIN3,OUTPUT);
	mdio_setPinstatus(PORTD,PIN2,INPUT_FLOAT);



	mExInt_CallBack(func);

	hlcd_init();

	mtimrer1_init();
	mtimer_init();

	mExInt_init(PIN_INT0,RISING_EDGE);

	mExInt_EnableInt(PIN_INT0);


	mGIE_EnableGie();


	while(1)
	{

		if(P_T != 0 && T_ON != 0)
		{
			hlcd_setCursor(0,0);
			hlcd_displayCharacter('a');
			hlcd_displayString(P_T);
			hlcd_setCursor(1,0);
			hlcd_displayString(T_ON);
		}


	}
	return 0 ;
}

void func(void)
{
	static u8_t count = 0;
	count++;
	if(count == 1)
	{
		mtimer1_SendReading(0);
	}
	else if(count == 2)
	{
		P_T = mtimer1_GetReading();
		mExInt_init(PIN_INT0, FALLING_EDGE);
	}
	else if (count == 3)
	{
		u16_t au16_data = mtimer1_GetReading();
		T_ON = au16_data - P_T;
		mExInt_DisableInt(PIN_INT0);
		count = 0 ;
	}
	return;
}
