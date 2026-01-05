#ifndef __KEY_H__
#define __KEY_H__

#define KEY1 DL_GPIO_readPins(KEY_PORT,KEY_K1_PIN)
#define KEY2 DL_GPIO_readPins(sensor_PORT,KEY_K2_PIN )
#define KEY3 DL_GPIO_readPins(sensor_PORT,KEY_K3_PIN )
#define KEY4 DL_GPIO_readPins(sensor_PORT,sensor_BSL_PIN )

int Key_Scan(void);
void Key_Handle(void);

#endif
