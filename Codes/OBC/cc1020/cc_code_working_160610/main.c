/* Main program for using CC1020 as Tranceiver

*/

#include <header.h>
#include <CC1020.h>
#include <cc1020functions.c>

#define flag 0x7E
/*
Pending Tasks (8-3-10)
1. Revise the receiver code.
	* Function for RSSI calculation in dB --> completed
	* Number of bytes to receive to be decided at runtime --> completed
2. Send ten packets and calculate how many packets are lost. 
   Implement some way to minimize the lost
3. Revise the transmitter code and implement AX.25 protocol
4. Testings,testings and testings!!

*/

//short int Numberofbytes;
volatile short int TX_complete=0;
volatile short int RX_complete=0;

//int TXBUFFER[];
//int count=0;
int i=0,a=0,n=0,m=0,b=0, lastBit, isFlag, lastBit, ONEScount ;

char header[5] = {0x01,0x02, 0x03, 0x04, 0x05};
char header_bytes = 5;

//char data[6] = {0x06,0x07, 0x7E, 0x09, 0x0A, 0x0B};
//char data_bytes = 6;

unsigned char data[4] = {0xAB, 0xCD, 0xEF, 0x78};
char data_bytes = 4;

//char crc_high = 0xAA;
//char crc_low = 0xBB;

char array1[30];

// ISR of INT0 Interrupt
/*
	Need to findout whether interrupt should be generated on +ve or -ve edge. Because DCLK_CS 
	goes from high to low when sgnal detected and low to high when transmitting data
	
	Ans: Generate interrupt on -ve edge of DCLK when transmitting and +ve edge of DCLK when receiving
	*/
/*
#ifdef CC1020_TX
ISR(INT0_vect)
{	
	
	
	
	cbi(SREG,SREG_I);
	sbi(GIFR,INTF0);
	static short int bytecounter=0;
	static short int bitcounter=1;
	static unsigned char dummy=0x55;  //TXBUFFER[0]
	static int count=0;
	
	//sbi(PORTA,LED_TEST); confirmed entering ISR
	
	if((dummy&0x80)==0x80) sbi(PORTB,DIO);
	else cbi(PORTB,DIO);
	dummy=dummy<<1;
	
	bitcounter++;
	count++;
	
	if(bitcounter > 8)
    {
		bitcounter=1;
		bytecounter++;
		dummy=TXBUFFER[bytecounter];
	}
	
	if(bytecounter > 14)
	{
		bytecounter=0;
		dummy=TXBUFFER[bytecounter];
		// stop transmission
		TX_complete=1;
		sbi(PORTA,LED_TEST2);
		TXBUFFER[15]=count;
		count=0;
		
	}
	else sbi(SREG,SREG_I);
}


#else
ISR(INT0_vect)
{
	cbi(SREG,SREG_I);
	sbi(GIFR,INTF0);
	static short int bytecounter=0;
	static short int bitcounter=1;
	static unsigned char dummy=0x00;
	static int count=0;
	
	dummy=dummy<<1;						// Important! First shift left then write
	if(PINB & (1<<DIO))
	   {dummy |= 0x01;}
	
	else dummy &= 0xFE;
	
	bitcounter++;
	count++;
	
	if (bitcounter > 8)
	{
	  bitcounter=1;
	  RXBUFFER[bytecounter]=dummy;
	  dummy=0x00;
	  bytecounter++;
	  sbi(PORTA,LED_TEST1);
	}
	
//	if (bytecounter==0)
//	{
//	 RXBUFFER[8]=ReadFromCC1020Register(CC1020_RSSI);
//	 RXBUFFER[9]=ReadFromCC1020Register(CC1020_STATUS);
//	}
	
	if (bytecounter > 14)
	{
	  bytecounter=0;
	  RX_complete=1;
	  sbi(PORTA,LED_TEST2);
	  RXBUFFER[15]=count;
	  count=0;
	}
	else sbi(SREG,SREG_I);
	
}

#endif
*/	

void Initialise_SPI(void) 
{
	DDRB &= ~(1 << MISO);	// set port B SPI data input to input
	DDRB |= (1 << MOSI);	// set port B SPI clock to output
	DDRB |= (1 << SCK);	// set port B SPI data out to output 
	DDRB |= (1 << SS_bar);	// set port B SPI chip select to output
	SPCR = (1 << SPE) | (1 << MSTR) | (0 << SPR1) | (0 << SPR0);
	
	DDRB &= ~(1 << DCLK);	// set DCLK as input
	
	//PORTB &= ~(1 << SS_bar);	// set chip select to low (MMC is selected)
}


void Initialise_UART(void)
{
	// USART initialization
	// Communication Parameters: 8 Data, 1 Stop, No Parity
	// USART Receiver: On
	// USART Transmitter: On
	// USART Mode: Asynchronous
	// USART Baud rate: 19200
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=0x19;
}

void usart_transmit(char *buffer)
{
	int i=0;
	while(buffer[i] != '\0')
	{
		UDR=buffer[i];
		while (! ( UCSRA & (1<<UDRE) ) );      // Always monitor UDRE and not TXC
		i++;
		
	
	}
}

unsigned short int crc;
unsigned char crc_high, crc_low;

void update_crc(unsigned int ch);
int hex2ascii (unsigned char val);
void go(void);

int cal_crc(void)
{
    go();
    return 0;
}

void go(void)
{
	unsigned int ch, i, x, y, crch;
	//unsigned char crc_high, crc_low;

    crc = 0xFFFF;
 

	for (i=0; i< data_bytes; i++)
	{

		ch = data[i];
		x = ch;
		y = ch;
		x = x & 0xF0;
		x = x >> 4;
		ch = hex2ascii(x);
		update_crc(ch);
		y = y & 0x0F;
		ch = hex2ascii(y);
		update_crc(ch);
	}

	crch = crc;
	crc_low = crch;
	crch = crch >> 8;
	crc_high = crch;
	
}




void update_crc(unsigned int ch)
{
    unsigned char i, xor_flag;

    ch<<=8;

    for(i=0; i<8; i++)
    {
        if ((crc ^ ch) & 0x8000)    xor_flag = 1;
        else			             xor_flag = 0;

        crc = crc << 1;

        if (xor_flag)
        {
             crc = crc ^ poly;
        }

        ch = ch << 1;
    }
}


int hex2ascii (unsigned char val)
{
	unsigned int asc;
	if(val<=9)	asc=val+0x30;
	else		asc=val+0x37;
	return (asc);
}


#ifdef CC1020_TX
/*void LoadTXBuffer(void)
{

  TXBUFFER[0]=0x55;			//
  TXBUFFER[1]=0x55;			//  3 Preamble bytes
  TXBUFFER[2]=0x55;
  TXBUFFER[3]=0x55;	    	//
  TXBUFFER[4]=0x55;			//  3 Preamble bytes
  TXBUFFER[5]=0x55;			//
  TXBUFFER[6]=0x55;			//
  TXBUFFER[7]=0x55;			//  4 Preamble bytes
  TXBUFFER[8]=0x55;	
  TXBUFFER[9]=0x55;
  TXBUFFER[10]=0xD3;			// Sync word 1
  TXBUFFER[11]=0x91;			// Sync word 2
  TXBUFFER[12]=0x04;			// Number of Data Bytes to be transmitted
  TXBUFFER[13]=0xaa;
  TXBUFFER[14]=0xbb;
  TXBUFFER[15]=0xcc;
  TXBUFFER[16]=0xdd;
  
  no_bytes_tosend=17;

}*/
void LoadTXBuffer(void)
{
	//int i;
	int count=0;
        for ( i=0; i<=9; i++)
        {
        	TXBUFFER[i]=0x55;
			count++;
		}


			TXBUFFER[10]=flag;
			count++;
			
			/*TXBUFFER[10]=0xD3;
			count++;
			TXBUFFER[11]=0x91;
			count++;
			TXBUFFER[12]=0x0E;
			count++;*/

        a = 10;
		//a = 12;
        n = header_bytes;
		
        for (i=0; i<n; i++)
        {
            TXBUFFER[i+(a+1)]=header[i];
			count++;
        }
		
        m = data_bytes;
		
        for (i=0; i<m; i++)
        {
            TXBUFFER[i+(a+1+n)]=data[i];
			count++;
        }

        b = a + n + m;
		
            TXBUFFER[b+1]=crc_high;
			count++;
			
            TXBUFFER[b+2]=crc_low;
			count++;
			
            TXBUFFER[b+3]=flag;
			count++;
			
			TXBUFFER[b+4]=flag;
			count++;
			
	no_bytes_tosend = count;
	
	/*for(int j=0;j <= no_bytes_tosend; j++)
	{
		sprintf(array1,"\n\rByte %d = %x",j,TXBUFFER[j]);
		usart_transmit(array1);
	}*/
}


#endif


int main()
{
	char array[30];
	int counter,pktcount = 0;
	DDRA = 0xFF;						// For LED indication
	
	Initialise_SPI();
	Initialise_UART();
	sbi(PORTB,SS_bar);
	sprintf(array,"\n\rWireless Comm using CC1020");
	usart_transmit(array);
	
	SetupCC1020PD();
	ResetCC1020();						//CC is still in PD mode after reset
	SetupCC1020Allregisters();
	
	//sprintf(array,"\n\r Interface = %x",ReadFromCC1020Register(CC1020_INTERFACE));
	//usart_transmit(array);
	//sprintf(array,"\n\r FREQ_0A = %x",ReadFromCC1020Register(CC1020_FREQ_0A));
	//usart_transmit(array);
	//sprintf(array,"\n\r FREQ_0B = %x",ReadFromCC1020Register(CC1020_FREQ_0B));
	//usart_transmit(array);
	//sprintf(array,"\n\r LOCK = %x",ReadFromCC1020Register(CC1020_LOCK));
	//usart_transmit(array);
	
	
	
	WakeUpCC1020ToTX(TXANALOG);
	if (!CalibrateCC1020(PA_POWER))
	{
		sprintf(array,"\n\rTX Calibration failed");
		usart_transmit(array);
	}

	WakeUpCC1020ToRX(RXANALOG);
	if (!CalibrateCC1020(PA_POWER))
	{
		sprintf(array,"\n\rRX Calibration failed");
		usart_transmit(array);
	}
	
	sprintf(array,"\n\r STATUS = %x",ReadFromCC1020Register(CC1020_STATUS));			// Expected value = 0xBX
	usart_transmit(array);
	
  // Now the CC1020 is calibrated for both RX and TX, we do not need to recalibrate
  // unless the frequency is changed, the temperature changes by 40 degrees C
  // or if the supply voltage changes by more than 0.5V 
  
#ifdef CC1020_TX
	/*
	IMPORTANT:
 
	1. When gating the DCLK signal with the carrier sense signal at least 2 dummy bits 
	should be added after the data payload in TX mode. Because the carrier sense signal
	is generated earlier in the receive chain (i.e. before the demodulator), causing it
	to be updated 2 bits before the corresponding data is available on the DIO pin (Pg 61).
	
	2. The transmitter adds a delay due to synchronization. The user must add a delay
	equivalent to 2 bits before stopping the transmission. 
	This point is separate from above point.

	*/
	//cal_crc();
	//LoadTXBuffer();			
	
	
	
  // Start Transmission
	
	sbi(DDRB,DIO);			// Set DIO as output	************
	//cbi(MCUCSR,ISC2);		// -ve edge triggered
	//MCUCR |= (1 << ISC01);
	//MCUCR &= ~(1 << ISC00);
	
	//for(int l=1; l<=50; l++)
	while(1)
	{
		cal_crc();
		LoadTXBuffer();
		//sbi(DDRB,DIO);
		
	    WakeUpCC1020ToTX(TXANALOG);													
	
		//Enable interrupt on negative edge
		// SREG,MCUCR, MCUCSR,GICR,GIFR
		//sbi(SREG,SREG_I);	    // Global interrupt enable
		//sbi(GICR,INT0);			// enable INT0
		
		if(!SetupCC1020TX(TXANALOG,PA_POWER))
		{
			sprintf(array,"\n\rPLL LOCK failed");
			usart_transmit(array);
		}
		
		sprintf(array,"\n\rTransmitting .....\n");
		usart_transmit(array);
		sbi(PORTA,LED_X);
		
		/*for(int j=0;j < no_bytes_tosend; j++)
			{
				sprintf(array,"\n\rByte %d = %x",j,TXBUFFER[j]);
				usart_transmit(array);
			}*/
		
		counter=Transmitpacket();
		//TxPacket();
		
		//while(!TX_complete);    // IT should wait here till one complete packet is Transmitted
		//TX_complete=0;
		
		//cbi(SREG,SREG_I);	    // Global interrupt disable
		//cbi(GICR,INT0);			// disable INT0
		
		_delay_ms(1);			// Approx. delay equivalent to 2 bits
		//_delay_ms(8);
		
		/*for(int j=0;j < no_bytes_tosend; j++)
			{
				sprintf(array,"\n\rByte %d = %x",j,TXBUFFER[j]);
				usart_transmit(array);
			}*/
		
		WriteToCC1020Register(CC1020_MAIN,0x1F);  // configure in PD and stop Transmission				
		cbi(PORTA,LED_X);
		
		sprintf(array,"\n\rTrans complete;count=%d",counter);
		usart_transmit(array);
		
		
		for(int d=1;d<=120;d++)
		_delay_ms(32);				// Delay of 3.84sec
	}
	//sbi(SREG,SREG_I);	    // Global interrupt enable
	//sbi(GICR,INT0);			// enable INT0
	WriteToCC1020Register(CC1020_MAIN,0x1F);  // configure in PD and stop Transmission

#else

	// Start Reception
	
	// Connect one MCU pin to LOCK pin and configure LOCK pin to indicate carrier sense (active low). 
	// When carrier is sensed read the RSSI value.
	
	
	cbi(DDRB,DIO);			// Set DIO as input
	cbi(DDRB,LOCKpin);	
	//MCUCR |= (1 << ISC01);
	//MCUCR |= (1 << ISC00);
	//sbi(MCUCSR,ISC2);		// +ve edge triggered.
	
	WakeUpCC1020ToRX(RXANALOG);
	sprintf(array,"\n\rReceiver ON");
	usart_transmit(array);
	
	if(!SetupCC1020RX(RXANALOG,PA_POWER))
	{
		sprintf(array,"\n\rPLL LOCK failed");
		usart_transmit(array);
	}
	
	while(1)
	{
		sbi(PORTA,LED_TEST1);	
		while (PINB&(1<<LOCKpin));		// In AVR pins are not bit-addresible
		counter = Receivepacket();
		
		if(counter==0)
		{
			sprintf(array,"\n\rError in SOF\n");
			usart_transmit(array);
			/*
			for(int k=0;k < 5; k++)
			{
				sprintf(array,"\n\rByte %d = %x",k,RXBUFFER[k]);
				usart_transmit(array);
			}*/
			
		}
		else	
		{
			//pktcount++;
			//sprintf(array,"\n\r Pktcount = %d",pktcount);
			//usart_transmit(array);
			sprintf(array,"\n\rPkt Recd.Total bit count=%d",counter);
			usart_transmit(array);
			counter = ReadRSSIlevelCC1020();
			sprintf(array,"\n\rRSSI =%d dBm",counter);
			usart_transmit(array);
			
			
			for(int j=4;j < curr_buffer_index; j++)
			{
				sprintf(array,"\n\rByte %d = %x",j,RXBUFFER[j]);
				usart_transmit(array);
			}	
		}
		
		
		
		//sbi(SREG,SREG_I);	    // Global interrupt enable 				
		//sbi(GICR,INT0);			// enable INT0
		//sbi(PORTA,LED_X);		// Receiver ON
		
			
		//while(!RX_complete); 	// IT should wait here till one complete packet ie 8 bytes is Received		
			
		//RX_complete=0;
		
		//cbi(SREG,SREG_I);	    // Global interrupt disable
		//cbi(GICR,INT0);			// disable INT0
			
		//WriteToCC1020Register(CC1020_MAIN,0x1F);  // Do not configure in PD and stop Reception			
		//cbi(PORTA,LED_X);
			
			
			//sprintf(array,"\n\rRSSI=%x",ReadFromCC1020Register(CC1020_RSSI));
			//usart_transmit(array);
			
			
			//sprintf(array,"\n\rSTATUS Reg=%x",ReadFromCC1020Register(CC1020_STATUS));
			//usart_transmit(array);
			
		
		
		//for(int d=1;d<=20;d++)	
		//_delay_ms(32);			// delay of 1sec
		cbi(PORTA,LED_TEST1);
	
	}

//WriteToCC1020Register(CC1020_MAIN,0x1F);  // configure in PD and stop Reception
#endif
		
		/*
		Important: After RX mode is on, if Power down mode is configured then the Squelch signal becomes low.
		Hence when receiver is ON then do not cofigure inPD mode. 
		
		Soln: But this should be worried if we are using interrupt using DCLK. If we are polling DCLK and interrupt
		is generated by LOCK pin, then Receiver can be configured in power down mode.
		
		Note: PSEL should be in tri-state or set to high in power down mode to prevent trickle current from flowing 
		in the internal pull up resistor.
		*/



	
	//while(1);
	
	return 0;
}
