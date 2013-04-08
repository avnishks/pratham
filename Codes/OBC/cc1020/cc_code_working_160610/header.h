
#define F_CPU 8000000 /* oscillator-frequency in Hz */ 
#include <avr/io.h>
#include <avr/interrupt.h>
//#include <inttypes.h>
#include <util/delay.h>
#include <stdio.h>

#define CC1020_TX			// Define as CC1020_TX to configure as Transmitter
// atmega32 Pin Definitions
// Directions: 0-> input; 1-> output

#define TEST_SW	PB0	
#define DIO		PB1	// Connected to DIO pin of CC1020
#define DCLK	PB2	// Connected to DCLK pin of CC1020
#define LOCKpin	PB3	// For Carrier sense indication. Not used

#define SS_bar	PB4	// SS*-->PSEL
#define MOSI	PB5	// MOSI-->PDI
#define MISO	PB6	// MISO<--PDO
#define SCK		PB7	// SCK-->PCLK

#define LED_X	PA0
#define LED_PLL	PA1
#define LED_TEST1 PA2
#define LED_TEST2 PA3
	


//Define Constants

#define FALSE 0
#define TRUE 1
#define CAL_ATTEMPT_MAX   4	// Maximum number of re-calibration attempts upon calibration failure


volatile char TXBUFFER[64];
volatile char RXBUFFER[64];
int curr_buffer_index, curr_byte;
int no_bytes_tosend;				// Total no. of bytes to be transmitted
int no_databytes_toread;			// No. of Data bytes to read after SOF2 and no. of bytes.
int rxcount;						// Total no. of bits received
#define SOF_1 0xD3
#define SOF_2 0x91
#define flag 0x7E

#define poly    0x1021          /* crc-ccitt mask */


//Define common functions
#define sbi(x,y) (x |= (1<<y))
#define cbi(x,y) (x &= ~(1<<y))
