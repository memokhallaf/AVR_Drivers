/*
 *	Name : MDIO_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of Global Interrupt Enable module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MGIE_INTERFACE_H_
#define MGIE_INTERFACE_H_
/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*USED TO ENABLE GLOBAL INTERRUPT*/
void mGIE_EnableGie(void);
/*USED TO DISABLE GLOBAL INTERRUPT*/
void mGIE_DisableGie(void);

#endif /* MGIE_INTERFACE_H_ */
