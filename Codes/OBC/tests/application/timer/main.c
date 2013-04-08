#include "common.h"
#include "timer.h"
#include "uart.h"

int main(void)
{
  int Time = 0;
  char buf[100];
  
  init_UART();
  send_UART((uint8_t *)"Hi\r\n", 4);
    timer_reset_two_sec();
    ///Loop begins
    while(1){
      sprintf(buf, "Timer: %u sec\r\n", Time);
      send_UART((uint8_t *)buf, strlen(buf));
      Time += FRAME_TIME;
      timer_wait_reset();
    }
  return 0;
}
