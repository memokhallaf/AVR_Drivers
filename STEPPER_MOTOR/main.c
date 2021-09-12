/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: memom
 */
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"

#define F_CPU 8000000UL
#include"util/delay.h"

void init(void);
void on_forward(void);


int main(void)
{
	init();
	while(1)
	{
	on_forward();
	_delay_ms(2000);
	ON_BACKWARD();
	}
	return 0;
}

void init(void)
{
	mdio_setPinstatus(PORTC, (PIN0 | PIN1 | PIN2 | PIN3), OUTPUT);

	return;
}

void on_forward(void)
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

	return;
}

void ON_BACKWARD(void)
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
	return;

}
