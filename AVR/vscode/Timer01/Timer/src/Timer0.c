#include "Timer0.h"

// Timer0 overflow interrupt service routine
    ISR(TIMER0_OVF_vect)
    {
      // Set Offset value for Timer0
        TCNT0 = Timer0_InitValue; // Start counting from 0
    }


void Timer0_Init(bool _initstause)
{
    if(_initstause)
    {
       
     // Timer0 ---> Mode(0) ---> Normal Mode
         bitSet(TCCR0A, WGM00); 
         bitSet(TCCR0A, WGM01);
         bitSet(TCCR0B, WGM02); 

    //Compare Output Mode ---> Toggle OC0A on Compare Match 
         bitSet(TCCR0A, COM0A0);
         bitClear(TCCR0A, COM0A1);    

    // Prescaler 64 for Timer0 12MHz/64 = 250kHz
        bitSet(TCCR0B, CS01);
        bitSet(TCCR0B, CS00);
        bitClear(TCCR0B, CS02);
    // Enable interrupt for Timer0 overflow
        bitSet(TIMSK0, TOIE0);
     // Enable global interrupts
        globalInt_Enable;
    //OC0A as output 
        GPIO_Config_OUTPUT(DDRB, DDB7);  
  
    //initilization of OC0A
        OCR0A = 0xFF; // Set the compare value for Timer0
    
    // Set Offset value for Timer0
        TCNT0 = Timer0_InitValue; // Start counting from 0
    
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
