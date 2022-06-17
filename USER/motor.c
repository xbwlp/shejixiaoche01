 #include "STM32F10X.h"
#include "motor.h"

void MotorInit(void)
{
	
	//初始化和使能单片机上的GPIO端口，保证可以正常给端口高低电平
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
//	MOTOR_APB_PERIPH_FUNG(MOTOr_APB_PORT , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD, GPIO_Pin_2);
}


//停止模式
void Stop(void)
{
	//左前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);
	GPIO_ResetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_12);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
}


//左转模式 -> 左电机正转，右电机反转
void Turnleft(void)
{
	//左前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_12);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_SetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
}

//右转模式 -> 左电机反转，右电机正转
void Turnright(void)
{
	//左前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_10);
	GPIO_ResetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_12);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_SetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	GPIO_SetBits(GPIOC,GPIO_Pin_9);
}

//后退模式 -> 左电机反转，右电机反转
void Turnback(void)
{
	//左前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_10);
	GPIO_ResetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_12);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_SetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
}

//前进模式 -> 左电机正转，右电机正转
void Turnfront(void)
{
	//左前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_12);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_SetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	GPIO_SetBits(GPIOC,GPIO_Pin_9);
}

//左平移
void Leftaround(void)
{
	//左前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_12);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_SetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
}

//右平移
void Rightaround(void)
{
	//左前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_10);
	GPIO_ResetBits(GPIOC,GPIO_Pin_11);
	//右前轮
	GPIO_SetBits(GPIOC,GPIO_Pin_12);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	//左后轮
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_SetBits(GPIOC,GPIO_Pin_8);
	//右后轮
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	GPIO_SetBits(GPIOC,GPIO_Pin_9);
}

