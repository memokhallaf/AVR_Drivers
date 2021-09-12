/*
 * Name: HLCD_interface.h
 * Author: Mohamed Tarek
 * Description: This file contains interfacing information of LCD module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

/************************************************************************************************/
/*                                      Interfacing macros                                      */
/************************************************************************************************/
/*LCD ROWS*/
#define ROW_0 (0)
#define ROW_1 (1)
/*LCD COLUMES*/
#define COL_0 	(0)
#define COL_1 	(1)
#define COL_2 	(2)
#define COL_3 	(3)
#define COL_4 	(4)
#define COL_5 	(5)
#define COL_6 	(6)
#define COL_7 	(7)
#define COL_8 	(8)
#define COL_9 	(9)
#define COL_10 	(10)
#define COL_11 	(11)
#define COL_12 	(12)
#define COL_13	(13)
#define COL_14 	(14)
#define COL_15 	(15)


/************************************************************************************************/
/*                                    Functions' prototypes                                     */
/************************************************************************************************/

/*this fun is used to init*/
void hlcd_init(void);
/*this fun is used to display a custom  character from ASCII table*/
void hlcd_displayCharacter(u8_t au8_charData);
/*this fun is used to display a custom series of character from ASCII table*/
void hlcd_displayString(u8_t* pu8_stringData);
/*this fun is used to set the cursor at specific location at LCD*/
void hlcd_setCursor(u8_t  au8_row, u8_t  au8_col);
/*this fun is used to creat custom charachter in CGRAM*/
void hlcd_creatCustomChar(void);
/*this fun is used to display a custom charachter from CGRAM */
void hlcd_displayCustomChar(void);
/*this fun is used to creat custom charachter in CGRAM*/
void hlcd_creatCustomChar1(void);
/*this fun is used to display a custom charachter from CGRAM */
void hlcd_displayCustomChar1(void);
#endif /* HLCD_INTERFACE_H_ */
