/*
 **************************************************************
 * AM2320_temperature_humidity.c
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

#include <avr/io.h>
#define F_CPU 16000000	// Clock frequency of CPU
#include <util/delay.h>
#include "AM2320_temperature_humidity.h"
#include "i2cmaster.h"

/*
*	AM2320_init()
*	-------------
*	Initialise the AM2320 temperature and humidity sensor.
*/
void AM2320_init() {
	i2c_start_wait(AM2320_ADDR | AM2320_I2C_WRITE);
	i2c_write(0x00); // Just sending a wakeup command
	i2c_stop();
}

/*
*	AM2320_update_temperature_humidity()
*	------------------------------------
*	Read the current temperature and humidity from the 
*	AM2320 sensor. The values are stored in the 
*	TEMPERATURE_HUMIDITY array found in the header file.
*	temperature is in degrees celsius and humidity in
*	% from 0-100
*/
void AM2320_update_temperature_humidity() {
	uint16_t humidity = 0;
	uint16_t temperature = 0;
	
	i2c_start_wait(AM2320_ADDR | AM2320_I2C_WRITE);
	i2c_write(AM2320_COMMAND_READ_REG_DATA);
	i2c_write(AM2320_HUMIDITY_REG_HIGH);
	i2c_write(0x04); // number of registers to read
	i2c_stop();
	
	_delay_ms(2); // Wait for sensor

	i2c_start_wait(AM2320_ADDR | AM2320_I2C_READ);
	i2c_readAck(); // Ignore returned function code.
	i2c_readAck(); // Ignore returned number of bytes
	
	humidity = ((uint16_t)i2c_readAck()) << 8; // High byte of humidity
	humidity |= i2c_readAck(); // Low byte of humidity
	temperature = ((uint16_t)i2c_readAck()) << 8; // High byte of temperature.
	temperature |= i2c_readAck(); // Low byte of temperature.
	
	// Ignore the CRC information.
	i2c_readAck();
	i2c_readNak(); // Read last byte with NAK
	
	i2c_stop();
	
	TEMPERATURE_HUMIDITY[0] = (float)temperature / 10;
	TEMPERATURE_HUMIDITY[1] = (float)humidity / 10;
}

/*
*	AM2320_get_temperature()
*	------------------------
*	Return the last recorded temperature from the sensor.
*/
float AM2320_get_temperature() {
	return TEMPERATURE_HUMIDITY[0];
}

/*
*	AM2320_get_humidity()
*	---------------------
*	Return the last recorded humidity from the sensor.
*/
float AM2320_get_humidity() {
	return TEMPERATURE_HUMIDITY[1];
}
