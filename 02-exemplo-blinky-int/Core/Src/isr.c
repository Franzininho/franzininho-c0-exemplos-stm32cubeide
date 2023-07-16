/*
 * isr.c
 *
 *  Created on: Jul 16, 2023
 *      Author: André A. M. Araújo
 */

#include "isr.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim17)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);	// Inverte saída do LED1 quando ocorre a interrupção (a cada 0,25s)
	}
}
