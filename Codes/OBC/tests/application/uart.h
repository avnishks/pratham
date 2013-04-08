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
void send_UART(char *data)
{
    uint16_t i = 0;
    while(data[i] != '\0')
    {
        while ( !(UCSRA & (_BV(UDRE))) );
        UDR = data[i];
        i++;
    }
}
  
