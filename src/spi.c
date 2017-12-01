/*
 * spi.c
 *
 *  Created on: 2017. dec. 1.
 *      Author: Zsolt
 */

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

SPI_HandleTypeDef hspi1;

void InitSpi()
{
	void MX_SPI2_Init(void)
	{
		hspi1.Instance = SPI1;
		hspi1.Init.Mode = SPI_MODE_MASTER;
		hspi1.Init.Direction = SPI_DIRECTION_2LINES;
		hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
		hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
		hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
		hspi1.Init.NSS = SPI_NSS_SOFT;
		hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
		hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
		hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
		hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
		hspi1.Init.CRCPolynomial = 10;

		/* Peripheral clock enable */
		__SPI1_CLK_ENABLE();

		if (HAL_SPI_Init(&hspi1) != HAL_OK)
		{
			Error_Handler();
		}


		GPIO_InitTypeDef GPIO_InitStruct;
		/**SPI1 GPIO Configuration
		PA5 ------> SPI1_SCK
		PA7 ------> SPI1_MOSI
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_0;                //Chip Select
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		__HAL_SPI_ENABLE(&hspi1);
	}

	void readTcrtSensor(uint8_t* buff)
	{
		uint8_t dummyData = 0;
		for(int8_t i = 0; i < 8; i++)
		{
			HAL_SPI_TransmitReceive(&hspi1, &i, &dummyData, 1, 0xFF);
			HAL_SPI_TransmitReceive(&hspi1, &dummyData, &dummyData, buff+1, 0xFF);
		}
	}
}
