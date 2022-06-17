#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "PWM.h"
void Loading_1(){                 //TIM2 ch3 PA2
    delay_init();			  
 	TIM2_PWM_Init(19999,71);
	TIM_SetCompare3(TIM2, 19500);
	delay_ms(1200);
  for(int i=10;i>=0;i--)    
	{
		TIM_SetCompare3(TIM2, 18500);
		delay_ms(2000);
	}		
	TIM_SetCompare3(TIM2, 17500);
	delay_ms(1200);
	TIM_SetCompare3(TIM2, 18500);
	delay_ms(2000);
}

void Loading_3(){                     //黑球
   delay_init();			  
 	TIM3_PWM_Init(19999,71);
		TIM_SetCompare1(TIM3, 11100);
		delay_ms(2000);  
  
}

void Loading_2(){	//TIM3 ch1 注意不能使用TIM3   PA6    乒乓球
    
	delay_init();			  
 	TIM3_PWM_Init(19999,71);
		TIM_SetCompare1(TIM3, 12200);
		delay_ms(2000);  
    
}

void Loading_4(){     //TIM4 ch2            PB7
    delay_init();			  
 	TIM4_PWM_Init(19999,71);
    TIM_SetCompare2(TIM4, 19500);
	delay_ms(100); 
	TIM_SetCompare2(TIM4, 18500);
	delay_ms(1000);
}
void Loading_5(){     //TIM2 ch4          PA3
    delay_init();			  
 	TIM2_PWM_Init(19999,71);
		TIM_SetCompare4(TIM2, 19500);
		delay_ms(90);
	TIM_SetCompare4(TIM2, 18500);
		delay_ms(1000);
  
}
void Loading_6(){    //                网球
  delay_init();			  
 	TIM3_PWM_Init(19999,71);
		TIM_SetCompare1(TIM3, 2800);
		delay_ms(2000);  
}


void Loading_8(){	//TIM3 ch1 注意不能使用TIM3   PA6
    
	delay_init();			  
 	TIM3_PWM_Init(19999,71);
		TIM_SetCompare1(TIM3, 11650);
		delay_ms(2000);  
 	
    
}
void Loading_9(){	//TIM3 ch1 注意不能使用TIM3   PA6
    
	delay_init();			  
 	TIM3_PWM_Init(19999,71);
		TIM_SetCompare1(TIM3, 19999);
		delay_ms(2000);  
 	
    
}



