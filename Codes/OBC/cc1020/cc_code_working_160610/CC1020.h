
/*                                                                           *
 * Revision history:                                                         *
 *                                                                           *
 * $Log: CC1020.h,v $
 * Revision 1.4  2005/11/22 15:25:24  tos
 * Removed osbolete code (AGC freeze).
 *
 * Revision 1.3  2004/03/23 16:44:22  tos
 * Introduced RSSI measurement (based on algorithm in SmartRF Studio).
 *
 * Revision 1.2  2003/09/17 15:03:05  tos
 * Mod's:
 *   - introduced new menu option ('J'): access (w/r) CC1020 register.
 *   - update EEPROM variable+table upon register write access ('J').
 *   - introduced new configuration option ('I'): preamble length.
 *   - moved TX buffer initialisation after configuration.
 *   - corrected inconsistent number conversion funtion.
 *
 * Revision 1.1  2003/07/31 13:17:14  tos
 * Initial version in CVS.
 *
 *
 *
 *                                                                           *
 ****************************************************************************/


/* Constants defined for CC1020 */

/* Register addresses */

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

// CC1020 Configuration Options ... change here only
//#define MAIN            0xC1
//#define RXMAIN          0x01  // for receiver
//#define INTERFACE       0xAA
//#define RESET           0xFF
//#define SEQUENCING      0x8F
//#define FREQ_2A         0x3A
//#define FREQ_1A         0x3E
//#define FREQ_0A         0x01
//#define CLOCK_A         0x59
//#define FREQ_2B         0x3A
//#define FREQ_1B         0x48
//#define FREQ_0B         0xAD
//#define CLOCK_B         0x39
//#define VCO             0x32
//#define MODEM           0x50
//#define DEVIATION       0x9D
//#define TXDEVIATION     0x9D
//#define RXDEVIATION     0x9D
//#define AFC_CONTROL     0xC1
//#define FILTER          0x2F
//#define VGA1            0x61
//#define VGA2            0x55
//#define VGA3            0x2F    // 2E for RX
//#define VGA4            0x2D    // 29 for RX
//#define LOCK            0x20
//#define FRONTEND        0x78
//#define ANALOG          0x47
//#define RXANALOG        0x47
//#define TXANALOG        0x47
//#define BUFF_SWING      0x14
//#define BUFF_CURRENT    0x22
//#define PLL_BW          0xAE
//#define CALIBRATE       0x34
#define PA_POWER        0x0F			//0 dbm output power
//#define PA_POWER_0_DBM  	0x60	//0F
//#define PA_POWER_5_DBM  	0x80	//80
//#define PA_POWER_n10_DBM    0x05 	//F0
//#define MATCH           0x00
//#define PHASE_COMP      0x00
//#define GAIN_COMP       0x00
//#define POWERDOWN       0x00

/* Functions for accessing the CC1020 */

//extern void ConfigureCC1020(char Count, short Configuration[]);
//extern void WriteToCC1020Register(unsigned char addr, unsigned char data);
//extern void WriteToCC1020RegisterWord(short addranddata);
//extern char ReadFromCC1020Register(unsigned char addr);
//extern void ResetCC1020(void);
//extern char CalibrateCC1020(char PA_POWER);
//extern char SetupCC1020RX(char RXANALOG, char PA_POWER);
//extern char SetupCC1020TX(char TXANALOG, char PA_POWER);
//extern void SetupCC1020PD(void);
//extern void SetupCC1020All(void);
//extern void WakeUpCC1020ToRX(char RXANALOG);
//extern void WakeUpCC1020ToTX(char TXANALOG);
//extern void ConfigurationMode(void);
//extern void HandleConfigMenu(char inputvalue);
//extern void DisplayConfigMenu(void);
//extern void SetPApower(void);
//extern void SetPreambleLength(void);
//extern void AccessCC1020Register(void);
//extern void ButtonConfig(void);
//extern void SetTXmode(char PA_POWER);
//extern void DefaultSettings(void);
//extern void DumpCC1020Regs(void);
//extern char hexdigit2int(char val);
//extern int  ReadRSSIlevelCC1020(void);



// Constants for CC1020

#define TXANALOG 0x47
#define RXANALOG 0x47

// Time-out values

//#define RSSI_TIMEOUT   0x3000
//#define INIT_TIMEOUT   0x0010   // Corresponds to approx. 150 usec
//#define BUTTON_TIMEOUT 0x6000

//Buffers


