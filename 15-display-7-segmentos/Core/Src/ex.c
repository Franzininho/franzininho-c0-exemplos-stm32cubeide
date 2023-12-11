/*
 * ex.c
 *
 *  Created on: Dec 9, 2023
 *      Author: André A. M. Aráújo
 */

#include <ex.h>

volatile uint8_t current_digit = 1;
volatile uint32_t current_value = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim14)
	{
		EX_DisplayDigit(current_digit, current_value);

		current_digit++;
		if (current_digit > SEG_DIGITS)
		{
			current_digit = 1;
		}
	}
}

uint16_t	EX_DecimalToSevenSeg (uint8_t decimal)
{
	uint16_t display_code = 0;

	//  Display de 7 segmentos
	//          ___
	//       F | A | B
	//         |___|
	//       E | G | C
	//         |___| .
	//           D   DOT

	switch(decimal)
	{
		case 0:
			display_code = SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F;
			break;

		case 1:
			display_code = SEG_B | SEG_C;
			break;

		case 2:
			display_code = SEG_A | SEG_B | SEG_D | SEG_E | SEG_G;
			break;

		case 3:
			display_code = SEG_A | SEG_B | SEG_C | SEG_D | SEG_G;
			break;

		case 4:
			display_code = SEG_B | SEG_C | SEG_F | SEG_G;
			break;

		case 5:
			display_code = SEG_A | SEG_C | SEG_D | SEG_F | SEG_G;
			break;

		case 6:
			display_code = SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
			break;

		case 7:
			display_code = SEG_A | SEG_B | SEG_C;
			break;

		case 8:
			display_code = SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
			break;

		case 9:
			display_code = SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G;
			break;

		default:	// Erro! Retorna "E"
			display_code = SEG_A | SEG_D | SEG_E | SEG_F | SEG_G;
	}
	return display_code;
}

void		EX_DisplayDigit (uint8_t digit, uint32_t value)
{
	uint8_t	display_value = 0;

	HAL_GPIO_WritePin(DIG_1_GPIO_Port, DIG_1_Pin, 1);
	HAL_GPIO_WritePin(DIG_2_GPIO_Port, DIG_2_Pin, 1);
	HAL_GPIO_WritePin(DIG_3_GPIO_Port, DIG_3_Pin, 1);
	HAL_GPIO_WritePin(DIG_4_GPIO_Port, DIG_4_Pin, 1);
	HAL_GPIO_WritePin(DIG_5_GPIO_Port, DIG_5_Pin, 1);
	HAL_GPIO_WritePin(DIG_6_GPIO_Port, DIG_6_Pin, 1);



	switch (digit)
	{
		case 1:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value%10));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_1_GPIO_Port, DIG_1_Pin, 0);
			break;

		case 2:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value%100/10));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_2_GPIO_Port, DIG_2_Pin, 0);
			break;

		case 3:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value%1000/100));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_3_GPIO_Port, DIG_3_Pin, 0);
			break;

		case 4:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value%10000/1000));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_4_GPIO_Port, DIG_4_Pin, 0);
			break;

		case 5:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value%100000/10000));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_5_GPIO_Port, DIG_5_Pin, 0);
			break;

		case 6:
			display_value = EX_DecimalToSevenSeg((uint8_t)(value/100000));
			HAL_GPIO_WriteMultipleStatePin(SEG_A_GPIO_Port, (display_value & SEG_MASK), (display_value ^ SEG_MASK));
			HAL_GPIO_WritePin(DIG_6_GPIO_Port, DIG_6_Pin, 0);
			break;

		default:
			asm("NOP");
			break;
	}
}

void EX_Run(void)
{
	uint32_t	initial_tick = 0;
	uint32_t	current_tick = 0;

	HAL_GPIO_WritePin(DIG_1_GPIO_Port, DIG_1_Pin, 1);
	HAL_GPIO_WritePin(DIG_2_GPIO_Port, DIG_2_Pin, 1);
	HAL_GPIO_WritePin(DIG_3_GPIO_Port, DIG_3_Pin, 1);
	HAL_GPIO_WritePin(DIG_4_GPIO_Port, DIG_4_Pin, 1);
	HAL_GPIO_WritePin(DIG_5_GPIO_Port, DIG_5_Pin, 1);
	HAL_GPIO_WritePin(DIG_6_GPIO_Port, DIG_6_Pin, 1);
	
	initial_tick = HAL_GetTick();

	HAL_TIM_Base_Start_IT(&htim14);

	while(1)
	{
		current_tick = HAL_GetTick();
		if ((current_tick - initial_tick) > 10)
		{
			current_value++;
			initial_tick = HAL_GetTick();
		}
	}
}
