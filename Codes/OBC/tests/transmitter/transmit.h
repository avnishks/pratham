#ifndef TRANSMIT_H
#define TRANSMIT_H

void cc1020_transmit_packet(uint8_t *data, uint8_t size);
void cc1020_init_dio(void);
void cc1020_transmit_bit(uint8_t bit);

#define DIO		PB1	// Connected to DIO pin of CC1020
#define DCLK	PB2	// Connected to DCLK pin of CC1020

#define PORT_TX PORTB
#define DDR_TX DDRB
#define PIN_TX PINB

#endif
