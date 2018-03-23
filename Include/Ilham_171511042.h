#ifndef ILHAM_171511042_H_INCLUDED
#define ILHAM_171511042_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#include "Ali_171511035.h"
#include "Firna_171511040.h"

typedef struct Pengguna{
	char nama[11];
	int skor;
	char *level;
};

extern Pengguna player,temp;

void HighScore_Menu(int *action, boolean *ceksound);
void Draw_Button_HighScore(int *action, boolean *ceksound);
void controller_Skor(int *action, boolean *ceksound);
void Write_Score(int level);
void Show_Score();
void Sort_Score();

#endif
