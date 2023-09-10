/*
 * keyboard.c
 *
 *  Created on: Sep 10, 2023
 *      Author: André A. M. Araújo
 */

#include "keyboard.h"

uint8_t key = KB_DEFAULT;

uint8_t KB_scan(void)
{
	uint16_t keyboard = 0;
	uint8_t  key 	  = 0;

	HAL_GPIO_WritePin(KB_C1_GPIO_Port, KB_C1_Pin | KB_C2_Pin | KB_C3_Pin, 0);

	HAL_GPIO_WritePin(KB_C1_GPIO_Port, KB_C1_Pin, 1);
	keyboard  = HAL_GPIO_ReadPin(KB_R1_GPIO_Port, KB_R1_Pin) << 1
			  | HAL_GPIO_ReadPin(KB_R2_GPIO_Port, KB_R2_Pin) << 4
			  | HAL_GPIO_ReadPin(KB_R3_GPIO_Port, KB_R3_Pin) << 7
			  | HAL_GPIO_ReadPin(KB_R4_GPIO_Port, KB_R4_Pin) << 10;
	HAL_GPIO_WritePin(KB_C1_GPIO_Port, KB_C1_Pin, 0);

	HAL_GPIO_WritePin(KB_C2_GPIO_Port, KB_C2_Pin, 1);
	keyboard |= HAL_GPIO_ReadPin(KB_R1_GPIO_Port, KB_R1_Pin) << 2
			  | HAL_GPIO_ReadPin(KB_R2_GPIO_Port, KB_R2_Pin) << 5
			  | HAL_GPIO_ReadPin(KB_R3_GPIO_Port, KB_R3_Pin) << 8
			  | HAL_GPIO_ReadPin(KB_R4_GPIO_Port, KB_R4_Pin);
	HAL_GPIO_WritePin(KB_C2_GPIO_Port, KB_C2_Pin, 0);

	HAL_GPIO_WritePin(KB_C3_GPIO_Port, KB_C3_Pin, 1);
	keyboard |= HAL_GPIO_ReadPin(KB_R1_GPIO_Port, KB_R1_Pin) << 3
			  | HAL_GPIO_ReadPin(KB_R2_GPIO_Port, KB_R2_Pin) << 6
			  | HAL_GPIO_ReadPin(KB_R3_GPIO_Port, KB_R3_Pin) << 9
			  | HAL_GPIO_ReadPin(KB_R4_GPIO_Port, KB_R4_Pin) << 11;
	HAL_GPIO_WritePin(KB_C3_GPIO_Port, KB_C3_Pin, 0);

	HAL_GPIO_WritePin(KB_C1_GPIO_Port, KB_C1_Pin | KB_C2_Pin | KB_C3_Pin, 1);

	switch (keyboard)
	{
		case KB_0:
			key = 0;
			break;

		case KB_1:
			key = 1;
			break;

		case KB_2:
			key = 2;
			break;

		case KB_3:
			key = 3;
			break;

		case KB_4:
			key = 4;
			break;

		case KB_5:
			key = 5;
			break;

		case KB_6:
			key = 6;
			break;

		case KB_7:
			key = 7;
			break;

		case KB_8:
			key = 8;
			break;

		case KB_9:
			key = 9;
			break;

		case KB_STAR:
			key = 0x0A;
			break;

		case KB_NUM:
			key = 0x0B;
			break;

		default:
			key = KB_DEFAULT;
			break;
	}
	return(key);
}
