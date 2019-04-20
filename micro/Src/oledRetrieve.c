/*
 * oledRetrieve.c
 *
 *  Created on: Apr 20, 2019
 *      Author: sophiagould
 */
#include "oledRetrieve.h"
#include "main.h"
#include <string.h>

int save = 0;
uint8_t input[5];

void oleditup(UART_HandleTypeDef* huart5){

	HAL_UART_Receive(huart5, input, 5, 300);
	if (!strcmp((char*) input, "right")){
		save = 1;
	}else if(!strcmp((char*) input, "left\0")){
		save = 2;
	}
}

