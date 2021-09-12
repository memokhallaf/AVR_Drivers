/*
 *	Name : MDIO_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of DIO module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/
/*DIO Ports*/
#define PORTA 		(1)
#define PORTB 		(2)
#define PORTC 		(3)
#define PORTD 		(4)

/*DIO Port pins*/
#define PIN0 		(0b00000001)
#define PIN1 		(0b00000010)
#define PIN2 		(0b00000100)
#define PIN3 		(0b00001000)
#define PIN4 		(0b00010000)
#define PIN5 		(0b00100000)
#define PIN6 		(0b01000000)
#define PIN7 		(0b10000000)

/*DIO Pin status*/
#define OUTPUT 			(1)
#define INPUT_FLOAT 	(2)
#define INPUT_PULLUP 	(3)
/*DIO Pin Values*/
#define LOW  (0)
#define HIGH  (1)
/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*used to set a specific pin status [ o/p - I/N Float - I/N Pullup] */
void mdio_setPinstatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status );

/*used to generate [0 or 1] over a specific pin */
void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_Value );

/*used to toggle pin value [0 -> 1 , 1 -> 0] over a specific pin */
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin );

/*used to get the value of a spacific pin*/
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin );


#endif /* MDIO_INTERFACE_H_ */
