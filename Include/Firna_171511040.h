#ifndef FIRNA_171511040_H_INCLUDED
#define FIRNA_171511040_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#include "Ali_171511035.h"

void controller_menu_utama(int *action, boolean *ceksound);
void Main_Menu(int *action, boolean *ceksound);
void random (int puzzle_size);
void victory(int *valid, int *win,int puzzle_size);
void cheats (int puzzle_size);
void soundcek(boolean *ceksound);
#endif
