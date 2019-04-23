#ifndef OLED_H
#define OLED_H
#include "stm32f4xx_hal.h"
#include<stdbool.h>

#define OLED_PIN_DC GPIO_PIN_1
#define OLED_PIN_CS GPIO_PIN_15
#define OLED_ROWS 64
#define OLED_COLS 128
#define OLED_ROW_ADDR_L 0x00
#define OLED_COL_ADDR_L 0x1C
#define OLED_ROW_ADDR_H 0x3F
#define OLED_COL_ADDR_H 0x5B

#define OLED_COMMAND_SET_COL_ADDR 0x15
#define OLED_COMMAND_ENABLE_RAM_WRITE 0x5C
#define OLED_COMMAND_ENABLE_RAM_READ 0x5D
#define OLED_COMMAND_SET_ROW_ADDR 0x75
#define OLED_COMMAND_SET_REMAP_DCL_MODE 0xA0
#define OLED_COMMAND_SET_DISPLAY_START 0xA1
#define OLED_COMMAND_SET_DISPLAY_OFFSET 0xA2
#define OLED_COMMAND_DISPLAY_MODE_OFF 0xA4
#define OLED_COMMAND_DISPLAY_MODE_ON 0xA5
#define OLED_COMMAND_DISPLAY_MODE_NORMAL 0xA6
#define OLED_COMMAND_DISPLAY_MODE_INVERT 0xA7
#define OLED_COMMAND_PARTIAL_MODE_ON 0xA8
#define OLED_COMMAND_PARTIAL_MODE_OFF 0xA9
#define OLED_COMMAND_VDD_SELECT 0xAB
#define OLED_COMMAND_SLEEP_MODE_ON 0xAE
#define OLED_COMMAND_SLEEP_MODE_OFF 0xAF
#define OLED_COMMAND_SET_PHASE_LENGTH 0xB1
#define OLED_COMMAND_SET_CLOCK_DIV 0xB3
#define OLED_COMMAND_DISPLAY_ENHANCE_A 0xB4
#define OLED_COMMAND_SET_GPIO 0xB5
#define OLED_COMMAND_SET_PRECHARGE_PERIOD 0xB6
#define OLED_COMMAND_SET_GRAY_TABLE 0xB8
#define OLED_COMMAND_RESET_GRAY_TABLE 0xB9
#define OLED_COMMAND_SET_PRECHARGE_VOLTAGE 0xBB
#define OLED_COMMAND_SET_RESET_VOLTAGE 0xBE
#define OLED_COMMAND_SET_CONTRAST_CURR 0xC1
#define OLED_COMMAND_MASTER_CONTRAST_CURR_CTRL 0xC7
#define OLED_COMMAND_SET_MUX_RATIO 0xCA
#define OLED_COMMAND_DISPLAY_ENHANCE_B 0xD1
#define OLED_COMMAND_SET_COMMAND_LOCK 0xFD


// sending raw data to the OLED
void OLED_sendCommand(uint8_t);
void OLED_sendParam(uint8_t, uint8_t);
void OLED_sendParams(uint8_t, uint8_t, uint8_t);
void OLED_setData(uint8_t *, int);

// library API functions
void OLED_init();
void OLED_setColumnAddr(uint8_t, uint8_t);
void OLED_setRowAddr(uint8_t, uint8_t);

// display functions
void OLED_fill();
void OLED_checker();
void OLED_clear();
void OLED_blit(uint8_t *, size_t);
void OLED_blitDecompress(int16_t *, size_t, bool, bool);
#endif
