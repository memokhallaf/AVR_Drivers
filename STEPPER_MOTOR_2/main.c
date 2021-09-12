/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: memom
 */


/************************************************************************************************/
/*                                           Includes                                           */
/************************************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HKEYPAD_interface.h"


#include"util/delay.h"

/************************************************************************************************/
/*                                           fun prototype                                           */
/************************************************************************************************/
void init(void);
void on_forward(u8_t au8_num);
void ON_BACKWARD(u8_t au8_num1);

/************************************************************************************************/
/*                                           mian programe                                           */
/************************************************************************************************/
int main(void)
{
	u8_t x =0;
	u8_t au8_numStep = 0;
	u8_t z = 0;

	init();
	hlcd_init();
	hkpd_init();

	hlcd_setCursor(ROW_0 , COL_0);
	hlcd_displayString("ENTER NUM");

	hlcd_setCursor(ROW_1 , COL_0);
	while(1)
	{
		hkpd_getPressKey(&z);
		switch(z)
		{
		case '*':

			/*looping to stop keypad looping*/
			while(!x)
			{
				hkpd_getPressKey(&x);
			}
			/*start routating x times  in forward diraction */
			on_forward(x - 48);
			/*display num of routating*/
			hlcd_displayCharacter(x);
			/*back x to 0 to start again*/
			x = 0;
			break;
		case '#':

			/*looping to stop keypad looping*/
			while(!x)
			{
				hkpd_getPressKey(&x);
			}
			/*start routating x times  in forward diraction */
			ON_BACKWARD(x - 48);
			/*display num of routating*/
			hlcd_displayCharacter(x);
			/*back x to 0 to start again*/
			x = 0;
			break;
		default:
			break;

		}
	}




	return 0;
}
/************************************************************************************************/
/*                                           fun difintions                                           */
/************************************************************************************************/
void init(void)
{
	mdio_setPinstatus(PORTC, (PIN0 | PIN1 | PIN2 | PIN3), OUTPUT);

	return;
}

void on_forward(u8_t au8_num)
{
	u8_t x = 0;

	for(x=0; x < au8_num; x++)
	{
	mdio_setPinValue(PORTC,PIN0,HIGH);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,HIGH);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,HIGH);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,HIGH);
	_delay_ms(200);


	}
	return;
}

void ON_BACKWARD(u8_t au8_num1)
{
	u8_t x = 0;

	for(x=0; x < au8_num1; x++)
	{
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,HIGH);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,HIGH);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,LOW);
	mdio_setPinValue(PORTC,PIN1,HIGH);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	mdio_setPinValue(PORTC,PIN0,HIGH);
	mdio_setPinValue(PORTC,PIN1,LOW);
	mdio_setPinValue(PORTC,PIN2,LOW);
	mdio_setPinValue(PORTC,PIN3,LOW);
	_delay_ms(200);
	}
	return;

}
