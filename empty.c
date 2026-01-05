#include "ti_msp_dl_config.h"

#include "JY901S.h"
#include "delay.h"
#include "sensor.h"
#include "pid.h"
#include "oled.h"
#include "key.h"
#include "stdio.h"

volatile unsigned char uart_data = 0;

void uart0_send_char(char ch);
void uart0_send_string(char* str);

int turn = 0;
int KEY_flag;

volatile uint32_t gpioA;
volatile int32_t gEncoderCount = 0;
float speed = 0;
extern float Yaw;
extern int key_val;

extern int a1;             //s1灰度传感器初始化
extern int a2;             //s2灰度传感器初始化
extern int a3;             //s3灰度传感器初始化
extern int a4;             //s4灰度传感器初始化
float Start_Yaw;
int main(void)
{
    SYSCFG_DL_init();

	
    NVIC_ClearPendingIRQ(UART_JY61P_INST_INT_IRQN);//清除串口中断标志
    NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
    
	  NVIC_EnableIRQ(UART_JY61P_INST_INT_IRQN);//使能串口中断
    NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
	
	NVIC_EnableIRQ(KEY_INT_IRQN);//开启按键引脚的GPIOA端口中断
	
//	turn = Turn(500);
//	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,500,GPIO_PWM_Motor_C0_IDX);//左
//	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,turn,GPIO_PWM_Motor_C1_IDX);//右   
	
//	NVIC_EnableIRQ(GPIO_EncoderA_INT_IRQN);//使能外部中断	
//	NVIC_EnableIRQ(TIMER_Sensor_INST_INT_IRQN);
//	DL_TimerA_startCounter(TIMER_Sensor_INST);
	
	

	delay_ms(1000);	
    Start_Yaw = Yaw; //起始YAW值
	
	OLED_Init();     //初始化OLED
    OLED_Clear();	
	
	
	while (1)
    {

//		Serial_JY61P_Zero_Yaw();
		//前进
//		DL_GPIO_setPins(Motor_PORT, Motor_AIN2_PIN   | Motor_BIN2_PIN);	
//		DL_GPIO_clearPins(Motor_PORT, Motor_AIN1_PIN | Motor_BIN1_PIN);	
		
//		DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,500,GPIO_PWM_Motor_C1_IDX);//右
//		DL_GPIO_setPins(Motor_PORT, Motor_AIN2_PIN | Motor_BIN2_PIN);	
//		DL_GPIO_clearPins(Motor_PORT, Motor_AIN1_PIN | Motor_BIN1_PIN);	
//		turn = Turn(50);
		
//		angle_task( (int16_t)Start_Yaw  ,(int16_t)Yaw);
		TRACE_2(); // 调用TRACE函数

//		OLED_ShowNum(0,0,((int)Yaw),40,8,1);//6*8 “ABC”
//		OLED_ShowNum(0,8,a2,1,12,1);//6*8 “ABC”
//		OLED_ShowNum(0,20,a3,1,16,1);//6*8 “ABC”
//		OLED_ShowNum(0,36,a4,1,24,1);//6*8 “ABC”

//		OLED_Refresh();

    }
}

void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
    //读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        //检查是否是KEY的GPIOA端口中断，注意是INT_IIDX，不是PIN_18_IIDX
        case KEY_INT_IIDX:
            //如果按键按下变为高电平
            if( DL_GPIO_readPins(KEY_PORT, KEY_K1_PIN) == 0 )
            {
                KeyFlag = 1;
//				TRACE_2();
//				KEY_flag++;
            }
        break;
    }
}

//串口发送单个字符
void uart1_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_1_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_1_INST, ch);
}

//串口发送字符串
void uart1_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart1_send_char(*str++);
    }
}

#if !defined(__MICROLIB)
//不使用微库的话就需要添加下面的函数
#if (__ARMCLIB_VERSION <= 6000000)
//如果编译器是AC5  就定义下面这个结构体
struct __FILE
{
	int handle;
};
#endif

FILE __stdout;

//定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x)
{
	x = x;
}
#endif


//printf函数重定义
int fputc(int ch, FILE *stream)
{
	//当串口0忙的时候等待，不忙的时候再发送传进来的字符
	while( DL_UART_isBusy(UART_1_INST) == true );
	
	DL_UART_Main_transmitData(UART_1_INST, ch);
	
	return ch;
}

//void GROUP1_IRQHandler(void)
//{
//    //获取中断信号
//    gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA,
//    GPIO_EncoderA_PIN_1_PIN | GPIO_EncoderA_PIN_2_PIN);

//    //如果是GPIO_EncoderA_PIN_0_PIN产生的中断
//    if((gpioA & GPIO_EncoderA_PIN_1_PIN) == GPIO_EncoderA_PIN_2_PIN)
//    {
//        //Pin0上升沿，看Pin1的电平，为低电平则判断为反转，高电平判断为正转
//        if(!DL_GPIO_readPins(GPIOA,GPIO_EncoderA_PIN_1_PIN))//P1为低电平
//        {
//            gEncoderCount--;
//        }
//        else//P1为高电平
//        {
//            gEncoderCount++;
//        }
//    }
//    
//    //类似于Stm32中编码器模式的AB两相都测，可得到2倍的计数
//    else if((gpioA & GPIO_EncoderA_PIN_1_PIN) == GPIO_EncoderA_PIN_1_PIN)
//    {
//        //Pin1上升沿
//        if(!DL_GPIO_readPins(GPIOA,GPIO_EncoderA_PIN_1_PIN))//P0为低电平
//        {
//            gEncoderCount++;
//        }
//        else//P1为高电平
//        {
//            gEncoderCount--;
//        }
//    }
//    
//    //最后清除中断标志位
//    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_EncoderA_PIN_1_PIN|GPIO_EncoderA_PIN_2_PIN);
//}

///* 每次获取完计数值后清零，则可获得以执行周期为单位的速度值 */
//        speed = gEncoderCount;
//        gEncoderCount = 0;
//        delay_cycles(320000);










