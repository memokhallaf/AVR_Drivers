/*
 *	Name : MTIMER0_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of TIMER0 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MTIMER0_INTERFACE_H__
#define MTIMER0_INTERFACE_H_H_
/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*USED TO INITIALIZE TIMER0 STATU */
void mtimer_init(void);
/*USED TO CALLBACK FUNCTION*/
void mtimer0_CallBack(void(*func)(void));


#endif /*MTIMER0_INTERFACE_H__H_ */
