#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#define pin_rx (uint16_t)1<<11
#define pin_tx (uint16_t)1<<10

void InitGPIO()
{

	__HAL_RCC_LSE_CONFIG(RCC_LSE_OFF);

	GPIO_InitTypeDef gpioastruct;
	gpioastruct.Mode=GPIO_MODE_OUTPUT_PP;
	gpioastruct.Pin= GPIO_PIN_9;
	gpioastruct.Speed=GPIO_SPEED_HIGH;
	__GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOA,&gpioastruct);

	GPIO_InitTypeDef gpiobstruct;
	gpiobstruct.Mode=GPIO_MODE_OUTPUT_PP;
	gpiobstruct.Pin= GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_13;
	gpiobstruct.Speed=GPIO_SPEED_HIGH;
	__GPIOB_CLK_ENABLE();
	HAL_GPIO_Init(GPIOB,&gpiobstruct);

	GPIO_InitTypeDef gpiocstruct;
	gpiocstruct.Mode=GPIO_MODE_OUTPUT_PP;
	gpiocstruct.Pin=GPIO_PIN_12 ;
	gpiocstruct.Speed=GPIO_SPEED_HIGH;
	gpiocstruct.Pull = GPIO_PULLUP;
	__GPIOC_CLK_ENABLE();
	HAL_GPIO_Init(GPIOC,&gpiocstruct);


	//USART 3
	gpiocstruct.Alternate = GPIO_AF7_USART3;
	gpiocstruct.Mode=GPIO_MODE_AF_PP;
	gpiocstruct.Pin=pin_rx|pin_tx;
	gpiocstruct.Pull=GPIO_PULLUP;
	gpiocstruct.Speed=GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOC,&gpiocstruct);

}
