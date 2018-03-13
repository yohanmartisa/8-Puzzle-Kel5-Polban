#include "Firna_171511040.h"

void Main_Menu(int *action){
	button Play,Score,About,Exit,sound;
	
	// Button Play
	Play.x = 325; 		//Koordinat x
	Play.y = 250; 		//Koordinat y
	Play.height = 50; 	//Tinggi Button
	Play.width = 150;	//Lebar Button
	Play.image = "Assets/play.BMP";
	Play.hover_image = "Assets/h_play.BMP";
		
	// Button Scores	
	Score.x = 325; 		//Koordinat x
	Score.y = 325; 		//Koordinat y
	Score.height = 50; 	//Tinggi Button
	Score.width = 150;	//Lebar Button
	Score.image = "Assets/Score.BMP";
	Score.hover_image = "Assets/h_Score.BMP";
	
	// Button About Us
	About.x = 325; 		//Koordinat x
	About.y = 400; 		//Koordinat y
	About.height = 50; 	//Tinggi Button
	About.width = 150;	//Lebar Button
	About.image = "Assets/About.BMP";
	About.hover_image = "Assets/h_About.BMP";
	
	// Button Exit
	Exit.x = 325; 		//Koordinat x
	Exit.y = 475; 		//Koordinat y
	Exit.height = 50; 	//Tinggi Button
	Exit.width = 150;	//Lebar Button
	Exit.image = "Assets/Exit.BMP";
	Exit.hover_image = "Assets/h_Exit.BMP";
	
	//Button Sound
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	readimagefile("Assets/bg_utama.BMP", 0, 0, 800, 600);
	make_button_img(Play,NOT_HOVER);
	make_button_img(Score,NOT_HOVER);
	make_button_img(About,NOT_HOVER);
	make_button_img(Exit,NOT_HOVER);
	make_button_img(sound,NOT_HOVER);
	controller_menu_utama(Play, Score, About, Exit, sound, action);
}

void controller_menu_utama(struct button Button1,struct button Button2,struct button Button3,struct button Button4,struct button sound,int *action){
	int valid=0;
	int x=-1,y=-1;
	const char *temp_sound;
	int psound=0;
	
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(200);
		if(x>=Button1.x && x<=Button1.x+Button1.width && y>=Button1.y && y<=Button1.y+Button1.height){
			valid = 1;
			*action = 1;
			make_button_img(Button1,HOVER);
		} else if ((x>=Button2.x && x<=Button2.x+Button2.width && y>=Button2.y && y<=Button2.y+Button2.height)){
			valid = 1;
			*action = 2;
			make_button_img(Button2,HOVER);
		} else if ((x>=Button3.x && x<=Button3.x+Button3.width && y>=Button3.y && y<=Button3.y+Button3.height)){
			valid = 1;
			*action = 3;
			make_button_img(Button3,HOVER);
		} else if ((x>=Button4.x && x<=Button4.x+Button4.width && y>=Button4.y && y<=Button4.y+Button4.height)){
			valid = 1;
			*action = 4;
			make_button_img(Button4,HOVER);
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
	delay(200);
	}
