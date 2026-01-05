#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "ti_msp_dl_config.h"

void motor_set(uint16_t leftSpeed, uint16_t rightSpeed);

void motor_stop(void);
void motor_start(void);



#endif