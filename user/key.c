#include "key.h"

uint8_t  keydown_data=0x00;    //�������º�ͷ��ص�ֵ
uint8_t  keyup_data=0x00;      //����̧�𷵻�ֵ
uint16_t  key_time=0x00;       //��������֮���ʱ���������ֵ����ɨ��һ�ΰ���������ʱ��͵��ڰ������µ�ʱ��
uint8_t  key_tem=0x00;         //�����İ���ֵ�밴��ɨ�������ɱ���
uint8_t  key_bak=0x00;         //����ɨ�������ɱ���


void keyscan(char mode)
{
	keyup_data=0;         //��̧��󰴼�ֵһ����Ч
	
	if(KEY0==0||KEY1==0||KEY2==0)   //�м�������
	{
		if(KEY0==0)      key_tem = KEY0_PRESS;
		else if(KEY1==0) key_tem = KEY1_PRESS;
		else if(KEY2==0) key_tem = KEY2_PRESS;
//		else if(KEY3==0) key_tem = KEY3_PRESS;
		
		  if(key_tem == key_bak)      //�м����º��һ��ɨ�費������else��ϵڶ���ɨ����Ч������ʵ����ȥ����
			{
				 key_time++;             //�м����º�ִ��һ��ɨ�躯�����ñ�����1
				 keydown_data = key_tem;   //����ֵ����keydown_data
				
				 if( (mode==0)&&(key_time>1) )//key_time>1����ֵ��Ч������ǵ��������modeΪ1��Ϊ����
						keydown_data=0;
			}
	    else                             //ȥ����      
			{
				 key_time = 0;
				 key_bak = key_tem;
			}
		
	}
	else       //��̧��
	{
		if(key_time > 2)            //����̧��󷵻�һ�ΰ���ֵ
		{
			keyup_data = key_tem;  //��̧��󰴼�ֵ����keydown_data            						
		}
		key_bak = 0;               //Ҫ���㣬��Ȼ�´�ִ��ɨ�����ʱ������ֵ���ϴΰ���ֵһ������û��ȥ����������
		key_time = 0;
		keydown_data = 0;		
	}    
}
