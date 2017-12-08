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

	uint8_t buf[24];
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


//		snprintf(send_buf, sizeof(send_buf), "Module #1\n%02X %02X %02X %02X %02X %02X %02X %02X \n", buf[0], buf[1], buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
//		SendOverBluetooth(send_buf);
		HAL_Delay(10);


	    /*Chip Select*/
		/* Sensor Module #6 */
	    HAL_Delay(50);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,GPIO_PIN_RESET);
	    readTcrtSensor(buf);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,GPIO_PIN_SET);



		snprintf(send_buf, sizeof(send_buf), "\nModule #6 \n %03d %03d %03d %03d %03d %03d %03d %03d", buf[0], buf[1], buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
		SendOverBluetooth(send_buf);
		HAL_Delay(10);	}


}
