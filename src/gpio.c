#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#define pin_rx (uint16_t)1<<3
#define pin_tx (uint16_t)1<<2

void InitGPIO()
{

	GPIO_InitTypeDef gpioastruct;
	gpioastruct.Alternate=GPIO_AF7_USART2;
	gpioastruct.Mode=GPIO_MODE_AF_PP;
	gpioastruct.Pin=pin_rx|pin_tx;
	gpioastruct.Pull=GPIO_PULLUP;
	gpioastruct.Speed=GPIO_SPEED_FREQ_LOW;
	__GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOA,&gpioastruct);

	GPIO_InitTypeDef gpiobstruct;
	gpioastruct.Mode=GPIO_NOPULL;
	gpioastruct.Pin=GPIO_PIN_8;
	gpioastruct.Speed=GPIO_SPEED_FREQ_LOW;
	__GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOB,&gpiobstruct);

	GPIO_InitTypeDef gpiobctruct;
	gpioastruct.Mode=GPIO_NOPULL;
	gpioastruct.Pin=GPIO_PIN_12;
	gpioastruct.Speed=GPIO_SPEED_FREQ_LOW;
	__GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOC,&gpiobctruct);
}
