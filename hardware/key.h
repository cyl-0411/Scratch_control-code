//
// Created by CYL04 on 2022/9/4.
//

#ifndef SCRATCH_CONTROL_CODE_KEY_H
#define SCRATCH_CONTROL_CODE_KEY_H

#include "headfile.h"

#define key1    HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define key2    HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
#define key3    HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)
#define key4    HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin)

void key_scan(void);




#endif //SCRATCH_CONTROL_CODE_KEY_H
