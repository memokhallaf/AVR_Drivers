/*
 *	Name : HSegment_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of 7-SEGMENT module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */
/* Header file guard */
#ifndef HSEGMENT_INTERFACE_H_
#define HSEGMENT_INTERFACE_H_
/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/
/**/
#define NUM_0 (0)
#define NUM_1 (1)
#define NUM_2 (2)
#define NUM_3 (3)
#define NUM_4 (4)
#define NUM_5 (5)
#define NUM_6 (6)
#define NUM_7 (7)
#define NUM_8 (8)
#define NUM_9 (9)

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*this fun is used to initialize 7 segment pins*/
void h7seg_init(void);
/*this fun is used to display a specific num over 7-segment [0 -> 9]*/
void h7seg_displayNum(u8_t au8_num);
/**/


#endif /* HSEGMENT_INTERFACE_H_ */
