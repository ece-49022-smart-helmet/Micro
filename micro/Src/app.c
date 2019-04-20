/*
 * app.c
 *
 *  Created on: Apr 15, 2019
 *      Author: sophiagould
 */

#include "main.h"
#include "BT.h"

void app_preloop(UART_HandleTypeDef* huart5) {
  BTCommandMode(huart5);
  HAL_Delay(100);
  BTChangeName(huart5);
  HAL_Delay(100);
  BTChangeAuth(huart5);
  HAL_Delay(100);
  BTDataMode(huart5);
  HAL_Delay(100);
}
