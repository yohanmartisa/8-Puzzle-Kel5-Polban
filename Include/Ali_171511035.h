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
#define B_MEDIUM 12
#define B_HARD	13
#define ACT_END	21
#define NO_ACT 100

//Tipe Data Puzzle
typedef int Puzzle;

//Tipe Data Image
typedef void *Image;

//Tipe Data Button
typedef struct Button{
		int Width,Height;
		int X,Y;
		const char *Image;
		const char *Hover_Image;
};

//Variable Yang Di Share Antar File
extern Puzzle Puzz_Final[5][5];
extern Puzzle Puzz_Rand[5][5];
extern Button Sound,Exit,Back;
extern int X_Puzz, Y_Puzz;

//Tipedata Times
typedef struct Times{
		int Hour;
		int Min;
		int Sec;
		int Msec;
};


void Waktu(int Delay);
// Prosedur Untuk Menghitung waktu pengerjaan
// Diambil Dari Penjumlahan Delay (Ms)

void Game_Menu(int *Action, boolean *Ceksound,char *Nama,int Puzzle_Size);
// Halaman Untuk Menampilkan Game Puzzle

void Draw_Button_Game();
//Menampilkan Button Game

void Make_Button_Img(struct Button Button,int Style);
//Menampilkan Button Press/Tidaknya

void De_Aloc_Img();
//Dealokasi Gambar di Memory

void Controller_Game(int *Action, boolean *Cek_Sound,int Puzzle_Size);
//Kontroller Mouse Untuk Menu Game

void Init_Puzz(int Puzzle_Size);
//Generate Puzzle Array 2D untuk ukurannnya sesuai puzzle size
//Isi Array Integer Berupa Increment Value

void Save_Img_Memory(const char* Filename, const char* Thumbs,int Grid_Size,int Puzzle_Size);
//Menampung Potongan Gambar kedalam Memory
//Ada 2 Proses Yang Pertama menampung Thumbnail dan Yang Kedua Potongan Gambar
//Grid_size untuk Mengatur width/Height untuk memotong gambar
//puzzle_size untuk ukuran puzzle

void Border_Puzz(int Grid_Size,int Puzzle_Size);
//Menampilkan Border Putih untuk membatasi puzzle

void Draw_Puzz(int Grid_Size,int Puzzle_Size);
//Menampilkan Gambar Puzzle

void Movement_Array(int Control,int Puzzle_Size, int *Movement);
//Mengatur Perpindahan Array 
#endif
