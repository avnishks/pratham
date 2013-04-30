
	list		p=16f877a	; list directive to define processor
	#include	<p16f877a.inc>	; processor specific variable definitions

;write the config bits
    __CONFIG _CP_OFF & _WDT_OFF & _BODEN_OFF & _PWRTE_ON & _HS_OSC & _LVP_OFF & _CPD_OFF 

;TODO
;uplink

cblock 0x20
	LoadStatus


	;0x21 stores ADC HM data
	;BatteryCurrent<--
	TotalCurrent

	;BatteryVoltage<--
	BatteryVoltageBy2

	;Panel<--
	ConsumptionCurrent

	SixVolt
 	
	;ThreeVolt<--
	DownlinkVoltageBy2	

    ;Overvoltage and low power of battery
    BatteryStatus
    
    
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
	Delay
	
	endc

;OBC Command Byte format
BEACONPOWER equ 7
PCONTROL equ 6
PGPS equ 5
PCC equ 4
POBC equ 3
PMAG equ 2

w_temp equ 0x70 ; variable used for context saving
status_temp equ 0x71 ; variable used for context saving
fsr_temp equ 0x72

I2C_ADDR equ 0x44


CheckLoadTimer macro

	movf Timer, W
    subwf INDF,W
	btfss STATUS, Z
    
	endm

TurnOnLoadOC macro  PORTW, COMPONENT
    
    bsf PORTW, COMPONENT
    bsf LoadStatus, COMPONENT
    
	endm

TurnOffLoadOC macro PORTCHECK, COMPONENTCHECK

    bcf PORTCHECK, COMPONENTCHECK
    bcf LoadStatus, COMPONENTCHECK
    movf Timer, W
    movwf INDF
    
	endm
    
CheckLoadOBC macro PORTW, COMPONENT

    btfss CommandByte, COMPONENT  
    bcf PORTW, COMPONENT
    btfsc CommandByte, COMPONENT
    bsf PORTW, COMPONENT
    
    endm

; ############################################################# macros end here ##############################################
	org 0x0000
	
	goto SleepMode
	
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

	bcf PIR1, SSPIF
	bcf INTCON, INTF

ExitISR: 

	movf    status_temp, W     ; retrieve copy of STATUS register
	movwf	STATUS            ; restore pre-isr STATUS register contents
	movf    fsr_temp, W     ; retrieve copy of FSR register
	movwf	FSR            ; restore pre-isr FSR register contents
	movf w_temp, W	;restore pre-isr W register
	retfie                    ; return from interrupt	

I2CHandler:
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
	; Beacon : Control: GPS: CC : OBC : Reserved: Reserved: Reserved
    banksel ADCON0
    
    btfsc TWIByte, 0
    goto SkipI2CData
    
    ;Check if Load has been turned off by Power MuC even when it should be on according to the OBC
    movwf CommandByte
    movwf BatteryStatus
    xorwf LoadStatus, f
    
	
	;Beacon
	btfss LoadStatus, BEACONPOWER
	goto SkipCheck7
	
    CheckLoadOBC PORTE, 0
    
SkipCheck7:
	;Control
	btfss LoadStatus, PCONTROL
	goto SkipCheck6
	
    CheckLoadOBC PORTC, 1

SkipCheck6:
	;GPS
	btfss LoadStatus, PGPS
	goto SkipCheck5
	
    CheckLoadOBC PORTC, 6

SkipCheck5:
	;CC
	btfss LoadStatus, PCC
	goto SkipCheck4
	
    CheckLoadOBC PORTE, 2
	
SkipCheck4:
	;OBC
	btfss LoadStatus, POBC
	goto SkipCheck3
	
    CheckLoadOBC PORTD, 2

SkipCheck3:
	;MAG
	btfss LoadStatus, PMAG
	goto SkipCheck2
	
    CheckLoadOBC PORTD, 5

SkipCheck2:
	;Copy CommandByte to LoadStatus
	movf CommandByte, W
	movwf LoadStatus

SkipI2CData:
	clrf TWIByte

ExitI2C:
	nop
	return

; ################################ old TPS shutdown ####################
;~ Shutdown:
  ;~ ; Kill. all loads
	;~ bcf PORTE, 0
	;~ bcf PORTC, 1
	;~ bcf PORTC, 6
	;~ bcf PORTE, 2
	;~ bcf PORTD, 2
	;~ bcf PORTD, 5
	;~ return
;#######################################################################

;##################### new PTH shutdown ################################
Startup:
	bcf PORTC, 1 ; downlink and beacon
	bcf PORTD, 1 ; torquers
	bcf PORTC, 5 ; OBC
	bcf PORTD, 6 ; GPS
	bcf PORTD, 7 ; Magnetometer
	return 

Shutdown:
	bsf PORTC, 1 ; downlink and beacon
	bsf PORTD, 1 ; torquers
	bsf PORTC, 5 ; OBC
	bsf PORTD, 6 ; GPS
	bsf PORTD, 7 ; Magnetometer
	return

;################ USART #################
Send:
	movwf TXREG
	call DelayTX
	return

; ---------------------------
; Message to send at startup
; ---------------------------
Message1:
	movlw 	'\r'		
	call	Send
	movlw 	'\r'		
	call	Send
	movlw 	'\r'		
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

	movlw 	'\t'
	call	Send
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
	movlw 	'\r'
	call	Send
	return

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

DelayTX:
 	movlw 4
	clrf 0x61
Delay19:
	clrf 0x60
Delay18:
	incfsz 0x60, f
	goto Delay18
	
	incfsz 0x61, f
	goto Delay19

  	return
;##########################################################
	
DelayS:
	movf Delay, W
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
; ########################## UART ####################################
	banksel ADCON1
	bsf TRISC, 7
	bcf TRISC, 6
	movlw 0x0C
	movwf SPBRG			 ;9600 baud ; Husain chutiya hai !! and baud 4800 hai
	clrf TXSTA
	bsf TXSTA, TXEN		 ;enable transmitter
;	movlw b'00100100'       ; brgh = high (2)
;   movwf TXSTA             ; enable Async Transmission, set brgh
	
	banksel ADCON0
	clrf RCSTA
	bsf RCSTA, SPEN		 ;enable UART on the pins
;	movlw b'10010000'       ; enable Async Reception
;    movwf RCSTA
	
	movlw 0x22
	movwf 0x70
	
; Message to send at startup
Message:
	call Message1
	call Delay_1s
	movlw '1' ; corresponding to sleep mode
	call Send
	movlw '\n'
	call Send
########################################################################

	banksel ADCON1
	;set RB0 as input for SNAP
	bsf TRISB, 0
	
	;~ ;set RC2 as input for Preflight
    ;~ bsf TRISC, 2
    ;~ ;enable interrupt for Preflight
    ;~ bsf PIE1, CCP1IE
    
	
	;enable output on the PTH inhibit pins
	bcf TRISC, 1
	bcf TRISD, 1
	bcf TRISC, 5
	bcf TRISD, 6
	bcf TRISD, 7

;########################### old ##############################
	;~ bcf TRISC, 1	; PTH inhibit of Beacon & downlink
	;~ bcf TRISC, 6 
	;~ bcf TRISE, 0
	;~ bcf TRISE, 2
	;~ bcf TRISD, 2
	;~ bcf TRISD, 5
;################################################################
	banksel ADCON0
	
	;configure Preflight Interrupt
	movlw 0x05
    movwf CCP1CON
    
    ;switch off all loads
    call Shutdown
    ;goto SleepMode
	
	;switch on the INT interrupt for wake up from sleep
	bsf INTCON, PEIE
  
	bsf INTCON, INTE
	bsf INTCON, GIE	
	bcf INTCON, INTF
	bcf PIR1, CCP1IF
	goto RealSleep  
 
RealSleep:
	movlw '2' ; going to sleep mode
	call Send
	
	sleep
	
	nop
	
	;2 second delay to confirm that the interrupt is not a fake
	;~ movlw 20
	;~ movwf Delay
	;~ call DelayS
	
	;Check Snap pin
	btfsc PORTB, 0
	goto Snap
	
	movlw '3' ; still in sleep mode
	call Send
	;Check Preflight Pin
	btfsc PORTC, 2
	goto Preflight
	
	goto RealSleep
	
Snap:
	;Implement the Eject Delay
	movlw '4' ; I snapped
	call Send
	
	clrf State
	goto Start
	
Preflight:
	movlw 0xFF
	movwf State


Start: 
	movlw '5' ; Lets get this started
	call Send
	
	banksel ADCON1
	;enable input on the batterystatus lines
    ;bsf TRISD, 7
    ;bsf TRISD, 6
    ;bsf TRISD, 5
    ;bsf TRISB, 3
    ;bsf TRISB, 2
    ;bsf TRISB, 1
    
    ;enable input on the Uplink lines
    bsf TRISB, 5
	bsf TRISB, 4
	
;############################### switching on all PTH #################
	call Startup

	;configure ADC
	clrf ADCON1

	;set ADC ports as input	
	movlw 0xFF
	movwf TRISA

	;confugure I2C
	clrf SSPSTAT
	clrf SSPCON2
	;configure address of I2C slave
    movlw I2C_ADDR
    movwf SSPADD

	;configure I2C ports as Input
	bsf TRISC, 3
	bsf TRISC, 4
	
	
	;enable input on the OC lines
	bsf TRISD, 0 ;PCONTROL
	bsf TRISC, 7 ;GPS
	bsf TRISD, 3 ;OBC
	bsf TRISE, 1 ;Beacon
	bsf TRISC, 0 ;CC

	;Enable SSP/I2C interrupt
	bsf PIE1, SSPIE

	banksel ADCON0	
    
    ;switch on the components

    bsf PORTE, 0
   ; bsf PORTD, 2
    bsf PORTC, 1
    

	movlw b'11001000'
	movwf LoadStatus
    movwf CommandByte

	
	;configure I2C

	movlw 0x36
	movwf SSPCON
	
	;Clear I2C interrupt flag
	clrf PIR1

	;Timer for OC and main Loop
	clrf Timer
	clrf HMCounter
	
	clrf BatteryStatus
	clrf TWIByte

;main loop
Loop:

	movlw '6'
	call Send
	;Uplink check
	btfss PORTB, 5
	goto SkipUplink
	
	;2 second delay to confirm that the interrupt is not a fake
	movlw 20
	movwf Delay
	call DelayS
	
	;Test Interrupt pin
	btfss PORTB, 5
	goto SkipUplink
	
	;Check data line, if high Kill satellite
	btfsc PORTB, 4
	goto Kill
	
	;Low: Reset
	call Shutdown
	
	;0.5 second Delay for components to shutdown
	movlw 5
	movwf Delay
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
	btfss PORTC, 2
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
	movlw '7' ; corresponding to checking loads
	call Send
	;select Channel in ADCON0
	movf InverseCount,W
	movwf Channel
	bcf STATUS, C
	
	rlf Channel,f
	rlf Channel,f
	rlf Channel,f
	
	movf Channel, W
	iorlw 0x81
	movwf ADCON0
	
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
	
	;OC code
	;If component switched off and it should be on according to the OBC:
	;Check the Components timer, if 1 min is over, to switch it on again
    ;confirm if component is switched off oc pin is high
	movf CommandByte, W
	xorwf LoadStatus, W
	;check if Load is off and OBC wants it on
	movwf Channel
	
    ;Storing address of Timer for future reference of the temporary timers of the Loads
    movlw Timer
    movwf FSR
    
    incf FSR, f
    
    btfss Channel, BEACONPOWER
    goto SkipOn7
    ;Compare Timer and temporary Timer
    CheckLoadTimer
    
    goto SkipOn7
    ;If equal Turn on the Load
    TurnOnLoadOC PORTE, 0
    
SkipOn7:
    incf FSR, f
    
	btfss Channel, PCONTROL
    goto SkipOn6
    
    CheckLoadTimer
    
    goto SkipOn6
    
    TurnOnLoadOC PORTC, 1
    
SkipOn6:
    incf FSR, f

    btfss Channel, PGPS
    goto SkipOn5
    
    CheckLoadTimer
    
    goto SkipOn5
    
    TurnOnLoadOC PORTC, 6
    
SkipOn5:
    incf FSR, f

    btfss Channel, PCC
    goto SkipOn4
    
    CheckLoadTimer
    
    goto SkipOn4
    
    TurnOnLoadOC PORTE, 2
    
SkipOn4:
    incf FSR, f

    btfss Channel, POBC
    goto SkipOn3
    
    CheckLoadTimer
    
    goto SkipOn3
    
    TurnOnLoadOC PORTD, 2
    
SkipOn3:
	
	;check if OC pin is low: if low switch off the Load and set it's timer
    
    movlw Timer
    movwf FSR
    
    incf FSR, f
    ;BEACONPOWER
    ;skip check if load is turned off
    btfss PORTE, 0
    goto SkipOff7
    btfsc PORTE, 1
    goto SkipOff7

    TurnOffLoadOC PORTE, 0
    
SkipOff7:
    incf FSR, f
	
		;PCONTROL
    btfss PORTC, 1
    goto SkipOff6
	
	
    btfsc PORTD, 0
    goto SkipOff6
    
    TurnOffLoadOC PORTC, 1
    
SkipOff6:
    incf FSR, f

    ;PGPS
    btfss PORTC, 6
    goto SkipOff5
    
    btfsc PORTC, 7
    goto SkipOff5
    
    TurnOffLoadOC PORTC, 6
    
SkipOff5:
    incf FSR, f
    
    ;PCC
    btfss PORTE, 2
    goto SkipOff4
    
    btfsc PORTC, 0
    goto SkipOff4
    
    TurnOffLoadOC PORTE, 2
    
SkipOff4:
    incf FSR, f

    ;POBC
    btfss PORTD, 2
    goto SkipOff3   

    btfsc PORTD, 3
    goto SkipOff3
    
    TurnOffLoadOC PORTD, 2
    
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
    
    ;Safe Mode check: If Battery Voltage drops below 3.2 V power off PCONTROL, PGPS, PCC: ADC Value is VBAT/2
    
    ;movlw 0x29      ;(VBat/2)*(255/5)
    ;subwf BatteryVoltage, W
    ;btfsc STATUS, C
    ;goto SkipSafeMode
    
    ;check whether it will be switched by the OC code
    ;bcf PORTC, PCONTROL
    ;bcf PORTC, PGPS
    ;bcf PORTD, PCC
    
    ;bcf LoadStatus, PCONTROL
    ;bcf LoadStatus, PGPS
    ;bcf LoadStatus, PCC
    
SkipSafeMode:

	;increment timer required for OC
	incf Timer, f
	
	;0.2 second delay for the main loop
	movlw 2
	movwf Delay
	call DelayS

	goto Loop

Kill:
	call Shutdown
	 
EndLoop
	nop
	goto EndLoop
	
	end

