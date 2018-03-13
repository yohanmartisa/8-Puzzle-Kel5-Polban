#ifndef RAEYFALDO_171511058_H_INCLUDED
#define RAEYFALDO_171511058_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>

#include "Ali_171511035.h"

void Menu_Difficult(int *action);
void draw_menu_dificult(struct button easy, struct button medium, struct button hard,struct button sound);
void controller_difficult(struct button easy, struct button medium, struct button hard, struct button sound,int *action);

#endif
