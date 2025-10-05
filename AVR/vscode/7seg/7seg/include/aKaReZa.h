#ifndef _aKaReZa_H
#define _aKaReZa_H
#define bool _Bool
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "seg7.h"
#include <avr/interrupt.h>
#include "einterrupt.h"
#include <stdbool.h>
#include "Timer0.h"
//macro
#define bitSet(Reg, Bit) (Reg |= (1<<Bit))
#define bitClear(Reg, Bit) (Reg &= ~(1<<Bit))
#define bitToggle(Reg, Bit) (Reg ^= 1<<Bit)
#define bitCheck(Reg, Bit) ((Reg>>Bit) & 0x01)
#define bitChange(Reg, Bit, Value) (Value == 1 ? bitSet(Reg, Bit) : bitClear(Reg, Bit))
#define delay_ms(delay_msValue) _delay_ms(delay_msValue)
#define GPIO_Config_OUTPUT(Reg, Bit) bitSet(Reg, Bit)
#define GPIO_Config_INPUT(Reg, Bit) bitClear(Reg, Bit)
#define Global_INT_Enable() bitSet(SREG, SREG_I)
#define Interrupt_Flag_Clear(Reg, Bit) bitSet(Reg, Bit)
#define initialize true
#define deInitialize false
// Switches
#define SW1_Control DDRD
#define SW1_Status PIND
#define SW1_Pin 2 // external interrupt 2
#define SW1_isPressed bitCheck(SW1_Status, SW1_Pin)

#define SW2_Control DDRD
#define SW2_Status PIND
#define SW2_Pin 3 // external interrupt 3
#define SW2_isPressed bitCheck(SW2_Status, SW2_Pin)

#define SW3_Control DDRB
#define SW3_Status PINB
#define SW3_Pin 5 // Pin change interrupt 5
#define SW3_isPressed bitCheck(SW3_Status, SW3_Pin)

void GPIO_Init(void);


#endif




