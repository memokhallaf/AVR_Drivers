/*
 *	Name : Hsegment_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of 7-SEGMENT module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */
/******************************************/
/*				INCLUDES		*/
/*******************************************/
#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"MDIO_interface.h"
#include"HSEGMENT_private.h"
#include"HSegment_interface.h"
/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/

void h7seg_init(void)
{
	/*setting 7-segmnt pins status as output*/
	mdio_setPinstatus(H7SEG_PORT, (H7SEG_A | H7SEG_B | H7SEG_C | H7SEG_D), OUTPUT);
	/*return from this fun*/
	return;
}

void h7seg_displayNum(u8_t au8_num)
{
	/*setting binary num from DIO over pins*/
	mdio_setPinValue(H7SEG_PORT, H7SEG_A, GET_BIT(au8_num, 0));
	mdio_setPinValue(H7SEG_PORT, H7SEG_B, GET_BIT(au8_num, 1));
	mdio_setPinValue(H7SEG_PORT, H7SEG_C, GET_BIT(au8_num, 2));
	mdio_setPinValue(H7SEG_PORT, H7SEG_D, GET_BIT(au8_num, 3));
	/*return from this fun*/
	return;
}
