/*
 *	Name : MTIMER0_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of TIMER0 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MTIMER0_PRIVATE_H__
#define MTIMER0_PRIVATE_H_H_
/******************************************/
/*					TIMER0 Register			*/
/*******************************************/
/*Timer/Counter Control Register (TCCR0)*/
#define TCCR0 (*(volatile u8_t*)(0x53))
/*Timer/Counter Register (TCNT0)*/
#define TCNT0 (*(volatile u8_t*)(0x52))
/*Output Compare Register (OCR0)*/
#define OCR0 (*(volatile u8_t*)(0x5C))
/*Timer/Counter Interrupt Mask Register (TIMSK)*/
#define TIMSK (*(volatile u8_t*)(0x59))
/*Timer/Counter Interrupt Flag Register*/
#define TIFR (*(volatile u8_t*)(0x58))


/*USED TO */
void __vector_10 (void) __attribute__((signal));
#endif /*MTIMER0_PRIVATE_H__H_*/
