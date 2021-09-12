/*
 * main.c
 *
 *  Created on: Sep 3, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "MTWI_interface.h"
#include "MGIE_interface.h"
int main (void)
{
	mtwi_SlaveInit(0b11010000);



	while(1);
	return 0;
}
