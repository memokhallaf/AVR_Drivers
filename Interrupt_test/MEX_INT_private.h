/*
 *	Name : MEX_INT_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of  External Interrupt module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MEX_INT_PRIVATE_H_
#define MEX_INT_PRIVATE_H_
/******************************************/
/*	 external interrupt Register			*/
/*******************************************/

/*Interrupt Register*/
#define MCUCR 	(*(volatile u8_t*)(0x55))
#define MCUCSR 	(*(volatile u8_t*)(0x54))
#define GICR 	(*(volatile u8_t*)(0x5B))
#define GIFR 	(*(volatile u8_t*)(0x5A))

/******************************************/
/*	 external interrupt FUNC PROTOTYPE			*/
/*******************************************/

/*FUNCTIONA PROTOTYPES for INTERRUPTES*/
void __vector_1(void)__attribute__((signal));


#endif /* MEX_INT_PRIVATE_H_ */
