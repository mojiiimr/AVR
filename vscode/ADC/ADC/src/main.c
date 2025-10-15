#include "aKaReZa.h"

#define Vref 5.0
#define Gain Vref/1023

uint16_t adcValue=0;
char usartBuffer[20];
float adcVoltage=0;


int main(void)
{
    usart_Init(Initialize);
    globalInt_Enable;
    adc_Init(Initialize);
    
    while (1) 
    {
      usart_Puts("----------------------------------\r\n");
      //Read ADC channel 0 and convert to voltage
      adcValue = adc_Read(0); // Read ADC channel 0
      adcVoltage = adcValue * Gain; // Convert ADC value to voltage
      sprintf(usartBuffer, "ADC0 Value: %u\r\n , ADC0 Voltage: %.2f V\r\n", adcValue, adcVoltage);
      usart_Puts(usartBuffer);
      //Read ADC channel 30 and convert to voltage
      adcValue = adc_Read(30); // Read ADC channel 30
      adcVoltage = adcValue * Gain; // Convert ADC value to voltage
      sprintf(usartBuffer, "ADC30 Value(VBG): %u\r\n , ADC30 Voltage: %.2f V\r\n", adcValue, adcVoltage);
      usart_Puts(usartBuffer);
      delay_ms(2000);
    }
}