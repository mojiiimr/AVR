#include "aKaReZa.h"

char lcd[17]; // 16 characters + null terminator
uint8_t counter=0; 
uint8_t RXdata;
int main(void)
{
    usart_Init(Initialize);
    alcd_init();
    alcd_clear();
   
    while (1) 
    {
        alcd_puts("Mojtaba");
        RXdata= usart_getChar();
        alcd_clear();
        delay_ms(1000);
    }
}