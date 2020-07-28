#include "key.h"

uint8_t  keydown_data=0x00;    //按键按下后就返回的值
uint8_t  keyup_data=0x00;      //按键抬起返回值
uint16_t  key_time=0x00;       //按键按下之后的时间计数，该值乘以扫描一次按键函数的时间就等于按键按下的时间
uint8_t  key_tem=0x00;         //长按的按键值与按键扫描程序过渡变量
uint8_t  key_bak=0x00;         //按键扫描程序过渡变量


void keyscan(char mode)
{
	keyup_data=0;         //键抬起后按键值一次有效
	
	if(KEY0==0||KEY1==0||KEY2==0)   //有键正按下
	{
		if(KEY0==0)      key_tem = KEY0_PRESS;
		else if(KEY1==0) key_tem = KEY1_PRESS;
		else if(KEY2==0) key_tem = KEY2_PRESS;
//		else if(KEY3==0) key_tem = KEY3_PRESS;
		
		  if(key_tem == key_bak)      //有键按下后第一次扫描不处理，与else配合第二次扫描有效，这样实现了去抖动
			{
				 key_time++;             //有键按下后执行一次扫描函数，该变量加1
				 keydown_data = key_tem;   //按键值赋予keydown_data
				
				 if( (mode==0)&&(key_time>1) )//key_time>1按键值无效，这就是单按，如果mode为1就为连按
						keydown_data=0;
			}
	    else                             //去抖动      
			{
				 key_time = 0;
				 key_bak = key_tem;
			}
		
	}
	else       //键抬起
	{
		if(key_time > 2)            //按键抬起后返回一次按键值
		{
			keyup_data = key_tem;  //键抬起后按键值赋予keydown_data            						
		}
		key_bak = 0;               //要清零，不然下次执行扫描程序时按键的值跟上次按的值一样，就没有去抖动处理了
		key_time = 0;
		keydown_data = 0;		
	}    
}
