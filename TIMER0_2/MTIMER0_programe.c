/*
 * MTIMER0_programe.c
 *
 *  Created on: Sep 7, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER0_private.h"
#include "MTIMER0_interface.h"
#include "MTIMER0_config.h"

void(*FunToSet)(void)=0;
void mtimer_init(void)
{
	/*select CTC mode*/
	SIT_BIT(TCCR0, 3);
	CLEAR_BIT(TCCR0,6);
	/*Enable Compare Match interrupt*/
	SIT_BIT(TIMSK,1);
	/*set compare match value*/
	OCR0 = OCR_VAL;
	/*prescaller*/
	SIT_BIT(TCCR0,0);
	SIT_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	return;
}
void mtimer0_CallBack(void(*func)(void))
{
	FunToSet = func;
	return;
}

void __vector_10 (void)
{
	if( FunToSet != 0)
		FunToSet();
}
