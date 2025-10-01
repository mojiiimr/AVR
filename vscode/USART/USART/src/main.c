#include "aKaReZa.h"

char lcd[17]; // 16 characters + null terminator
uint8_t counter=0; 
int main(void)
{
    usart_Init(Initialize);
    alcd_init();
    alcd_clear();
    usart_Putsln("MOJIIIJOON");
    alcd_puts("MOJIIIJOON");
    delay_ms(1000);
    while (1) 
    {
      sprintf(lcd,"Counter: %d",counter++);
      alcd_gotoxy(0,0);
      usart_Putsln(lcd);
      alcd_puts(lcd); 
      delay_ms(100);
    }
}