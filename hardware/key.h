//
// Created by CYL04 on 2022/7/27.
//

#ifndef STM32G0XX_HAL_MSP_C_KEY_H
#define STM32G0XX_HAL_MSP_C_KEY_H

#define key1        HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define key2        HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
#define key3        HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)
#define key4        HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin)


void key_scan(void);
void key1_task(void);
void key2_task(void);
void key3_task(void);
void key4_task(void);

#endif //STM32G0XX_HAL_MSP_C_KEY_H
