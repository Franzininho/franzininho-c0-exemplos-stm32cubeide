/*
 * isr.c
 *
 *  Created on: Sep 10, 2023
 *      Author: André A. M. Araújo
 */

#ifndef SRC_ISR_C_
#define SRC_ISR_C_

#include "tim.h"

#include "isr.h"

uint32_t counter = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	counter = __HAL_TIM_GET_COUNTER(htim);
}

#endif /* SRC_ISR_C_ */
