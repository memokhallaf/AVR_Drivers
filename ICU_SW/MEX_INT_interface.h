 /*
 *	Name : MEX_INT_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of External Interrupt module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MEX_INT_INTERFACE_H_
#define MEX_INT_INTERFACE_H_
/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/
/*Interrupt Pins*/
#define PIN_INT0 (0)
#define PIN_INT1 (1)
#define PIN_INT2 (2)
/*Interrupt Pins Status*/
#define RISING_EDGE 	(0)
#define FALLING_EDGE 	(1)
#define SWITCHING 		(2)
#define LOW_LEVEL 		(3)

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*Used to initialize Interrupt Pins*/
void mExInt_init(u8_t au8_IntPin, u8_t au8_IntMode);
/*Used to Enable Interrupt Pins*/
void mExInt_EnableInt(u8_t au8_IntPin);
/*used to Disable Interrupt pins*/
void mExInt_DisableInt(u8_t Intpin);
/*used to call back ISR FUNC Address  */
void mExInt_CallBack(void(*mExInt_Fun)(void));
#endif /* MEX_INT_INTERFACE_H_ */
