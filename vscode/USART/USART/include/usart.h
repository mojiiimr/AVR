#ifndef _usart_h_
#define _usart_h_
#include "aKaReZa.h"
// USART0 TX on PE1
#define __usart_TX_Congig DDRE
#define __usart_TX_Control PORTE
#define __usart_TX_Bit 1
// USART0 RX on PE0
#define __usart_RX_Congig DDRE
#define __usart_RX_Control PORTE
#define __usart_RX_Bit 0

#define Buffer_size 33 // 32 byte Data + 1 null
#define usart_frameError bitCheck(UCSR0A,FE0) //Check FramError Bir
#define usart_DataOverRight bitCheck(UCSR0A,DOR0); //Check DataOverRight Bit

void usart_Init(bool _initStatus);
void usart_Write(uint8_t _Data);
void usart_Puts(char* _String);
void usart_Putsln(char* _String);
uint8_t usart_getChar(void); // Get Character from Serial Port
void usart_Flush(void); // Flush the usartBuffer


#endif