/*
 * htu21d.c
 *
 *  Created on: Aug 10, 2023
 *      Author: André A. M. Araújo
 */

#include "HTU21D.h"

HAL_StatusTypeDef HTU_reset(void)
{
	uint8_t buffer[1] = {0};
	HAL_StatusTypeDef status = HAL_ERROR;

	buffer[0] = HTU_CMD_RESET;
	status = HAL_I2C_Master_Transmit(&hi2c1, HTU_ADDR, buffer, 1, 5);

	HAL_Delay(15);	// Reset do sensor leva menos de 15 ms

	return(status);	// Retorna sucesso ou falha na transmissão I2C
}

int16_t HTU_getTemperature(void)
{
	uint8_t buffer[3] = {0, 0, 0};
	float T = 0.0;
	int16_t temperature = 0;

	buffer[0] = HTU_CMD_TEMP;
	HAL_I2C_Master_Transmit(&hi2c1, HTU_ADDR, buffer, 1, 5);
	HAL_Delay(50);
	HAL_I2C_Master_Receive(&hi2c1, HTU_ADDR, buffer, 3, 5);

	temperature = (buffer[0] << 8) | (buffer[1] & 0xFC);
	T = (175.72 * temperature) / 65536.0 - 46.85;

	temperature = (int16_t)(T * 100);
	return(temperature);
}

uint16_t HTU_getHumidity(void)
{
	uint8_t buffer[3] = {0, 0, 0};
	float RH = 0.0;
	uint16_t humidity = 0;

	buffer[0] = HTU_CMD_HUMID;
	HAL_I2C_Master_Transmit(&hi2c1, HTU_ADDR, buffer, 1, 5);
	HAL_Delay(16);
	HAL_I2C_Master_Receive(&hi2c1, HTU_ADDR, buffer, 3, 5);

	humidity = (buffer[0] << 8) | (buffer[1] & 0xFC);
	RH = (125 * humidity) / 65536.0 - 6;

	humidity = (uint16_t)(RH * 10);
	return(humidity);
}
