/*
 * mian.c
 *
 *  Created on: Sep 3, 2021
 *      Author: AlaaElnagar
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"

#include "FreeRTOS.h"


#include "task.h"
#include "semphr.h"


#define switching  0
#define semaphor    1


#define mode   semaphor

#if mode == switching
void task_1(void *pv)
{
	static u8_t au8_state =0;

	while(1)
	{
		TOGGLE_BIT(au8_state,0);
		mdio_setPinValue(PORTA,PIN0,au8_state);
		vTaskDelay(1000);
	}
}

void task_2(void *pv)
{
	static u8_t au8_state =0;

	while(1)
	{
		TOGGLE_BIT(au8_state,0);
		mdio_setPinValue(PORTA,PIN1,au8_state);
		vTaskDelay(2000);
	}
}

void task_3(void *pv)
{
	static u8_t au8_state =0;

	while(1)
	{
		TOGGLE_BIT(au8_state,0);
		mdio_setPinValue(PORTA,PIN2,au8_state);
		vTaskDelay(500);
	}
}

int main(void)
{
	mdio_setPinstatus(PORTA,PIN0,OUTPUT);
	mdio_setPinstatus(PORTA,PIN1,OUTPUT);
	mdio_setPinstatus(PORTA,PIN2,OUTPUT);
	xTaskCreate(task_1, NULL, 200, NULL, 1, NULL);
	xTaskCreate(task_2, NULL, 200, NULL, 2, NULL);
	xTaskCreate(task_3, NULL, 200, NULL, 3, NULL);
	vTaskStartScheduler();
	return 0;
}

#elif mode == semaphor

xSemaphoreHandle task_sem;

void task_1(void *pv)
{
	static u8_t au8_state =0;

	u8_t au8_semaphorstate = 0;

	while(1)
	{
		/*ask for semaphore*/
		 au8_semaphorstate = xSemaphoreTake(task_sem, 0);

		if(au8_semaphorstate == pdPASS)
		{
			TOGGLE_BIT(au8_state,0);
			mdio_setPinValue(PORTA,PIN0,au8_state);
			xSemaphoreGive(task_sem) ;
		}

		vTaskDelay(1000);
	}
}

void task_2(void *pv)
{
	static u8_t au8_state =0;
	u8_t au8_semaphorstate = 0;

	while(1)
	{
		/*ask for semaphore*/
		au8_semaphorstate = xSemaphoreTake(task_sem, 0);

		if(au8_semaphorstate == pdPASS)
		{
			TOGGLE_BIT(au8_state,0);
			mdio_setPinValue(PORTA,PIN1,au8_state);
			xSemaphoreGive(task_sem);
		}

		vTaskDelay(500);
	}
}

int main(void)
{
	mdio_setPinstatus(PORTA,PIN0,OUTPUT);
	mdio_setPinstatus(PORTA,PIN1,OUTPUT);
	//mdio_setPinstatus(PORTA,PIN2,OUTPUT);


	task_sem = xSemaphoreCreateCounting(1,1);
	xTaskCreate(task_1, NULL, 200, NULL, 1, NULL);
	xTaskCreate(task_2, NULL, 200, NULL, 2, NULL);
	//xTaskCreate(task_3, NULL, 200, NULL, 3, NULL);
	vTaskStartScheduler();
	return 0;
}


#endif




