#include "aKaReZa.h"
 #define _dalay(x)  ((x*156)/100) //

 int main(void)
 {
      // Period Frequency = 50 Hz
      // Period Time = 20 ms
     /* Initialize Waveform Generation Timer0 in Phase Correct PWM Mode
      with OCRA as TOP and prescaler 1024  */

      // Set Waveform Generation Mode to Phase Correct PWM with OCRA as TOP
     bitSet  ( TCCR0A, WGM00);
     bitClear( TCCR0A, WGM01);
     bitSet  ( TCCR0B, WGM02);

     // Set Prescaler to 1024
     bitSet   (TCCR0B, CS00);
     bitClear (TCCR0B, CS01);
     bitSet   (TCCR0B, CS02);

     //Set OC0B as non-inverting mode
     bitClear ( TCCR0A, COM0B0);
     bitSet   ( TCCR0A, COM0B1);

     //Config OC0B Pin as Output
     GPIO_Config_OUTPUT(OC0B_Config, OC0B_Pin);

     // Set OCRA for 20 ms Period Time (generate PWM Waveform with 50 Hz Frequency)
     OCR0A = 156;  // TOP Value

     // Set Initial Duty Cycle
     OCR0B=_dalay(3); // 3 ms Pulse Width for 90 Degree Position


      

     /* Enable global interrupts */
     globalInt_Enable;

     while (1)
     {
         /* Main loop code */
     }

     return 0;
 }