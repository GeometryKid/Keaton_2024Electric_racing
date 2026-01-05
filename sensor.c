#include "sensor.h"
#include "ti_msp_dl_config.h"
#include "pid.h"
#include "stdint.h"
#include "JY901S.h"
#include "motor.h"

// 函数使用初始化
void tracing_race();
void judge_race();

extern float Start_Yaw;
extern float Yaw;
extern int KEY_flag;

int judge_flag = 1;
int16_t PWM_OUT1,PWM_OUT2;
int16_t LeftSpeed,RightSpeed;
float err_Yaw;

/**
 * @brief 处理TIMER_Sr_INST的中断请求 10ms
 *
 * 该函数用于处理灰度传感器产生的中断。在中断处理过程中，
 * 会读取前后灰度传感器的数值，进行行为逻辑判断，
 * 定时更新小车运行位置状态
 */
//定时器的中断服务函数 已配置为1秒的周期
//void TIMER_Sensor_INST_IRQHandler(void)
//{
//    static volatile uint8_t num = 0; // 用于计数中断发生次数
//    //如果产生了定时器中断
//    switch( DL_TimerG_getPendingInterrupt(TIMER_Sensor_INST) )
//    {
//        case DL_TIMER_IIDX_ZERO://如果是0溢出中断
//        {   
////			Start_Yaw = Yaw; //起始YAW值
////			TRACE(); // 调用TRACE函数
//            // 中断发生次数累计，当达到一定次数时翻转LED的状态
//            if (num<10)
//            {
//                num++;
//            }
//            else
//            {
//                //			OLED_Clear();
//                num = 0;                                                     // 重置计数器
////                DL_GPIO_togglePins(LED1_PORT, LED1_PIN_0_PIN); // 翻转LED状态
//            }
//        }
//        break;

//        default:   // 其他的定时器中断
//            break; // 对未知中断不做处理
//    }
//}

// 标志位初始化
int mode=1;             //题号

// 0是白,1是黑
int a1 = 0;             //s1灰度传感器初始化
int a2 = 0;             //s2灰度传感器初始化
int a3 = 0;             //s3灰度传感器初始化
int a4 = 0;             //s4灰度传感器初始化

/**
 * @brief 读取灰度传感器的状态
*/
void tracing_race()
{           
    if(DL_GPIO_readPins(sensor_PORT,sensor_PIN_3_PIN)==0)         
    { 
        a2=0;                
    }
    else      
    {
        a2=1;
    }

    if(DL_GPIO_readPins(sensor_PORT,sensor_PIN_4_PIN)==0)          
    {
        a1=0;
    }
    else           
    {
        a1=1;
    }

    if(DL_GPIO_readPins(sensor_PORT,sensor_PIN_5_PIN)==0)            
    {
        a3=0;
    }
    else           
    {
        a3=1;
    }

    if(DL_GPIO_readPins(sensor_PORT,sensor_PIN_6_PIN)==0)           
    {
        a4=0;
    }
    else             
    {
        a4=1;
    }
}

/**
 * @brief 根据灰度传感器的状态,判断小车的运行状态
*/
void judge_race_1()              
{
	// 判断a1、a2、a3、a4的值，根据不同情况设置flag的值
    if(a1==1 & a2==1 & a3==1 & a4==1 )   // 全白        
    {    
		angle_task( (int16_t)Start_Yaw  ,(int16_t)Yaw);
    }                                             
    else
    {  
		judge_flag = 0;
    }                                                                     
}

void judge_race_2()
{
	PWM_OUT1=200;
	PWM_OUT2=200;  
	
	// 判断a1、a2、a3、a4的值，根据不同情况设置flag的值
    if(a1==0 & a2==0 & a3==0 & a4==0)
	{
		motor_stop();
	}
    else if(a1==0 & a2==1 & a3==1 & a4==1 )	// 黑白白白            
    {  
        LeftSpeed  = PWM_OUT1-150;
        RightSpeed  = PWM_OUT2+150;    
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);		
    }
    else if(a1==1 & a2==0 & a3==1 & a4==1 )            
    {  
        LeftSpeed  = PWM_OUT1-50;
        RightSpeed  = PWM_OUT2+50;                
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);
    }    
    else if(a1==1 & a2==1 & a3==0 & a4==1)            
    {  
        LeftSpeed  = PWM_OUT1+70;
        RightSpeed  = PWM_OUT2-70;               
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);
    }    
    else if(a1==1 & a2==1 & a3==1 & a4==0 )            
    {  
        LeftSpeed  = PWM_OUT1+150;
        RightSpeed  = PWM_OUT2-150;   
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);		
    } 
	  else if(a1==0 & a2==0 & a3==1 & a4==1 )            
	  {  
        LeftSpeed  = PWM_OUT1-20;
        RightSpeed  = PWM_OUT2+20;
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);		  
	  }    
    else if(a1==1 & a2==0 & a3==0 & a4==1)            
    {  
        LeftSpeed  = PWM_OUT1;
        RightSpeed  = PWM_OUT2;
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);                
//		angle_task( (int16_t)Start_Yaw  ,(int16_t)Yaw);

    }    
    else if(a1==1 & a2==1 & a3==0 & a4==0)            
    {  
        LeftSpeed  = PWM_OUT1+20;
        RightSpeed  = PWM_OUT2-20;	
		motor_set((uint16_t)LeftSpeed, (uint16_t)RightSpeed);		
    }      
    if(a1==1 & a2==1 & a3==1 & a4==1 )   // 全白        
    {    
		angle_task( (int16_t)Start_Yaw  ,(int16_t)Yaw);
    }                                             
}

void TRACE_1()
{
	tracing_race(); // 读取灰度传感器的状态
//	judge_race_1();   // 根据灰度传感器的状态判断小车的运行状态
	if(judge_flag == 1)
	{	
		judge_race_1();   // 根据灰度传感器的状态判断小车的运行状态
	}
	else motor_stop();
}

void TRACE_2()
{
	tracing_race(); // 读取灰度传感器的状态
	if(judge_flag == 1)
	{	
		judge_race_2();   // 根据灰度传感器的状态判断小车的运行状态
	}
	else motor_stop();
}