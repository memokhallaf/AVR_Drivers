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


/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/
void(*FunToSet)(void)=0;



void mtimer_init(void)
{

	/*SET FAST  PWM MODE */
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
	/*NON INVERTING MODE*/

	SET_BIT(TCCR0, 5);

	CLEAR_BIT(TCCR0,4);


	/**/
	OCR0 = 100;
	/*SET PRESCALLER*/
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0,2);



	return;
}

void mtimrer1_init(void)
{
	/*SET NORMAL MODE*/
	CLEAR_BIT(TCCR1A,0);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1B,4);
	/*SET PRESCALLER*/
	CLEAR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1A,2);

	return;
}

u16_t mtimer1_GetReading(void)
{

	return TCNT1 ;
}

void mtimer1_SendReading(u16_t au16_Value)
{
	TCNT1 = au16_Value;
	return;
}

void mtimer_BusyWait(u16_t au16_value)
{
	/**/
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);

	/**/
	CLEAR_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);


	return;
}

void mtimer0_GeneratePWM(u8_t au8_DutyCycle)
{
	OCR0 = au8_DutyCycle;
	return;
}
void mtimer0_CallBack(void(*func)(void))
{
	FunToSet = func;
}



void __vector_10 (void)
{
	if( FunToSet != 0)
		FunToSet();
}
