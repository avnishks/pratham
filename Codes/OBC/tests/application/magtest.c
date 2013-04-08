#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h>
#include<math.h>
#include<stdio.h>


float B_x, B_y, B_z;

void send_data(char *data, uint16_t size)
{
  uint16_t i = 0;
  
  ///Loop through the data
  while(i < size)
  {
    ///* Wait for empty transmit buffer 
    while ( !(UCSRA & (_BV(UDRE))) );
    ///* Start transmission
    UDR = data[i];
    i++;
  }
}

void init_UART_sensor(void )
{

  UCSRA = 0;
  UCSRB = 0;
  UCSRC = 0;
  
  ///* Double Baud Rate
  UCSRA |= _BV(U2X);
  ///* Enable Transmission and Reception
  UCSRB |=  _BV(TXEN) | _BV(RXEN);
  ///* 8-bit Data Byte
  UCSRC |= _BV(URSEL) | _BV(UCSZ1) | _BV(UCSZ0);
  ///* Set Baud Rate to 9600
  UBRRL = 207;
  UBRRH = 0;
}

uint8_t receive_UART(void)
{
  while ((UCSRA & (1 << RXC)) == 0);
  return UDR;
}

///Check if interrupts should be used or not, will depend on how the magnetometer
///readings are used to calculate omega



void send_MM_cmd(char *data, uint8_t lines)
{
  char a, i;
  ///Send the char array till stop
  while((*data) != '\0')
  {
    ///* Wait for empty transmit buffer 
    while ( !(UCSRA & (_BV(UDRE))) );
    ///* Start transmission
    UDR = *data;
    data++;
  }
  
  ///Check whether to wait for the response or not
  for(i = 0; i < lines; i++)
    while((a = receive_UART()) != '\r');
}

void poll_MM(void)
{
  int16_t x, y, z;
  
  send_MM_cmd("*00P\r", 0);
  
  x = ((int16_t)receive_UART()) << 8;
  x &= 0xFF00;
  x |= (int16_t)receive_UART();
  
  
  y = ((int16_t)receive_UART()) << 8;
  y &= 0xFF00;
  y |= (int16_t)receive_UART();
  
  z = ((int16_t)receive_UART()) << 8;
  z &= 0xFF00;
  z |= (int16_t)receive_UART();
  
  receive_UART();
  
  B_x = ((float) x) / 15000;
  B_y = ((float) y) / 15000;
  B_z = ((float) z) / 15000;
}


void configure_MM(void)
{
  /// <b>Initialization commands</b>

  ///Baud Rate-> Set baud rate=9600 bps
  send_MM_cmd("*99WE\r", 1);
  send_MM_cmd("*99!BR=S\r", 2);
  ///Device ID-> Set device ID=00
  send_MM_cmd("*99WE\r", 1);
  send_MM_cmd("*99ID=00\r", 1); 
  ///Format-> Turn Binary Mode on mode on
  send_MM_cmd("*00WE\r", 1);
  send_MM_cmd("*00B\r", 1);
  
  
  ///Output-> Turn polling mode on
  send_MM_cmd("*00P\r", 1);
  
  ///Turn off Zero reading
  send_MM_cmd("*00WE\r", 1);
  send_MM_cmd("*00ZF\r", 1);

  ///S/R Mode-> Automatic S/R Pulses
  send_MM_cmd("*00WE\r", 1);
  send_MM_cmd("*00TN\r", 1);
  ///Average Readings-> Turn average off
  send_MM_cmd("*00WE\r", 1);
  send_MM_cmd("*00VF\r", 1);
  ///Store parameters: Paramters reloaded on restoring power.
  send_MM_cmd("*00WE\r", 1);
  send_MM_cmd("*00SP\r", 2);
}



int main(void)
{
  char a, b[100];
  uint8_t i = 0;
  
  DDRC = 0xff;
  PORTC = 0x01;
  init_UART_sensor();

  configure_MM();
  
  send_MM_cmd("*00Q\r", 0);
  while((a = receive_UART()) != '\r')
    b[i++] = a;
  b[i++] = '\r';
  b[i] = '\0';
  
  poll_MM();
  
  PORTC = 0xff;
  
  for(a=0;a<10;a++)
  _delay_ms(3000);
  
  PORTC = 0x00;
  
  send_MM_cmd(b, 0);
  
  send_data((char *)&B_x, sizeof(float));
  send_data((char *)&B_y, sizeof(float));
  send_data((char *)&B_z, sizeof(float));
  
  while(1);
}
