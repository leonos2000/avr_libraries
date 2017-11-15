/*
 *  hct574.cpp
 *
 *  Created on: 03.07.2016
 * 		Author: Leon Czajka
 *
 */
#include "hct574.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>


void hct574Init(void) {
	HCT574_D0_DDR |= (1<<HCT574_D0_PIN);
	HCT574_D1_DDR |= (1<<HCT574_D1_PIN);
	HCT574_D2_DDR |= (1<<HCT574_D2_PIN);
	HCT574_D3_DDR |= (1<<HCT574_D3_PIN);
	HCT574_D4_DDR |= (1<<HCT574_D4_PIN);
	HCT574_D5_DDR |= (1<<HCT574_D5_PIN);
	HCT574_D6_DDR |= (1<<HCT574_D6_PIN);
	HCT574_D7_DDR |= (1<<HCT574_D7_PIN);
	HCT574_EN_DDR |= (1<<HCT574_EN_PIN);
}


void hct574Send(uint8_t data, volatile uint8_t* portCLK, uint8_t pinCLK) {
	volatile uint8_t *port[8];
	uint8_t pins[8];

	port[0] = &HCT574_D0_PORT;
	port[1] = &HCT574_D1_PORT;
	port[2] = &HCT574_D2_PORT;
	port[3] = &HCT574_D3_PORT;
	port[4] = &HCT574_D4_PORT;
	port[5] = &HCT574_D5_PORT;
	port[6] = &HCT574_D6_PORT;
	port[7] = &HCT574_D7_PORT;

	pins[0] = HCT574_D0_PIN;
	pins[1] = HCT574_D1_PIN;
	pins[2] = HCT574_D2_PIN;
	pins[3] = HCT574_D3_PIN;
	pins[4] = HCT574_D4_PIN;
	pins[5] = HCT574_D5_PIN;
	pins[6] = HCT574_D6_PIN;
	pins[7] = HCT574_D7_PIN;


	for (uint8_t i=0;i<8;i++) {
		*port[i] &= ~(1<<pins[i]);
		*port[i] |= ( data & (1<<i) ) ? (1<<pins[i]) : 0;
	}
	*portCLK |= (1<<pinCLK);
	*portCLK &= ~(1<<pinCLK);
}

void hct574Enable(bool enable) {
	if (!enable) HCT574_EN_PORT |= (1<<HCT574_EN_PIN);
	else HCT574_EN_PORT &= ~(1<<HCT574_EN_PIN);
}
