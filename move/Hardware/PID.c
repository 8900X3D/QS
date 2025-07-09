#include "stm32f10x.h"                  // Device header
#include "PID.h"
/**
  * @brief  λ��PID�㷨ʵ��
  * @param  actual_val:ʵ�ʲ���ֵ
  *	@note 	��
  * @retval ͨ��PID���������
  */
  

float PosionPID_realize(PID *pid, float actual_val)
{
	/*����Ŀ��ֵ��ʵ��ֵ�����*/
	pid->Error = pid->target_val - actual_val;
	/*������*/
	pid->integral += pid->Error;
	/*PID�㷨ʵ��*/
	pid->output_val = pid->Kp * pid->Error +
	                  pid->Ki * pid->integral +
	                  pid->Kd *(pid->Error -pid->LastError);
	/*����*/
	pid-> LastError = pid->Error;
	/*���ص�ǰʵ��ֵ*/
	return pid->output_val;
}
