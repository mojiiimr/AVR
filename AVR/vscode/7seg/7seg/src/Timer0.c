#include "Timer0.h"


extern uint16_t Counter;

// Timer0 overflow interrupt service routine
    ISR(TIMER0_OVF_vect)
    {
      static uint16_t timcount=0;
      seg7_Puts(Counter);
      timcount++;
        if(timcount==769) // 1 second elapsed (187.5KHz/187 = 1000ms)
        {
            timcount=0;
            Counter++;
            if(Counter>9999) Counter=0;
        }

    }


void Timer0_Init(bool _initstause)
{
    if(_initstause)
    {
       
     // Timer0 ---> Mode(0) ---> Normal Mode
         bitSet(TCCR0A, WGM00); 
         bitSet(TCCR0A, WGM01);
         bitSet(TCCR0B, WGM02); 

    // Prescaler 64 for Timer0 12MHz/64 = 187.5KHz
        bitSet(TCCR0B, CS00);
        bitSet(TCCR0B, CS01);
        bitClear(TCCR0B, CS02);

    // Enable interrupt for Timer0 overflow
        bitSet(TIMSK0, TOIE0);

    
    }
    else
    {
        // Disable interrupt for Timer0 overflow
        bitClear(TIMSK0, TOIE0);
        // Disable global interrupts
        // Stop Timer0 by clearing the clock source bits
        bitClear(TCCR0B, CS00);
        bitClear(TCCR0B, CS01);
        bitClear(TCCR0B, CS02);


    }

}
