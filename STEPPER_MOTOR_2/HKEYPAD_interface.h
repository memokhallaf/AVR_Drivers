/*
 *	Name : HKEYPAD_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of KEY_PAD module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef HKEYPAD_INTERFACE_H_
#define HKEYPAD_INTERFACE_H_
/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*this fun is used to initialize keypad pins */
void hkpd_init(void);
/*this fun is used to get the pressed keypad key*/
void hkpd_getPressKey(u8_t* pu8_key);

#endif /* HKEYPAD_INTERFACE_H_ */
