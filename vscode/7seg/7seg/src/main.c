#include "aKaReZa.h"

uint16_t Counter =0;
uint8_t Delay=0;

int main(void)
{
  
  GPIO_Init(); // Switches Initialization
  seg7_init(); // 7-Segment Initialization
  eINT2_Init(initialize); // External Interrupt Initialization for SW1
  eINT3_Init(initialize); // External Interrupt Initialization for SW2
  pcINT0_Init(initialize); // Pin Change Interrupt Initialization for SW3
  Global_INT_Enable(); // Enable global interrupts
  Timer0_Init(initialize); // Timer0 Initialization
  while(1)
  {
  
  };
};