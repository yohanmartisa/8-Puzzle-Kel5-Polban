#ifndef ALI_171511035_H_INCLUDED
#define ALI_171511035_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#include "Ilham_171511042.h"

#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define HOVER 1
#define NOT_HOVER 0
#define B_LEVEL	1
#define B_SCORE	2
#define B_ABOUT	3
#define B_EXIT	4
#define B_EASY	11
#define B_MEDIUM	12
#define B_HARD	13
#define ACT_END	21
#define NO_ACT 100

//Tipe Data Puzzle
typedef int puzzle;

//Tipe Data Image
typedef void *image;

//Tipe Data Button
typedef struct button{
		int width,height;
		int x,y;
		const char *image;
		const char *hover_image;
};

//Variable Yang Di Share Antar File
extern puzzle puzz_final[5][5];
extern puzzle puzz_rand[5][5];
extern button sound,Exit,Back;
extern int x_puzz, y_puzz;

//Tipedata Times
typedef struct times{
		int hour;
		int min;
		int sec;
		int msec;
};


void waktu(int Delay);
// Prosedur Untuk Menghitung waktu pengerjaan
// Diambil Dari Penjumlahan Delay (Ms)

void game_menu(int *action, boolean *ceksound,char *nama,int puzzle_size);
// Halaman Untuk Menampilkan Game Puzzle

void DrawButtonGame();
//Menampilkan Button Game

void make_button_img(struct button Button,int style);
//Menampilkan Button Press/Tidaknya

void DeAlocGambar();
//Dealokasi Gambar di Memory

void controller_game(int *action, boolean *ceksound,int puzzle_size);
//Kontroller Mouse Untuk Menu Game

void InitPuzz(int puzzle_size);
//Generate Puzzle Array 2D untuk ukurannnya sesuai puzzle size
//Isi Array Integer Berupa Increment Value

void SaveImgMemory(const char* filename, const char* thumbs,int grid_size,int puzzle_size);
//Menampung Potongan Gambar kedalam Memory
//Ada 2 Proses Yang Pertama menampung Thumbnail dan Yang Kedua Potongan Gambar
//Grid_size untuk Mengatur width/Height untuk memotong gambar
//puzzle_size untuk ukuran puzzle

void BorderPuzz(int grid_size,int puzzle_size);
//Menampilkan Border Putih untuk membatasi puzzle

void DrawPuzz(int grid_size,int puzzle_size);
//Menampilkan Gambar Puzzle

void Movement(int Control,int puzzle_size, int *movement);
//Mengatur Perpindahan Array 
#endif
