/*
 * Name: HLCD_Private.h
 * Author: Mohamed Tarek
 * Description: This file contains private information of LCD module
 * Version: v1.0
 * */



/*Header file guard*/
#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_
/************************************************************************************************/
/*                               LCD CONNECTIONS                                                  */
/************************************************************************************************/
/*LCD CONTROL PORT*/
#define HLCD_CTRL_PORT  (PORTB)
/*LCD CONTROL PINS*/
#define HLCD_RS_PIN (PIN0)
#define HLCD_RW_PIN (PIN1)
#define HLCD_EN_PIN (PIN2)

/*LCD DATA PORT*/
#define HLCD_DATA_PORT  (PORTD)
/*LCD DATA PINS*/
#define HLCD_D0_PIN (PIN0)
#define HLCD_D1_PIN (PIN1)
#define HLCD_D2_PIN (PIN2)
#define HLCD_D3_PIN (PIN3)
#define HLCD_D4_PIN (PIN4)
#define HLCD_D5_PIN (PIN5)
#define HLCD_D6_PIN (PIN6)
#define HLCD_D7_PIN (PIN7)

#endif /* HLCD_PRIVATE_H_ */
