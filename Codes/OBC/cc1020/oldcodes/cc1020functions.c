/*
  All functions related to programming of CC1020
*/

#include "common.h"
#include "cc1020.h"


// Default RF setups, stored in Flash
    
// SmartRF Studio v5.3.0.0

// Device: CC1020

// System parameters:
// X-tal frequency: 14.745600 MHz	Internal
// X-tal accuracy: +/-  5 ppm
// RF frequency A: 434.052500 MHz	Active  	Rx
// RF frequency B: 434.052500 MHz	Inactive	Tx
// Frequency separation: 4.950 kHz
// Data rate: 4.800 kBaud
// Data Format: NRZ		Accurate
// RF output power: +10 dBm
// Channel width: 25 kHz
// Modulation: FSK		Dithering enabled
// Lock: Continuous
// Carrier sense offset:   0 dBm	DCLK squelch disabled
// Operator Mode: Rx

// There is no change in register values for TX or RX except CC1020_MAIN


/// Default config for 433 MHz
/// @todo To be changed for finalized frequency.
const char DefaultConfig433[32] =
  {
    0x0F,  // 0x01, INTERFACE			//DCLK_CS will be used in RX mode
    0xFF,  // 0x02, RESET
    0x8F,  // 0x03, SEQUENCING
    0x3A,  // 0x04, FREQ_2A  39
    0x7A,  // 0x05, FREQ_1A	F0
    0xF1,  // 0x06, FREQ_0A	0F
    0x3B,  // 0x07, CLOCK_A
    0x3A,  // 0x08, FREQ_2B   39
    0x85,  // 0x09, FREQ_1B   FA
    0x9D,  // 0x0A, FREQ_0B   B9
    0x3B,  // 0x0B, CLOCK_B
    0x44,  // 0x0C, VCO
    0x50,  // 0x0D, MODEM
    0x0B,  // 0x0E, DEVIATION
    0xCC,  // 0x0F, AFC_CONTROL
    0x2F,  // 0x10, FILTER
    0x61,  // 0x11, VGA1
    0x55,  // 0x12, VGA2
    0x2F,  // 0x13, VGA3
    0x2D,  // 0x14, VGA4       			// Carrier Sense Threshold Level = 5dB
    0x10,  // 0x15, LOCK       	   		// When not used, set as high
    0x78,  // 0x16, FRONTEND
    0x47,  // 0x17, ANALOG, RX=47/TX=47
    0x14,  // 0x18, BUFF_SWING
    0x22,  // 0x19, BUFF_CURRENT
    0xAE,  // 0x1A, PLL_BW
    0x34,  // 0x1B, CALIBRATE
    0xF0,  // 0x1C, PA_POWER			// 10dbm output power
    0x00,  // 0x1D, MATCH
    0x00,  // 0x1E, PHASE_COMP
    0x00,  // 0x1F, GAIN_COMP
    0x00   // 0x20, POWERDOWN
  };


/****************************************************************************/
/*  This routine writes to a single CC1020 register                         */
/****************************************************************************/

void WriteToCC1020Register(unsigned char addr, unsigned char data)
{
  cbi(PORT_CS,CC1020);		        // Clear SS_bar to enable slave
  //char array1[25];
  unsigned char dummy;
  dummy=SPDR;

  SPDR=(addr<<1)|0x01;			// Write address to CC1020, left shift,write bit is always 1
	
  // Wait until data is written 
  while (! (SPSR & (1<<SPIF)));
  if(WCOL==1)
    {
      //sprintf(array1,"\nCollision detected!!!");
      //usart_transmit(array1);
    }
	
  dummy=SPDR;  
  SPDR=data;

  while (! (SPSR & (1<<SPIF)));
  //PORTD |=0x01;			//********1******
  sbi(PORT_CS,CC1020); 			//PSEL must be made high for atleast 50ns after each read/write operation	
}

/****************************************************************************/
/*  This routine reads from a single CC1020 register                        */
/****************************************************************************/

unsigned char ReadFromCC1020Register(unsigned char addr)
{
  char Value;
  //	char dummy;

  cbi(PORT_CS,CC1020);
  Value=SPDR;
  SPDR=(addr<<1)&0xFE; // Write address to CC1020, write bit is always 0->read

  // Wait until data is written 
  while (! (SPSR & (1<<SPIF)));
  
  SPDR=0xFF; // Dummy write to initiate shift/read via SPI
  while (! (SPSR & (1<<SPIF)));
  Value=SPDR;
  //PORTD |=0x02;
  
  sbi(PORT_CS,CC1020);
  return Value;
}

/****************************************************************************/
/*  This routine puts the CC1020 into power down mode. Use WakeUpCC1020ToRX */
/*  followed by SetupCC1020RX or WakeupCC1020ToTX followed by SetupCC1020TX */
/*  to wake up from power down                                              */
/****************************************************************************/

void SetupCC1020PD(void)
{
  // Put CC1020 into power-down
  WriteToCC1020Register(CC1020_MAIN,0x1F);
  // Turn off PA to minimise current draw
  WriteToCC1020Register(CC1020_PA_POWER,0x00);
}


/****************************************************************************/
/*  This routine resets the CC1020, clearing all registers.                 */
/****************************************************************************/  

void ResetCC1020(void)
{
  // Reset CC1020
  WriteToCC1020Register(CC1020_MAIN, 0x0E);
  // Bring CC1020 out of reset
  WriteToCC1020Register(CC1020_MAIN, 0x1F);
}


/****************************************************************************/
/*  This routine configures all CC1020 registers as per values stored in DefaultConfig433[] */
/****************************************************************************/

void SetupCC1020Allregisters(void)
{
  char counter, value;
  
  for(counter=0x01; counter<=0x20; counter++)
    {
      value=DefaultConfig433[counter-1];				// For Transmitter as well as Receiver
      WriteToCC1020Register(counter,value);
    }


}


/********************************************************************************/
/*  This routine wakes the CC1020 up from PD mode to TX mode. CC is still in	*/
/*  power down mode 								*/
/********************************************************************************/

void WakeUpCC1020ToTX(char TXANALOG1)
{
  // Turn on xtal oscillator core
  WriteToCC1020Register(CC1020_MAIN,0xDB);
  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,TXANALOG1);
  // Insert wait routine here, must wait for xtal oscillator to stabilise, 
  // typically takes 2-5ms.
  //for (i=0x0260; i > 0; i--);
  _delay_ms(3);
  // Turn on bias generator
  WriteToCC1020Register(CC1020_MAIN,0xD9);
  // Wait for 150 usec
  int i = 0;
  for (i=0x0010; i > 0; i--);
  //_delay_us(150);			 // Not possible, max delay using this function is 96us  
  // Turn on frequency synthesiser
  WriteToCC1020Register(CC1020_MAIN,0xD1);
}


/****************************************************************************/
/*  This routine wakes the CC1020 up from PD mode to RX mode                */
/****************************************************************************/

void WakeUpCC1020ToRX(char RXANALOG1)
{
  // Turn on xtal oscillator core
  WriteToCC1020Register(CC1020_MAIN,0x1B);

  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,RXANALOG1);

  // Insert wait routine here, must wait for xtal oscillator to stabilise, 
  // typically takes 2-5ms.
  //for (i=0x0260; i > 0; i--);
  _delay_ms(3);

  // Turn on bias generator
  WriteToCC1020Register(CC1020_MAIN,0x19);

  // Wait for 150 usec
  int i;
  for (i=0x0010; i > 0; i--);
  //_delay_us(150);


  // Turn on frequency synthesiser
  WriteToCC1020Register(CC1020_MAIN,0x11);
}


/****************************************************************************/
/*  This routine calibrates the CC1020                                      */
/*  Returns 0 if calibration fails, non-zero otherwise. Checks the LOCK     */
/*  to check for success.                                                   */
/****************************************************************************/

int CalibrateCC1020(char PA_POWER1)
{
  volatile int TimeOutCounter;
  volatile int nCalAttempt;

  // Turn off PA to avoid spurs during calibration in TX mode
  WriteToCC1020Register(CC1020_PA_POWER,0x00);

  // Calibrate, and re-calibrate if necessary:
  for (nCalAttempt = CAL_ATTEMPT_MAX; (nCalAttempt>0); nCalAttempt--) 
    {

      // Start calibration
      WriteToCC1020Register(CC1020_CALIBRATE,0xB4);            // verified with cc1020 datasheet
	
      // Wait for 100 usec. As given errata notes.
      int i;
      for (i=0x000B; i > 0; i--);

      // Monitor calibration complete bit in STATUS register
      // CAL_COMPLETE bit set to 1 when calibration is complete
      // Waiting time according to register settings is approx 27ms. Ref_freq=fosc/2 and CAL_WAIT = 11
      // We are waiting for 30ms
      for(TimeOutCounter=30; ((ReadFromCC1020Register(CC1020_STATUS)&0x80)==0x00)&&(TimeOutCounter>0); TimeOutCounter--)
	{_delay_ms(1);}		
	
      // Monitor lock
      // LOCK_CONTINUOUS bit in STATUS register is set to 1 when PLL is in LOCK
      for(TimeOutCounter=30; ((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0x00)&&(TimeOutCounter>0); TimeOutCounter--)
	{_delay_ms(1);}		

      // Abort further recalibration attempts if successful LOCK
      if((ReadFromCC1020Register(CC1020_STATUS)&0x10) == 0x10) 
	{
	  break;
	}
    }

  // Restore PA setting
  WriteToCC1020Register(CC1020_PA_POWER, PA_POWER1);

  // Return state of LOCK_CONTINUOUS bit
  return ((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0x10);
}


/****************************************************************************/
/*  This routine puts the CC1020 into TX mode (from RX). When switching to  */
/*  TX from PD, use WakeupCC1020ToTX first                                  */
/****************************************************************************/

char SetupCC1020TX(char TXANALOG1, char PA_POWER1)
{
  volatile int TimeOutCounter;
  int lock_status;

  // Turn off PA to avoid frequency splatter
  WriteToCC1020Register(CC1020_PA_POWER,0x00);

  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,TXANALOG1);

  // Switch into TX, switch to freq. reg B
  WriteToCC1020Register(CC1020_MAIN,0xC1);     // TX Coming out of Power down at this stage

  // Monitor lock
  // LOCK_CONTINUOUS bit set to 1 when PLL is in LOCK
  for(TimeOutCounter=30; ((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0x00)&&(TimeOutCounter>0); TimeOutCounter--)
    {_delay_ms(1);}
	
  // If PLL in lock 
  if((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0x10)
    {
      lock_status = TRUE;
      //sbi(PORTA,LED_PLL);
    }
  else	// if PLL is not locked then Recalibrate
    {
      // If recalibration ok
      if(CalibrateCC1020(PA_POWER1))
	{
	  lock_status = TRUE;
	  //sbi(PORTA,LED_PLL);
	  // Else (recalibration failed)
	}
      else
	{
	  lock_status = FALSE;
	  //cbi(PORTA,LED_PLL);
	}
    }

  // Restore PA setting
  WriteToCC1020Register(CC1020_PA_POWER,PA_POWER1);

  // Turn OFF DCLK_CS (Carrier Sense Squelch) in TX
  WriteToCC1020Register(CC1020_INTERFACE,ReadFromCC1020Register(CC1020_INTERFACE)&~0x10);
  
  // Configure LOCK pin to continuous lock status. Active low indicates PLL in lock
  WriteToCC1020Register(CC1020_LOCK,0x20);

  // Return LOCK status to application
  return (lock_status);
}

/****************************************************************************/

int Transmitpacket(char* str, int size)
{
  short int bytecounter,bitcounter;
  unsigned char dummy;
  int count=0,d;
	
  for(bytecounter=0;bytecounter<=size;bytecounter++)
    {
      dummy=str[bytecounter];
      //sbi(PORTA,LED_TEST1);
      for(bitcounter=1;bitcounter<=8;bitcounter++)
	{
	  while (!(PIN_TX&(1<<DCLK))); /* put new data on negative edge of DCLK  */
	  while (PIN_TX&(1<<DCLK));      // since by then it is stable
	  if((dummy&0x80)==0x80) sbi(PORT_TX,DIO);
	  else cbi(PORT_TX,DIO);
	  dummy=dummy<<1;
	  count++;
	}
      //cbi(PORTA,LED_TEST1);
    }
	
  /* Addition of two dummy bits */
  for(d=1;d<=2;d++)
    {
      while ( !(PINB&(1<<DCLK)) ); // put new data on negative edge of DCLK
      while (PINB&(1<<DCLK));	   // since by then it is stable
      sbi(PORTB,DIO);
    }
	
  return(count);
}
