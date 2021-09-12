/*
 * MTIMER0_private.h
 *
 *  Created on: Sep 7, 2021
 *      Author: memom
 */

#ifndef MTIMER0_PRIVATE_H_
#define MTIMER0_PRIVATE_H_
/******************************************/
/*					TIMER0 Register			*/
/*******************************************/
/*Timer/Counter Control Register (TCCR0)*/
#define TCCR0  (*(volatile u8_t *)(0x53))
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


#endif /* MTIMER0_PRIVATE_H_ */
