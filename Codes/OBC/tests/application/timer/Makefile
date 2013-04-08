MCU = atmega16

PROJ = test

TARGET = $(PROJ).out

CFLAGS = -g -mmcu=$(MCU) -Os \
	-fpack-struct -fshort-enums             \
	-funsigned-bitfields -funsigned-char    \
	-Wall -Wstrict-prototypes               \
	-Wa,-ahlms=$(firstword                  \
	$(filter %.lst, $(<:.c=.lst)))
	
LDFLAGS=-Wl,-Map,$(TARGET).map -mmcu=$(MCU) -lm
	
OBJ = timer.o main.o


LST = $(OBJ:.o=.lst)

all: $(TARGET)

$(TARGET): $(OBJ)
	avr-gcc $(OBJ) -o $(TARGET) $(LDFLAGS)
    
%.o: %.c
	avr-gcc $(CFLAGS) -c $< -o $@

%.hex: %.out
	avr-objcopy -O ihex $< $@

program: $(PROJ).hex
	avrdude -c usbasp -P usb -p $(MCU) -U flash:w:$<

clean:
	rm -f $(OBJ) $(LST) 
	rm -f $(PROJ).hex $(TARGET) $(TARGET).map
size: $(TARGET)
	avr-size $(TARGET)
