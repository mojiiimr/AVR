#include "einterrupt.h"
 
extern uint16_t Counter;

// External Interrupt 2 Service Routine (for SW1)
ISR(INT2_vect) 
{
 Counter += 1000;
 eINT3_Init(deInitialize); // Disable external interrupt 2 (SW1)
}

// External Interrupt 3 Service Routine (for SW2)
ISR(INT3_vect)
{
    Counter += 100;
   
}

// interrupt service routine for pin change interrupt 0 (for SW3)
ISR(PCINT0_vect)
{
    static bool lastState = 0;
    bool currentState = SW3_isPressed;
    if (currentState != lastState) {
        if (currentState == 1) { // Button pressed
            Counter += 10;
        }
        lastState = currentState;
    }
    eINT3_Init(initialize); // Re-enable external interrupt 2 (SW1)
}


//functions

void eINT2_Init(bool initStatus)
{   
    if (initStatus) {
        bitSet(EIMSK, INT2); // Enable external interrupt 2 (SW1)
        bitClear(EICRA, ISC20); // Trigger on rising edge
        bitSet(EICRA, ISC21); // Trigger on rising edge
    } else {
        bitClear(EIMSK, INT2); // Disable external interrupt 2 (SW1)
    }
}

void eINT3_Init(bool initStatus)
{
    if (initStatus) {
        bitSet(EIMSK, INT3); // Enable external interrupt 3 (SW2)
        bitClear(EICRA, ISC30); // Trigger on rising edge
        bitSet(EICRA, ISC31); // Trigger on rising edge
        Interrupt_Flag_Clear(EIFR, INTF3); // Clear any pending interrupt flag for INT3
    } else {
        bitClear(EIMSK, INT3); // Disable external interrupt 3 (SW2)
    }
}


void pcINT0_Init(bool initStatus)
{   
    if (initStatus) {
        bitSet(PCICR, PCIE0); // Enable pin change interrupt 0 (SW3)
        bitSet(PCMSK0, PCINT5); // Enable pin change interrupt for SW3 (PB5)
    } else {
        bitClear(PCICR, PCIE0); // Disable pin change interrupt 0 (SW3)
        bitClear(PCMSK0, PCINT5); // Disable pin change interrupt for SW3 (PB5)
    }
}



