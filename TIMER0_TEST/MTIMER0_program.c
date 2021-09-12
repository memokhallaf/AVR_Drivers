/*
 * MTIMER_program.c
 *
 *  Created on: Aug 26, 2021
 *      Author: memom
 */

#include  "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER0.private.h"
#include "MTIMER0_interface.h"


void(*FunToSet)(void)=0;



void mtimer_init(void)
{
	TCNT0 = 192;

	/**/
	CLEAR_BIT(TCCR0, 3);
	CLEAR_BIT(TCCR0, 6);
	/**/
	SIT_BIT(TIMSK, 0);


	/**/
	CLEAR_BIT(TCCR0,0);
	SIT_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0,2);



	return;
}

void mtimer0_CallBack(void(*func)(void))
{
	FunToSet = func;
}



void __vector_11 (void)
{
	if( FunToSet != 0)
		FunToSet();
}
