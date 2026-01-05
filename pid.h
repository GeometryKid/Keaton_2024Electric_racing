#ifndef __pid_h__
#define __pid_h__

#include "ti_msp_dl_config.h"
//#include "Car.h"
//#include "Tracking.h"


#define Speed_Max   220
#define Speed_Nomal 150

typedef enum
{
		Speed_PidA=1,
	  Speed_PidB,
    Position_Pid,
	  Angle_Pid
}Mode;	

typedef struct
{
	int16_t target;	
	int16_t now;
	int16_t error[3];		
	int16_t kp,ki,kd;
	int16_t pout, dout, iout;
	int16_t out;   
	
	Mode pid_mode;

}pid_t;

extern pid_t Angle_PID,Position_PID;


void PID_Init(uint16_t Speed_L_Target,uint16_t Speed_R_Target);
void PID_Running(pid_t * pid);
void uart_send(void);

void angle_task(int16_t targetAngle, int16_t currentAngle);

#endif


