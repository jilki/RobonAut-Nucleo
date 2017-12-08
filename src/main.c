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
			
extern SPI_HandleTypeDef hspi1;


int main(void)
{

	HAL_Init();
	InitUart();
	InitGPIO();
	InitSpi();

	uint32_t buf[24];
	uint8_t send_buf[]="some really long string and more lenghtgfdgfdwe fg wew\n";
	SendOverBluetooth(send_buf);
	uint8_t dummyData = 0xAA;
	uint8_t dummyWrite = 0xAA;
	while(1)
	{
		/*Interrupt to start measurement*/
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	    HAL_Delay(50);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);

	    HAL_Delay(2);

	    /*Chip Select*/
	    /* Sensor Module #1 */
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,GPIO_PIN_RESET);
	    HAL_Delay(50);
	    //readTcrtSensor(buf);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,GPIO_PIN_SET);



	    /*Chip Select*/
		/* Sensor Module #6 */
	    HAL_Delay(1);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,GPIO_PIN_RESET);
	    readTcrtSensor(buf);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,GPIO_PIN_SET);



		snprintf(send_buf, sizeof(send_buf), "\nModule #6 \n %03d %03d %03d %03d %03d %03d %03d %03d", (uint8_t) buf[0], (uint8_t)buf[1], (uint8_t)buf[2],(uint8_t)buf[3],(uint8_t)buf[4],(uint8_t)buf[5],(uint8_t)buf[6],(uint8_t)buf[7]);
		SendOverBluetooth(send_buf);
		HAL_Delay(10);
	}


}
