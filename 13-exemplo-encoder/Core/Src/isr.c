/*
 * isr.c
 *
 *  Created on: Sep 10, 2023
 *      Author: André A. M. Araújo
 */

#ifndef SRC_ISR_C_
#define SRC_ISR_C_

#include "isr.h"

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	encoder_counter = __HAL_TIM_GET_COUNTER(htim);
	flag_encoder_changed = 1;
}

#endif /* SRC_ISR_C_ */
