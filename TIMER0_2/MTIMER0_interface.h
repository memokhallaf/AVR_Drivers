/*
 * MTIMER0_interface.h
 *
 *  Created on: Sep 7, 2021
 *      Author: memom
 */

#ifndef MTIMER0_INTERFACE_H_
#define MTIMER0_INTERFACE_H_

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*USED TO INITIALIZE TIMER0 STATU */
void mtimer_init(void);
/*USED TO CALLBACK FUNCTION*/
void mtimer0_CallBack(void(*func)(void));

#endif /* MTIMER0_INTERFACE_H_ */
