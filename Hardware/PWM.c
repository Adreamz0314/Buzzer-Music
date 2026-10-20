#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void PWM_Init(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;
	TIM_TimeBaseInitStructer.TIM_ClockDivision=TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructer.TIM_CounterMode= TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructer.TIM_Period=100-1 ;      				//以下两个参数由定时公式决定 ARR
	TIM_TimeBaseInitStructer.TIM_Prescaler= 1636-1;					//PSC
	TIM_TimeBaseInitStructer.TIM_RepetitionCounter= 0;				//自动重装器只存在于高级定时器中 这里无需使用
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructer);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	

	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode= TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity= TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse= 50;								//CCR
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);
}

/*
void PWM_SetFre(uint16_t Freq)
{
	TIM_SetCompare1(TIM2,50);
	uint16_t psc;
	// 限制频率范围，防止除0、PSC溢出
	if(Freq < 11)
		Freq = 11;
	if(Freq > 65535)
		Freq = 65535;
	
	psc = 720000 / Freq - 1;
	TIM_PrescalerConfig(TIM2, psc, TIM_PSCReloadMode_Update);
	Delay_ms(400);
	TIM_SetCompare1(TIM2,80);
	Delay_ms(50);

}


void PWM_SetFre_Lg(uint16_t Freq)
{
	TIM_SetCompare1(TIM2,50);
	uint16_t psc;
	// 限制频率范围，防止除0、PSC溢出
	if(Freq < 11)
		Freq = 11;
	if(Freq > 65535)
		Freq = 65535;
	
	psc = 720000 / Freq - 1;
	TIM_PrescalerConfig(TIM2, psc, TIM_PSCReloadMode_Update);
	Delay_ms(800);
	TIM_SetCompare1(TIM2,80);
	Delay_ms(50);

}

*/

uint16_t BPM=72;										//每分钟BPM拍
uint16_t beat_base=4;									//beat_base分音符为一拍

void PWM_Set_Fre_Lg_Gap(uint16_t music_note,uint16_t Lg,uint16_t Gap)			// 输入参数：音高、音符时值（Lg分音符）、间断时长（默认间隔Gap为1，无间隔为0）
{
	TIM_SetCompare1(TIM2,50);
	uint16_t psc;
	// 限制频率范围，防止除0、PSC溢出
	if(music_note < 11)
		music_note = 11;
	if(music_note > 65535)
		music_note = 65535;
	
	if(music_note==11)
	{
		TIM_SetCompare1(TIM2,90);
		Delay_ms(60000*beat_base/(BPM*Lg));
	}
	
	else	
	{
	psc = 720000 / music_note - 1;
	TIM_PrescalerConfig(TIM2, psc, TIM_PSCReloadMode_Update);
	Delay_ms(60000*beat_base*(10-Gap)/(BPM*Lg*10));
	TIM_SetCompare1(TIM2,90);
	Delay_ms(60000*beat_base*Gap/(BPM*Lg*10));
	}

}




