#include "aKaReZa.h"

char lcd[17]; // 16 characters + null terminator
uint8_t counter=0; 
uint8_t RXdata;
volatile extern bool usart_RxFlag ; //True: RX Complete
extern char usart_Rxbuffer[Buffer_size];
extern bool usart_errFlag; //True:OverFlow



int main(void)
{
    globalInt_Enable;
    usart_Init(Initialize);
    alcd_init();
    usart_Putsln("Mojtaba");
   
    while (1) 
    {
        if (usart_RxFlag)
            {
            alcd_gotoxy(0,0);
            alcd_clear();
            alcd_puts(usart_Rxbuffer);
            usart_Flush();
            }
    
        if(usart_errFlag)
        {
            alcd_clear();
            alcd_puts("usart_errFlag");
            usart_Flush();
        }
    }
        
}