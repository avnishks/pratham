/**
 * @file master.c
 * @brief Main file for master uC.
 * 
 * Contains the scheduler, preflight check routines, high level task blocks like power, control and communication.
 */

#include "common.h"
#include "spi.h"
#include "timer.h"
#include "peripherals.h"
#include "mag.h"
#include "gps.h"
#include "hm.h"
#include "slave_comm.h"
#include "comm.h"
#include "controller.h"
#include "ax25.h"
#include<stdio.h>

/// @todo Write Error checking codes to ensure the OBC does not go into infinite loops

/**
 * @defgroup global_state Global State parameters
 */
//@{
volatile uint8_t GPS_done = -1;
uint8_t Mode;
uint64_t Time;
volatile struct state Current_state;
//@}

int main(void)
{
  _delay_ms(1000);
  char buf[10], a = 0;
  
  init_UART_MM();
  send_MM_cmd("Hi\r", 0);
  
  init_SPI();
  
  Current_state.gps.x = 1;
  Current_state.gps.y = 2;
  Current_state.gps.z = 3;
  
  while(1)
  {
    _delay_ms(2000);
    a++;
    sprintf(buf, "sent %d", a);
    send_MM_cmd(buf, 0);
    slave_send (HM_DATA, (char *)&Current_state, sizeof (struct state));
  }
  
  return 0;
}
