/*
 * keyboard.h
 *
 *  Created on: Sep 10, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_

#include "gpio.h"

//
//	  C   C   C
//	  1   2   3
//	┌───┬───┬───┐
//	│ 1 │ 2 │ 3 │ R1
//	├───┼───┼───┤
//	│ 4 │ 5 │ 6 │ R2
//	├───┼───┼───┤
//	│ 7 │ 8 │ 9 │ R3
//	├───┼───┼───┤
//	│ * │ 0 │ # │ R4
//  └───┴───┴───┘
//
//	Fonte para elaborar desenho acima: https://asciiflow.com/
//	Datasheet do componente: Pasta "\Datasheets\"
//

#define KB_0 		0x0001	// 0
#define KB_1 		0x0002	// 1
#define KB_2 		0x0004	// 2
#define KB_3 		0x0008	// 3
#define KB_4 		0x0010	// 4
#define KB_5 		0x0020	// 5
#define KB_6 		0x0040	// 6
#define KB_7 		0x0080	// 7
#define KB_8 		0x0100	// 8
#define KB_9 		0x0200	// 9
#define KB_STAR		0x0400	// *
#define KB_NUM		0x0800	// #

#define KB_DEFAULT	0x80	// Leitura do teclado se nenhuma tecla é pressionada
#define BUTTON_MASK 0x10	// Máscara para botão da Franzininho C0 (pino A8)
#define BUTTON_LSH	4		// Bits necessários para deslocar (à esrquera) a leitura do botão até a posição da máscara BUTTON_MASK

extern uint8_t key;

uint8_t KB_scan(void);

#endif /* INC_KEYBOARD_H_ */
