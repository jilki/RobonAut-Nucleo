/*
 * gpio.h
 *
 *  Created on: 2017. dec. 1.
 *      Author: Zsolt
 */

#ifndef GPIO_H_
#define GPIO_H_

void InitGPIO(void);

void activateChipSelect(uint8_t moduleNumber);

void deactivateChipSelect(uint8_t moduleNumber);


#endif /* GPIO_H_ */
