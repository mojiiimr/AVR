#ifndef __7seg_H
#define __7seg_H

#include <stdint.h>
#include "aKaReZa.h"
#define _7seg_A_Control PORTC
#define _7seg_A_Config  DDRC
#define _7seg_A_Pin     0

#define _7seg_B_Control PORTC
#define _7seg_B_Config  DDRC
#define _7seg_B_Pin     1

#define _7seg_C_Control PORTC
#define _7seg_C_Config  DDRC
#define _7seg_C_Pin     2

#define _7seg_D_Control PORTC
#define _7seg_D_Config  DDRC
#define _7seg_D_Pin     3

#define _7seg_E_Control PORTD
#define _7seg_E_Config  DDRD
#define _7seg_E_Pin     0

#define _7seg_F_Control PORTD
#define _7seg_F_Config  DDRD
#define _7seg_F_Pin     1

#define _7seg_G_Control PORTD
#define _7seg_G_Config  DDRD
#define _7seg_G_Pin     4

#define _7seg_DP_Control PORTD
#define _7seg_DP_Config  DDRD
#define _7seg_DP_Pin     7

#define _7seg_Digit1_Control PORTB
#define _7seg_Digit1_Config DDRB
#define _7seg_Digit1_Pin 0

#define _7seg_Digit2_Control PORTB
#define _7seg_Digit2_Config DDRB
#define _7seg_Digit2_Pin 1

#define _7seg_Digit3_Control PORTB
#define _7seg_Digit3_Config DDRB
#define _7seg_Digit3_Pin 2

#define _7seg_Digit4_Control PORTB
#define _7seg_Digit4_Config DDRB
#define _7seg_Digit4_Pin 4

#define _7seg_refreshDelay delay_ms(10)  

void seg7_init(void);
void seg7_Puts(uint16_t _7segValue);

#endif