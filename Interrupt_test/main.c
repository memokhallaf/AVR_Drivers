/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: memom
 */
/******************************************/
/*			INCLUDES				      */
/******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MEX_INT_interface.h"

void mExInt_FunToSet(void);
/******************************************/
/*		    	MAIN					 */
/******************************************/
int main(void)
{

	mExInt_CallBack(mExInt_FunToSet);

	/*SETTING PORTD PIN2 STATUS TO I/P PULLUP FOR INTERRUPT */
	mdio_setPinstatus(PORTD, PIN2, INPUT_PULLUP);
	/*SETTING PORTB PIN0 STATUS TO OUTPUT*/
	mdio_setPinstatus(PORTB, PIN0, OUTPUT);
	/*SETTING INTERRUPT PIN0 STATUS TO FALLING EDGE */
	mExInt_init(PIN_INT0,FALLING_EDGE);
	/**/
	mExInt_EnableInt(PIN_INT0);
	/**/
	mGIE_EnableGie();


	while(1);


	return 0;
}

/******************************************/
/*		    	ISR FUNCTION			*/
/******************************************/
void mExInt_FunToSet(void)
{
	mdio_togglePinValue(PORTB,PIN0);
	return;
}
