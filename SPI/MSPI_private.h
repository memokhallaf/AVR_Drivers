/*
 * MSPI_private.h
 *
 *  Created on: Sep 2, 2021
 *      Author: memom
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/*SPI STATUS REGISTER*/
#define SPSR   (*(volatile u8_t *)(0x2E))
/*SPI CONTROL REGISTER */
#define SPCR   (*(volatile u8_t *)(0x2D))
/*SPI DATA REGISTER*/
#define SPDR   (*(volatile u8_t *)(0x2F))



#endif /* MSPI_PRIVATE_H_ */
