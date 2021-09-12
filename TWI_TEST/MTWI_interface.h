/*
 * MTWI_interface.h
 *
 *  Created on: Sep 3, 2021
 *      Author: memom
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

/**/
void mtwi_MasterInit(u8_t au8_SlaveAddress);
/**/
void mtwi_SlaveInit(u8_t au8_SlaveAddress);
/**/
void mtwi_SendStart(void);
/**/
void mtwi_SendRepeatedStart(void);
/**/
void mtwi_SendSlaveAddressWithWrite(u8_t au8_SlaveAddress);
/**/
void mtwi_SendSlaveAddressWithRead(u8_t au8_SlaveAddress);
/**/
void mtwi_MasterWriteDataByte(u8_t au8_DataByte);
/**/
u8_t mtwi_MasterReadDataByte(void);
/**/
void mtim_SendStopCondition(void);

#endif /* MTWI_INTERFACE_H_ */
