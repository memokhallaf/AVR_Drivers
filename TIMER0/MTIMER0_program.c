/*
 *	Name : MTIMER0_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of TIMER0 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES					*/
/*******************************************/
#include  "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER0.private.h"
#include "MTIMER0_interface.h"

/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/
void(*FunToSet)(void)=0;



void mtimer_init(void)
{
	OCR0 = 250;

	/**/
	CLEAR_BIT(TCCR0, 3);
	CLEAR_BIT(TCCR0, 6);
	/**/
	SIT_BIT(TIMSK, 1);


	/**/
	CLEAR_BIT(TCCR0,0);
	SIT_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0,2);



	return;
}

//void mtimer_BusyWait(u16_t au16_value)
//{
	/**/
/*	SIT_BIT(TCCR0, 3);
	SIT_BIT(TCCR0, 6);

	/**/
	/*CLEAR_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);


	return;
}*/

void mtimer0_CallBack(void(*func)(void))
{
	FunToSet = func;
}



void __vector_10 (void)
{
	if( FunToSet != 0)
		FunToSet();
}
