/*
 *	Name : LBIT_MATH.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains the bit mathemetical operation
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

/**********************************************/
/*            BIT MATH OPERATIONS             */
/**********************************************/

/* SITTING A SPECIFIC REGISTER BIT TO 1*/
#define SET_BIT(REG, BIT_NO) REG |= (1 << BIT_NO)

/* SITTING A SPECIFIC REGISTER BIT TO 0*/
#define CLEAR_BIT(REG, BIT_NO) REG &= ~(1 << BIT_NO)

/* TOGGLING A SPECIFIC REGISTER BIT */
#define TOGGLE_BIT(REG, BIT_NO) REG ^= (1 << BIT_NO)

/* GETTING A SPECIFIC REGISTER VALUE */
#define GET_BIT(REG, BIT_NO) ((REG >> BIT_NO)&1)


#endif /* LBIT_MATH_H_ */
