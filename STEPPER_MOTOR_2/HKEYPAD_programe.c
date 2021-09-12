/*	Name : HKEYPAD_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of KEY_PAD module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES					*/
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_Private.h"
#include "MDIO_interface.h"
#include"HKEYPAD_private.h"
#include"HKEYPAD_interface.h"
/******************************************/
/*			IMPORTANT VARIABLES		      */
/*******************************************/
/*Global 2-d array used to draw the keypad map*/
u8_t gu8_kpdMap [HKPD_ROWS][HKPD_COLS] = {
											{'1','2','3'},
											{'4','5','6'},
											{'7','8','9'},
											{'*','0','#'}
};
/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/

void hkpd_init(void)
{
	/*setting rows pins as i/p pullup*/
	mdio_setPinstatus(HKPD_PORT, (HKPD_ROW_0 | HKPD_ROW_1 | HKPD_ROW_2 | HKPD_ROW_3), INPUT_PULLUP);
	/*setting rows pins as o/p*/
	mdio_setPinstatus(HKPD_PORT, (HKPD_COLS_0 | HKPD_COLS_1 | HKPD_COLS_2 ), OUTPUT);
	/*setting columns pins to high*/
	mdio_setPinValue(HKPD_PORT, (HKPD_COLS_0 | HKPD_COLS_1 | HKPD_COLS_2 ),HIGH);
	/*return from this fun*/
	return;
}

void hkpd_getPressKey(u8_t* pu8_key)
{
	/*local variable used in rows looping operations*/
	u8_t au8_rowIterator = 0 ;
	/*local variable used in cols looping operations*/
	u8_t au8_colIterator = 0;
	/**/
	u8_t au8_keyFlag = 0;
	/*resetting the key value holder variables*/
	*pu8_key = 0;
	/**/
	for(au8_colIterator= 0 ;au8_colIterator < HKPD_COLS ;au8_colIterator++ )
	{
		/**/
		mdio_setPinValue(HKPD_PORT, (HKPD_COLS_0 << au8_colIterator), LOW);
		/*looping over keypad rows*/
		for(au8_rowIterator= 0; au8_rowIterator < HKPD_ROWS; au8_rowIterator++)
		{
			/**/
			if(mdio_getPinValue(HKPD_PORT, (HKPD_ROW_0 << au8_rowIterator)) == LOW)
			{
				/*report the pressed pin*/
				*pu8_key = gu8_kpdMap[au8_rowIterator][au8_colIterator];
				/**/
				au8_keyFlag++;
				/*break from rows loop*/
				break;
			}
			else
			{
				/*do nothing*/
			}
		}
		/*setting specific col pin to high*/
		mdio_setPinValue(HKPD_PORT, (HKPD_COLS_0 << au8_colIterator), HIGH);
		/**/
		if(au8_keyFlag)
		{
			/*braek from columns loop*/
			break;
		}
		else
		{
			/*do nothing*/
		}
	}
	/*return from this fun*/
	return;
}
