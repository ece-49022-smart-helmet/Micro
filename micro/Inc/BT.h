/*
 * BT.h
 *
 *  Created on: Apr 9, 2019
 *      Author: sophiagould
 */

#ifndef BT_H_
#define BT_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

uint8_t BTCommandMode(UART_HandleTypeDef*);
void BTDataMode(UART_HandleTypeDef*);
void BTChangeAuth(UART_HandleTypeDef*);

void BTChangeName(UART_HandleTypeDef*);

#endif /* BT_H_ */
