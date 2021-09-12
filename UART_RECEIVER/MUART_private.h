/*
 * MUART_private.h
 *
 *  Created on: Sep 1, 2021
 *      Author: memom
 */

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_
/**/
#define UCSRB   (*(volatile u8_t *)(0x2A))
/**/
#define UCSRC   (*(volatile u8_t *)(0x40))
/**/
#define UBRRL   (*(volatile u8_t *)(0x29))
/**/
#define UCSRA   (*(volatile u8_t *)(0x2B))
/**/
#define UDR   (*(volatile u8_t *)(0x2C))

#endif /* MUART_PRIVATE_H_ */
