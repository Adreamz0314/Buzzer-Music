#include "stm32f10x.h"                  // Device header
#include "music_note_freq.h"

uint16_t REST=11;	//休止符
//==== C2 大字组（低音区，低音谱表）====
uint16_t C2=65;		//do
uint16_t C2U=69;	//升do
uint16_t D2=73;		//re
uint16_t D2U=78;	//升re
uint16_t E2=82;		//mi
uint16_t F2=87;		//fa
uint16_t F2U=92;	//升fa
uint16_t G2=98;		//so
uint16_t G2U=104;	//升so
uint16_t A2=110;	//la
uint16_t A2U=117;	//升la
uint16_t B2=123;	//si

//==== C3 小字组（低音谱表，低音do）====
uint16_t C3=131;	//do
uint16_t C3U=139;	//升do
uint16_t D3=147;	//re
uint16_t D3U=156;	//升re
uint16_t E3=165;	//mi
uint16_t F3=175;	//fa
uint16_t F3U=185;	//升fa
uint16_t G3=196;	//so
uint16_t G3U=208;	//升so
uint16_t A3=220;	//la
uint16_t A3U=233;	//升la
uint16_t B3=247;	//si

//==== C4 小字一组【你原来的中央C，高音低音谱表中间】====
uint16_t C4=262; 	//do
uint16_t C4U=277;	//升do
uint16_t D4=294;	//re
uint16_t D4U=311;	//升re
uint16_t E4=330;	//mi
uint16_t F4=349;	//fa
uint16_t F4U=370;	//升fa
uint16_t G4=392;	//so
uint16_t G4U=415;	//升so
uint16_t A4=440;	//la
uint16_t A4U=466;	//升la
uint16_t B4=494;	//si

//==== C5 小字二组（高音谱表，高音do）====
uint16_t C5=523;	//do
uint16_t C5U=554;	//升do
uint16_t D5=587;	//re
uint16_t D5U=622;	//升re
uint16_t E5=659;	//mi
uint16_t F5=699;	//fa
uint16_t F5U=740;	//升fa
uint16_t G5=784;	//so
uint16_t G5U=831;	//升so
uint16_t A5=880;	//la
uint16_t A5U=932;	//升la
uint16_t B5=988;	//si

//==== C6 小字三组（高音谱表上加线，超高音）====
uint16_t C6=1047;	//do
uint16_t C6U=1109;	//升do
uint16_t D6=1175;	//re
uint16_t D6U=1245;	//升re
uint16_t E6=1319;	//mi
uint16_t F6=1397;	//fa
uint16_t F6U=1480;	//升fa
uint16_t G6=1568;	//so
uint16_t G6U=1661;	//升so
uint16_t A6=1760;	//la
uint16_t A6U=1865;	//升la
uint16_t B6=1976;	//si

