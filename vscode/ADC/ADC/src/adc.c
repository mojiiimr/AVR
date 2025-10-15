#include "adc.h"

void adc_Init(bool initStatus) 
{
    if (initStatus) {
        // Select Prescaler = F_CPU/128
        bitSet(ADCSRA, ADPS2);
        bitSet(ADCSRA, ADPS1);
        bitSet(ADCSRA, ADPS0);
        // Enable ADC
        bitSet(ADCSRA, ADEN);
        // Set reference voltage to AVcc
        bitSet(ADMUX, REFS0);
        bitClear(ADMUX, REFS1);
        // Set ADC to right adjust result
        bitClear(ADMUX, ADLAR);

        
    } else {
        // Disable ADC
        bitClear(ADCSRA, ADEN);
        // Clear ADMUX register
        ADMUX = 0;
        // Clear ADCSRA register
        ADCSRA = 0;
    }

}

uint16_t adc_Read(uint8_t _adcChannel) 
{
    // Select ADC Channel 
    bitChange(ADMUX, MUX0, bitCheck(_adcChannel, 0));
    bitChange(ADMUX, MUX1, bitCheck(_adcChannel, 1));
    bitChange(ADMUX, MUX2, bitCheck(_adcChannel, 2));
    bitChange(ADMUX, MUX3, bitCheck(_adcChannel, 3));
    bitChange(ADMUX, MUX4, bitCheck(_adcChannel, 4));
    bitChange(ADCSRB, MUX5, bitCheck(_adcChannel, 5));
    delay_ms(1); // ADC channel settling time

    // Start single conversion
    bitSet(ADCSRA, ADSC);

    // Wait for conversion to complete
    bitWaitHigh(ADCSRA, ADIF);
    intFlag_clear(ADCSRA, ADIF); // Clear ADIF by writing one to it

    return Combine_8to16(ADCH, ADCL); // Return ADC value
}