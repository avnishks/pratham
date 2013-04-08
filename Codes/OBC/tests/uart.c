#define F_CPU 16000000 /* oscillator-frequency in Hz */ 
#include<avr/io.h>
void init_UART_MM(void)
{

  UCSR1A = 0;
  UCSR1B = 0;
  UCSR1C = 0;
  
  ///Double Baud Rate
  UCSR1A |= _BV(U2X1);
  ///Enable Transmission and Reception
  UCSR1B |= _BV(TXEN1) | _BV(RXEN1);
  ///8-bit Data Byte
  UCSR1C |= _BV(UCSZ11) | _BV(UCSZ10);
  ///Set Baud Rate to 9600
  UBRR1L = 207;
  UBRR1H = 0;
}

void send_UART(char *data)
{
  ///Send the char array till stop
  while((*data) != '\0')
  {
    ///* Wait for empty transmit buffer 
    while ( !(UCSR1A & (_BV(UDRE1))) );
    ///* Start transmission
    UDR1 = *data;
    data++;
  }
}

