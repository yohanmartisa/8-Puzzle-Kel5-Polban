#ifndef ILHAM_171511042_H_INCLUDED
#define ILHAM_171511042_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#include "Ali_171511035.h"
#include "Firna_171511040.h"

typedef struct Pengguna{
	char Nama[11];
	int Skor;
	char *Level;
};

extern Pengguna Player,Temp;

void Highscore_Menu(int *Action, boolean *Cek_Sound);
void Draw_Button_And_List_Highscore(int *Action, boolean *Cek_Sound);
void Controller_Skor(int *Action, boolean *Cek_Sound);
void Write_Score(int Level);
void Show_Score();
void Sort_Score();

#endif
