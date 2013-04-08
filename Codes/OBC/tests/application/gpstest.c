
/**
 * @file gps.c
 * @brief Read the GPS data using a UART interrupt
 */
#define F_CPU 16000000
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include<stdio.h>
#include<string.h>


struct GPS_reading{
  ///* Position data bytes: Long(4) Unit(mm) ECEF Frame
  int32_t x;
  int32_t y;
  int32_t z;
  
  ///* Velocity data bytes: Long(4) Unit(mm/s) ECEF Frame
  int32_t v_x;
  int32_t v_y;
  int32_t v_z;
  
  ///* Latitude Longitude Altitude
  int32_t lat;
  int32_t lon;
  int32_t alt;
  
  ///* Time data HH:MM:SS DD/MM/YYYY
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
  
  uint8_t date;
  uint8_t month;
  uint16_t year;
  
};


///4-byte buffer for the GPS reading
volatile static uint32_t buffer = 0;
///Position variables for the data in GPS structure
volatile static uint8_t pos = 0xFF,vel = 0xFF,dop = 0xFF,geo = 0xFF, time = 0xFF;
///Variables to check whether the message has ended
volatile static uint8_t last_byte, message_end;
volatile static uint16_t pdop = 0xFFFF;
volatile struct GPS_reading gps;
volatile uint8_t counter = 0;

void init_UART_GPS(void )
{

  UCSRA = 0;
  UCSRB = 0;
  UCSRC = 0;
  
  ///Double Baud Rate
  UCSRA |= _BV(U2X);
  ///Enable Reception
  UCSRB |= _BV(RXEN) | _BV(TXEN) | _BV(RXCIE);
  ///8-bit Data Byte, 2 Stop bits
  UCSRC |= _BV(URSEL) | _BV(USBS) | _BV(UCSZ1) | _BV(UCSZ0);
  ///Set Baud Rate to 9600
  UBRRL = 207;
  UBRRH = 0;
}

/** @brief Interrupt on receiving a byte through UART GPS
 */
ISR(USART_RXC_vect)
{
  ///Buffer the Received Byte
  last_byte = UDR;
  
  ///Put the received byte in the last 4-bytes buffer
  buffer = buffer << 8;
  buffer &= 0xFFFFFF00;
  buffer |= (uint32_t) last_byte;
  
  ///Check if the last byte was for position
  if(pos < 12)
  {
    
    ///* Put the data into the structure
    *((uint8_t *)&gps.x + pos) = last_byte;
    
    ///* Increment position and terminate it if full
    pos++;
    if(pos == 12)
      pos = 0xFF;
  }
  
  ///Check if the last byte was for velocity
  if(vel < 12)
  {
    *((uint8_t *)&gps.v_x + vel) = last_byte;
    
    vel++;
    if(vel == 12)
      vel = 0xFF;
  }
  
  ///Check if the last byte was for PDOP
  if(dop < 4)
  {
    if(dop >= 2)
      *((uint8_t *)&pdop + (dop - 2)) = last_byte;
      
    dop++;
    if(dop == 4)
      dop = 0xFF;
  }
  
  ///Check if the last byte was for Geodetic position
  if(geo < 16)
  {
    if(geo >= 4)
    *((uint8_t *)&gps.lat + (geo - 4)) = last_byte;
    
    geo++;
    if(geo == 16)
      geo = 0xFF;
  }
  
  ///Check if the last byte was for Time
  if(time < 7)
  {
    *((uint8_t *)&gps.hours + time) = last_byte;
    
    time++;
    if(time == 7)
    {
      time = 0xFF;
      ///* * The Entire message has been read
      message_end = 1;
      counter++;
    }
  }
  
  ///Check the buffer against message ID's
  ///Position
  if(buffer == 0x3F3F04AC)
  {
    message_end = 0;
    pos = 0;
  }
  ///Velocity
  else if(buffer == 0x3F3F05AC)
    vel = 0;
  ///DOP
  else if(buffer == 0x3F3F0BAC)
    dop = 0;
  ///Geodetic System
  else if(buffer == 0x3F3F0EAC)
    geo = 0;
  ///Time
  else if(buffer == 0x3F3F0FAC)
    time = 0;
  
  ///Check if PDOP < 500(factor 100), shut off the interrupt and the GPS device
  if((pdop < 500) && (pdop!=0) && message_end)
  {
    ///* Switch off the interrupt
    UCSRB &= ~(_BV(RXCIE));
    
  }
}

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

int main(void)
{
  char a,b[100];
  
  DDRC = 0xFF;
  
  init_UART_GPS();
  
  sei();
  
  PORTC = 0xFF;
  
  while((UCSRB & (1<<RXCIE)) != 0x00);
  
  PORTC = 0x00;
  
  for(a=0;a<10;a++)
    _delay_ms(3000);
    
  PORTC = 0xff;
  
  sprintf(b, "%ld %ld %ld\r", gps.x, gps.y, gps.z);
  a = strlen(b);
  send_data(b, a);
  
  sprintf(b, "%ld %ld %ld\r", gps.v_x, gps.v_y, gps.v_z);
  a = strlen(b);
  send_data(b, a);
  
  sprintf(b, "%ld %ld %ld\r", gps.lat, gps.lon, gps.alt);
  a = strlen(b);
  send_data(b, a);
  
  sprintf(b, "%d:%d:%d %d/%d/%d\r", gps.hours, gps.minutes, gps.seconds, gps.date, gps.month, gps.year  );
  a = strlen(b);
  send_data(b, a);
  
  sprintf(b, "%d %d\r", pdop,counter);
  a = strlen(b);
  send_data(b, a);
  
  while(1);
}
