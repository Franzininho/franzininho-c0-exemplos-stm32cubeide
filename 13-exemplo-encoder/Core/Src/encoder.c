/*
 * encoder.c
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#include "encoder.h"

volatile uint16_t encoder_counter = 0;
uint16_t encoder_prev_counter = 0;
int16_t encoder_output = 0;

uint8_t flag_encoder_changed = 0;
