/*
 * MSPI_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: memom
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/**/
void mspi_InitMaster(void);

/**/
void mspi_InitSlave(void);
/**/
u8_t mspi_tran(u8_t au8_data);
/**/
u8_t mspi_ReadSPDI_Slave(void);

#endif /* MSPI_INTERFACE_H_ */
