#ifndef _WS2812_H
#define _WS2812_H
#endif

#include "headfile.h"

#define PIXEL_NUM  56
#define NUM (24*PIXEL_NUM + 500)        // Reset 280us / 1.25us = 224
#define WS1 58
#define WS0  22

extern uint16_t send_Buf[NUM];

void WS_Load(void);
void WS_WriteAll_RGB(uint8_t n_R, uint8_t n_G, uint8_t n_B);
void WS_CloseAll(void);
