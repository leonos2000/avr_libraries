/*
 *  ds3231.c
 *
 *  Created on: 03.07.2016
 * 		Author: Leon Czajka
 *
 */

#include "ds3231.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../I2C/i2c.h"


void dsInit(void) {
	uint8_t ctrl = 0;

	twiInit();
	twiStart(DS3231 + TWI_WRITE);
	twiWrite(0x0e);
	twiRx(DS3231 + TWI_WRITE, &ctrl, 1);

	EICRA |= (1<<ISC01) | (1<<ISC00);
	EIMSK |= (1<<INT0);
	sei();
}

void dsGetData(dsData* data) {
	uint8_t buf[7];
	twiStart(DS3231 + TWI_WRITE);
	twiWrite(0x00);
	twiRx(DS3231 + TWI_READ, buf, 7);

	uint8_t* ptr = (uint8_t*) data;

	for (uint8_t i = 0; i < 7; i++) {
		*(ptr++) = bcd2dec(buf[i]);
	}
}

void dsSetTime(uint8_t hh, uint8_t mm, uint8_t ss) {
	uint8_t buf[3];
	buf[0] = dec2bcd(ss);
	buf[1] = dec2bcd(mm);
	buf[2] = dec2bcd(hh);

	twiStart(DS3231 + TWI_WRITE);
	twiWrite(0x00);
	twiTx(DS3231 + TWI_WRITE, buf, 3);
}

void dsSetDate(uint8_t year, uint8_t month, uint8_t day, uint8_t dayofweek) {
	uint8_t buf[4];
	buf[0] = dayofweek;
	buf[1] = dec2bcd(day);
	buf[2] = dec2bcd(month);
	buf[3] = dec2bcd(year);

	twiStart(DS3231 + TWI_WRITE);
	twiWrite(0x03);
	twiTx(DS3231 + TWI_WRITE, buf, 4);
}

uint8_t dec2bcd(uint8_t dec) {
	return ( ( dec / 10 ) << 4 ) | ( dec % 10 );
}

uint8_t bcd2dec(uint8_t bcd) {
    return ( ( ( bcd >> 4 ) & 0x0F ) * 10 ) + ( bcd & 0x0F );
}
