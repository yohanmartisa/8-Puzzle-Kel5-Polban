#ifndef ALI_171511035_H_INCLUDED
#define ALI_171511035_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>

#define CS_ORANGE COLOR(255,204,0)
#define CS_B_ORANGE COLOR(255,153,0)
#define CS_RED COLOR(255,51,0)
#define CS_B_RED COLOR(204,0,0)
#define keyUp 0x048
#define keyDown 0x050
#define keyLeft 0x04b
#define keyRight 0x04d
#define puzzle_size 3
#define RANDOM_KEY 1
#define SOLVE_KEY 2
#define UP_KEY 3
#define HOVER 1
#define NOT_HOVER 0

typedef int puzzle;
typedef void *image;
typedef struct button{
		int width,height;
		int color,color2;
		int x,y;
		int id;
		const char *image;
		const char *hover_image;
	};
typedef struct times{
		int hour;
		int min;
		int sec;
		int msec;
};	

void waktu(int Delay);
void game_menu(int *action);
//Interface Button
void kotak(int x,int y,int width,int height);
void make_button(int x,int y,int width,int height,int color,int color2);
void draw_sidemenu(struct button up,struct button down,struct button left,struct button right,struct button sound,
				   struct button reset,struct button solve,struct button exit);
void make_button_img(struct button Button,int style);

//Kontroller Mouse
void controller_game(struct button up,struct button down,struct button left,struct button right,struct button sound,
				     struct button reset,struct button solve,struct button exit,int *action);

//Puzzle
void InitPuzz();
void SaveImgMemory(const char* filename, const char* thumbs,int grid_size);
void BorderPuzz();
void DrawPuzz(int grid_size);

//Action

#endif
