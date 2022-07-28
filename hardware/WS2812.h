//
// Created by CYL04 on 2022/7/27.
//

#ifndef STM32G0XX_HAL_MSP_C_WS2812_H
#define STM32G0XX_HAL_MSP_C_WS2812_H

#define WS2812_SIGNAL_1                 72
#define WS2812_SIGNAL_0                 25
#define WS2812_SIGNAL_RST               0

#define LED_NUM         10
#define NUM             (LED_NUM*24+300)

#define WS2812_WHITE        WB2812_SET_RGB(255,255,255)
#define WS2812_RED        WB2812_SET_RGB(255,0,0)
#define WS2812_GREEN        WB2812_SET_RGB(0,255,0)
#define WS2812_BLUE        WB2812_SET_RGB(0,0,255)

void WS2812_init(void);
void WS2812_LOAD(void);
void WB2812_SET_RGB(uint8_t n_R,uint8_t n_G,uint8_t n_B);


#endif //STM32G0XX_HAL_MSP_C_WS2812_H
