#ifndef _Timer0_H
#define _Timer0_H
#include "aKaReZa.h"

void Timer0_Init(bool _initstause);
#define Timer0_InitValue 56  // For 1ms at 16MHz with prescaler 64

#endif