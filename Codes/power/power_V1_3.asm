
	list		p=16f877a	; list directive to define processor
	#include	<p16f877a.inc>	; processor specific variable definitions

;write the config bits
    __CONFIG _CP_OFF & _WDT_OFF & _BODEN_OFF & _PWRTE_ON & _HS_OSC & _LVP_OFF & _CPD_OFF 

#define DEBUG ; to send debuging data on UART
;#define DEBUG_ADC ; to send measured data by ADC on UART

	cblock 0x20
	LoadStatus


	;0x21 stores ADC HM data
	;BatteryCurrent<--
	TotalCurrent

	;BatteryVoltage<--
	BatteryVoltageBy2

	;Panel<--
	ConsumptionCurrent

	;SixVolt <--
	SixVolt
 	
	;ThreeVolt<--
	DownlinkVoltageBy2	

    ;BatteryStatus<-- 
    BatteryStatus ; Overvoltage and low power of battery
    
    
	HMCounter
	
	;variables required for adc: Don't use in interrupts
	Channel
	Count
	InverseCount

	;variables required for OC
	Timer
	Timer7
	Timer6
	Timer5
	Timer4
	Timer3

	;variables required for OBC Command
	CommandByte
	
	;Variable for i2c byte status
	TWIByte
	
	;Variable for Ejection State: Snap/Preflight
	State
	;Variable for delays
	;Delay
	;TPS_EN 	;it saves current enable pin status of all TPS. Bit order as described below.
	endc

;OBC Command Byte format & TPS_EN byte format
PBEACON equ 7
PCONTROL equ 6
PGPS equ 5
PDOWNLINK equ 4
POBC equ 3
PMAG equ 2

w_temp equ 0x70 ; variable used for context saving
status_temp equ 0x71 ; variable used for context saving
fsr_temp equ 0x72
w_temp_send equ 0x73 ; variable used for context saving
status_temp_send equ 0x74 ; variable used for context saving


I2C_ADDR equ 0x44


CheckLoadTimer macro

	movf Timer, W
    subwf INDF,W
	btfss STATUS, Z
    
	endm
;{
TurnOnLoadOC macro  PORT_TPS_ON, COMPONENT_TPS_ON, bit_pos_ON
    
    bsf PORT_TPS_ON, COMPONENT_TPS_ON
	;bsf TPS_EN, bit_pos_ON
    bsf LoadStatus, bit_pos_ON
    
	endm
TurnOffLoadOC macro PORT_TPS_OFF, COMPONENT_TPS_OFF, bit_pos_OFF

    bcf PORT_TPS_OFF, COMPONENT_TPS_OFF
	;bcf TPS_EN, bit_pos_OFF
    bcf LoadStatus, bit_pos_OFF

    movf Timer, W
    movwf INDF
    
	endm
 ;}  
;CheckLoadOBC macro PORT_TPS, COMPONENT_TPS, bit_pos
;
;    btfss CommandByte, bit_pos 
;    bcf PORT_TPS, COMPONENT_TPS
;	#ifdef DEBUG
;		call Mpoweroff
;	#endif
;    btfsc CommandByte, bit_pos
;    bsf PORT_TPS, COMPONENT_TPS
;	#ifdef DEBUG
;		call Mpoweron
;	#endif
;    
;    endm

; ############################################################# macros end here ##############################################
	org 0x0000
	
	goto SleepMode

;{	
	org     0x004             ; interrupt vector location

	movwf   w_temp            ; save off current W register contents
	movf	STATUS, W          ; move status register into W register
	movwf	status_temp       ; save off contents of STATUS register
	movf	FSR, W
	movwf	fsr_temp		;save FSR register
	
	banksel ADCON0
	
	btfsc PIR1, SSPIF
	call I2CHandler   ; I2C receive interrupt
	
	banksel ADCON0

	;bcf PIR1, SSPIF
	bcf INTCON, INTF

ExitISR: 

	movf    status_temp, W     ; retrieve copy of STATUS register
	movwf	STATUS            ; restore pre-isr STATUS register contents
	movf    fsr_temp, W     ; retrieve copy of FSR register
	movwf	FSR            ; restore pre-isr FSR register contents
	movf w_temp, W	;restore pre-isr W register
	retfie                    ; return from interrupt	

I2CHandler:
	bcf PIR1, SSPIF
	movf SSPBUF, W
	;Check Read/Write bit
    banksel ADCON1
   
	;Check if last byte was Data or address
	btfsc SSPSTAT, 5
	;If it was Data call the OBC command response subroutine	
	goto OBCCommandResponse
	
	;If it was Address call the send HM data routine

SendHMData:
	;Check if Master in Read Mode
	btfss SSPSTAT, 2
	goto ExitI2C

    banksel ADCON0
  
	movlw LoadStatus
	movwf FSR

	;Calculate address of next data byte
	movf HMCounter, W
	addwf FSR, f
	movf INDF, W

WriteI2C:  
	;Send Data
	bcf SSPCON, WCOL
	movwf SSPBUF
	btfsc SSPCON, WCOL
	goto WriteI2C
	
	;Release Clock
	incf TWIByte, f
	bsf SSPCON, CKP

	;Increment Counter, check if equal to 7 make it 0
	incf HMCounter, f
	movlw 7
	subwf HMCounter, W
	btfsc STATUS, Z
    clrf HMCounter
	
	goto ExitI2C

OBCCommandResponse:
	;OBC Command format: Bit 7:0 
	; Beacon : Control: GPS: Downlink : OBC : Reserved: Reserved: Reserved
    banksel ADCON0
    
    btfsc TWIByte, 0
    goto SkipI2CData
    
    ;Check if Load has been turned off by Power MuC even when it should be on according to the OBC
    movwf CommandByte
    ;movwf BatteryStatus
    xorwf LoadStatus, f
    
	
	;PBeacon
	btfss LoadStatus, PBEACON
	goto SkipCheck7
	
    ;CheckLoadOBC PORTE, 0, PBEACON 
	btfss CommandByte, PBEACON 
    bcf PORTE, 0 ;OFF TPS 
	#ifdef DEBUG
		call Mpoweroff
	#endif
    btfsc CommandByte, PBEACON 
    bsf PORTE, 0 ;ON TPS
	#ifdef DEBUG
		call Mpoweron
	#endif
    #ifdef DEBUG
		call Mbeacon
	#endif

SkipCheck7:
	;PDownlink
	btfss LoadStatus, PDOWNLINK
	goto SkipCheck6
	
    ;CheckLoadOBC PORTE, 2, PDOWNLINK
	btfss CommandByte, PDOWNLINK
    bcf PORTE, 2 ;OFF TPS
	#ifdef DEBUG
		call Mpoweroff
	#endif
    btfsc CommandByte, PDOWNLINK 
    bsf PORTE, 2 ;ON TPS
	#ifdef DEBUG
		call Mpoweron
	#endif
	#ifdef DEBUG
		call Mdownlink
	#endif

SkipCheck6:
	;PControl
	btfss LoadStatus, PCONTROL
	goto SkipCheck5
	
    ;CheckLoadOBC PORTC, 2, PCONTROL
	btfss CommandByte, PCONTROL
    bcf PORTC, 2 ;OFF TPS
	bsf PORTD, 1 ;OFF PTH
	#ifdef DEBUG
		call Mpoweroff
	#endif
    btfsc CommandByte, PCONTROL 
    bsf PORTC, 2 ;ON TPS
	bcf PORTD, 1 ;ON PTH
	#ifdef DEBUG
		call Mpoweron
	#endif
	#ifdef DEBUG
		call Mcontrol
	#endif

SkipCheck5:
	;POBC
	btfss LoadStatus, POBC
	goto SkipCheck4
	
    ;CheckLoadOBC PORTD, 2, POBC
	btfss CommandByte, POBC
    bcf PORTD, 2 ;OFF TPS
	bsf PORTC, 5 ;OFF PTH 
	#ifdef DEBUG
		call Mpoweroff
	#endif
    btfsc CommandByte, POBC
    bsf PORTD, 2 ;ON TPS
	bcf PORTC, 5 ;ON PTH
	#ifdef DEBUG
		call Mpoweron
	#endif
	#ifdef DEBUG
		call Mobc
	#endif
	
SkipCheck4:
	;PGPS
	btfss LoadStatus, PGPS
	goto SkipCheck3
	
    ;CheckLoadOBC PORTD, 4, PGPS
	btfss CommandByte, PGPS
    bcf PORTD, 4 ;OFF TPS
	bsf PORTD, 6 ;OFF PTH
	#ifdef DEBUG
		call Mpoweroff
	#endif
    btfsc CommandByte, PGPS
    bsf PORTD, 4 ;ON TPS
	bcf PORTD, 6 ;ON PTH
	#ifdef DEBUG
		call Mpoweron
	#endif
	#ifdef DEBUG
		call Mgps
	#endif

SkipCheck3:
;	;PMAG
;	btfss LoadStatus, PMAG
;	goto SkipCheck2
;	
;   ;CheckLoadOBC PORTD, 7, PMAG
;	btfss CommandByte, PMAG 
;    bcf PORTD, 7 ;TPS
;	#ifdef DEBUG
;		call Mpoweroff
;	#endif
;    btfsc CommandByte, PMAG
;    bsf PORTD, 7 ;TPS
;	#ifdef DEBUG
;		call Mpoweron
;	#endif
;
;	#ifdef DEBUG
;		call Mmag
;	#endif

SkipCheck2:
	;Copy CommandByte to LoadStatus
	movf CommandByte, W
	movwf LoadStatus

SkipI2CData:
	clrf TWIByte

ExitI2C:
	nop
	return
;}



Startup_all:
	banksel PORTD

	#ifdef DEBUG
		movlw 	'S'		
		call	Send
		movlw   '\r'
		call    Send
		movlw   '\n'	
		call    Send
	#endif
	
	;TPS startup
	bsf PORTE, 0 ; EN4=>Enable TPS of BEACON	
	bsf PORTE, 2 ; EN5=>Enable TPS of DOWNLINK
	bsf PORTC, 2 ; EN6=>Enable TPS of CONTROL/TORQUE
	bsf PORTD, 2 ; EN3=>Enable TPS of OBC
	bsf PORTD, 4 ; EN2=>Enable TPS of GPS
	bsf PORTD, 7 ; EN7=>Enable TPS of MAG 

	movlw b'11111000' ;Bit 7 to 0 => B:C:G:D:O:-:-:-
	movwf LoadStatus
    movwf CommandByte

	;pth startup
	bcf PORTC, 1 ; BEACON & DOWNLINK
	bcf PORTD, 1 ; CONTROL/TORQUE
	bcf PORTC, 5 ; OBC
	bcf PORTD, 6 ; GPS

	return 

Startup:
	banksel PORTD

	#ifdef DEBUG
		movlw 	'S'		
		call	Send
		movlw   '\r'
		call    Send
		movlw   '\n'	
		call    Send
	#endif

	;TPS startup
	bsf PORTE, 0 ; EN4=>Enable TPS of BEACON	
	bcf PORTE, 2 ; EN5=>Enable TPS of DOWNLINK
	bsf PORTC, 2 ; EN6=>Enable TPS of CONTROL/TORQUE
	bsf PORTD, 2 ; EN3=>Enable TPS of OBC
	bcf PORTD, 4 ; EN2=>Enable TPS of GPS
	bcf PORTD, 7 ; EN7=>Enable TPS of MAG 

	;pth startup
	bcf PORTC, 1 ; BEACON & DOWNLINK
	bcf PORTD, 1 ; CONTROL/TORQUE
	bcf PORTC, 5 ; OBC
	bsf PORTD, 6 ; GPS

	movlw b'11001000' ;Bit 7 to 0 => B:C:G:D:O:-:-:-
	movwf LoadStatus
    movwf CommandByte

	return 


Shutdown:
	banksel PORTD

	#ifdef DEBUG
		movlw 	's'		
		call	Send
		movlw   '\r'
		call    Send
		movlw   '\n'	
		call    Send
	#endif

	;TPS shutdown
	bcf PORTE, 0 ; EN4=>Enable TPS of BEACON
	bcf PORTE, 2 ; EN5=>Enable TPS of DOWNLINK	
	bcf PORTC, 2 ; EN6=>Enable TPS of CONTROL/TORQUE
	bcf PORTD, 2 ; EN3=>Enable TPS of OBC	
	bcf PORTD, 4 ; EN2=>Enable TPS of GPS
	bcf PORTD, 7 ; EN7=>Enable TPS of MAG 

	;pth shutdown
	bsf PORTC, 1 ; BEACON & DOWNLINK 
	bsf PORTD, 1 ; CONTROL/TORQUE
	bsf PORTC, 5 ; OBC
	bsf PORTD, 6 ; GPS

	movlw b'00000000' ;Bit 7 to 0 => B:C:G:D:O:-:-:-
	movwf LoadStatus
    movwf CommandByte

	return

#ifdef DEBUG
;################ USART #################
Send:
    movwf   w_temp_send            ; save off current W register contents
	movf	STATUS, W          ; move status register into W register
	movwf	status_temp_send       ; save off contents of STATUS register
	movf w_temp_send, W	;restore pre-isr W register
	banksel ADCON0
	movwf TXREG
	call DelayTX
	movf    status_temp_send, W     ; retrieve copy of STATUS register
	movwf	STATUS            ; restore pre-isr STATUS register contents
	return

;{

; ---------------------------
; Message to send at startup
; ---------------------------
Message1:
	movlw 	'\r'		
	call	Send
	movlw 	'\n'		
	call	Send
	movlw 	'H'		
	call	Send
	movlw 	'e'
	call	Send
	movlw 	'l'
	call	Send
	movlw 	'l'
	call	Send
	movlw 	'o'
	call	Send
	movlw   '\r'
	call 	Send
	movlw   '\n'
	call 	Send
	movlw 	'T'
	call	Send
	movlw 	'h'
	call	Send
	movlw 	'i'
	call	Send
	movlw 	's'
	call	Send
	movlw 	' '
	call	Send
	movlw 	'i'
	call	Send
	movlw 	's'
	call	Send
	movlw 	' '
	call	Send
	movlw 	'I'
	call	Send
	movlw 	'I'
	call	Send
	movlw 	'T'
	call	Send
	movlw 	'B'
	call	Send
	movlw 	"'"
	call	Send
	movlw 	's'
	call	Send
	movlw 	' '		
	call	Send
	movlw 	'S'
	call	Send
	movlw 	't'
	call	Send
	movlw 	'u'
	call	Send
	movlw 	'd'
	call	Send
	movlw 	'e'
	call	Send
	movlw 	'n'
	call	Send
	movlw 	't'
	call	Send
	movlw 	' '
	call	Send
	movlw 	'S'
	call	Send
	movlw 	'a'
	call	Send
	movlw 	't'
	call	Send
	movlw 	'e'
	call	Send
	movlw 	'l'
	call	Send
	movlw 	'l'
	call	Send
	movlw 	'i'
	call	Send
	movlw 	't'
	call	Send
	movlw 	'e'
	call	Send
	movlw 	'.'
	call	Send
	movlw 	'.'
	call	Send
	movlw   '\r'
	call 	Send
	movlw   '\r'
	call 	Send
	movlw   '\n'
	call 	Send
	return
Mpoweron:
	movlw 	'\r'		
	call	Send
	movlw 	'\n'
	call	Send
	movlw 	'P'		
	call	Send
	movlw 	'O'		
	call	Send
	movlw 	'W'		
	call	Send
	movlw 	'E'		
	call	Send
	movlw 	'R'		
	call	Send
	movlw 	' '		
	call	Send	
	movlw 	'O'		
	call	Send
	movlw 	'N'		
	call	Send
	movlw 	'-'		
	call	Send
	return
Mpoweroff:
	movlw 	'\r'		
	call	Send
	movlw 	'\n'
	call	Send
	movlw 	'P'		
	call	Send
	movlw 	'O'		
	call	Send
	movlw 	'W'		
	call	Send
	movlw 	'E'		
	call	Send
	movlw 	'R'	
	call	Send
	movlw 	' '		
	call	Send
	movlw 	'O'		
	call	Send
	movlw 	'F'		
	call	Send
	movlw 	'F'		
	call	Send
	movlw 	'-'		
	call	Send
	return
Mbeacon:
	movlw 	'B'		
	call	Send
	movlw 	'e'		
	call	Send
	movlw 	'a'		
	call	Send
	movlw 	'c'		
	call	Send
	movlw 	'o'		
	call	Send
	movlw 	'n'		
	call	Send	
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
Mdownlink:
	movlw 	'D'		
	call	Send
	movlw 	'o'		
	call	Send
	movlw 	'w'		
	call	Send
	movlw 	'n'		
	call	Send
	movlw 	'l'		
	call	Send
	movlw 	'i'		
	call	Send
	movlw 	'n'		
	call	Send
	movlw 	'k'		
	call	Send	
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
Mcontrol:
	movlw 	'C'		
	call	Send
	movlw 	'o'		
	call	Send
	movlw 	'n'		
	call	Send
	movlw 	't'		
	call	Send
	movlw 	'r'		
	call	Send
	movlw 	'o'		
	call	Send
	movlw 	'l'		
	call	Send	
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
Mobc:
	movlw 	'O'		
	call	Send
	movlw 	'B'		
	call	Send
	movlw 	'C'		
	call	Send
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
Mgps:
	movlw 	'G'		
	call	Send
	movlw 	'P'		
	call	Send
	movlw 	'S'		
	call	Send
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
Mmag:
	movlw 	'M'		
	call	Send
	movlw 	'A'		
	call	Send
	movlw 	'G'		
	call	Send
	movlw 	'\r'		
	call	Send	
	movlw 	'\n'
	call	Send
	return
#endif

;}
	






Delay_1s:
	movlw 8
	movwf 0x62
Delay20:
	clrf 0x61
Delay109:
	clrf 0x60
Delay108:
	incfsz 0x60, f
	goto Delay108
	
	incfsz 0x61, f
	goto Delay109

	decfsz 0x62, f
	goto Delay20
	
	return

#ifdef DEBUG
DelayTX:
 		clrf 0x61
Delay19:
		clrf 0x60
Delay18:
		incfsz 0x60, f
		goto Delay18
	
		incfsz 0x61, f
		goto Delay19
  	return
#endif
;##########################################################
	
DelayS:
	movwf 0x62
Delay3:
	clrf 0x61
Delay2:
	clrf 0x60
Delay1:
	incfsz 0x60, f
	goto Delay1
	
	incfsz 0x61, f
	goto Delay2

	decfsz 0x62, f
	goto Delay3
	
	return

SleepMode:

#ifdef DEBUG
	; ########################## UART ####################################
	banksel ADCON1
	bsf TRISC, 7
	bcf TRISC, 6
	;movlw 0x08 ;14400 baud rate ;BRGH=0
	;movlw 0x0C ;9600 baud rate ;BRGH=0
	;movlw 0x19 ;19200 baud rate ;BRGH=1
	;movlw 0x08 ;56000 baud rate ;BRGH=1
	;movlw 0x03 ;128000 baud rate ;BRGH=1
	movlw 0x01 ;256000 baud rate ;BRGH=1
	movwf SPBRG			 
	clrf TXSTA
	bsf TXSTA, TXEN		 ;enable transmitter
	bsf TXSTA, BRGH
	banksel ADCON0
	clrf RCSTA
	bsf RCSTA, SPEN		 ;enable UART on the pins
	
	movlw 0x22
	movwf 0x70
	
	; Message to send at startup
Message:
		call Message1
		call Delay_1s
		movlw '\n'
		call Send
		movlw '1' ; corresponding to sleep mode
		call Send
		movlw '\r'
		call Send
		movlw '\n'	
		call Send
#endif
;########################################################################

	banksel ADCON1
	;set RB0 as input for SNAP
	bsf TRISB, 0    
	
	
	bsf ADCON1,1 ;to select AN0 to AN4 as adc and AN5 to An7 as digital pins

	;set input direction on the PTH inhibit pins
	bcf TRISC, 1 ; PON1=> inhibit PTH Beacon & Downlink
	bcf TRISD, 1 ; PON2=> inhibit PTH CONTROL/TORQUE
	bcf TRISC, 5 ; PON3=> inhibit PTH OBC
	bcf TRISD, 6 ; PON4=> inhibit PTH GPS

	;set input direction on the TPS enable  pins
	bcf TRISD, 4 ; EN2=>Enable TPS of GPS
	bcf TRISD, 2 ; EN3=>Enable TPS of OBC
	bcf TRISE, 0 ; EN4=>Enable TPS of BEACON	
	bcf TRISE, 2 ; EN5=>Enable TPS of DOWNLINK
	bcf TRISC, 2 ; EN6=>Enable TPS of CONTROL/TORQUE
	bcf TRISD, 7 ; EN7=>Enable TPS of MAG

	;enable input on the OC lines
	bsf TRISD, 5 ;GPS
	bsf TRISD, 3 ;OBC
	bsf TRISE, 1 ;Beacon
	bsf TRISC, 0 ;Downlink	
	bsf TRISD, 0 ;PCONTROL

	;enable input on the Uplink lines
    bsf TRISB, 5
	bsf TRISB, 4

	;configure I2C ports as Input
	bsf TRISC, 3
	bsf TRISC, 4
	
	
	banksel ADCON0
    
    ;switch off all loads
    call Shutdown
    ;goto SleepMode
	
	;switch on the INT interrupt for wake up from sleep
	bsf INTCON, PEIE
  
	bsf INTCON, INTE
	bsf INTCON, GIE	
	bcf INTCON, INTF
 
RealSleep:
	#ifdef DEBUG
		movlw '2' ; going to sleep mode
		call Send
		movlw '\r'
		call Send
		movlw '\n'	
		call Send
	#endif 

	sleep
	
	nop
	
	;2 second delay to confirm that the interrupt is not a fake
	movlw 15 ; this gives 2.07 sec delay
	call DelayS
	
	;Check Snap pin
	btfsc PORTB, 0
	goto Snap

	#ifdef DEBUG	
		movlw '3' ; still in sleep mode
		call Send
		movlw '\r'
		call Send
		movlw '\n'	
		call Send
	#endif

	;Check Preflight Pin
	btfsc PORTB, 1
	goto Preflight
	
	goto RealSleep
	
Snap:
	;Implement the Eject Delay
	#ifdef DEBUG
		movlw '4' ; I snapped
		call Send
		movlw '\r'
		call Send
		movlw '\n'	
		call Send
	#endif 

	clrf State
	goto Start
	
Preflight:
	movlw 0xFF
	movwf State


Start: 
	#ifdef DEBUG
		movlw '5' ; Lets get this started
		call Send
		movlw '\r'
		call Send
		movlw '\n'	
		call Send
	#endif 

	;enable input on the batterystatus lines
    ;bsf TRISD, 7
    ;bsf TRISD, 6
    ;bsf TRISD, 5
    ;bsf TRISB, 3
    ;bsf TRISB, 2
    ;bsf TRISB, 1
	
;############################### switching on all PTH #################
	;call Startup_all
	call Startup

	banksel ADCON1
	;configure ADC
	clrf ADCON1
	bsf ADCON1,1 ;to select AN0 to AN4 as adc and AN5 to An7 as digital pins


	;set ADC ports as input	
	movlw 0xFF
	movwf TRISA

	;confugure I2C
	clrf SSPSTAT
	clrf SSPCON2
	;configure address of I2C slave
    movlw I2C_ADDR
    movwf SSPADD



	;Enable SSP/I2C interrupt
	bsf PIE1, SSPIE

	banksel ADCON0	
   


	
	;configure I2C

	movlw 0x36
	movwf SSPCON ;I2C mode 7-bit address
	
	;Clear I2C interrupt flag
	clrf PIR1

	;Timer for OC and main Loop
	clrf Timer
	clrf HMCounter
	
	clrf BatteryStatus
	clrf TWIByte

;main loop
Loop:

;	#ifdef DEBUG
;		movlw '\t'
;		call Send	
;		movlw 'M'
;		call Send
;	#endif

	;Uplink check
	btfss PORTB, 5
	goto SkipUplink
	
	;2 second delay to confirm that the interrupt is not a fake
	movlw 15
	call DelayS
	
	;Test Interrupt pin
	btfss PORTB, 5
	goto SkipUplink
	
	#ifdef DEBUG
		movlw 'U'
		call Send	
	#endif
	;Check data line, if high Kill satellite
	btfsc PORTB, 4
	goto Kill
	
	;Low: Reset
	call Shutdown
	
	;0.5 second Delay for components to shutdown
	movlw 5 ; 0.49345 sec delay
	call DelayS
	
	goto Start

SkipUplink:

	;Check State variable for preflight check
	;Counter for looping 8 times
	movlw 0x08
	movwf InverseCount
	;Counter for number of high bits in State variable
	clrf Count
	;Copy State variable to a temp variable
	movf State, W
	movwf Channel
BitCheck:
	;Extract Bit and Check if high, increment Count
	btfsc Channel, 0
	incf Count, f
	;Do right Shift to get the next bit
	rrf Channel, f
	;Decrement Loop counter and exit loop if it becomes 0
	decfsz InverseCount, f
	goto BitCheck
	
	;Compare the bit counter with 4
	movlw 0x04
	subwf Count, W
	;Skip Check if in Snap mode
	btfss STATUS, C
	goto SkipPreflight
	
	;Check if Preflight pin is still high
	btfss PORTB, 1
	goto SleepMode
	
SkipPreflight:
	;counter for 5 ADC inputs	
	movlw 0x05
	
	movwf Count
	
	clrf InverseCount
	
	;set indirect address
	;movlw BatteryCurrent
	movlw TotalCurrent
	movwf FSR

ADCLoop:
;	#ifdef DEBUG
;		movlw 'A' ; corresponding to checking loads
;		call Send
;	#endif
	;select Channel in ADCON0
	movf InverseCount,W
	movwf Channel
	bcf STATUS, C
	
	rlf Channel,f
	rlf Channel,f
	rlf Channel,f
	
	movf Channel, W
	iorlw 0x81
	movwf ADCON0 ;fosc/32 clock conversion
	
	;Small delay for ADC
	movlw 0x03
	movwf 0x61
Delay5:
	clrf 0x60
Delay4:
	incfsz 0x60, f
	goto Delay4
	
	decfsz 0x61, f
	goto Delay5
	
	movf ADCON0, W				

	;start conversion
	bsf ADCON0, GO
ADCWait:
	btfsc ADCON0,GO
	goto ADCWait
	
	movf ADRESH, W
	
	movwf INDF	

	incf InverseCount, f
	incf FSR, f
	decfsz Count, f
	goto ADCLoop

	;debug : sending current and voltage reading to serial terminal
#ifdef DEBUG_ADC 
	movlw '\n'
	call Send
	movlw '\n'
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send
	movlw 'I'
	call Send
	movlw '1'
	call Send
	movf TotalCurrent,w
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send

	movlw 'I'
	call Send
	movlw '2'
	call Send
	movf ConsumptionCurrent,w
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send

	movlw 'V'
	call Send
	movlw '1'
	call Send
	movf BatteryVoltageBy2,w
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send

	movlw 'V'
	call Send
	movlw '2'
	call Send
	movf SixVolt,w
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send
	

	movlw 'V'
	call Send
	movlw '3'
	call Send
	movf DownlinkVoltageBy2,w
	call Send
	movlw '\n'
	call Send
	movlw '\r'
	call Send
	
#endif	
	;OC code
	;If component switched off and it should be on according to the OBC:
	;Check the Components timer, if 1 min is over, to switch it on again
    ;confirm if component is switched off oc pin is high
	movf CommandByte, W
	xorwf LoadStatus, W
	;check if Load is off and OBC wants it on
	movwf Channel ; using Channel variable as its use in ADC is finished and now its free to use.
	

;	#ifdef DEBUG
;		;lets assume that OBC wants downlink load on
;		movlw 0x40
;		movwf Channel
;	#endif

    ;Storing address of Timer for future reference of the temporary timers of the Loads
    movlw Timer7
    movwf FSR
    
    ;PBEACON
    btfss Channel, PBEACON
    goto SkipOn7
    ;Compare Timer and temporary Timer
    CheckLoadTimer
    
    goto SkipOn7
    ;If equal Turn on the Load
	
	#ifdef DEBUG
		call Mpoweron
		call Mbeacon
	#endif
    TurnOnLoadOC PORTE, 0, PBEACON
    
SkipOn7:
    incf FSR, f
	;PDOWNLINK
    btfss Channel, PDOWNLINK
    goto SkipOn6
    
    CheckLoadTimer
    
    goto SkipOn6
    
	#ifdef DEBUG	
		call Mpoweron
		call Mdownlink   
	#endif
    TurnOnLoadOC PORTE, 2, PDOWNLINK
    
SkipOn6:
    incf FSR, f
    ;PCONTROL
	btfss Channel, PCONTROL
    goto SkipOn5
    
    CheckLoadTimer
    
    goto SkipOn5
    
	#ifdef DEBUG	
		call Mpoweron
		call Mcontrol  
	#endif
	;turn on PTH
	bcf PORTD, 1
    TurnOnLoadOC PORTC, 2, PCONTROL
    
SkipOn5:
  	incf FSR, f
	;POBC
    btfss Channel, POBC
    goto SkipOn4
    
    CheckLoadTimer
    
    goto SkipOn4
    
	#ifdef DEBUG	
		call Mpoweron
		call Mobc  
	#endif
	;turn on PTH
	bcf PORTC, 5
    TurnOnLoadOC PORTD, 2, POBC
    
SkipOn4:
    incf FSR, f
	;PGPS
    btfss Channel, PGPS
    goto SkipOn3
    
    CheckLoadTimer
    
    goto SkipOn3
    
	#ifdef DEBUG	
		call Mpoweron
		call Mgps
	#endif
	;turn on PTH
	bcf PORTD, 6
    TurnOnLoadOC PORTD, 4, PGPS
    
SkipOn3:
	
	;check if OC pin is low: if low switch off the Load and set it's timer
 
    movlw Timer7
    movwf FSR
   
    ;skip check if load is turned off
    ;PBEACON
	;btfss TPS_EN, PBEACON
	btfss LoadStatus, PBEACON
    goto SkipOff7
 	
    btfsc PORTE, 1 ;OC Pin of TPS
    goto SkipOff7
	
	#ifdef DEBUG
		call Mpoweroff
		call Mbeacon
	#endif
    TurnOffLoadOC PORTE, 0, PBEACON
    
SkipOff7:
    incf FSR, f
    
    ;PDOWNLINK
    ;btfss TPS_EN, PDOWNLINK
	btfss LoadStatus, PDOWNLINK
    goto SkipOff6
    
    btfsc PORTC, 0
    goto SkipOff6
    
	#ifdef DEBUG	
		call Mpoweroff
		call Mdownlink   
	#endif
	TurnOffLoadOC PORTE, 2, PDOWNLINK
    
SkipOff6:
    incf FSR, f

	;PCONTROL
    ;btfss TPS_EN, PCONTROL
	btfss LoadStatus, PCONTROL
    goto SkipOff5	
	
    btfsc PORTD, 0
    goto SkipOff5
   
	#ifdef DEBUG
		call Mpoweroff
		call Mcontrol
	#endif
	;turn off PTH
	bsf PORTD, 1
    TurnOffLoadOC PORTC, 2, PCONTROL
	
SkipOff5:
  	incf FSR, f

    ;POBC
    ;btfss TPS_EN, POBC
	btfss LoadStatus, POBC
    goto SkipOff4  

    btfsc PORTD, 3
    goto SkipOff4
    
	#ifdef DEBUG	
		call Mpoweroff
		call Mobc
	#endif
	;turn off PTH
	bsf PORTC, 5
    TurnOffLoadOC PORTD, 2, POBC
    
SkipOff4:
 	incf FSR, f

    ;PGPS
    ;btfss TPS_EN, PGPS
	btfss LoadStatus, PGPS
    goto SkipOff3
    
    btfsc PORTD, 5
    goto SkipOff3
    
	#ifdef DEBUG
		call Mpoweroff
		call Mgps    
	#endif         
	;turn off PTH
	bsf PORTD, 6                              
    TurnOffLoadOC PORTD, 4, PGPS
    
SkipOff3:

    ;Overvoltage and low power bits in BatteryStatus
    ;LP2 OV3 LP3 - OV1 LP1 OV2 -
    ;clrf BatteryStatus
    ;movlw b'11100000'
    ;andwf PORTD, W
    ;movwf BatteryStatus
    
    ;movlw b'00001110'
    ;andwf PORTB, W
    ;iorwf BatteryStatus, f
    
    ;Safe Mode check: If Battery Voltage drops below 3.2 V power off PCONTROL, PGPS, PDOWNLINK: ADC Value is VBAT/2
    
    ;movlw 0x29      ;(VBat/2)*(255/5)
    ;subwf BatteryVoltage, W
    ;btfsc STATUS, C
    ;goto SkipSafeMode
    
    ;check whether it will be switched by the OC code
    ;bcf PORTC, PCONTROL
    ;bcf PORTC, PGPS
    ;bcf PORTD, PDOWNLINK
    
    ;bcf LoadStatus, PCONTROL
    ;bcf LoadStatus, PGPS
    ;bcf LoadStatus, PDOWNLINK
    
SkipSafeMode:

	;increment timer required for OC
	incf Timer, f
	
	;0.2 second delay for the main loop
	movlw 2 ;0.1973815 sec delay
	call DelayS

	goto Loop

Kill:
	call Shutdown
	 
EndLoop
	nop
	goto EndLoop
	
	end

