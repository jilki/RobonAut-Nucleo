#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"


uint16_t uartsize=40 ;
uint32_t uarttimeout=10000 ;
uint8_t pData='a';

UART_HandleTypeDef uart3struct;

void InitUart()
{

	uart3struct.Instance=USART3;
	uart3struct.Init.BaudRate= 9600;
	uart3struct.Init.WordLength=UART_WORDLENGTH_8B;
	uart3struct.Init.StopBits=UART_STOPBITS_1;
	uart3struct.Init.Parity=UART_PARITY_NONE;
	uart3struct.Init.Mode=UART_MODE_TX_RX;
	uart3struct.Init.HwFlowCtl=UART_HWCONTROL_NONE;

	HAL_UART_MspInit (&uart3struct);
	__USART3_CLK_ENABLE();

	HAL_UART_Init(&uart3struct);
}

void SendOverBluetooth(uint8_t *msg)
{
	HAL_UART_Transmit(&uart3struct,msg,uartsize,uarttimeout);
}
