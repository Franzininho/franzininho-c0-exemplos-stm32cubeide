/*
 * isr.h
 *
 *  Created on: Jul 16, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_ISR_H_
#define INC_ISR_H_

#include "gpio.h"
#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);	// Função de retorno da interrupção de timers

#endif /* INC_ISR_H_ */
