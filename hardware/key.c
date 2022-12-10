//
// Created by CYL04 on 2022/9/4.
//

#include "key.h"

void key_scan(void)
{
    uint8_t i=0;
    if(key1==0)
    {
        TIM1->CCR1=1800;
        WS_WriteAll_RGB(255 ,11,11);
        while(key1==0);
    }

    if(key2==0)
    {
        TIM1->CCR1=2000;
        WS_WriteAll_RGB(20,20,127);
        while(key2==0);
    }


    if(key3==0) {
        TIM1->CCR1=1800;
        HAL_Delay(10);
        WS_WriteAll_RGB(0,0,0);
        while(key3==0);
    }
    if(key4==0) {

    }

}