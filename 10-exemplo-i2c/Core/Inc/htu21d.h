/*
 * htu21d.h
 *
 *  Created on: Aug 10, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_HTU21D_H_
#define INC_HTU21D_H_

#include "i2c.h"

#define HTU_ADDR 	   			(0x40 << 1)	// Endereço I2C do sensor
											// (HAL requer que seja deslocado 1 bit à esquerda)

// Registradores do sensor
#define HTU_CMD_TEMP_HOLD		0xE3
#define HTU_CMD_HUMID_HOLD		0xE5
#define HTU_CMD_TEMP			0xF3
#define HTU_CMD_HUMID			0xF5
#define HTU_CMD_WRITE_USER_REG	0xE6
#define HTU_CMD_READ_USER_REG	0xE7
#define HTU_CMD_RESET			0xFE

HAL_StatusTypeDef	HTU_reset(void);
 int16_t 			HTU_getTemperature(void);
uint16_t 			HTU_getHumidity(void);

#endif /* INC_HTU21D_H_ */

// Datasheet do componente:
// https://www.te.com/usa-en/product-CAT-HSC0004.html
// https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FHPC199_6%7FA6%7Fpdf%7FEnglish%7FENG_DS_HPC199_6_A6.pdf%7FCAT-HSC0004
