#include "oled.h"
#include "stm32f4xx_hal.h"


extern SPI_HandleTypeDef hspi2;

void OLED_sendData(uint8_t * buf, int sz)
{
	HAL_GPIO_WritePin(GPIOB, OLED_PIN_DC, GPIO_PIN_SET); // data mode
	//HAL_Delay(1);
	//HAL_GPIO_WritePin(GPIOB, OLED_PIN_CS, GPIO_PIN_RESET); // select device
	HAL_SPI_Transmit(&hspi2, buf, sz, 1000);
	//HAL_GPIO_WritePin(GPIOB, OLED_PIN_CS, GPIO_PIN_SET); // unselect device
}

void OLED_sendCommand(uint8_t command)
{
	HAL_GPIO_WritePin(GPIOB, OLED_PIN_DC, GPIO_PIN_RESET); // command mode
	//HAL_Delay(10);
	//HAL_GPIO_WritePin(GPIOB, OLED_PIN_CS, GPIO_PIN_RESET); // select device
	HAL_SPI_Transmit(&hspi2, &command, 1, 1000);
	//HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB, OLED_PIN_DC, GPIO_PIN_SET); // unselect device
}

void OLED_sendParam(uint8_t command, uint8_t param1)
{
	OLED_sendCommand(command);
	OLED_sendData(&param1, 1);
}

void OLED_sendParams(uint8_t command, uint8_t param1, uint8_t param2)
{
	uint8_t params[2] = {param1, param2};

	OLED_sendCommand(command);
	OLED_sendData(params, 2);
}

void OLED_init()
{
	// source: https://luma-oled.readthedocs.io/en/latest/_modules/luma/oled/device.html
	OLED_sendParam(OLED_COMMAND_SET_COMMAND_LOCK, 0x12);
	OLED_sendCommand(OLED_COMMAND_DISPLAY_MODE_OFF);
	OLED_sendParam(OLED_COMMAND_SET_CLOCK_DIV, 0xF2);
	OLED_sendParam(OLED_COMMAND_SET_MUX_RATIO, 0x3F);
	OLED_sendParam(OLED_COMMAND_SET_DISPLAY_OFFSET, 0x00);
	OLED_sendParam(OLED_COMMAND_SET_DISPLAY_START, 0x00);
	OLED_sendParams(OLED_COMMAND_SET_REMAP_DCL_MODE, 0x14, 0x11);
	OLED_sendParam(OLED_COMMAND_SET_GPIO, 0x00);
	OLED_sendParam(OLED_COMMAND_VDD_SELECT, 0x01);
	OLED_sendParams(OLED_COMMAND_DISPLAY_ENHANCE_A, 0xA0, 0xFD);
	OLED_sendParam(OLED_COMMAND_MASTER_CONTRAST_CURR_CTRL, 0x0F);
	OLED_sendCommand(OLED_COMMAND_RESET_GRAY_TABLE);
	OLED_sendParam(OLED_COMMAND_SET_PHASE_LENGTH, 0xF0);
	OLED_sendParams(OLED_COMMAND_DISPLAY_ENHANCE_B, 0x82, 0x20);
	OLED_sendParam(OLED_COMMAND_SET_PRECHARGE_VOLTAGE, 0x0D);
	OLED_sendParam(OLED_COMMAND_SET_PRECHARGE_PERIOD, 0x08);
	OLED_sendParam(OLED_COMMAND_SET_RESET_VOLTAGE, 0x00);
	OLED_sendCommand(OLED_COMMAND_DISPLAY_MODE_NORMAL);
	OLED_sendCommand(OLED_COMMAND_PARTIAL_MODE_OFF);
	OLED_sendCommand(OLED_COMMAND_SLEEP_MODE_OFF);

}

void OLED_setColumnAddr(uint8_t lo, uint8_t hi)
{
	OLED_sendCommand(0x15);
	OLED_sendData(&lo, 1);
	OLED_sendData(&hi, 1);
}

void OLED_setRowAddr(uint8_t lo, uint8_t hi)
{
	OLED_sendCommand(0x75);
	OLED_sendData(&lo, 1);
	OLED_sendData(&hi, 1);
}

void OLED_fill()
{
	OLED_setColumnAddr(OLED_COL_ADDR_L, OLED_COL_ADDR_H);
	OLED_setRowAddr(OLED_ROW_ADDR_L, OLED_ROW_ADDR_H);
	OLED_sendCommand(OLED_COMMAND_ENABLE_RAM_WRITE);

	uint8_t bright = 0xFF;

	for (int i = 0; i < OLED_ROWS; i++)
	{
		for (int j = 0; j < OLED_COLS; j++)
			OLED_sendData(&bright, 1);
	}

}

void OLED_checker()
{
	OLED_setColumnAddr(OLED_COL_ADDR_L, OLED_COL_ADDR_H);
	OLED_setRowAddr(OLED_ROW_ADDR_L, OLED_ROW_ADDR_H);
	OLED_sendCommand(OLED_COMMAND_ENABLE_RAM_WRITE);

	uint8_t bright = 0xFF;
	uint8_t dark = 0x00;

	for (int i = 0; i < OLED_ROWS / 2; i++)
	{
		for (int j = 0; j < OLED_COLS / 2; j++)
		{
			OLED_sendData(&bright, 1);
			OLED_sendData(&dark, 1);
		}
//		for (int j = 0; j < OLED_COLS / 4; j++)
//		{
//			OLED_sendData(&bright, 1);
//			OLED_sendData(&bright, 1);
//		}
		for (int j = 0; j < OLED_COLS / 2; j++)
		{
			OLED_sendData(&dark, 1);
			OLED_sendData(&bright, 1);
		}
	}
}

void OLED_clear()
{
	OLED_setColumnAddr(OLED_COL_ADDR_L, OLED_COL_ADDR_H);
	OLED_setRowAddr(OLED_ROW_ADDR_L, OLED_ROW_ADDR_H);
	OLED_sendCommand(OLED_COMMAND_ENABLE_RAM_WRITE);

	uint8_t data = 0x00;

	for (int i = 0; i < OLED_ROWS; i++)
	{
		for (int j = 0; j < OLED_COLS; j++)
			OLED_sendData(&data, 1);
	}

}

void OLED_blit(uint8_t * buf, size_t size)
{
	OLED_setColumnAddr(OLED_COL_ADDR_L, OLED_COL_ADDR_H);
	OLED_setRowAddr(OLED_ROW_ADDR_L, OLED_ROW_ADDR_H);
	OLED_sendCommand(OLED_COMMAND_ENABLE_RAM_WRITE);

	uint8_t dark = 0x00;
	uint8_t bright = 0xFF;

	for (size_t i = 0; i < size; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((buf[i] << j) & 0x80)
				OLED_sendData(&bright, 1);
			else
				OLED_sendData(&dark, 1);
		}
	}
}

void OLED_blitDecompress(int16_t * data, size_t size, bool hflip, bool vflip)
{
	// changing that bit changes the COM scan direction
	if (vflip ^ hflip) OLED_sendParams(OLED_COMMAND_SET_REMAP_DCL_MODE, 0x04, 0x11);
	else OLED_sendParams(OLED_COMMAND_SET_REMAP_DCL_MODE, 0x14, 0x11);

	OLED_setColumnAddr(OLED_COL_ADDR_L, OLED_COL_ADDR_H);
	OLED_setRowAddr(OLED_ROW_ADDR_L, OLED_ROW_ADDR_H);
	OLED_sendCommand(OLED_COMMAND_ENABLE_RAM_WRITE);

	uint8_t dark = 0x00;
	uint8_t bright = 0xFF;

	for (size_t k = 0; k < size; k++)
	{
		size_t i = hflip ? size - 1 - k : k;
		if (data[i] < 0)
		{
			for (int j = 0; j < -8 * data[i]; j++)
				OLED_sendData(&dark, 1);
		}
		else
		{
			for (int j = 0; j < 8; j++)
			{
				if ((data[i] << (hflip? 7 - j : j)) & 0x80)
					OLED_sendData(&bright, 1);
				else
					OLED_sendData(&dark, 1);
			}
		}
	}
}
