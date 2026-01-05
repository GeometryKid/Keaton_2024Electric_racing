#include "ti_msp_dl_config.h"

//uint16_t leftSpeed,rightSpeed

void motor_set(uint16_t leftSpeed, uint16_t rightSpeed)
{
	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,(uint16_t)leftSpeed,GPIO_PWM_Motor_C1_IDX);//×ó
	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,(uint16_t)rightSpeed,GPIO_PWM_Motor_C0_IDX);//ÓÒ
}	






void motor_stop(void)
{
//	DL_GPIO_setPins(Motor_PORT, Motor_AIN2_PIN   | Motor_BIN2_PIN);	
	DL_GPIO_clearPins(Motor_PORT, Motor_AIN1_PIN | Motor_AIN2_PIN | 
						Motor_BIN1_PIN | Motor_BIN2_PIN);	
}

void motor_start(void)
{
	DL_GPIO_clearPins(Motor_PORT, Motor_AIN2_PIN   | Motor_BIN2_PIN);	
	DL_GPIO_setPins(Motor_PORT, Motor_AIN1_PIN | Motor_BIN1_PIN);	
}
