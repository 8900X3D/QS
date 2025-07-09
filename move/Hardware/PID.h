#ifndef __PID_H
#define __PID_H
#include "stm32f10x.h"                  // Device header

typedef struct
{
	float target_val;   //Ŀ��ֵ
	float Error;          /*�� k ��ƫ�� */
	float LastError;     /* Error[-1],�� k-1 ��ƫ�� */
	float PrevError;    /* Error[-2],�� k-2 ��ƫ�� */
	float Kp,Ki,Kd;     //���������֡�΢��ϵ��
	float integral;     //����ֵ
	float output_val;   //���ֵ
}PID;

float PosionPID_realize(PID *pid, float actual_val);



#endif