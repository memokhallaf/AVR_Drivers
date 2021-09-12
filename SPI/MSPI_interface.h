/*
 * MSPI_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: memom
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/*INITIALIZE MASTER MODE*/
void mspi_InitMaster(void);

/*INITIALIZE SLAVE MODE*/
void mspi_InitSlave(void);
/*START TRANSMITTER*/
u8_t mspi_tran(u8_t au8_data);

#endif /* MSPI_INTERFACE_H_ */
