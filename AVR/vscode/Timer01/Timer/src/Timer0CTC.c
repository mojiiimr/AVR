#include "Timer0CTC.h"

    ISR(TIMER0_COMPA_vect)
    {
      static uint16_t counter = 0;
        counter++;
        if(counter == 1000) // 1000ms = 1 second
        {
            bitToggle(PORTB, PORTB6); // Toggle an LED connected to PORTB7
            counter = 0; // Reset counter
        }
    }

void Timer0CTC_Init(bool _initstause)
{
    if(_initstause)
    {
       GPIO_Config_OUTPUT(DDRB, DDB6); // Configure PORTB6 as output for LED
     // Timer0 ---> Mode(2) ---> CTC Mode
         bitClear(TCCR0A, WGM00); 
         bitSet(TCCR0A, WGM01);
         bitClear(TCCR0B, WGM02); 
    
    //Compare Output Mode ---> Toggle OC0A on Compare Match 
         bitSet(TCCR0A, COM0A0);
         bitClear(TCCR0A, COM0A1);    
    //OC0A as output 
        GPIO_Config_OUTPUT(DDRB, DDB7); 

    // Prescaler 64 for Timer0 12MHz/64 = 187.5kHz
        bitSet(TCCR0B, CS01);
        bitSet(TCCR0B, CS00);
        bitClear(TCCR0B, CS02);
  
    //initilization of OC0A
        OCR0A = 188; // Set the compare value for Timer0 for 1ms at 12MHz with prescaler 64

    // Enable interrupt for Timer0 compare match
        bitSet(TIMSK0, OCIE0A);
    // Enable global interrupts 
        globalInt_Enable;
    }
    else
    {
        // Disable interrupt for Timer0 overflow
        bitClear(TIMSK0, TOIE0);
        // Disable global interrupts
        globalInt_Disable;
        // Stop Timer0 by clearing the clock source bits
        bitClear(TCCR0B, CS00);
        bitClear(TCCR0B, CS01);
        bitClear(TCCR0B, CS02);


    }

}
