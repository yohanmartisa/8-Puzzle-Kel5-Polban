#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>

#include "Include\\Ali_171511035.h"
#include "Include\\Firna_171511040.h"
#include "Include\\Ilham_171511042.h"
#include "Include\\RaeyFaldo_171511058.h"
#include "Include\\Yohan_171511033.h"


int main(){
	int Action=NO_ACT;
	char Nama[11];
	boolean Cek_Sound = true;
	
	initwindow(800,600,"Game");
	Awal();
	
	PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
			
	while(Action != B_EXIT){
		Main_Menu(&Action, &Cek_Sound);
		switch(Action){
			case B_LEVEL : {
				cleardevice();
				Menu_Difficult(&Action, &Cek_Sound, Nama);
				break;
			}
			case B_SCORE:{
				cleardevice();
				Highscore_Menu(&Action, &Cek_Sound);
				break;
			}
			case B_ABOUT:{
				cleardevice();
				About_Menu(&Action, &Cek_Sound);
				break;
			}
			default : break;
		}
		
		//Game Menu
		while (Action == B_EASY || Action == B_MEDIUM || Action == B_HARD || Action == 21){
			switch(Action){
				case B_EASY :{
					cleardevice();
					Game_Menu(&Action, &Cek_Sound, Nama,3);
					break;}
				case B_MEDIUM:{
					cleardevice();
					Game_Menu(&Action, &Cek_Sound, Nama,4);
					break;}
				case B_HARD:{
					cleardevice();
					Game_Menu(&Action, &Cek_Sound, Nama,5);
					break;}
				case ACT_END :{
					cleardevice();
					Highscore_Menu(&Action, &Cek_Sound);
					break;
				}
				default : break;
			}
		}
				
	}
}
