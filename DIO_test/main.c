#include"LBIT_MATH.h"
#include"LSTD_TYPES.h"
#include"MDIO_interface.h"

int main(void)
{
	 mdio_setPinstatus( PORTC, (PIN0 | PIN5), OUTPUT );
	 mdio_setPinstatus(PORTD,(PIN1 | PIN4), INPUT_PULLUP );
	 while(1)
	 {
		 if( mdio_getPinValue(PORTD,PIN0) == LOW )
		 {
			 mdio_setPinValue( PORTC, PIN0 , HIGH);
		 }
		 else if( mdio_getPinValue(PORTD,PIN4) == LOW)
		 {
			 mdio_setPinValue( PORTC, PIN5 , HIGH);
		 }
		 else
		 {

		 }
	 }
	return 0 ;
}


