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

float TEMPERATURE_HUMIDITY[2];

void AM2320_init();
void AM2320_update_temperature_humidity();
float AM2320_get_temperature();
float AM2320_get_humidity();

#endif /* AM2320_TEMPERATURE_HUMIDITY_H_ */