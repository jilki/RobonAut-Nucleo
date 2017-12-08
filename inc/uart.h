/*
 * uart.h
 *
 *  Created on: 2017. dec. 1.
 *      Author: Zsolt
 */

#ifndef UART_H_
#define UART_H_

void InitUart(void);

void SendOverBluetooth(uint8_t *msg);

#endif /* UART_H_ */
