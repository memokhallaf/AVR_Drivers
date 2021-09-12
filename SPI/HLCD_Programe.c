/*
 * Name: HLCD_Programe.h
 * Author: Mohamed Tarek
 * Description: This file contains logical implementation of LCD module
 * Version: v1.0
 * */


/************************************************************************************************/
/*                                           Includes                                           */
/************************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_Private.h"
#include "HLCD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
/************************************************************************************************/
/*                                    Functions' definitions                                    */
/************************************************************************************************/

static void hlcd_sendData(u8_t au8_data)
{
	/*SETTING RS PIN TO HIGH FOR SENDING DATA*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, HIGH);
	/*SETTING RW PIN TO LOW FOR WRITING DATA*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, LOW);
	/*PASSING DATA OVER DATA PINS*/
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D0_PIN, GET_BIT(au8_data, 0));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D1_PIN, GET_BIT(au8_data, 1));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D2_PIN, GET_BIT(au8_data, 2));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D3_PIN, GET_BIT(au8_data, 3));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(au8_data, 4));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(au8_data, 5));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(au8_data, 6));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(au8_data, 7));
	/*TRIGGERING DATA BY ENABLE SIGNAL*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, LOW);
	_delay_us(50);
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);
	/*return from this function*/
	return;
}

static void hlcd_sendCmd(u8_t au8_cmd)
{
	/*SETTING RS PIN TO LOW FOR SENDING DATA*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, LOW);
	/*SETTING RW PIN TO LOW FOR WRITING DATA/CMD*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, LOW);
	/*PASSING COMMEND OVER DATA PINS*/
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D0_PIN, GET_BIT(au8_cmd, 0));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D1_PIN, GET_BIT(au8_cmd, 1));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D2_PIN, GET_BIT(au8_cmd, 2));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D3_PIN, GET_BIT(au8_cmd, 3));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(au8_cmd, 4));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(au8_cmd, 5));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(au8_cmd, 6));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(au8_cmd, 7));
	/*TRIGGERING DATA BY ENABLE SIGNAL*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, LOW);
	_delay_us(50);
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);

	/*return from this function*/
	return;
}



void hlcd_init(void)
{
	/*SETTING CONTROL PORT PINS TO OUTPUT*/
	mdio_setPinstatus(HLCD_CTRL_PORT, (HLCD_RS_PIN | HLCD_RW_PIN | HLCD_EN_PIN), OUTPUT);

	/*SETTING DATA PORT PINS TO OUTPUT*/
	mdio_setPinstatus(HLCD_DATA_PORT, (HLCD_D0_PIN | HLCD_D1_PIN | HLCD_D2_PIN | HLCD_D3_PIN |
										HLCD_D4_PIN | HLCD_D5_PIN | HLCD_D6_PIN | HLCD_D7_PIN), OUTPUT);
	/*SETTING EN PIN TO HIGH TO READ*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);
	/*waiting for vdd to reach 4.5v*/
	_delay_ms(50);
	/*SENDING FUN SET COMNEND*/
	hlcd_sendCmd(0x3C);
	/*DELAY FOR ONLY 1 ms*/
	_delay_ms(1);
	/*Sending display on/off command*/
	hlcd_sendCmd(0x0F);

	/*Delaying for 1ms*/
	_delay_ms(1);

	/*Sending display clear command*/
	hlcd_sendCmd(0x01);

	/*Delaying for 2ms*/
	_delay_ms(2);

	/*Sending entry mode set command*/
	hlcd_sendCmd(0x06);

	/*Delaying for 1ms*/
	_delay_ms(1);
	/*return from this function*/
	return;
}

void hlcd_displayCharacter(u8_t au8_charData)
{
	/*Sending character data*/
		hlcd_sendData(au8_charData);
		while(au8_charData != 0)
		{
			/*do nothing*/
		}
	/*return from this function*/
	return;
}

void hlcd_displayString(u8_t* pu8_stringData)
{
	/*Looping over string characters*/
		while(*pu8_stringData != '\0')
		{
			/*Sending character data*/
			hlcd_sendData(*pu8_stringData);

			/*Incrementing pointer address*/
			pu8_stringData++;
		}
	/*return from this function*/
	return;
}

void hlcd_setCursor(u8_t  au8_row, u8_t  au8_col)
{
	/*switching over LCD rows*/
	switch(au8_row)
	{
	case ROW_0:
		hlcd_sendCmd(((0x80) | au8_col));
		break;
	case ROW_1:
		hlcd_sendCmd(((0xC0) | au8_col));
		break;
	default:
		break;
	}
	/*return from this function*/
	return;
}

 void hlcd_creatCustomChar(void)
{
	/*setting CGRAM Address*/
	hlcd_sendCmd((0x40));
	/*Sending custom charachter to CGRAM*/
	hlcd_sendData((0x00));
	hlcd_sendData((0x0A));
	hlcd_sendData((0x1F));
	hlcd_sendData((0x1F));
	hlcd_sendData((0x1F));
	hlcd_sendData((0x07));
	hlcd_sendData((0x04));
	hlcd_sendData((0x00));
	/*setting DDRAM Address*/
	hlcd_sendCmd((0x80));

	/*return from this fun*/
	return;
}

void hlcd_displayCustomChar(void)
{
	/*sending character data*/
	hlcd_sendData((0x00));
	/*return from this fun*/
	return;
}
void hlcd_creatCustomChar1(void)
{
	/*setting CGRAM Address*/
		hlcd_sendCmd((0x48));
		/*Sending custom charachter to CGRAM*/
		hlcd_sendData((0x04));
		hlcd_sendData((0x0E));
		hlcd_sendData((0x0E));
		hlcd_sendData((0x0E));
		hlcd_sendData((0x0E));
		hlcd_sendData((0x1F));
		hlcd_sendData((0x04));
		hlcd_sendData((0x00));
		/*setting DDRAM Address*/
		hlcd_sendCmd((0xC0));
	/*return from this fun*/
	return;
}
void hlcd_displayCustomChar1(void)
{
	/*sending character data*/
		hlcd_sendData((0x01));
	/*return from this fun*/
	return;
}
