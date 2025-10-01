#include "usart.h"

void usart_Init(bool _initStatus)
{
    if(_initStatus)
    {
        bitSet(DDRE,1); // TXD0 ,   set as output
        bitSet(PORTE,1); // TXD0 ,   set high

        //Asynchronous mode, no parity, 1 stop bit, 8 bit size
        bitClear(UCSR0C,UMSEL01);  // Asynchronous mode
        bitClear(UCSR0C,UMSEL00);  // Asynchronous mode
        bitClear(UCSR0C,UPM01);    // No parity
        bitClear(UCSR0C,UPM00);    // No parity
        bitClear(UCSR0C,USBS0);    // 1 stop bit
        bitSet(UCSR0C,UCSZ01);     // 8 bit size
        bitSet(UCSR0C,UCSZ00);     // 8 bit size
        bitClear(UCSR0B,UCSZ00);   // 8 bit size
        // Tx enable
        bitSet(UCSR0B,TXEN0); 
        // Baud rate: 9600, for 16MHz clock
        UBRR0L = 103;
        UBRR0H = 0;
    }
    else
    {
        // Tx disable
        bitClear(UCSR0B,TXEN0);
        // Clear UBRR registers
        UBRR0L = 0;
        UBRR0H = 0;
        // Clear UCSR registers
        UCSR0A = 0;
        UCSR0B = 0;
        UCSR0C = 0;
        // Set TXD pin as input (high impedance)
        bitClear(DDRE,1);
        bitClear(PORTE,1);
    }
    
}

void usart_Write(uint8_t _Data)
{
    // Wait for empty transmit buffer
    while ( !( UCSR0A & (1<<UDRE0)) );
    // Put data into buffer, sends the data
    UDR0 = _Data;
    while(!bitCheck(UCSR0A,TXC0));
}


void usart_Puts(char* _String)
{
    while(*_String !='\0')
    {
        usart_Write(*_String++);
    }
}

void usart_Putsln(char* _String)
{
    while(*_String !='\0')
    {
        usart_Write(*_String++);
    }
    usart_Write('\r');
    usart_Write('\n');
}