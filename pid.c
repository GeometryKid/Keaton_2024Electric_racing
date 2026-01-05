//#include "motor.h"
//#include "Tracking.h"
#include "stdint.h"
#include "motor.h"
#include "sensor.h"

uint8_t inTurn = 0;

// 位置PID参数
int16_t posKp = 15; // 位置比例系数
int16_t posKi = 0;  // 位置积分系数
int16_t posKd = 6;  // 位置微分系数

// 角度PID参数
int16_t angleKp = 50; // 角度比例系数 1.50
int16_t angleKi = 0;  // 角度积分系数 1.0
int16_t angleKd = 40;  // 角度微分系数 1.40 

// 位置PID变量
int16_t posLastError = 0; // 上一次位置误差
int16_t posIntegral = 0;  // 位置误差积分

// 角度PID变量
int16_t angleLastError = 0; // 上一次角度误差
int16_t angleIntegral = 0;  // 角度误差积分

// 位置目标值
const int16_t posTarget = 0; // 位置目标

// 防止积分饱和的限值
const int16_t integralMax = 5000;  // 积分上限
const int16_t integralMin = -5000; // 积分下限

// 位置增量PID计算
int16_t computePosIncrementalPID(int16_t currentError)
{
    // 计算当前误差的增量
    int16_t derivative = currentError - posLastError;

    // 防止积分饱和
    posIntegral += currentError;
    if (posIntegral > integralMax) posIntegral = integralMax;
    if (posIntegral < integralMin) posIntegral = integralMin;

    // 计算PID输出
    int16_t output = (posKp * currentError + posKi * posIntegral + posKd * derivative) / 10;

    // 保存当前误差
    posLastError = currentError;

    return output;
}

// 角度PID计算
int16_t computeAnglePID(int16_t currentError)
{
    // 计算当前误差的增量
    int16_t derivative = currentError - angleLastError;

    // 防止积分饱和
    angleIntegral += currentError;
    if (angleIntegral > integralMax) angleIntegral = integralMax;
    if (angleIntegral < integralMin) angleIntegral = integralMin;

    // 计算PID输出
    int16_t output = (angleKp * currentError + angleKi * angleIntegral + angleKd * derivative) / 10;

    // 保存当前误差
    angleLastError = currentError;

    return output;
}

// 读取传感器数据并计算偏移位置
//int8_t readSensors()
//{
//    uint8_t sensorData = judge_race(); // 获取传感器数据
//    int8_t position = 0; // 初始化位置变量

//    // 根据传感器数据判断位置
//    switch(sensorData) {
//        case 0xE7: // 1110 0111
//        case 0xC3: // 1100 0011
//            position = 0;
//            break;
//        case 0x00: // 0000 0000
//        case 0x0F: // 0000 1111
//        case 0x07: // 0000 0111
//            position = -9;
//            break;
//        case 0xF0: // 1111 0000
//        case 0xE0: // 1110 0000
//            position = 9;
//            break;
//        case 0xE3: // 1110 0011
//        case 0xF7: // 1111 0111
//            position = 2;
//            break;
//        case 0xC1: // 1100 0001
//            position = 1;
//            break;
//        case 0xF3: // 1111 0011
//            position = 4;
//            break;
//        case 0xF1: // 1111 0001
//        case 0xFB: // 1111 1011
//            position = 6;
//            break;
//        case 0xF9: // 1111 1001
//        case 0xFD: // 1111 1101
//            position = 8;
//            break;
//        case 0xF8: // 1111 1000
//            position = 10;
//            break;
//        case 0xFC: // 1111 1100
//            position = 12;
//            break;
//        case 0xFE: // 1111 1110
//            position = 14;
//            break;
//        case 0x87: // 1000 0111
//            position = -2;
//            break;
//        case 0xC7: // 1100 0111
//            position = -1;
//            break;
//        case 0xEF: // 1110 1111
//            position = -2;
//            break;
//        case 0xCF: // 1100 1111
//            position = -4;
//            break;
//        case 0x8F: // 1000 1111
//        case 0xDF: // 1101 1111
//            position = -6;
//            break;
//        case 0x9F: // 1001 1111
//        case 0xBF: // 1011 1111
//            position = -8;
//            break;
//        case 0x1F: // 0001 1111
//            position = -10;
//            break;
//        case 0x3F: // 0011 1111
//            position = -12;
//            break;
//        case 0x7F: // 0111 1111
//            position = -14;
//            break;
//        case 0xFF: // 1111 1111
//            position = posLastError > 0 ? 16 : -16;
//            break;
//        default:
//            position = 0;
//            break;
//    }

//    return position;
//}

// 硬件任务函数
//void hw_task(void)
//{
//    int8_t position = readSensors(); // 读取传感器位置
//    int16_t error = posTarget - position; // 计算位置误差

//    // 计算位置PID修正值
//    int16_t correction = computePosIncrementalPID(error);

//    // 设置基础速度，弯道时降低速度
//    int16_t baseSpeed = inTurn ? 200 : 250;
//    int16_t leftSpeed = baseSpeed - correction;  // 左轮速度
//    int16_t rightSpeed = baseSpeed + correction; // 右轮速度

//    // 确保速度在合法范围内
//    if (leftSpeed > 500) leftSpeed = 500;
//    if (leftSpeed < 10) leftSpeed = 10;
//    if (rightSpeed > 500) rightSpeed = 500;
//    if (rightSpeed < 10) rightSpeed = 10;

//    // 设置电机速度
//    motor_set((uint16_t)leftSpeed, (uint16_t)rightSpeed);
//}

// 角度闭环运行任务
void angle_task(int16_t targetAngle, int16_t currentAngle)
{
    motor_start();
	int16_t angleError = targetAngle - currentAngle; // 计算角度误差

    // 计算角度PID修正值
    int16_t angleCorrection = computeAnglePID(angleError);

    // 设置基础速度，弯道时降低速度
    int16_t baseSpeed = 800;	// 1.800
    int16_t leftSpeed = baseSpeed - angleCorrection;  // 左轮速度
    int16_t rightSpeed = baseSpeed + angleCorrection; // 右轮速度

    // 确保速度在合法范围内	1.2000
    if (leftSpeed > 2000) leftSpeed = 2000;
    if (leftSpeed < 10) leftSpeed = 10;
    if (rightSpeed > 2000) rightSpeed = 2000;
    if (rightSpeed < 10) rightSpeed = 10;

    // 设置电机速度
    motor_set((uint16_t)leftSpeed, (uint16_t)rightSpeed);
}
