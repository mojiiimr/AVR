#include "aKaReZa.h"

#define _dury(x)  ((x*156)/(100))
#define _ServoDeg(x) OCR0B= 0.0845*x + 4.68 // 0 degree = 4.68 , 180 degree = 19.89

uint8_t deg=0;

int main(void)
{

/*Waveform Generation Mode PWM Phase Correct with OCRA Top */

// Set Phase Correct with OCRA as TOP
bitSet  (TCCR0A, WGM00);
bitClear(TCCR0A, WGM01);
bitSet  (TCCR0B, WGM02);

// Set Prescaler to 1024
bitSet  (TCCR0B, CS02);
bitClear(TCCR0B, CS01);
bitSet  (TCCR0B, CS00);

// Set OCRA value
OCR0A = 156;

//Set OCROB , non-inverting mode
bitClear(TCCR0A, COM0B0);
bitSet  (TCCR0A, COM0B1);

// Set OCROB pin as output
GPIO_Config_OUTPUT(OC0B_Config, OC0B_Pin);

//OCR0B = _dury(7.5); // 3% duty cycle

  while (1)
  {
    // for (deg=0; deg<=180; deg++)
    // {
    //   _ServoDeg(deg);
    //   _delay_ms(25);
    // }
    // for (deg=180; deg>0; deg--)
    // {
    //   _ServoDeg(deg);
    //   _delay_ms(25);
    // }
  

    // Your main code here
  }
}