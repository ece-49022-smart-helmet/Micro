/*
 * audio.h
 *
 *  Created on: Apr 15, 2019
 *      Author: sophiagould
 */

#ifndef AUDIO_H_
#define AUDIO_H_
#include "stm32f4xx_hal.h"

void ADCSampling(ADC_HandleTypeDef*, ADC_HandleTypeDef*, ADC_HandleTypeDef*, DAC_HandleTypeDef*);
void user_pwm_setvalue(uint16_t);

#endif /* AUDIO_H_ */
