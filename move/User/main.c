#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Motor.h"
#include "Serial.h"
int8_t Speed;		//定义速度变量
char RxData;
int FBflag=0;
int main(void)
{
	/*模块初始化*/
	 Motor_Init();		//直流电机初始化
   Serial_Init();
	while(1)
	{
		RxData=Serial_GetRxData();
		if(Serial_GetRxFlag())
		{
			if(RxData=='A')break;
			if(RxData=='G')
			{
				FBflag=1;
			}
			if(RxData=='K')
			{
				FBflag=-1;
			}
			if(RxData=='H')
			{
				FBflag=2;
			}
			if(RxData=='J')
			{
				FBflag=-2;
			}
			if(RxData=='I')
			{
				FBflag=0;
			}
			if(FBflag==1)
			{
				Motor_SetSpeed1(30);
				Motor_SetSpeed2(29);
			}
			if(FBflag==-1)
			{
				Motor_SetSpeed1(-30);
				Motor_SetSpeed2(-29);
			}
			if(FBflag==0)
			{
				Motor_SetSpeed1(0);
				Motor_SetSpeed2(0);
			}
			
			if(FBflag==2)
			{
				Motor_SetSpeed1(-30);
				Motor_SetSpeed2(25);
			}
			if(FBflag==-2)
			{
				Motor_SetSpeed1(30);
				Motor_SetSpeed2(-25);
			}
		}
	}
	Motor_SetSpeed1(0);
	Motor_SetSpeed2(0);
	
//    Motor_SetSpeed1(30);				//设置直流电机的速度为速度变量
//	Motor_SetSpeed2(29);
//	Delay_ms(5000);
//	Motor_SetSpeed1(0);
//	Motor_SetSpeed2(0);
//	Delay_ms(1500);
//	for(int i=0;i<500000;i++)
//	{
//	Motor_SetSpeed1(-30);
//	Motor_SetSpeed2(25);
//	}
//	Motor_SetSpeed1(0);
//	Motor_SetSpeed2(0);
//	Delay_ms(1500);
//	Motor_SetSpeed1(30);				//设置直流电机的速度为速度变量
//	Motor_SetSpeed2(29);
//	Delay_ms(3000);
//	Motor_SetSpeed1(0);
//	Motor_SetSpeed2(0);
//	Delay_ms(1500);
//	for(int i=0;i<500000;i++)
//	{
//	Motor_SetSpeed1(30);
//	Motor_SetSpeed2(-25);
//	}
//	Motor_SetSpeed1(0);
//	Motor_SetSpeed2(0);
//	Delay_ms(1000);
//    Motor_SetSpeed1(30);				//设置直流电机的速度为速度变量
//	Motor_SetSpeed2(29);
//	Delay_ms(3000);
//	Motor_SetSpeed1(0);				//设置直流电机的速度为速度变量
//	Motor_SetSpeed2(0);
}
