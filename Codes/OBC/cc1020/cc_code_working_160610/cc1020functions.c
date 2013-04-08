/*
All functions related to programming of CC1020
*/

#include <util/delay.h>
#include<header.h>
#include<CC1020.h>

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
const char DefaultConfig433[32] =
{
  0x0F,  // 0x01, INTERFACE		//DCLK_CS will be used in RX mode
  0xFF,  // 0x02, RESET
  0x8F,  // 0x03, SEQUENCING
  0x39,  // 0x04, FREQ_2A  	39
  0xF0,  // 0x05, FREQ_1A	F0
  0x0F,  // 0x06, FREQ_0A	0F
  0x3B,  // 0x07, CLOCK_A
  0x39,  // 0x08, FREQ_2B   39
  0xFA,  // 0x09, FREQ_1B   FA
  0xB9,  // 0x0A, FREQ_0B   B9
  0x3B,  // 0x0B, CLOCK_B
  0x44,  // 0x0C, VCO
  0x50,  // 0x0D, MODEM
  0x0B,  // 0x0E, DEVIATION
  0xCC,  // 0x0F, AFC_CONTROL
  0x2F,  // 0x10, FILTER
  0x61,  // 0x11, VGA1
  0x55,  // 0x12, VGA2
  0x2F,  // 0x13, VGA3
  0x2D,  // 0x14, VGA4			Carrier Sense Threshold Level = 5dB
  0x10,  // 0x15, LOCK          // When not used, set as high
  0x78,  // 0x16, FRONTEND
  0x47,  // 0x17, ANALOG, RX=47/TX=47
  0x14,  // 0x18, BUFF_SWING
  0x22,  // 0x19, BUFF_CURRENT
  0xAE,  // 0x1A, PLL_BW
  0x34,  // 0x1B, CALIBRATE
  0xF0,  // 0x1C, PA_POWER		// 10dbm output power
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
	cbi(PORTB,SS_bar); // Clear SS_bar to enable slave
	char array1[25];
	unsigned char dummy;
	dummy=SPDR;

	SPDR=(addr<<1)|0x01; // Write address to CC1020, left shift,write bit is always 1
	
	// Wait until data is written 
	while (! (SPSR & (1<<SPIF)));
	if(WCOL==1)
	{
	 sprintf(array1,"\nCollision detected!!!");
	 usart_transmit(array1);
	}
	
	dummy=SPDR;  
	SPDR=data;

	while (! (SPSR & (1<<SPIF)));
	//PORTD |=0x01;												
	sbi(PORTB,SS_bar); //PSEL must be made high for atleast 50ns after each read/write operation	
}

/****************************************************************************/
/*  This routine reads from a single CC1020 register                        */
/****************************************************************************/

unsigned char ReadFromCC1020Register(unsigned char addr)
{
	char Value;
//	char dummy;

	cbi(PORTB,SS_bar);
	Value=SPDR;
	SPDR=(addr<<1)&0xFE; // Write address to CC1020, write bit is always 0->read

	// Wait until data is written 
	while (! (SPSR & (1<<SPIF)));
	
	
	SPDR=0xFF; // Dummy write to initiate shift/read via SPI
	while (! (SPSR & (1<<SPIF)));
	Value=SPDR;
	//PORTD |=0x02;
	
	sbi(PORTB,SS_bar);
	return Value;
}

/****************************************************************************/
/*  This routine puts the CC1020 into power down mode. Use WakeUpCC1020ToRX */
/*  followed by SetupCC1020RX or WakeupCC1020ToTX followed by SetupCC1020TX */
/*  to wake up from power down                                              */
/****************************************************************************/

void SetupCC1020PD(void)
{
  uint8_t x;
  char bufff[100];
  
  // Put CC1020 into power-down
  WriteToCC1020Register(CC1020_MAIN,0x1F);
  
  x = ReadFromCC1020Register(CC1020_MAIN);
  
  sprintf(bufff,"Wake up complete : %d a\r\n",x);
  usart_transmit(bufff);

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


/****************************************************************************/
/*  This routine wakes the CC1020 up from PD mode to TX mode. CC is still in 
	power down mode 		*/
/****************************************************************************/

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
  for (int i=0x0010; i > 0; i--);
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
  for (int i=0x0010; i > 0; i--);
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
	for (int i=0x000B; i > 0; i--);

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
	sbi(PORTA,LED_PLL);
  }
  else	// if PLL is not locked then Recalibrate
  {
    // If recalibration ok
		if(CalibrateCC1020(PA_POWER1))
		{
		lock_status = TRUE;
		sbi(PORTA,LED_PLL);
	// Else (recalibration failed)
		}
	   else
	   {
		lock_status = FALSE;
		cbi(PORTA,LED_PLL);
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
/*  This routine puts the CC1020 into RX mode (from TX). When switching to  */
/*  RX from PD, use WakeupC1020ToRX first                                   */
/****************************************************************************/

/* 
	Carrier Sense Threshold is used in RX mode to determine whether valid data 
	is recieved or not. The DCLK signal is generated only when RSSI is greater 
	than CS threshold. The CS threshold is set using CS_level[4:0] bits in VGA4 
	register.
*/

char SetupCC1020RX(char RXANALOG1, char PA_POWER1)
{
  volatile int TimeOutCounter;
  char lock_status;
  
  // Turn ON DCLK_CS (Carrier Sense Squelch) in RX
  WriteToCC1020Register(CC1020_INTERFACE,ReadFromCC1020Register(CC1020_INTERFACE) | 0x10);


  // Switch into RX, switch to freq. reg A		
  WriteToCC1020Register(CC1020_MAIN,0x11);

  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,RXANALOG);

  // Monitor LOCK
  for(TimeOutCounter=30; ((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0)&&(TimeOutCounter>0); TimeOutCounter--)
  {_delay_ms(1);}

  // If PLL in lock 
  if((ReadFromCC1020Register(CC1020_STATUS)&0x10)==0x10)
  {
    lock_status = TRUE;
	sbi(PORTA,LED_PLL);
  }
  else	// Recalibrate
  {
    // If recalibration ok
		if(CalibrateCC1020(PA_POWER1))
		{
		lock_status = TRUE;
		sbi(PORTA,LED_PLL);
		// Else (recalibration failed)
		}
	   else
	   {
		lock_status = FALSE;
		cbi(PORTA,LED_PLL);
		}
  }


  // Switch RX part of CC1020 on				// RX coming out of PD at this stage
  WriteToCC1020Register(CC1020_MAIN,0x01);
  
  // Configure LOCK pin to continuous lock status. Active low indicates PLL in lock
  //WriteToCC1020Register(CC1020_LOCK,0x20);
  
  // Configure LOCK pin to indicate carrier sense. Active low when RSSI above threshold
  WriteToCC1020Register(CC1020_LOCK,0x40);

  // Return LOCK status to application
  return (lock_status);
}

/****************************************************************************/

int Transmitpacket(void)
{

	short int bytecounter,bitcounter;
	unsigned char dummy;
	int count=0,d;
	
	for(bytecounter=1;bytecounter<=no_bytes_tosend;bytecounter++)
	{
	 dummy=TXBUFFER[bytecounter-1];
	 sbi(PORTA,LED_TEST1);
	 for(bitcounter=1;bitcounter<=8;bitcounter++)
		{
			while ( !(PINB&(1<<DCLK)) );	// put new data on negative edge of DCLK
			while (PINB&(1<<DCLK));			// since by then it is stable
			//_delay_us(100);
			
			if((dummy&0x80)==0x80) sbi(PORTB,DIO);
			else cbi(PORTB,DIO);
			dummy=dummy<<1;
			count++;
		}
	cbi(PORTA,LED_TEST1);
	
	}
	
	// Addition of two dummy bits
	
	for(d=1;d<=2;d++)
	{
		while ( !(PINB&(1<<DCLK)) );	// put new data on negative edge of DCLK
		while (PINB&(1<<DCLK));			// since by then it is stable
		//_delay_us(100);
		
		sbi(PORTB,DIO);
	}
	
	return(count);
		
}


/****************************************************************************/

/*
As seen in the result of reception. a delay of approx 4 and half bytes is present. This means that after 
carrier sense is detected the MCU should read DIO after a delay equivalent to 4 and half bytes.

Next steps:

1. Continue reading till 20 bytes.

2. Introduce a delay after detecting carrier sense. Not foolproof because once the shift was of 5 and half bytes.

3. Interrupt on DIO pin to detect start of data.

4. use manchester coding

5. Manually check for 55 and then interpret data.

TO Decide (9-3-10)
1. What to do when SOF is not correctly received? Chances are less if preamble is properly detected

*/


int Receivepacket(void)
{


	unsigned char dummy=0x00;
//	unsigned char reg=0x00;
	char prev_bit=1;
	char Preamblefound=0, SOF=0, err_flag=0;
	curr_buffer_index=0;
	no_databytes_toread=0;
	rxcount=0;
	
	RXBUFFER[curr_buffer_index]=ReadFromCC1020Register(CC1020_RSSI);	//RXBUFFER[0]=RSSI
	curr_buffer_index++;
	RXBUFFER[curr_buffer_index]=ReadFromCC1020Register(CC1020_STATUS);	//RXBUFFER[1]=STATUS	
	curr_buffer_index++;
	
	// Detect preamble.
	while(!Preamblefound)
	{
		// Read first bit
		 while (PINB&(1<<DCLK));			// read data on rising edge of DCLK
		 while (!(PINB&(1<<DCLK)));		// since by then it is stable
		 //_delay_us(100);
		  
		 if(PINB & (1<<DIO))				// Is the first bit 1?
		{
			if(prev_bit==0)					// 01 found, increment count
			rxcount=rxcount+2;
			else
			rxcount=0;
		}
		 else								
		{
			// No, first bit is 0. Next read second bit
			while (PINB&(1<<DCLK));			
			while (!(PINB&(1<<DCLK)));	
			//_delay_us(100);
			
			if(PINB & (1<<DIO))			// Is 2nd bit 1?
				{
				prev_bit=1;
				rxcount=rxcount+2;				// 01 found, increment count
				}
			else
				{
				prev_bit=0;
				rxcount=0;
				}
		}
			
		//if(rxcount==40)	// 5 bytes of preamble received. This is value is changeable.
		if(rxcount==56)		// 7 bytes of preamble received. This is value is changeable.
		//if(rxcount==72)			// 9 bytes
		{
		    Preamblefound=1;
		}  

	}
	
	// Detect Start of Frame (SOF)
	/*while(!SOF)
	{	
		dummy=0x00;
		for(int l=1;l<=4;l++)			// Read 4 bits. 
		{
			while (PINB&(1<<DCLK));			
			while (!(PINB&(1<<DCLK)));
			//_delay_us(100);
			
			dummy=dummy<<1;
			if(PINB & (1<<DIO))
				{dummy |= 0x01;}
			else dummy &= 0xFE;
		}
		switch(dummy)
		{
			case 0x00:		//error
				err_flag=1;
				break;
				
			case 0x01:		//error
				err_flag=1;
				break;
			
			case 0x02:		//error
				err_flag=1;
				break;
				
			case 0x03:		//error
				err_flag=1;
				break;
			
			case 0x04:		//error
				err_flag=1;
				break;
				
			case 0x05:		// Part of remaining preamble. Just increment count, do nothing
				rxcount=rxcount+2;
				break;
				
			case 0x06:		//error
				err_flag=1;
				break;
			
			case 0x07:		//Start of frame detetcted
				SOF=1;
				for(int l=5;l<=8;l++)	// Read the remaining 4 bits
				{
					while (PINB&(1<<DCLK));			
					while (!(PINB&(1<<DCLK)));
					//_delay_us(100);
					dummy=dummy<<1;
					if(PINB & (1<<DIO))
						{dummy |= 0x01;}
					else dummy &= 0xFE;
				}
			
				RXBUFFER[curr_buffer_index]=rxcount;		//RXBUFFER[2]=No. of bits of preamble received. 
				curr_buffer_index++;
				
				RXBUFFER[curr_buffer_index]=dummy;			//RXBUFFER[3]=SOF_1 / flag
				curr_buffer_index++;
				
				/*ReadNumberofBytes(2);						//RXBUFFER[4]=SOF_2 & RXBUFFER[5]=Number of Data bytes to read
				curr_buffer_index--;			
				no_databytes_toread = RXBUFFER[curr_buffer_index];
				curr_buffer_index++;*/
				
				/*ReadNumberofBytes(1);
				curr_buffer_index--;
				curr_byte = RXBUFFER[curr_buffer_index];
				curr_buffer_index++;
				
				//if((RXBUFFER[3] != SOF_1) || (RXBUFFER[4] != SOF_2))
				if((RXBUFFER[3] != flag))
				{
				   //SOF is not correctly received
				   err_flag=1;
				   
				}
			break;
		}
		
		if(err_flag==1)
		{
		   return(0);
		}
			   
	}*/
	
	while(!SOF)
	{	
		dummy=0x00;
		for(int l=1;l<=8;l++)			// Read 8 bits. 
		{
			while (PINB&(1<<DCLK));			
			while (!(PINB&(1<<DCLK)));
			//_delay_us(100);
			
			dummy=dummy<<1;
			if(PINB & (1<<DIO))
				{dummy |= 0x01;}
			else dummy &= 0xFE;
		}
		
		while (dummy != flag)
		{
			while (PINB&(1<<DCLK));			
			while (!(PINB&(1<<DCLK)));
			//_delay_us(100);
			dummy=dummy<<1;
			if(PINB & (1<<DIO))
			{dummy |= 0x01;}
			else dummy &= 0xFE;
		}
		
		SOF = 1;
		RXBUFFER[curr_buffer_index]=rxcount;		//RXBUFFER[2]=No. of bits of preamble received. 
		curr_buffer_index++;
				
		RXBUFFER[curr_buffer_index]=dummy;			//RXBUFFER[3]=SOF_1 / flag
		curr_buffer_index++;
				
		/*ReadNumberofBytes(2);						//RXBUFFER[4]=SOF_2 & RXBUFFER[5]=Number of Data bytes to read
		curr_buffer_index--;			
		no_databytes_toread = RXBUFFER[curr_buffer_index];
		curr_buffer_index++;*/
				
		ReadNumberofBytes(1);
		curr_buffer_index--;
		curr_byte = RXBUFFER[curr_buffer_index];
		curr_buffer_index++;
				
		//if((RXBUFFER[3] != SOF_1) || (RXBUFFER[4] != SOF_2))
		if((RXBUFFER[3] != flag))
		{
		//SOF is not correctly received
		err_flag=1;
		//return(0);
				   
		}
		
	}
	
	if(err_flag==1)
		{
		   return(0);
		}
		
	//ReadNumberofBytes(no_databytes_toread);
	while (curr_byte != flag)
	{
	ReadNumberofBytes(1);
	curr_buffer_index--;
	curr_byte = RXBUFFER[curr_buffer_index];
	curr_buffer_index++;	
	}
	
	return(rxcount);
}	


void ReadNumberofBytes(int number_of_bytes)
{
	short int bytecounter,bitcounter;
	char byte=0x00;
	for(bytecounter=1;bytecounter<=number_of_bytes;bytecounter++)		
	{
	 for(bitcounter=1;bitcounter<=8;bitcounter++)
		{
			while (PINB&(1<<DCLK));			// read data on rising edge of DCLK
			while (!(PINB&(1<<DCLK)));			// since by then it is stable
			//_delay_us(100);
			byte=byte<<1;						// Important! First shift left then write
			
			if(PINB & (1<<DIO))
			{byte |= 0x01;}
	
			else byte &= 0xFE;
			rxcount++;
		}
	 RXBUFFER[curr_buffer_index]=byte;
	 curr_buffer_index++;
	 
	}

}

/*
	//Expected Received Packet

	RXBUFFER[0]= RSSI
	RXBUFFER[1]= STATUS
	RXBUFFER[2]= No. of bits of preamble received.
	RXBUFFER[3]=SOF_1
	RXBUFFER[4]=SOF_2
	RXBUFFER[5]=0x04
	RXBUFFER[6]=0xAA
	RXBUFFER[7]=0xBB
	RXBUFFER[8]=0xCC
	RXBUFFER[9]=0xDD
*/

/*	
	for(bytecounter=4;bytecounter<=4;bytecounter++)		// changed for techfest
	{
	 for(bitcounter=1;bitcounter<=8;bitcounter++)
		{
			while (PINB&(1<<DCLK));			// read data on rising edge of DCLK
			while (!(PINB&(1<<DCLK)));			// since by then it is stable
			dummy=dummy<<1;						// Important! First shift left then write
			
			if(PINB & (1<<DIO))
			{dummy |= 0x01;}
	
			else dummy &= 0xFE;
			count++;
		}
	 RXBUFFER[bytecounter]=dummy;
	}*/
	
	
/*
int Receivepacket(void)
{

	short int bytecounter,bitcounter;
	unsigned char dummy=0x00;
	int count=0;
	
	RXBUFFER[0]=ReadFromCC1020Register(CC1020_RSSI);
	RXBUFFER[1]=ReadFromCC1020Register(CC1020_STATUS);
	
	for(bytecounter=2;bytecounter<=21;bytecounter++)
	{
	 //sbi(PORTA,LED_TEST1);
	 for(bitcounter=1;bitcounter<=8;bitcounter++)
		{
			while (PINB&(1<<DCLK));			// read data on rising edge of DCLK
			while (!(PINB&(1<<DCLK)));			// since by then it is stable
			
			
			dummy=dummy<<1;						// Important! First shift left then write
			if(PINB & (1<<DIO))
			{dummy |= 0x01;}
	
			else dummy &= 0xFE;
			count++;
		}
	 RXBUFFER[bytecounter]=dummy;
	//cbi(PORTA,LED_TEST1);
	
	}
	
	return(count);
		
}
*/

/****************************************************************************/
/*  This routine acquires the average RSSI level in dBm. CC1020 library     */
/****************************************************************************/
int ReadRSSIlevelCC1020(void)
{
  char i;
  //unsigned char RSSI[5];
  unsigned char FILTER;
  int RSSI_dBm;

  // RSSI formula based on CC1020 datahseet and application note 30:
  // P = 1.5 x RSSI - 3 x VGA_SETTING - RSSI_Offset [dBm]

  /*
  VGA_SETTING based on SmartRF Studio - CC1020, v5.3.0.0
  Note: these settings could be subject to optimisation.
  
  434MHz range:
  -------------------------------------------------
  12.5 => VGA3 = 0x31 => VGA_SETTING = 0x11 = 17dec
  25   => VGA3 = 0x2F => VGA_SETTING = 0x0F = 15dec
  50   => VGA3 = 0x2E => VGA_SETTING = 0x0E = 14dec
  100  => VGA3 = 0x2D => VGA_SETTING = 0x0D = 13dec
  150  => VGA3 = 0x2F => VGA_SETTING = 0x0F = 15dec
  200  => VGA3 = 0x32 => VGA_SETTING = 0x12 = 18dec
  500  => VGA3 = 0x33 => VGA_SETTING = 0x13 = 19dec
  
  868MHz range:
  -------------------------------------------------
  12.5 => VGA3 = 0x2F => VGA_SETTING = 0x0F = 15dec
  25   => VGA3 = 0x2E => VGA_SETTING = 0x0E = 14dec
  50   => VGA3 = 0x2D => VGA_SETTING = 0x0D = 13dec
  100  => VGA3 = 0x2D => VGA_SETTING = 0x0D = 13dec
  150  => VGA3 = 0x2E => VGA_SETTING = 0x0E = 14dec
  200  => VGA3 = 0x30 => VGA_SETTING = 0x10 = 16dec
  500  => VGA3 = 0x34 => VGA_SETTING = 0x14 = 20dec
  */

  // Get current channel spacing
  FILTER = ReadFromCC1020Register(CC1020_FILTER)&0x7F;

  // Calculate average RSSI in dBm (initially without offset):
  //for(i = 0; i < 5; i++) {
  //  RSSI[i] = ReadFromCC1020Register(CC1020_RSSI);
  //}
  //RSSI_dBm = (int)((((unsigned int)RSSI[0]+(unsigned int)RSSI[1]+(unsigned int)RSSI[2]+(unsigned int)RSSI[3]+(unsigned int)RSSI[4])*3)/(2*5));
  
  RSSI_dBm = RXBUFFER[0];	
  RSSI_dBm = ((RSSI_dBm*3) - (3*(int)(ReadFromCC1020Register(CC1020_VGA3)&0x1F)*2)) / 2;		// RSSI w/o offset

  // Calculate average RSSI in dBm with offset, according to frequency band:
  // Active frequency is in 800 MHz band
  if( (ReadFromCC1020Register(CC1020_ANALOG)&0x80) == 0x80 ) 
  {
    switch ( FILTER ) 
	{
      case 0x58://12.5 kHz spacing
      case 0x3F://12.5 kHz spacing, optimal sensitivity
        RSSI_dBm = RSSI_dBm - 95;
        break;
      case 0x2F://25 kHz spacing
        RSSI_dBm = RSSI_dBm - 96;
        break;
      case 0x2B://50 kHz spacing
        RSSI_dBm = RSSI_dBm - 95;
        break;
      case 0x25://100 kHz spacing
        RSSI_dBm = RSSI_dBm - 96;
        break;
      case 0x22://150 kHz spacing
        RSSI_dBm = RSSI_dBm - 99;
        break;
      case 0x01://200 kHz spacing
        RSSI_dBm = RSSI_dBm - 99;
        break;
      case 0x00://500 kHz spacing
        RSSI_dBm = RSSI_dBm - 101;
        break;
    }
  // Active frequency is in 434 MHz band
  } 
  else 
  {
    switch ( FILTER ) {
      case 0x38://12.5 kHz spacing
      case 0x2F://25 kHz spacing
        RSSI_dBm = RSSI_dBm - 102;
        break;
      case 0x2B://50 kHz spacing
        RSSI_dBm = RSSI_dBm - 100;
        break;
      case 0x25://100 kHz spacing
        RSSI_dBm = RSSI_dBm - 99;
        break;
      case 0x22://150 kHz spacing
        RSSI_dBm = RSSI_dBm - 101;
        break;
      case 0x01://200 kHz spacing
        RSSI_dBm = RSSI_dBm - 102;
        break;
      case 0x00://500 kHz spacing
        RSSI_dBm = RSSI_dBm - 103;
        break;
      }
  }

  return(RSSI_dBm);
}
