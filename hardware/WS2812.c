//
// Created by CYL04 on 2022/7/27.
//

#include "headfile.h"

uint16_t WS2812_Buffer[NUM];


void WS2812_init(void)
{
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);

}

void WS2812_LOAD(void)
{
    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)WS2812_Buffer,NUM);
}

void WB2812_SET_RGB(uint8_t n_R,uint8_t n_G,uint8_t n_B)
{
    uint16_t i, j;
    uint8_t dat[24];

    for (i = 0; i < 8; i++)
    {
        dat[i] = ((n_G & 0x80) ? WS2812_SIGNAL_1 : WS2812_SIGNAL_0);
        n_G <<= 1;
    }
    for (i = 0; i < 8; i++)
    {
        dat[i + 8] = ((n_R & 0x80) ? WS2812_SIGNAL_1 : WS2812_SIGNAL_0);
        n_R <<= 1;
    }
    for (i = 0; i < 8; i++)
    {
        dat[i + 16] = ((n_B & 0x80) ? WS2812_SIGNAL_1 : WS2812_SIGNAL_0);
        n_B <<= 1;
    }
    for (i = 0; i < LED_NUM; i++)
    {
        for (j = 0; j < 24; j++)
        {
            WS2812_Buffer[i * 24 + j] = dat[j];
        }
    }
    for (i = LED_NUM * 24; i < NUM; i++)
        WS2812_Buffer[i] = 0;

    WS2812_LOAD();
}



void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim3,TIM_CHANNEL_2);
}