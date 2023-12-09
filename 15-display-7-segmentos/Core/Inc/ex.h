/*
 * ex.h
 *
 *  Created on: Dec 9, 2023
 *      Author: André A. M. Aráújo
 */

#ifndef INC_EX_H_
#define INC_EX_H_

#include "main.h"
#include "tim.h"

#define SEG_A		GPIO_PIN_0	//  Display de 7 segmentos
#define	SEG_B   	GPIO_PIN_1	//          ___
#define SEG_C   	GPIO_PIN_2	//       F | A | B
#define SEG_D   	GPIO_PIN_3	//         |___|
#define SEG_E   	GPIO_PIN_4	//       E | G | C
#define SEG_F   	GPIO_PIN_5	//         |___| .
#define SEG_G   	GPIO_PIN_6	//           D   DOT

#define	DOT 		0x0000		//	Não utilizado neste exemplo

#define SEG_MASK	0x007F		// Todos os pinos de 0 a 6

#define SEG_DIGITS	6

extern volatile uint8_t current_digit;
extern volatile uint32_t current_value;

void 		HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

uint16_t	EX_DecimalToSevenSeg (uint8_t decimal);

void		EX_DisplayDigit (uint8_t digit, uint32_t value);

void EX_Run(void);

#endif /* INC_EX_H_ */
