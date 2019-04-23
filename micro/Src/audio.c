/*
 * audio.c
 *
 *  Created on: Apr 15, 2019
 *      Author: sophiagould
 */
#include "audio.h"
#include "main.h"
#include <string.h>

uint32_t hadc1Value = 0;
uint32_t hadc2Value = 0;
uint32_t hadc3Value = 0;
uint32_t hadc13Value = 0;
uint32_t hadc23Value = 0;
uint32_t hadcFinal1 = 0;
uint32_t hadcFinal2 = 0;
uint32_t test;
int check;

float noiseRatio = 0;

void ADCSampling(ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2, ADC_HandleTypeDef* hadc3, DAC_HandleTypeDef* hdac){
	hadc1Value = 0;
	if (HAL_ADC_PollForConversion(hadc1, 1000) == HAL_OK){
		hadc1Value = HAL_ADC_GetValue(hadc1);
		if (hadc1Value > 2000){
			hadc1Value = 0;
		}
	}
	if (HAL_ADC_PollForConversion(hadc2, 1000) == HAL_OK){
		hadc2Value = HAL_ADC_GetValue(hadc2);
		/*if (hadc1Value == 0){
			hadc2Value = 0;
		}else if(hadc2Value < 200){
			hadc2Value = 0;
			hadc1Value = 0;
		}*/
	}
	if (HAL_ADC_PollForConversion(hadc3, 1000) == HAL_OK){
		hadc3Value = HAL_ADC_GetValue(hadc3);

		hadc3Value = hadc3Value/10;
		//hadc3Value = 0;
	}
	/*
	if (hadc1Value != 0){
		if (hadc3Value != 0){
			hadc13Value = hadc1Value - 735;
					//(((hadc1Value - 300) * 7)+300) + (noiseRatio * hadc3Value);
			hadc23Value = hadc2Value - 735;
					//(((hadc2Value - 300) * 7)+300) + (noiseRatio * hadc3Value);
		}else{
			hadc13Value = hadc1Value - 735;
				//((hadc1Value - 300) * 7)+300;
			hadc23Value = hadc2Value - 735;
				//((hadc2Value - 300) * 7)+300;
		}

	}else{
		hadc13Value = 0;//noiseRatio *hadc1Value;
		hadc23Value = 0;//noiseRatio *hadc2Value;
	}
	user_pwm_setvalue(hadc23Value);
	//hadc13Value = ((hadc1Value - 200) * 30 * (1 - (hadc1Value*.0001)));//(1.6 * hadc1Value) + (1.4 * hadc3Value);
	//hadc23Value = ((hadc2Value - 200) * 30 * (1 - (hadc2Value*.0001)));//(1.6 * hadc2Value) + (1.4 * hadc3Value);
	HAL_DAC_SetValue(hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, hadc23Value);
	//HAL_DAC_SetValue(hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, hadc23Value);
*/

	hadcFinal1 = (hadc1Value - hadc2Value);
	if (hadcFinal1 > 4096){
		hadcFinal1 = 0;
	}
	else{
		hadcFinal1 = (hadcFinal1 *10);
	}


	if(hadc3Value > 240){
		hadcFinal1 = hadcFinal1 + (hadc3Value - 240);
	}

	hadcFinal2 = (hadc2Value - hadc1Value);
	if (hadcFinal2 > 4096){
		hadcFinal2 = 0;
	}
	/*else if(hadcFinal2 < 100){
		hadcFinal2 = 0;
		if(hadc3Value < 90){
			//hadcFinal2 = 90 - hadc3Value;
		}
	}*/
	else{
		hadcFinal2 = hadcFinal2 *10;
	}

	if(hadc3Value < 90){
		hadcFinal2 = hadcFinal2 + (90 - hadc3Value);
	}


/*
	if (hadc1Value < 955){
		hadcFinal2 = 955 - hadc1Value;
	}else if(hadc1Value > 955){
		hadcFinal1 = hadc1Value - 955;
	}
	if(hadcFinal1 > 600 || hadcFinal2 > 600){
		hadcFinal1 = 0;
		hadcFinal2 = 0;
	}
*/

	HAL_DAC_SetValue(hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, hadcFinal1);
	HAL_DAC_SetValue(hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, hadcFinal2);

}



