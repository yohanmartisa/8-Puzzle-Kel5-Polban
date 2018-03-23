#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>

#include "Include\\Ali_171511035.h"
#include "Include\\Firna_171511040.h"
#include "Include\\Ilham_171511042.h"
#include "Include\\RaeyFaldo_171511058.h"
#include "Include\\Yohan_171511033.h"
#include "Include\\config.h"


int main(){
	int action=NO_ACT;
	char nama[11];
	boolean ceksound = true;
	
	initwindow(800,600,"Game");
	awal();
	
	mciSendString("open Assets\\intro.wav type waveaudio alias myMidi",NULL,0,NULL);
	mciSendString("play myMidi notify",NULL,0,NULL);
			
	while(action != B_EXIT){
		Main_Menu(&action, &ceksound);
		switch(action){
			case B_LEVEL : {
				cleardevice();
				Menu_Difficult(&action, &ceksound, nama);
				break;
			}
			case B_SCORE:{
				cleardevice();
				HighScore_Menu(&action, &ceksound);
				break;
			}
			case B_ABOUT:{
				cleardevice();
				About_Menu(&action, &ceksound);
				break;
			}
			default : break;
		}
		
		//Game Menu
		while (action == B_EASY || action == B_MEDIUM || action == B_HARD || action == 21){
			switch(action){
				case B_EASY :{
					cleardevice();
					game_menu(&action, &ceksound, nama,3);
					break;}
				case B_MEDIUM:{
					cleardevice();
					game_menu(&action, &ceksound, nama,4);
					break;}
				case B_HARD:{
					cleardevice();
					game_menu(&action, &ceksound, nama,5);
					break;}
				case ACT_END :{
					cleardevice();
					HighScore_Menu(&action, &ceksound);
					break;
				}
				default : break;
			}
		}
				
	}
	//mciSendString("play ""Assets\\intro.wav""",NULL,0,NULL);
}
