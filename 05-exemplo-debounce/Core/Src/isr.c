/*
 * isr.c
 *
 *  Created on: Jul 23, 2023
 *      Author: André A. M. Araújo
 */

#include "isr.h"

volatile uint8_t 	currentButton  = 0;				// Variáveis para armazenar estado do botão
volatile uint8_t 	previousButton = 0;				//

volatile uint8_t 	debounceCounter = 0;			// Variáveis para algoritmo de debounce
volatile uint8_t  	debouncedButtonPressed  = 0;	//
volatile uint8_t  	debouncedButtonReleased = 0;	//

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)	// Função de callback para tratamento da interrupção externa (subida)
{														// obtida do arquivo "stm32c0xx_hal_gpio"
	if(GPIO_Pin == Button_Pin)		// Quando uma borda de subida do botão é detectada...
	{								// ... Inicia o Timer para o debounce
			initDebounceTimer(Button_Pin);
	}
}

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)	// Função de callback para tratamento da interrupção externa (subida)
{														// obtida do arquivo "stm32c0xx_hal_gpio"
	if(GPIO_Pin == Button_Pin)		// Quando uma borda de descida do botão é detectada...
	{								// ... Inicia o Timer para o debounce
		initDebounceTimer(Button_Pin);
	}
}

void initDebounceTimer(uint16_t GPIO_Pin)		// Função para iniciar timer que fará a base de tempo para debounce
{
	HAL_NVIC_DisableIRQ(EXTI4_15_IRQn);				// Desabilita interrupções externas
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);	// Acende LED1 para indicar detecção de borda
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);				// Limpa flag de interrupção
	HAL_TIM_Base_Start_IT(&htim17);					// Inicia contagem no Timer 17 (intervalo de 1ms)
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim17)	// Timed debounce routine:
	{							//	Após detecção da primeira borda, acumula
								// 	DEBOUNCE_STABLE_PERIOD amostras iguais;
								//  finalmente, seta flag "PRESSED" ou "RELEASED" e
								//	desabilita contador até que ocorra a próxima deteccção
		previousButton = currentButton;
		currentButton  = HAL_GPIO_ReadPin(Button_GPIO_Port, Button_Pin);

		if (currentButton == previousButton)	// Incrementa contador se leitura é estável
		{
			debounceCounter++;
		}
		else									// Reseta contador se leitura é instável
		{
			debounceCounter = 0;
		}

		if (debounceCounter >= DEBOUNCE_STABLE_PERIOD)
		{										// Debounce finalizado
			HAL_TIM_Base_Stop_IT(&htim17);		// Desabilita timer
			debounceCounter = 0;				// Zera contador para debounce

			if (currentButton == 0)				// Ativo em 0
			{
				debouncedButtonPressed = 1;		// Botão pressionado
			}
			else
			{
				debouncedButtonReleased = 1;	// Botão solto
			}

			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);	// Apaga LED1 da indicação de detecção de borda
			HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);				// Ativa interrupções externas
		}
	}
}
