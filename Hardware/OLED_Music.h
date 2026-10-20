# ifndef _OLED_MUSIC_H
# define _OLED_MUSIC_H

	typedef struct
{
	int(*data)[3];
	int notes_seq;
			
} Bars_Notes_Seq;

void OLED_Pre_Show(void);
void OLED_Var_Show(int i,int n,Bars_Notes_Seq bar_test[23]);

	typedef struct 
{
    int val;
    char name[8];
} Note;

extern Note noteTable[61];
extern int tableLen;
extern int table_seq;

# endif
