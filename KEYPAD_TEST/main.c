/*
 * main.c
 *
 *  Created on: Aug 19, 2021
 *      Author: memom
 */
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "HKEYPAD_interface.h"


int main(void)
{
	u8_t x = 0;

	hkpd_init();
	h7seg_init();
	while(1)
	{
		hkpd_getPressKey(&x);

		x = x - '0';

		h7seg_displayNum(x);

	}

	return 0;
}
