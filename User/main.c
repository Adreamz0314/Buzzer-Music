#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "music_note_freq.h"
#include "music_bar.h"
#include "OLED_Music.h"

/*

切歌步骤：

修改BPM和beat_base；  												位于PWM.c;
修改乐谱，注释掉不需要的乐谱;										位于music_bar.c和music_bar.h
修改Bars_Notes_Seq bar_test[2] ，
2替换为小节数
复制延伸{(int (*)[3])bar1,7}，bar2,bar3,bar4, 
7替换为各小节音符数;
修改while(1)，其中for(n=0;n<=2-1;n++)将2替换为小节数.				位于main.c;

uint16_t Freq;
uint16_t Lg;

*/

	Bars_Notes_Seq bar_test[23] = 
{
	
	{(int (*)[3])bar1,8},
	{(int (*)[3])bar2,9},
	{(int (*)[3])bar3,9},
	{(int (*)[3])bar4,9},
	{(int (*)[3])bar5,9},
	{(int (*)[3])bar6,13},
	{(int (*)[3])bar7,6},
	{(int (*)[3])bar8,6},
	{(int (*)[3])bar9,8},
	{(int (*)[3])bar10,9},
	{(int (*)[3])bar11,9},
	{(int (*)[3])bar12,10},
	{(int (*)[3])bar13,9},
	{(int (*)[3])bar14,13},
	{(int (*)[3])bar15,6},
	{(int (*)[3])bar16,4},
	{(int (*)[3])bar17,18},
	{(int (*)[3])bar18,9},
	{(int (*)[3])bar19,10},
	{(int (*)[3])bar20,11},
	{(int (*)[3])bar21,11},
	{(int (*)[3])bar22,6},
	{(int (*)[3])bar23,2}

};

int main(void)
{
	OLED_Init();
	PWM_Init();
	OLED_Pre_Show();
	
	uint16_t i=0;				// 音符
	uint16_t n=0;				//小节

while(1)
{
	
	for(n=0;n<=23-1;n++)
	{
		for(i=0;i<=bar_test[n].notes_seq-1;i++)						
		{
			OLED_Var_Show(i,n,bar_test);
			PWM_Set_Fre_Lg_Gap(bar_test[n].data[i][0],bar_test[n].data[i][1],bar_test[n].data[i][2]);
		}
	}

}
		
}
	

