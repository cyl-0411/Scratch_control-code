//
// Created by CYL04 on 2022/7/28.
//

#include "MG995.h"
#include "tim.h"

void MG995_init(void)
{
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
}

void MG995_OPEN(void)
{
    TIM1->CCR1=1311;
}

void MG995_CLOSE(void)
{
    TIM1->CCR1=3644;
}