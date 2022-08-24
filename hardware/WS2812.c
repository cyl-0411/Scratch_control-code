//
// Created by CYL04 on 2022/7/27.
//

#include "headfile.h"

uint16_t WS2812_Buffer[NUM];

/* 函数名：WS2812_init
 * 功能：开启PWM-DMA传输
 * 形参：无
 * 返回值：无
 */

void WS2812_init(void)
{
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);

}

/* 函数名：WB2812_SET_RGB
 * 功能：设置传输给DMA的值，并发给DMA，嵌套使用了WS2812_LOAD
 * 形参：R G B对应的数值
 * 返回值：无
 */
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

/* 函数名：WS2812_LOAD
 * 功能：将值发给DMA
 * 形参：R G B对应的数值
 * 返回值：无
 */
void WS2812_LOAD(void)
{
    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)WS2812_Buffer,NUM);
}

/* 函数名：HAL_TIM_PWM_PulseFinishedCallback
 * 功能：回调函数，停止DMA发送，无需调用。
 *      应该是DMA发送完最后一个数值时会触发回调函数，然后停止后续发送。
 * 形参：无
 * 返回值：无
 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim3,TIM_CHANNEL_2);
}