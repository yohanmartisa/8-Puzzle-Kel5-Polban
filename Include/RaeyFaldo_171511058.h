#ifndef RAEYFALDO_171511058_H_INCLUDED
#define RAEYFALDO_171511058_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#include "Firna_171511040.h"
#include "Ali_171511035.h"

void Awal();														//modul untuk menampilkan interface paling awal
//Tampilan Awal
void Menu_Difficult(int *Action, boolean *Cek_Sound, char *Nama);	//modul untuk mengaktifkan tombol (jika suatu tombol diklik maka akan melakukan sesuatu)
void Input_Nama(char *Nama);										// modul untuk input nama
void Controller_Difficult(int *Action, boolean *Ceksound);			////modul untuk mengaktifkan tombol (jika suatu tombol diklik maka akan melakukan sesuatu)


#endif
