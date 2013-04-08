#include "common.h"
#include "eeprom.h"
#include "uart.h"
#include<stdio.h>

static uint32_t read_addr = 2222, write_addr = 2222;
#define MAX_ADDR 65536
#define FRAME_SIZE 5

int write_frame_to_eeprom(uint8_t *frame)
{
  //correct the eeprom function for supporting 32-bit addresses
  static uint8_t start = 0;
  uint8_t x;
  
  //if((write_addr == read_addr) && start)
    //read_addr += FRAME_SIZE;
    
  x = eeprom_write_bytes((uint16_t)write_addr, FRAME_SIZE,frame);
  write_addr += FRAME_SIZE;
  
  if(write_addr + FRAME_SIZE > MAX_ADDR)
    write_addr = 0;
  
  start = 1;
  
  return x;
}

int read_frame_from_eeprom(uint8_t *frame)
{
  uint8_t x;
  x = eeprom_read_bytes((uint16_t)read_addr, FRAME_SIZE, frame);
  read_addr += FRAME_SIZE;
  
  if(read_addr + FRAME_SIZE > MAX_ADDR)
    read_addr = 0;
    
  return x;
}



int main(void)
{
  uint8_t frame[100]; 
  
  ioinit();
  init_UART();
  send_UART("Hi\r",3  );
  uint8_t i, j;
  
  /*for(i = 0;i < 6; i++)
  {
    for(j = 0;j < FRAME_SIZE; j++)
      frame[j] = j * (i + 1);
    write_frame_to_eeprom(frame);
  }*/
   
  for(i = 0;i < 6; i++)
  {
    read_frame_from_eeprom(frame);
    send_UART(frame, FRAME_SIZE);
  }
  return 0;
}
