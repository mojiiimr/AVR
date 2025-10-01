#ifndef _usart_h_
#define _usart_h_
#include "aKaReZa.h"

void usart_Init(bool _initStatus);
void usart_Write(uint8_t _Data);
void usart_Puts(char* _String);
void usart_Putsln(char* _String);
#endif