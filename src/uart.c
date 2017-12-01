#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"


uint16_t uartsize=8 ;
uint32_t uarttimeout=10000 ;
uint8_t pData='a';

UART_HandleTypeDef uart2struct;

void InitUart()
{

	uart2struct.Instance=USART2;
	uart2struct.Init.BaudRate= 9600;
	uart2struct.Init.WordLength=UART_WORDLENGTH_8B;
	uart2struct.Init.StopBits=UART_STOPBITS_1;
	uart2struct.Init.Parity=UART_PARITY_NONE;
	uart2struct.Init.Mode=UART_MODE_TX_RX;
	uart2struct.Init.HwFlowCtl=UART_HWCONTROL_NONE;

	HAL_UART_MspInit (&uart2struct);
	__USART2_CLK_ENABLE();

	HAL_UART_Init(&uart2struct);
}

void SendOverBluetooth(char *msg)
{
	HAL_UART_Transmit(&uart2struct,msg,uartsize,uarttimeout);
}
