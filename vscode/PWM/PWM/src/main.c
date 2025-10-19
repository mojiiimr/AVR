#include "aKaReZa.h"

#define _duty(x) (uint8_t) ((x*255.0)/100)

int main()
{

    // waveform Generation Mode: Fast PWM (Top=0xFF)
    bitClear(TCCR0B, WGM02);
    bitSet(TCCR0A, WGM00);
    bitSet(TCCR0A, WGM01);
    // Compare Output Mode: Non-Inverting Mode
    bitClear(TCCR0A, COM0A0);
    bitSet(TCCR0A, COM0A1);
    // Set Prescaler = F_CPU/64
    bitClear(TCCR0B, CS02);
    bitSet(TCCR0B, CS01);
    bitSet(TCCR0B, CS00);

    // Set PB7/OC0A as output
    GPIO_Config_OUTPUT(DDRB, PB7);


    while(1)
    {
        for(uint8_t dutyCycle = 0; dutyCycle <= 100; dutyCycle++)
        {
            OCR0A = _duty(dutyCycle);
            _delay_ms(10);
        }
    }
}