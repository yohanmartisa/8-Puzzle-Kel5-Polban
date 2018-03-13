#include "RaeyFaldo_171511058.h"
void draw_menu_dificult(struct button easy, struct button medium, struct button hard,struct button sound){	
	make_button_img(easy,NOT_HOVER);
	make_button_img(medium,NOT_HOVER);
	make_button_img(hard,NOT_HOVER);
	make_button_img(sound,NOT_HOVER);
}
void controller_difficult(struct button easy, struct button medium, struct button hard, struct button sound,int *action){
	int valid=0;
	//int sound=0;
	int x=-1,y=-1;
	const char *temp_sound;
	int psound=0;
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(200);
		if(x>=easy.x && x<=easy.x+easy.width && y>=easy.y && y<=easy.y+easy.height){
				make_button_img(easy,HOVER);
			
				valid = 1;
				*action = 11;
		}else if(x>=medium.x && x<=medium.x+medium.width && y>=medium.y && y<=medium.y+medium.height){
				make_button_img(medium,HOVER);
			
				valid = 1;
				*action = 12;
		}else if(x>=hard.x && x<=hard.x+hard.width && y>=hard.y && y<=hard.y+hard.height){
				make_button_img(hard,HOVER);
			
				valid = 1;
				*action = 13;
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
		//valid=0;
		//delay(500);
}

void Menu_Difficult(int *action){
	
	button easy;
	button medium;
	button hard,sound;
	
	easy.x = 125; 		//Koordinat x
	easy.y = 425; 		//Koordinat y
	easy.height = 50; 	//Tinggi Button
	easy.width = 150;	//Lebar Button
	easy.image = "Assets/Easy.bmp";		//Kalau Ada Gambar Buttonnya
	easy.hover_image = "Assets/h_Easy.bmp";
	
	//Alokasi Button Pertama
	medium.x = 325; 		//Koordinat x
	medium.y = 425; 		//Koordinat y
	medium.height = 50; 	//Tinggi Button
	medium.width = 150;	//Lebar Button
	medium.image = "Assets/Medium.bmp";		//Kalau Ada Gambar Buttonnya
	medium.hover_image = "Assets/h_Medium.bmp";
	
	hard.x = 525; 		//Koordinat x
	hard.y = 425; 		//Koordinat y
	hard.height = 50; 	//Tinggi Button
	hard.width = 150;	//Lebar Button
	hard.image = "Assets/Hard.bmp";		//Kalau Ada Gambar Buttonnya
	hard.hover_image = "Assets/h_Hard.bmp";
	
		//Button Sound
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	readimagefile("Assets/bg_utama_level.bmp", 0, 0, 800, 600);
	draw_menu_dificult(easy, medium, hard,sound);
	controller_difficult(easy, medium, hard, sound,action);
}
