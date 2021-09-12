/*
 * main.c
 *
 *  Created on: Aug 19, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"HSegment_interface.h"

#define F_CPU 8000000UL
#include"util/delay.h"
int main(void)
{
	u8_t i =0 ;
	h7seg_init();

	while(1)
	{
		for(i = NUM_0; i <= NUM_9 ; i++)
		{
			h7seg_displayNum(i);
			_delay_ms(1000);
		}
	}
	return 0;
}

