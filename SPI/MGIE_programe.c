/*
 *	Name : MDIO_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main program of Global Interrupt Enable module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES	            */
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MGIE_private.h"

/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/

void mGIE_EnableGie(void)
{
	/*SETTING SREG REGISTER BIT NO 7 FROM (0 -> 1)*/
	SET_BIT(SREG, 7);
	return;
}

void mGIE_DisableGie(void)
{
	/*SETTING SREG REGISTER BIT NO 7 FROM (0 -> 1)*/
	CLEAR_BIT(SREG, 7);
	return;
}
