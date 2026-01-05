#include "key.h"
#include "delay.h"
#include "ti_msp_dl_config.h"
#include "sensor.h"

// 按键扫描函数
int Key_Scan(void)
{
	// 定义一个静态变量，用于记录按键是否被按下
	static int key_up = 0;
	// 定义一个变量，用于存储按键值
	int key_val = 0;
	// 如果四个按键都未被按下，则将key_up置为1
	if(KEY1&&KEY2&&KEY3&&KEY4) key_up = 1;
	// 如果key_up为1，且四个按键中有一个被按下，则进行以下操作
	else if(key_up&&(!KEY1||!KEY2||!KEY3||!KEY4))
	{
		// 延时10ms
		delay_ms(10);
		// 如果四个按键中有一个被按下，则将key_up置为0
		if(!KEY1||!KEY2||!KEY3||!KEY4)
		{
			key_up = 0;
			
			// 根据被按下的按键，将对应的按键值赋给key_val
			if(!KEY1) key_val = 1;
			else if(!KEY2) key_val = 2;
			else if(!KEY3) key_val = 3;
			else if(!KEY4) key_val = 4;
			
		}
	}
	// 返回按键值
	return key_val;
}

// 按键处理函数
void Key_Handle(void)
{
	int key_val;
	switch(key_val)
	{
		case 1:
			// 按键1处理函数
			TRACE_1(); // 调用TRACE函数
			break;
		case 2:
			// 按键2处理函数
			TRACE_2(); 
			break;
//		case 3:
//			// 按键3处理函数
////			Requirement_3();
//			break;
//		case 4:
//			// 按键4处理函数
////			Requirement_4();
//			break;
		default:
			break;
	}
}