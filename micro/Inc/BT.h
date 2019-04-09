/*
 * BT.h
 *
 *  Created on: Apr 9, 2019
 *      Author: sophiagould
 */

#ifndef BT_H_
#define BT_H_

void BTCommandMode(UART_HandleTypeDef*);
void BTDataMode(UART_HandleTypeDef*);

void BTChangeName(UART_HandleTypeDef*);

#endif /* BT_H_ */
