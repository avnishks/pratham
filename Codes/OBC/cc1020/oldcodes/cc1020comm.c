/*
  Program for communication using CC1020.
  Author: Nikunj A.Bhagat, M.Tech, EE Dept, IIT Bombay
*/


/*
  Important: Refer pin assignment in header file.
*/

#include "spi.h"
#include "cc1020.h"

int init_CC1020 (void){
  init_SPI_trans(CC1020);
  SetupCC1020PD();
  ResetCC1020();//CC is still in PD (Power_Down mode) after reset
  SetupCC1020Allregisters();
  WakeUpCC1020ToTX(TXANALOG);
  return CalibrateCC1020 (PA_POWER);
}
/*
  This function transmit one packet from CC1020. To tranmsit multiple times call this function multiple times
*/

void Transmit_CC1020(char* str, int size)
{
  
  /// @note DCLK from CC1020
  /// @todo DIO pin to be assigned. Set DIO as output
  int count;
  ///* Wake up CC1020 for transmission
  WakeUpCC1020ToTX(TXANALOG);	
  ///* Check PLL again. @todo How to handle any failures here?
  if(!SetupCC1020TX(TXANALOG,PA_POWER))
    {
      //sprintf(array,"\n\rPLL LOCK failed");
      //usart_transmit(array);
    }
		
  //sprintf(array,"\n\rTransmitting .....\n");
  //usart_transmit(array);
	
  count = Transmitpacket(str,size); //Monitors clock
  		
  WriteToCC1020Register(CC1020_MAIN,0x1F);  // configure in PD and stop Transmission				

  //sprintf(array,"\n\rTrans complete;count=%d",counter);
  //usart_transmit(array);
}

// Sample main program 
/*
int main(void)
{
  int t = init_CC1020();
  if(t == 0){
    //ERROR 
  }
  Transmit_CC1020();
  return 0;
}
*/
