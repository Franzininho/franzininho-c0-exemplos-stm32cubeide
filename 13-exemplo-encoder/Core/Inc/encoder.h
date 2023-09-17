/*
 * encoder.h
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "main.h"

#define ENCODER_COUNTER_MIN   0
#define ENCODER_COUNTER_MAX 255

#define ENCODER_OUTPUT_MIN	  0
#define ENCODER_OUTPUT_MAX	 20

extern volatile uint16_t encoder_counter;
extern uint16_t encoder_prev_counter;

extern uint8_t flag_encoder_changed;

#endif /* INC_ENCODER_H_ */
