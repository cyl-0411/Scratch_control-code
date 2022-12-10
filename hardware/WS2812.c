//
// Created by CYL04 on 2022/9/4.
//

#include "WS2812.h"
#include "memory.h"

uint16_t send_Buf[NUM];

void WS_Load(void)
{
    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_2, (uint32_t *)send_Buf, NUM);
}

void WS_CloseAll(void)
{
    uint16_t i;
    for (i = 0; i < PIXEL_NUM * 24; i++)
        send_Buf[i] = WS0; // 写入逻辑0的占空比
    for (i = PIXEL_NUM * 24; i < NUM; i++)
        send_Buf[i] = 0; // 占空比比为0，全为低电平
    WS_Load();
}

void WS_WriteAll_RGB(uint8_t n_R, uint8_t n_G, uint8_t n_B)
{
    memset(send_Buf,0,NUM);

    uint16_t i, j;
    uint8_t dat[24];
    // 将RGB数据进行转换
    for (i = 0; i < 8; i++)
    {
        dat[i] = ((n_G & 0x80) ? WS1 : WS0);
        n_G <<= 1;
    }
    for (i = 0; i < 8; i++)
    {
        dat[i + 8] = ((n_R & 0x80) ? WS1 : WS0);
        n_R <<= 1;
    }
    for (i = 0; i < 8; i++)
    {
        dat[i + 16] = ((n_B & 0x80) ? WS1 : WS0);
        n_B <<= 1;
    }
    for (i = 0; i < PIXEL_NUM; i++)
    {
        for (j = 0; j < 24; j++)
        {
            send_Buf[i * 24 + j] = dat[j];
        }
    }
//    for (i = PIXEL_NUM * 24; i < NUM; i++)
//        send_Buf[i] = 0; // 占空比比为0，全为低电平
    WS_Load();
}
