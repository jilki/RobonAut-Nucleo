/*
 * spi.h
 *
 *  Created on: 2017. dec. 1.
 *      Author: Zsolt
 */

#ifndef SPI_H_
#define SPI_H_

void MX_SPI2_Init(void);

void readTcrtSensor(uint8_t* buff);

#endif /* SPI_H_ */
