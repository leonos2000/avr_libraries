/*
 * hct574.h
 *
 *  Created on: 29.01.2017
 *      Author: Leon
 */

#ifndef HCT574_HCT574_H_
#define HCT574_HCT574_H_

#include <stdbool.h>
#include <avr/io.h>

/*
 * Macros for user to define data dirs, ports and pins.
 */
#define HCT574_D0_DDR		DDRC
#define HCT574_D0_PORT		PORTC
#define HCT574_D0_PIN		0

#define HCT574_D1_DDR		DDRC
#define HCT574_D1_PORT		PORTC
#define HCT574_D1_PIN		1

#define HCT574_D2_DDR		DDRC
#define HCT574_D2_PORT		PORTC
#define HCT574_D2_PIN		3

#define HCT574_D3_DDR		DDRB
#define HCT574_D3_PORT		PORTB
#define HCT574_D3_PIN		1

#define HCT574_D4_DDR		DDRB
#define HCT574_D4_PORT		PORTB
#define HCT574_D4_PIN		0

#define HCT574_D5_DDR		DDRD
#define HCT574_D5_PORT		PORTD
#define HCT574_D5_PIN		0

#define HCT574_D6_DDR		DDRD
#define HCT574_D6_PORT		PORTD
#define HCT574_D6_PIN		1

#define HCT574_D7_DDR		DDRB
#define HCT574_D7_PORT		PORTB
#define HCT574_D7_PIN		2

#define HCT574_EN_DDR		DDRD
#define HCT574_EN_PORT		PORTD
#define HCT574_EN_PIN		7

/*
 * Set HCT574 communication pins to output.
 */
void hct574Init(void);
/*
 * Send data to HCT574 and display it on the outputs with specified CLK pin.
 */
void hct574Send(uint8_t data, volatile uint8_t* portCLK, uint8_t pinCLK);
/*
 * Enable or disable HCT574 outputs.
 */
void hct574Enable(bool enable);

#endif /* HCT574_HCT574_H_ */
