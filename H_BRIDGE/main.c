#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"

#define F_CPU 8000000UL
#include"util/delay.h"
int main(void)
{
	/*setting portA as I/P PULLUP*/
	mdio_setPinstatus(PORTA,(PIN0 | PIN2),INPUT_PULLUP );
	/*SETTING PORTD AS O/P*/
	mdio_setPinstatus(PORTD,(PIN0 | PIN1), OUTPUT);
	while(1)
	{
		if(mdio_getPinValue(PORTA,PIN0) == 0)
		{
			mdio_setPinValue(PORTD,PIN0,HIGH);
			_delay_ms(5000);
			mdio_setPinValue(PORTD,PIN0,LOW);
			mdio_setPinValue(PORTD,PIN1,HIGH);
			_delay_ms(5000);
			mdio_setPinValue(PORTD,PIN1,LOW);

		}
		else
		{
			/*do nothing*/
		}


	}
	return 0;
}
