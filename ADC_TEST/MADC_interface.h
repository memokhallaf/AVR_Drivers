/*
 *	Name : MADC_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of ADC module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_



/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*USED TO INITIALIZE ADC MODULE*/
void madc_init(void);
/**/
u16_t madc_ReadAnalogPolling(u8_t au8_Channel);
#endif /* MADC_INTERFACE_H_ */
