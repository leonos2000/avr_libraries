/*
 * ds3231.h
 *
 *  Created on: 27.01.2017
 *      Author: Leon
 */

#ifndef DS3231_DS3231_H_
#define DS3231_DS3231_H_

#include <avr/io.h>

/*
 * Set DS3231 address, in common devices it is 0xD0.
 */
#define DS3231 0xD0

/*
 * Struct witch all data received from ds3231 for user.
 */
typedef struct{
	uint8_t ss;			// Seconds
	uint8_t mm;			// Minutes
	uint8_t hh;			// Hours
	uint8_t wd;			// Day of week
	uint8_t dd;			// Day
	uint8_t mo;			// Month
	uint8_t yy;			// Year
	int8_t 	dg;			// Celsius degrees
	uint8_t fd;			// Fract celsius degrees
} dsData;

/*
 * Initialise DS3231 module.
 */
void dsInit(void);
/*
 * Get data from DS3231 and store it in dsData struct.
 */
void dsGetData(dsData* data);
/*
 * Set time directly into DS3231.
 */
void dsSetTime(uint8_t hh, uint8_t mm, uint8_t ss);
/*
 * Set date directly into DS3231.
 */
void dsSetDate(uint8_t year, uint8_t month, uint8_t day, uint8_t dayofweek);

uint8_t dec2bcd(uint8_t dec);
uint8_t bcd2dec(uint8_t bcd);

#endif /* DS3231_DS3231_H_ */
