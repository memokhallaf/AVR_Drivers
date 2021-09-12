/*
 *	Name : MDIO_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of DIO module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES		*/
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_Private.h"
#include "MDIO_interface.h"
/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/
void mdio_setPinstatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status )
{
	/*switching over DIO port*/
	switch(au8_port)
	{
	/*IN case of choosing port A*/
	case PORTA:
			/*switching over pin status*/
			switch(au8_status)
			{
				/*In case of choosing output*/
				case OUTPUT:
					/*Setting specific DIO pins to output*/
					MDIO_DDRA |= au8_pin;
					/*Break from this case*/
					break;
				/*In case of choosing input floating*/
				case INPUT_FLOAT:
					/*Setting specific DIO pins to input floating*/
					MDIO_DDRA &= ~au8_pin;
					/*Break from this case*/
					break;
				/*In case of choosing input pull-up*/
				case INPUT_PULLUP:
					/*Setting specific DIO pins to input floating*/
					MDIO_DDRA &= ~au8_pin;
					/*Activating specific DIO input pins pull-up resistor*/
					MDIO_PORTA |= au8_pin;
					/*Break from this case*/
					break;
				/*In case of default*/
				default:
					/*Break from default case*/
					break;
			}
		break;

	/*IN case of choosing port B*/
	case PORTB:
		/*switching over pin status*/
		switch(au8_status)
		{
			/*In case of choosing output*/
			case OUTPUT:
				/*Setting specific DIO pins to output*/
				MDIO_DDRB |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of choosing input floating*/
			case INPUT_FLOAT:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRB &= ~au8_pin;
				/*Break from this case*/
				break;
			/*In case of choosing input pull-up*/
			case INPUT_PULLUP:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRB &= ~au8_pin;
				/*Activating specific DIO input pins pull-up resistor*/
				MDIO_PORTB |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of default*/
			default:
				/*Break from default case*/
				break;
		}
		break;

	/*IN case of choosing port C*/
	case PORTC:
		/*switching over pin status*/
		switch(au8_status)
		{
			/*In case of choosing output*/
			case OUTPUT:
				/*Setting specific DIO pins to output*/
				MDIO_DDRC |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of choosing input floating*/
			case INPUT_FLOAT:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRC &= ~au8_pin;
				/*Break from this case*/
				break;
				/*In case of choosing input pull-up*/
			case INPUT_PULLUP:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRC &= ~au8_pin;
				/*Activating specific DIO input pins pull-up resistor*/
				MDIO_PORTC |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of default*/
			default:
				/*Break from default case*/
				break;
		}
		break;
	/*IN case of choosing port D*/
	case PORTD:
		/*switching over pin status*/
		switch(au8_status)
		{
			/*In case of choosing output*/
			case OUTPUT:
				/*Setting specific DIO pins to output*/
				MDIO_DDRD |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of choosing input floating*/
			case INPUT_FLOAT:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRD &= ~au8_pin;
				/*Break from this case*/
				break;
				/*In case of choosing input pull-up*/
			case INPUT_PULLUP:
				/*Setting specific DIO pins to input floating*/
				MDIO_DDRD &= ~au8_pin;
				/*Activating specific DIO input pins pull-up resistor*/
				MDIO_PORTD |= au8_pin;
				/*Break from this case*/
				break;
			/*In case of default*/
			default:
				/*Break from default case*/
				break;
		}
		break;
			/*in casing of default*/
		default:
			break;
	}
	/*Return from this function*/
	return;
}


void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_Value )
{
	/*switching over DIO Ports*/
	switch(au8_port)
	{
	/*IN CASE OF CHOOSING PORT A*/
	case PORTA:
		/*switching over pin value*/
		switch(au8_Value)
		{
		/*in case of choosing high*/
		case HIGH:
			/*setting specific DIO Pins to high */
			MDIO_PORTA |= au8_pin;
			/*break from this case*/
			break;
		/*in case of choosing low*/
		case LOW:
			/*setting specific DIO pin to low*/
			MDIO_PORTA &= ~ au8_pin;
			/*break from this case*/
			break;
		/*in case of default*/
		default:
			/*break from default*/
			break;
		}
		/*break from this case*/
		break;
	/*IN CASE OF CHOOSING PORT B*/
	case PORTB:
		/*switching over pin value*/
		switch(au8_Value)
		{
		/*in case of choosing high*/
		case HIGH:
			/*setting specific DIO Pins to high */
			MDIO_PORTB |= au8_pin;
			/*break from this case*/
			break;
		/*in case of choosing low*/
		case LOW:
			/*setting specific DIO pin to low*/
			MDIO_PORTB &= ~ au8_pin;
			/*break from this case*/
			break;
		/*in case of default*/
		default:
			/*break from default*/
			break;
		}
		/*break from this case*/
		break;
	/*IN CASE OF CHOOSING PORT C*/
	case PORTC:
		/*switching over pin value*/
		switch(au8_Value)
		{
		/*in case of choosing high*/
		case HIGH:
			/*setting specific DIO Pins to high */
			MDIO_PORTC |= au8_pin;
			/*break from this case*/
			break;
		/*in case of choosing low*/
		case LOW:
			/*setting specific DIO pin to low*/
			MDIO_PORTC &= ~ au8_pin;
			/*break from this case*/
			break;
		/*in case of default*/
		default:
			/*break from default*/
			break;
		}
		/*break from this case*/
		break;
	/*IN CASE OF CHOOSING PORT D*/
	case PORTD:
		/*switching over pin value*/
		switch(au8_Value)
		{
		/*in case of choosing high*/
		case HIGH:
			/*setting specific DIO Pins to high */
			MDIO_PORTD |= au8_pin;
			/*break from this case*/
			break;
		/*in case of choosing low*/
		case LOW:
			/*setting specific DIO pin to low*/
			MDIO_PORTD &= ~ au8_pin;
			/*break from this case*/
			break;
		/*in case of default*/
		default:
			/*break from default*/
			break;
		}
		/*break from this case*/
		break;
	}
	/*Return from this function*/
	return;
}


void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin )
{
	/*switching over DIO PORTS*/
	switch(au8_port)
	{
	/*in case of choosing PORTA*/
	case PORTA:
		/*toggling specific DIO pin*/
		MDIO_PORTA |= au8_pin;
		/*break from this case*/
		break;
	/*in case of choosing PORTB*/
	case PORTB:
		/*toggling specific DIO pin*/
		MDIO_PORTB |= au8_pin;
		/*break from this case*/
		break;
	/*in case of choosing PORTB*/
	case PORTC:
		/*toggling specific DIO pin*/
		MDIO_PORTC |= au8_pin;
		/*break from this case*/
		break;
	/*in case of choosing PORTB*/
	case PORTD:
		/*toggling specific DIO pin*/
		MDIO_PORTD |= au8_pin;
		/*break from this case*/
		break;
	/*in case of default*/
	default:
		/*break from default*/
		break;
	}
	/*Return from this function*/
	return;
}


u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin )
{
	/*Local variable used to get a specific pin value*/
	u8_t au8_pinValue = 0;
	/*switching over DIO ports*/
	switch(au8_port)
	{
	/*in case of choosing PORTA*/
	case PORTA:
		/*checking a specific pin value*/
		if(MDIO_PINA & au8_pin)
		{
			/*setting the pin value to high*/
			au8_pinValue = HIGH;
		}
		else
		{
			/*setting the pin value to low*/
			au8_pinValue = LOW;
		}
		/*break from this case*/
		break;
	/*in case of choosing PORTB*/
	case PORTB:
		/*checking a specific pin value*/
		if(MDIO_PINB & au8_pin)
		{
			/*setting the pin value to high*/
			au8_pinValue = HIGH;
		}
		else
		{
			/*setting the pin value to low*/
			au8_pinValue = LOW;
		}
		/*break from this case*/
		break;
	/*in case of choosing PORTC*/
	case PORTC:
		/*checking a specific pin value*/
		if(MDIO_PINC & au8_pin)
		{
			/*setting the pin value to high*/
			au8_pinValue = HIGH;
		}
		else
		{
			/*setting the pin value to low*/
			au8_pinValue = LOW;
		}
		/*break from this case*/
		break;
	/*in case of choosing PORTD*/
	case PORTD:
		/*checking a specific pin value*/
		if(MDIO_PIND & au8_pin)
		{
			/*setting the pin value to high*/
			au8_pinValue = HIGH;
		}
		else
		{
			/*setting the pin value to low*/
			au8_pinValue = LOW;
		}
		/*break from this case*/
		break;
	/*in case of default*/
	default:
		/*break from default*/
		break;
	}
	/*Return from this function*/
	return au8_pinValue ;
}
