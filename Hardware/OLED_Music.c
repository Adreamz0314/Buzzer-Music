#include "stm32f10x.h"                  // Device header
#include "OLED_Music.h"
#include "music_note_freq.h"
#include "OLED.h"

//OLED预显示
void OLED_Pre_Show(void)
{
		
OLED_ShowString(1, 1,"bar");
OLED_ShowString(2, 1,"note");

OLED_ShowString(1, 9,"C major");
OLED_ShowString(2, 9,"4/4 time");
OLED_ShowString(3, 9,"BPM 72");
	
OLED_ShowString(4, 1,"1/");	

}

//OLED变量显示
void OLED_Var_Show(int i,int n,Bars_Notes_Seq bar_test[23])
{
			uint16_t show_length=0;				//显示节拍
			OLED_ShowString(4,3,"  ");			//清理区域
			OLED_ShowString(3,3,"  ");
					
			OLED_ShowNum(1,5,n+1,2);			//bar
			OLED_ShowNum(2,5,i+1,2);			//note
			
			if(bar_test[n].data[i][1]%4==0)		//拍子取整
				show_length=bar_test[n].data[i][1];
			else if(bar_test[n].data[i][1]==2)
				show_length=2;
			else 
				show_length=((bar_test[n].data[i][1]/4)+1)*4;
			
			if (show_length>10)					//自动左对齐
				OLED_ShowNum(4, 3,show_length,2);
			else OLED_ShowNum(4, 3,show_length,1);//length
			
			
			for(table_seq=0;table_seq<=tableLen-1;table_seq++)		//求当前音符
				{
						if(bar_test[n].data[i][0]==noteTable[table_seq].val)
					{
						OLED_ShowString(3, 1,noteTable[table_seq].name);
						break;
					}
				}
}
	

// 建立 数值 和 名称字符串 的对应关系
Note noteTable[61] = {
    {REST, "REST"},
    {C2, "C2"},
    {C2U, "C2U"},
    {D2, "D2"},
    {D2U, "D2U"},
    {E2, "E2"},
    {F2, "F2"},
    {F2U, "F2U"},
    {G2, "G2"},
    {G2U, "G2U"},
    {A2, "A2"},
    {A2U, "A2U"},
    {B2, "B2"},

    {C3, "C3"},
    {C3U, "C3U"},
    {D3, "D3"},
    {D3U, "D3U"},
    {E3, "E3"},
    {F3, "F3"},
    {F3U, "F3U"},
    {G3, "G3"},
    {G3U, "G3U"},
    {A3, "A3"},
    {A3U, "A3U"},
    {B3, "B3"},

    {C4, "C4"},
    {C4U, "C4U"},
    {D4, "D4"},
    {D4U, "D4U"},
    {E4, "E4"},
    {F4, "F4"},
    {F4U, "F4U"},
    {G4, "G4"},
    {G4U, "G4U"},
    {A4, "A4"},
    {A4U, "A4U"},
    {B4, "B4"},

    {C5, "C5"},
    {C5U, "C5U"},
    {D5, "D5"},
    {D5U, "D5U"},
    {E5, "E5"},
    {F5, "F5"},
    {F5U, "F5U"},
    {G5, "G5"},
    {G5U, "G5U"},
    {A5, "A5"},
    {A5U, "A5U"},
    {B5, "B5"},

    {C6, "C6"},
    {C6U, "C6U"},
    {D6, "D6"},
    {D6U, "D6U"},
    {E6, "E6"},
    {F6, "F6"},
    {F6U, "F6U"},
    {G6, "G6"},
    {G6U, "G6U"},
    {A6, "A6"},
    {A6U, "A6U"},
    {B6, "B6"}
};

int tableLen = sizeof(noteTable)/sizeof(noteTable[0]);
int table_seq;
