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
	int action=0;
	initwindow(800,600,"Game");
	PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
	while(action != 4){
		Main_Menu(&action);
		switch(action){
			case 1 : {
				cleardevice();
				Menu_Difficult(&action);
				break;
			}
			case 2:{
				cleardevice();
				HighScore_Menu(&action);
				break;
			}
			case 3:{
				cleardevice();
				About_Menu(&action);
				break;
			}
			default : break;
		}
		
		//Level Menu
		switch(action){
			case 11 :{
				cleardevice();
				game_menu(&action);
				break;}
			case 12:{
				cleardevice();
				game_menu(&action);
				break;}
			case 13:{
				cleardevice();
				game_menu(&action);
				break;}
			default : break;
		}
				
	}
	
}
