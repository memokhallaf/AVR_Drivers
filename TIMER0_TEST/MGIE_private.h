/*
 *	Name : MDIO_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of  Global Interrupt Enable module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MGIE_PRIVATE_H_
#define MGIE_PRIVATE_H_
/******************************************/
/*	 Enable Interrupt Register			*/
/*******************************************/
/*STATUS REGISSTR*/
#define SREG 	(*(volatile u8_t*)(0x5F))

#endif /* MGIE_PRIVATE_H_ */
