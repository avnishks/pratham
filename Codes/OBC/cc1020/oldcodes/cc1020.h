/**
 * @file cc1020.h
 * @brief CC1020 port and function definitions.
 * @todo Port and pins for CC on board from slave and master
 * @todo AX.25 to be added
 */
#ifndef CC1020_H
#define CC1020_H
#include "common.h"
#include "spi.h"
// atmega32 Pin Definitions
// Directions: 0-> input; 1-> output
/// Pin connected to CC Data I/O pin
#define DIO	PB1	
/// Clock from CC1020
#define DCLK	PB2	
/// For Carrier sense indication. Not used
#define LOCKpin	PB3	
/*
#define SS_bar	PB4	
/// MOSI-->PDI
#define MOSI	PB5	
/// MISO<--PDO
#define MISO	PB6	
/// SCK-->PCLK
#define SCK	PB7	
*/

/*
#define LED_X	PA0
#define LED_PLL	PA1
#define LED_TEST1 PA2
#define LED_TEST2 PA3
*/
#define PORT_TX PORTB
#define PIN_TX  PINB


/// Maximum number of re-calibration attempts upon calibration failure
#define CAL_ATTEMPT_MAX   4	

//volatile char TXBUFFER[64];
//volatile char RXBUFFER[64];

/* Constants defined for CC1020 */

/**
 * @defgroup CC_Reg_addr CC1020 register addresses
 * Register address definitions for CC1020
 * @hide
 */
//@{
/// @ref CC_Reg_addr
#define CC1020_MAIN            0x00
#define CC1020_INTERFACE       0x01
#define CC1020_RESET           0x02
#define CC1020_SEQUENCING      0x03
#define CC1020_FREQ_2A         0x04
#define CC1020_FREQ_1A         0x05
#define CC1020_FREQ_0A         0x06
#define CC1020_CLOCK_A         0x07
#define CC1020_FREQ_2B         0x08
#define CC1020_FREQ_1B         0x09
#define CC1020_FREQ_0B         0x0A
#define CC1020_CLOCK_B         0x0B
#define CC1020_VCO             0x0C
#define CC1020_MODEM           0x0D
#define CC1020_DEVIATION       0x0E
#define CC1020_AFC_CONTROL     0x0F
#define CC1020_FILTER          0x10
#define CC1020_VGA1            0x11
#define CC1020_VGA2            0x12
#define CC1020_VGA3            0x13
#define CC1020_VGA4            0x14
#define CC1020_LOCK            0x15
#define CC1020_FRONTEND        0x16
#define CC1020_ANALOG          0x17
#define CC1020_BUFF_SWING      0x18
#define CC1020_BUFF_CURRENT    0x19
#define CC1020_PLL_BW          0x1A
#define CC1020_CALIBRATE       0x1B
#define CC1020_PA_POWER        0x1C
#define CC1020_MATCH           0x1D
#define CC1020_PHASE_COMP      0x1E
#define CC1020_GAIN_COMP       0x1F
#define CC1020_POWERDOWN       0x20
#define CC1020_TEST1           0x21
#define CC1020_TEST2           0x22
#define CC1020_TEST3           0x23
#define CC1020_TEST4           0x24
#define CC1020_TEST5           0x25
#define CC1020_TEST6           0x26
#define CC1020_TEST7           0x27
#define CC1020_STATUS          0x40
#define CC1020_RESET_DONE      0x41
#define CC1020_RSSI            0x42
#define CC1020_AFC             0x43
#define CC1020_GAUSS_FILTER    0x44
#define CC1020_STATUS1         0x45
#define CC1020_STATUS2         0x46
#define CC1020_STATUS3         0x47
#define CC1020_STATUS4         0x48
#define CC1020_STATUS5         0x49
#define CC1020_STATUS6         0x4A
#define CC1020_STATUS7         0x4B

#define PA_POWER               0x0F	//0 dbm output power

#define TXANALOG 	       0x47
#define RXANALOG 	       0x47
//@}

/// Initializes CC1020
int init_CC1020 (void);

/**
 *  @brief  This function transmit one packet from CC1020. To tranmsit multiple times call this function multiple times
 *  @return void
 */
void Transmit_CC1020(char* str, int size);

/**
 *  This routine writes to a single CC1020 register                         
 */

void WriteToCC1020Register(unsigned char addr, unsigned char data);

/**
 *  This routine reads from a single CC1020 register                        
 */

unsigned char ReadFromCC1020Register(unsigned char addr);

/**
 *  This routine puts the CC1020 into power down mode. Use WakeUpCC1020ToRX 
 *  followed by SetupCC1020RX or WakeupCC1020ToTX followed by SetupCC1020TX 
 *  to wake up from power down                                              
*/

void SetupCC1020PD(void);

/**
 *  This routine resets the CC1020, clearing all registers.                 
 */

void ResetCC1020(void);


/**
 * This routine configures all CC1020 registers as per values stored in DefaultConfig433[]
 */

void SetupCC1020Allregisters(void);

/**
 * This routine wakes the CC1020 up from PD mode to TX mode. CC is still in	
 * power down mode 								
 */

void WakeUpCC1020ToTX(char TXANALOG1);

/**
 *  This routine wakes the CC1020 up from PD mode to RX mode                
 */

void WakeUpCC1020ToRX(char RXANALOG1);

/**
 *  This routine calibrates the CC1020                                      
 *  Returns 0 if calibration fails, non-zero otherwise. Checks the LOCK     
 *  to check for success.                                                   
 */

int CalibrateCC1020(char PA_POWER1);

/**
 * This routine puts the CC1020 into TX mode (from RX). When switching to  
 * TX from PD, use WakeupCC1020ToTX first                                  
 */
char SetupCC1020TX(char TXANALOG1, char PA_POWER1);

/**
 * @brief Transmits a given string across the network.
 * @param str Character pointer to string location
 * @param size Size of string
 */
int Transmitpacket(char* str, int size);
#endif
