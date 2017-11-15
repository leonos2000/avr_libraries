/*
 * i2c_twi.h
 *
 *  Created on: 2010-09-07
 *       Autor: Miros³aw Kardaœ
 */

#ifndef I2C_TWI_H_
#define I2C_TWI_H_

#include <avr/io.h>


#define __BITRATE 			100000

#define TWI_WRITE 			0x00
#define TWI_READ 			0x01

#define BITRATE ( F_CPU / __BITRATE )

/*
 * Initialise twi module with bitrate specified
 * in __BITRATE macro.
 */
void twiInit(void);

/*
 * Connect to a new slave with given address. Last
 * bit determinate if it is transmitting or
 * receiving communication.
 */
void twiStart(uint8_t addr);
/*
 * Disable twi module and disconnect from I2C bus.
 */
void twiStop(void);
/*
 * Write one byte to the slave.
 */
void twiWrite(uint8_t data);
/*
 * Get one byte from a slave and send to it request
 * for next data byte.
 */
uint8_t twiReadAck(void);
/*
 * Get one byte from a slave and not requesting for
 * net data byte.
 */
uint8_t twiReadNack(void);

/*
 * Send specified length of bytes to the slave on
 * specified address.
 */
void twiTx(uint8_t addr, uint8_t *data, uint8_t len);
/*
 * Get specified length of bytes from the slave on
 * specified address.
 */
void twiRx(uint8_t addr, uint8_t *data, uint8_t len);

#endif /* I2C_TWI_H_ */
