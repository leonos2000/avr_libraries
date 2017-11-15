/*
 * i2c_twi.c
 *
 *  Created on: 2010-09-07
 *       Autor: Miros³aw Kardaœ
 */

#include "i2c.h"

#include <avr/io.h>

void twiInit(void) {
	TWBR = ( BITRATE >= 16 ) ? ( ( BITRATE - 16 ) / 2 ) : ( BITRATE );
}

void twiStart(uint8_t addr) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while ( !( TWCR & (1<<TWINT) ) );

	twiWrite(addr);
}

void twiStop(void) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

uint8_t twiReadAck(void) {
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while ( !( TWCR & (1<<TWINT) ) );
	return TWDR;
}

uint8_t twiReadNack(void) {
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ( !( TWCR & (1<<TWINT) ) );
	return TWDR;
}

void twiWrite(uint8_t data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ( !( TWCR & (1<<TWINT) ) );
}

void twiTx(uint8_t addr, uint8_t *data, uint8_t len){
	twiStart(addr);
	while (len--) twiWrite(*data++);
	twiStop();
}

void twiRx(uint8_t addr, uint8_t *data, uint8_t len) {
	twiStart(addr);
	while (len--) *data++ = len ? twiReadAck() : twiReadNack();
	twiStop();
}
