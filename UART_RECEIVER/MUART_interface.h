/*
 * UART_interface.h
 *
 *  Created on: Sep 1, 2021
 *      Author: memom
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/

/**/
void uart_init(void);
/**/
void uart_send(u8_t au8_data);
/**/
u8_t uart_receive(void);

#endif /* MUART_INTERFACE_H_ */
