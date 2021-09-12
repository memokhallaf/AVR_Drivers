/*
 *	Name : HKEYPAD_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of KEY_PAD module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef HKEYPAD_PRIVATE_H_
#define HKEYPAD_PRIVATE_H_

/******************************************/
/*					DIO Register			*/
/*******************************************/

/*KEYPAD ROWS AND COLUMS SIZE*/
#define HKPD_ROWS (4)
#define HKPD_COLS  (3)
/*KEYPAD DIO PORT*/
#define HKPD_PORT (PORTA)
/*KEYPAD DIO ROWS PINS*/
#define HKPD_ROW_0 (PIN0)
#define HKPD_ROW_1 (PIN1)
#define HKPD_ROW_2 (PIN2)
#define HKPD_ROW_3 (PIN3)
/*KEYPAD DIO COLUMS PINS*/
#define HKPD_COLS_0 (PIN4)
#define HKPD_COLS_1 (PIN5)
#define HKPD_COLS_2 (PIN6)


#endif /* HKEYPAD_PRIVATE_H_ */
