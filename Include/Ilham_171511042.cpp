#include "ilham_171511042.h"
void HighScore_Menu(int *action)
{
	readimagefile("Assets/bg_highscore.bmp",0,0,800,600);
	kotak(150,100,500,300);
	line(150,150,650,150);
	setfillstyle(1,BLACK);
	floodfill(155,155,WHITE);
	Draw_Button_HighScore(action);	
}

void Draw_Button_HighScore(int *action)
{
	button Back;			// Tombol Main Lagi
	button Exit;			// Tombol Keluar
	button sound;
	
	
	Back.x = 150;			// Koordinat X
	Back.y = 425;			// Koordinat Y
	Back.width = 150;		// Lebar button
	Back.height = 50;		// Tinggi button
	Back.image = "Assets/Back.bmp";
	Back.hover_image = "Assets/h_Back.bmp";
	
	Exit.x = 500;			// Koordinat X
	Exit.y = 425;			// Koordinat Y
	Exit.width = 150;		// Lebar button
	Exit.height = 50;		// Tinggi button
	Exit.image = "Assets/Exit.bmp";
	Exit.hover_image = "Assets/h_exit.bmp";
	
		//Button Sound
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	make_button_img(Back,NOT_HOVER);	
	make_button_img(Exit,NOT_HOVER);
	make_button_img(sound,NOT_HOVER);
	
	controller_Skor(Back, Exit, sound,action);
}

void controller_Skor(struct button Button1, struct button Button2,struct button sound,int *action){
	int valid=0;
	int x=-1,y=-1;
	const char *temp_sound;
	int psound=0;
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(100);
		if(x>=Button1.x && x<=Button1.x+Button1.width && y>=Button1.y && y<=Button1.y+Button1.height){
			make_button_img(Button1,HOVER);
			valid = 1;
			*action = 0;
		}
		else if(x>=Button2.x && x<=Button2.x+Button2.width && y>=Button2.y && y<=Button2.y+Button2.height){
			make_button_img(Button2,HOVER);
			valid = 1;
			*action = 4;
			//closegraph();
		}
		else if(x>=sound.x && x<=sound.x+sound.width && y>=sound.y && y<=sound.y+sound.height){
				psound=psound+1;
				if(psound%2==1){
					mciSendString("pause myMidi",0,0,0);
					temp_sound = sound.image;
					sound.image = sound.hover_image;
				}
				else {
					sound.image = temp_sound;
					mciSendString("resume myMidi",0,0,0);	
				}
				valid = 1;
				}
	}
	delay(500);
	clearmouseclick(WM_LBUTTONDOWN);
}

