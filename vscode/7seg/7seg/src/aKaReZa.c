#include "aKaReZa.h"

void GPIO_Init(void)
{
    GPIO_Config_INPUT(SW3_Control, SW3_Pin);
    GPIO_Config_INPUT(SW2_Control, SW2_Pin);
    GPIO_Config_INPUT(SW1_Control, SW1_Pin);
}

