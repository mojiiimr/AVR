#include "usart.h"

    bool usart_RxFlag=false;        //True: RX Complete
    bool usart_RxbufferOVF=false;   //True:OverFlow
    bool usart_errFlag =false ;     //True: Error Occur
    char usart_Rxbuffer[Buffer_size];
    uint8_t _bufferIndex=0; 
void usart_Init(bool _initStatus)
{
    if(_initStatus)
    {
        bitSet(__usart_TX_Congig,__usart_TX_Bit); // TXD0 ,   set as output
        bitSet(__usart_TX_Control,__usart_TX_Bit); // TXD0 ,   set high
        bitClear(__usart_RX_Congig,__usart_RX_Bit); // RXD0 ,   set as input
        bitSet(__usart_RX_Control,__usart_RX_Bit); // RXD0 ,   set high (pull-up enabled)

        //Asynchronous mode, no parity, 1 stop bit, 8 bit size
        bitClear(UCSR0C,UMSEL01);  // Asynchronous mode
        bitClear(UCSR0C,UMSEL00);  // Asynchronous mode
        bitClear(UCSR0C,UPM01);    // No parity
        bitClear(UCSR0C,UPM00);    // No parity
        bitClear(UCSR0C,USBS0);    // 1 stop bit
        bitSet(UCSR0C,UCSZ01);     // 8 bit size
        bitSet(UCSR0C,UCSZ00);     // 8 bit size
        bitClear(UCSR0B,UCSZ00);   // 8 bit size

        
        bitSet(UCSR0B,TXEN0); // Tx enable
        
        bitSet(UCSR0B,RXEN0); // Rx enable

        bitSet(UCSR0B,RXCIE0); // Receive Interrupt Enable
        bitSet(UCSR0A,U2X0); //Double Speed

        // Baud rate: 115200, for 16MHz clock
        UBRR0H=0;
        UBRR0L=16;
        usart_Flush();
        
        
        
        
        
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

ISR(USART0_RX_vect)
{
    uint8_t _RxData;
    usart_errFlag=false;
    usart_errFlag = usart_RxbufferOVF |usart_frameError | usart_DataOverRight ;

    _RxData=UDR0;
    if( !usart_errFlag)
        {
        if(_RxData=='\n')
        {
            usart_Rxbuffer[_bufferIndex++]='\0';
            usart_RxFlag=true;
        }
        else
        {
            if(_RxData !='\r')
            {
            usart_Rxbuffer[_bufferIndex++]=_RxData;
            if (_bufferIndex>Buffer_size) usart_RxbufferOVF=true;
            }
        }
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

uint8_t usart_getChar(void)
{
    // Wait for data to be received
    while ( !bitCheck(UCSR0A,RXC0));
    // Get and return received data from buffer
    return UDR0;
}

void usart_Flush (void)
{
    uint8_t _index=0;
    for (_index=Buffer_size; _index<Buffer_size; _index++)
    {
        usart_Rxbuffer [_index]='\0';
    }
    usart_RxFlag=false;
     _bufferIndex=0; 
    usart_RxbufferOVF=false;
    usart_errFlag=false;
}