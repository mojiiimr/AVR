#include "Timer1CTC.h"

void Timer1CTC_Init(bool _initstause)
{
    if(_initstause)
    {
       
     // Timer1 ---> Mode(4) ---> CTC Mode
         bitClear(TCCR1A, WGM10); 
         bitClear(TCCR1A, WGM11);
         bitSet(TCCR1B, WGM12); 
         bitClear(TCCR1B, WGM13);
    
    //Compare Output Mode ---> Toggle OC1A on Compare Match 
         bitSet(TCCR1A, COM1A0);
         bitClear(TCCR1A, COM1A1);    
    //OC1A as output 
        GPIO_Config_OUTPUT(DDRB, DDB5); 

    // Prescaler 1024 for Timer1 12MHz/1024 = 11718.75Hz
        bitSet(TCCR1B, CS10);
        bitClear(TCCR1B, CS11);
        bitSet(TCCR1B, CS12);
  
    //initilization of OC1A
        OCR1A = 15625; // Set the compare value for Timer1 for 1ms at 12MHz with prescaler 64
    
    
    }
    else
    {
        // Disable interrupt for Timer1 overflow
        bitClear(TIMSK1, TOIE1);
        // Disable global interrupts
        globalInt_Disable;
        // Stop Timer1 by clearing the clock source bits
        bitClear(TCCR1B, CS10);
        bitClear(TCCR1B, CS11);
        bitClear(TCCR1B, CS12);
    }
}