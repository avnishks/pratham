#include "common.h"
#include "spi.h"
#include "transmit.h"
#include "ax25.h"
#include "functions.h"
#include "uart.h"
int main()
{
  uint8_t frame[100], x, buf[100], i, j = 0;
  
  init_UART();
  send_UART("Hi\r\n", 3);
  
  init_SPI();
  cc1020_init_dio();
  
  x = init_CC1020();
  sprintf(frame, "%d Done1\r\n", x);
  send_UART(frame, strlen(frame));
  
  sprintf(buf, "Number");
  i = strlen(buf);
  buf[i - 1] = 0x7e;
  
  while(1) 
  {
    buf[i] = j;
    make_ax25_frame_from_data(frame, buf);
    cc1020_transmit_packet(frame, FRAME_SIZE);
    send_UART("A", 1);
    _delay_ms(2000);
    j++;
  }
  return 0;
}
