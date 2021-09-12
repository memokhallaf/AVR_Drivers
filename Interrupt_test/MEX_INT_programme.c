/*
 *	Name : MEX_INT_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of External Interrupt module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES	            */
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MEX_INT_private.h"
#include "MEX_INT_interface.h"


/*used to take ISR FUNC Address and make it global*/
void(*global_fun)(void)=0;
/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/

void mExInt_init(u8_t au8_IntPin, u8_t au8_IntMode)
{
	/*SWITCHING OVER INTERRUPT PINS*/
	switch(au8_IntPin)
	{
	/*IN CASE OF CHOOSING PIN_INT0 */
	case PIN_INT0:
		/*SWITCHING OVER INTERRUPT STATUES  */
		switch(au8_IntMode)
		{
		/*IN OF CHOOSING RISING EDGE*/
		case RISING_EDGE:
			/*SETTING MCUCR REGISTER BIT NO 0 FROM (0 -> 1) */
			SET_BIT(MCUCR,0);
			/*SETTING MCUCR REGISTER BIT NO 1 FROM (0 -> 1) */
			SET_BIT(MCUCR,1);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING FALLING EDGE*/
		case FALLING_EDGE:
			/*SETTING MCUCR REGISTER BIT NO 0 FROM (1 -> 0) */
			CLEAR_BIT(MCUCR,0);
			/*SETTING MCUCR REGISTER BIT NO 1 FROM (0 -> 1) */
			SET_BIT(MCUCR,1);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING SWITCHING*/
		case SWITCHING:
			/*SETTING MCUCR REGISTER BIT NO 0 FROM (0 -> 1) */
			SET_BIT(MCUCR,0);
			/*SETTING MCUCR REGISTER BIT NO 1 FROM (1 -> 0) */
			CLEAR_BIT(MCUCR,1);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING LOW LEVEL*/
		case LOW_LEVEL:
			/*SETTING MCUCR REGISTER BIT NO 0 FROM (1 -> 0) */
				CLEAR_BIT(MCUCR,0);
				/*SETTING MCUCR REGISTER BIT NO 1 FROM (1 -> 0) */
				CLEAR_BIT(MCUCR,1);
				/*BREAK FROM THIS CASE*/
				break;
		/*IN CASE OF DEFAULT*/
		default:
			/*BREAK FROM DEFAULT*/
			break;
		}
		/*BREAK FROM PIN_INT0 CASE*/
		break;
	/*IN CASE OF CHOOSING PIN_INT1*/
	case PIN_INT1:
		/*SWITCHING OVER INTERRUPT STATUES  */
		switch(au8_IntMode)
		{
		/*IN OF CHOOSING RISING EDGE*/
		case RISING_EDGE:
			/*SETTING MCUCR REGISTER BIT NO 2 FROM (0 -> 1) */
			SET_BIT(MCUCR,2);
			/*SETTING MCUCR REGISTER BIT NO 3 FROM (0 -> 1) */
			SET_BIT(MCUCR,3);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING FALLING EDGE*/
		case FALLING_EDGE:
			/*SETTING MCUCR REGISTER BIT NO 2 FROM (1 -> 0) */
			CLEAR_BIT(MCUCR,2);
			/*SETTING MCUCR REGISTER BIT NO 3 FROM (0 -> 1) */
			SET_BIT(MCUCR,3);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING SWITCHING*/
		case SWITCHING:
			/*SETTING MCUCR REGISTER BIT NO 2 FROM (0 -> 1) */
			SET_BIT(MCUCR,2);
			/*SETTING MCUCR REGISTER BIT NO 3 FROM (1 -> 0) */
			CLEAR_BIT(MCUCR,3);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING LOW LEVEL*/
		case LOW_LEVEL:
			/*SETTING MCUCR REGISTER BIT NO 2 FROM (1 -> 0) */
				CLEAR_BIT(MCUCR,2);
				/*SETTING MCUCR REGISTER BIT NO 3 FROM (1 -> 0) */
				CLEAR_BIT(MCUCR,3);
				/*BREAK FROM THIS CASE*/
				break;
		/*IN CASE OF DEFAULT*/
		default:
			/*BREAK FROM DEFAULT*/
			break;
		}
		/*BREAK FROM PIN_INT1 CASE*/
		break;
	/*IN CASE OF CHOOSING PIN_INT2*/
	case PIN_INT2:
		/*SWITCHING OVER INTERRUPT STATUES  */
		switch(au8_IntMode)
		{
		/*IN OF CHOOSING RISING EDGE*/
		case RISING_EDGE:
			/*SETTING MCUCSR REGISTER BIT NO 6 FROM (0 -> 1) */
			SET_BIT(MCUCSR,6);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF CHOOSING FALLING EDGE*/
		case FALLING_EDGE:
			/*SETTING MCUCSR REGISTER BIT NO 6 FROM (1 -> 0) */
			CLEAR_BIT(MCUCSR,6);
			/*BREAK FROM THIS CASE*/
			break;
		/*IN CASE OF DEFAULT*/
		default:
			/*BREAK FROM DEFAULT*/
			break;
		}
		/*BREAK FROM PIN_INT2 CASE*/
		break;
	/*IN CASE OF DEFAULT*/
	default:
		/*BREAK FROM DEFAULT*/
		break;
	}
	/*RETURN FROM THIS FUN*/
	return;
}

void mExInt_EnableInt(u8_t au8_IntPin)
{
	/*SWITCHING OVER INTERRUPT PINS*/
	switch(au8_IntPin)
	{
	/*IN CASE OF CHOOSING */
	case PIN_INT0:
		/*SETTING GICR REGISTER BIT NO 6 FROM (0 -> 1) */
		SET_BIT(GICR,6);
		/*BREAK FROM THIS CASE*/
		break;
	/*IN CASE OF CHOOSING */
	case PIN_INT1:
		/*SETTING GICR REGISTER BIT NO 7 FROM (0 -> 1) */
		SET_BIT(GICR,7);
		/*BREAK FROM THIS CASE*/
		break;
	/*IN CASE OF CHOOSING */
	case PIN_INT2:
		/*SETTING GICR REGISTER BIT NO 5 FROM (0 -> 1) */
		SET_BIT(GICR,5);
		/*BREAK FROM THIS CASE*/
		break;
	/*IN CASE OF CHOOSING*/
	default:
		/*BREAK FROM THIS CASE*/
		break;

	}
	return;
}

void mExInt_CallBack(void(*mExInt_Fun)(void))
{
	global_fun = mExInt_Fun;
	return;
}


/*INTERRUPT FUNC DIFINITIONS*/
void __vector_1(void)
{
	if(global_fun != 0)
	{
		global_fun();
	}
	else
	{
		/*do nothing*/
	}
	return;
}

