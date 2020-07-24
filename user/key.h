#ifndef KEY_H_
#define KEY_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
//#define KEY3 HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)

#define KEY0_PRESS 1
#define KEY1_PRESS 2
#define KEY2_PRESS 3
#define KEY3_PRESS 4

extern uint8_t   keydown_data;    //�������º�ͷ��ص�ֵ
extern uint8_t   keyup_data;      //����̧�𷵻�ֵ
extern uint16_t  key_time;
extern uint8_t   key_tem; 

void keyscan(char mode);

#endif
