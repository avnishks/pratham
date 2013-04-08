/**
 * @file sun.c
 * @brief Read the ADC values for the Sun sensors
 */

#include "common.h"
#include "sun.h"
#include "spi.h"

void init_UART(void)
{
    UCSRA = 0;
    UCSRB = 0;
    UCSRC = 0;
    
    UCSRA |= (1<<U2X);
    UCSRB|=(1<<RXEN)|(1<<TXEN);
    UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

    UBRRL = 207;
    UBRRH = 0;
}
void send_UART(char *data)
{
    uint16_t i = 0;
    while(data[i] != '\0')
    {
        while ( !(UCSRA & (_BV(UDRE))) );
        UDR = data[i];
        i++;
    }
}
  


uint16_t reading[6];

void configure_SS(void)
{
  ///Set PD and range pins as output
  sbi(DDRB, PB2);
  sbi(DDRB, PB3);
  
  ///Set PD high: power up the ADC IC
  sbi(PORTB, PB2);
  
  /*
  ///Configure Auto-2 Mode
  
  ///Program the Program register of Auto-2 Mode:
  
  SPI_transfer(0b10010001);
  
  SPI_transfer(0b01000000);
  
  ///Configure GPIO pins - GPIO3 as PD and GPIO2 as range input
  SPI_transfer(0b01000001);
  
  SPI_transfer(0b10000000);
  
  ///Set Mode to Auto-2
  
  SPI_transfer(0b00111100);
  
  SPI_transfer(0b00000000);
  
  SPI_transfer(0b00111000);
  
  SPI_transfer(0b00000000);*/
}

void poll_SS(void)
{
  uint8_t channel = 0;
  
  ///Loop for reading the 6 sun sensor values
  while(channel < 1)
  {
      cbi(PORTB, ADC_S);
    ///* Put the ADC reading in the appropriate variable
    reading[channel] = SPI_transfer(0x00);
    reading[channel] = reading[channel] << 8;
    reading[channel] &= 0x0F00;
     reading[channel] |= SPI_transfer(0x00);
    channel++;
    sbi(PORTB, ADC_S);
}
  ///Power Down PD low
  cbi(PORTB, PB2);
  
}

int main(void)
{
  char buf[100];
  
  init_UART();
  
  send_UART("Hi\r");
  
  init_SPI();
  
  _delay_ms(100);
  
  while(1)
  {
      
    configure_SS();
    
    poll_SS();
    
  sprintf(buf, "%d\r", reading[0]);
    //sprintf(buf, "%d %d %d %d %d %d\r", reading[0], reading[1], reading[2], reading[3], reading[4], reading[5]);
    send_UART(buf);
    _delay_ms(1000);
  }
  
  return 0;
}
