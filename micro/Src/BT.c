/*
 * BT.c
 *
 *  Created on: Apr 9, 2019
 *      Author: sophiagould
 */

#include "main.h"
#include <string.h>

uint8_t BTCommandMode(UART_HandleTypeDef* huart5){
	uint8_t cmd[5];
	HAL_GPIO_WritePin(GPIOPC5_GPIO_Port, GPIOPC5_Pin, GPIO_PIN_RESET);
	HAL_UART_Receive(huart5, cmd, 5, 1000);
	if(strcmp((char*) cmd, "CMD\r\n") == 0){
		return 0;
	} else {
		return -1;
		/*SCREAMING_GOAT.JPEG*/
	}

}

void BTDataMode(UART_HandleTypeDef* huart5){
	uint8_t end[5];
	HAL_GPIO_WritePin(GPIOPC5_GPIO_Port, GPIOPC5_Pin, GPIO_PIN_SET);
	HAL_UART_Receive(huart5, end, 5, 300);
	if(!strcmp((char*) end, "END\r\n")){

	} else {

		/*SCREAMING_GOAT.JPEG*/
	}
}

void BTChangeName(UART_HandleTypeDef* huart5){
	char* name = "SN,SmartHelmet\n";
	HAL_UART_Transmit(huart5, (uint8_t*) name, 15, 30);
	//change name of module
}

void BTChangeAuth(UART_HandleTypeDef* huart5){
	char* auth = "SA,0\n";
		HAL_UART_Transmit(huart5, (uint8_t*) auth, 5, 30);
}

void BTSendStr(UART_HandleTypeDef* huart5, const char* st){
	//char* name = "h\r\n";//"SN,SmartHelmet";
	HAL_UART_Transmit(huart5, (uint8_t*) st, 14, 30);
	//change name of module
}

