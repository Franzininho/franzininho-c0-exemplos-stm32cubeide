/*
 * isr.h
 *
 *  Created on: Sep 10, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_ISR_H_
#define INC_ISR_H_

#include "gpio.h"
#include "tim.h"

#define	DEBOUNCE_STABLE_PERIOD	20					// Período para debounce em ms

extern volatile uint8_t currentButton;				// Variáveis para armazenar estado do botão
extern volatile uint8_t previousButton;				//

extern volatile uint8_t debounceCounter;			// Variáveis para algoritmo de debounce
extern volatile uint8_t debouncedButtonPressed;		//
extern volatile uint8_t debouncedButtonReleased;	//

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin);
void initDebounceTimer(uint16_t GPIO_Pin);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_ISR_H_ */
