void init_UART(void)
{
    UCSRA = 0;
    UCSRB = 0;
    UCSRC = 0;
    
    UCSRA |= (1<<U2X);
    UCSRB |=(1<<RXEN)|(1<<TXEN);
    UCSRC |=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

    UBRRL = 103;
    UBRRH = 0;
}
void send_UART(char *data, uint8_t size)
{
    uint16_t i;
    for(i = 0;i < size; i++)
    {
        while ( !(UCSRA & (_BV(UDRE))) );
        UDR = data[i];
    }
}
  
