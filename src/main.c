/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include <gpio.h>
#include <uart.h>
#include <spi.h>
			

int main(void)
{

	HAL_Init();
	InitUart();
	InitGPIO();

	uint8_t buf[20];
	while(1)
	{
		/*Interrupt to start measurement*/
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,GPIO_PIN_SET);
	    HAL_Delay_Microseconds(50);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,GPIO_PIN_RESET);

	    HAL_Delay(2);

	    /*Chip Select*/
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8,GPIO_PIN_RESET);
	    HAL_Delay_Microseconds(50);
	    readTcrtSensor(buf);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8,GPIO_PIN_SET);



		SendOverBluetooth(buf);
		HAL_Delay(500);
		//pData='a' ;
	}


}
