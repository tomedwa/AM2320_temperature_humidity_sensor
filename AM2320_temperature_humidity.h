/*
 **************************************************************
 * AM2320_temperature_humidity.h
 * Author: Tom
 * Date: 18/01/2023
 * AVR Library for the AM2320 temperature and humidity
 * sensor. This lib requires the Peter Fleury i2cmaster 
 * interface.
 **************************************************************
 * EXTERNAL FUNCTIONS
 **************************************************************
 * AM2320_init() - Initialise the AM2320.
 * AM2320_update_temperature_humidity() - Update the current
 * readings for temperature and humidity.
 * AM2320_get_temperature() - Get the current reading for temp.
 * AM2320_get_humidity() - Get current reading for humidity.
 **************************************************************
*/

#ifndef AM2320_TEMPERATURE_HUMIDITY_H_
#define AM2320_TEMPERATURE_HUMIDITY_H_

#define AM2320_ADDR			0xB8
#define AM2320_I2C_READ			0x01
#define AM2320_I2C_WRITE		0x00
#define AM2320_COMMAND_READ_REG_DATA	0x03
#define AM2320_HUMIDITY_REG_HIGH	0x00
#define AM2320_HUMIDITY_REG_LOW		0x01
#define AM2320_TEMP_REG_HIGH		0x02
#define AM2320_TEMP_REG_LOW		0x03

// Index 0 = temperature, 1 = humidity.
float TEMPERATURE_HUMIDITY[2];

void AM2320_init();
void AM2320_update_temperature_humidity();
float AM2320_get_temperature();
float AM2320_get_humidity();

#endif /* AM2320_TEMPERATURE_HUMIDITY_H_ */