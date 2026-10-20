# ifndef _PWM_H
# define _PWM_H

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
//	void PWM_SetFre(uint16_t Freq);
//	void PWM_SetFre_Lg(uint16_t Freq);
void PWM_Set_Fre_Lg_Gap(uint16_t music_note,uint16_t Lg,uint16_t Gap);

# endif
