/*
 * mian.c
 *
 *  Created on: Sep 3, 2021
 *      Author: AlaaElnagar
 */


#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "DIO_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "CLCD_interface.h"

#define TASK_1    				 1
#define COUNTING_SEMAPHOUR       2
#define TASK_3        			 3
#define TASK_4     4

#define CUREEENT  				COUNTING_SEMAPHOUR

#if CUREEENT == TASK_1


void LED1(void *pv) ;
void LED2(void *pv) ;
void LED3(void *pv) ;

void main (){

	DIO_VidSetPinDirection(Port_A , Pin_0 , output) ;
	DIO_VidSetPinDirection(Port_A , Pin_1 , output) ;
	DIO_VidSetPinDirection(Port_A , Pin_2 , output) ;

	xTaskCreate(LED1 ,NULL ,100, NULL , 0 , NULL);
	xTaskCreate(LED2 ,NULL ,100 , NULL , 1 , NULL);
	xTaskCreate(LED3 ,NULL ,100 , NULL , 2 , NULL);

	vTaskStartScheduler() ;

	while (1) {


	}


}


void LED1(void *pv) {

	static u8 local_u8state = 0 ;
	while (1){

		TOGGLE_BIT(local_u8state , 0);
		DIO_VidSetPinValue(Port_A,local_u8state,Pin_0) ;
		vTaskDelay(1000) ;
	}

}
void LED2(void *pv) {

	static u8 local_u8state = 0 ;
	while (1){

		TOGGLE_BIT(local_u8state , 0);
		DIO_VidSetPinValue(Port_A,local_u8state,Pin_1) ;
		vTaskDelay(2000) ;

	}
}
void LED3(void *pv) {

	static u8 local_u8state = 0 ;
	while (1){

		TOGGLE_BIT(local_u8state , 0);
		DIO_VidSetPinValue(Port_A,local_u8state,Pin_2) ;
		vTaskDelay(50000) ;

	}
}


#elif CUREEENT == COUNTING_SEMAPHOUR


void LCD1(void *pv) ;
void LCD2(void *pv) ;
u8 Global_u8Flag = 1 ;
xSemaphoreHandle LCDSem   ;

void main (){

	DIO_VidSetPortDirection(Port_A , 0xff );
	DIO_VidSetPortDirection(Port_C , 0xff) ;

	CLCD_VidInit() ;
	DIO_VidSetPortDirection(Port_B ,Port_High ) ;

	LCDSem = xSemaphoreCreateCounting(1,1) ;


	xTaskCreate(LCD1 ,NULL ,500, NULL , 1, NULL);
	xTaskCreate(LCD2 ,NULL ,500 , NULL , 1, NULL);

	vTaskStartScheduler() ;

	while (1) {

	}


}


void LCD1(void *pv) {

	u8 Local_u8SemaphourState;

	while (1){
		/*Try to take the semaphour */
		Local_u8SemaphourState = xSemaphoreTake(LCDSem,0) ;

		if (Local_u8SemaphourState == pdPASS){
			/*semaphour is taken access LCD */
			CLCD_VidSendString("Iam Task 1_") ;
			/*give back the semaphour */
			xSemaphoreGive(LCDSem) ;
		}
		vTaskDelay(1000) ;

	}
}

void LCD2(void *pv) {
	u8 Local_u8SemaphourState;

	while (1){
		/*Try to take the semaphour */
		Local_u8SemaphourState = xSemaphoreTake(LCDSem,0) ;

		if (Local_u8SemaphourState == pdPASS){
			/*semaphour is taken access LCD */
			CLCD_VidSendString("Iam Task 2_") ;
			/*give back the semaphour */
			xSemaphoreGive(LCDSem) ;
		}
		vTaskDelay(1000) ;

	}
}















#endif
