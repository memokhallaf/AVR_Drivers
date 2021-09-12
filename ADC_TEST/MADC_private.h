/*
 *	Name : MADC_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of ADC module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/******************************************/
/*					ADC Register		  */
/*******************************************/
/*ADC Multiplexer Selection Register (ADMUX)*/
#define ADMUX 	(*(volatile u8_t*)(0x27))
/*ADC Control and Status Register A (ADCSRA)*/
#define ADCSRA 	(*(volatile u8_t*)(0x26))
/*The ADC Data Register (ADCL) , (ADCH)*/
#define ADCL 	(*(volatile u16_t*)(0x24))
#define ADCH 	(*(volatile u8_t*)(0x25))
/*Special FunctionIO Register (SFIOR)*/
#define SFIOR 	(*(volatile u8_t*)(0x50))

#endif /* MADC_PRIVATE_H_ */
