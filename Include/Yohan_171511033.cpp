#include "Yohan_171511033.h"
void About_Menu(int *action){
	
	readimagefile("Assets/bg_about.bmp",0,0,800,600);
	
	button Back,Ali,Firna,Cahya,Yohan,Aldo,sound;
	
	Back.x = 10; 		Back.y = 540;
	Back.width = 150; 	Back.height = 50;
	Back.image = "Assets/back.bmp";
	Back.hover_image = "Assets/h_back.bmp";
	
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	Yohan.x=75;		Yohan.y=150;
	Yohan.image="Assets/Foto.bmp";
	Yohan.hover_image="Assets/h_Foto.bmp";
	
	Ali.x=325;		Ali.y=150;
	Ali.image="Assets/Foto.bmp";
	Ali.hover_image="Assets/h_Foto.bmp";
	
	Firna.x=575;		Firna.y=150;
	Firna.image="Assets/Foto.bmp";
	Firna.hover_image="Assets/h_Foto.bmp";
	
	Cahya.x=200;		Cahya.y=375;
	Cahya.image="Assets/Foto.bmp";
	Cahya.hover_image="Assets/h_Foto.bmp";
	
	Aldo.x=450;		Aldo.y=375;
	Aldo.image="Assets/Foto.bmp";
	Aldo.hover_image="Assets/h_Foto.bmp";
	
	Yohan.width = Yohan.height = Ali.width = Ali.height = Firna.width = Firna.height = 
	Cahya.width = Cahya.height = Aldo.width = Aldo.height = 150 ;
	
	make_button_img(Yohan,NOT_HOVER);
	make_button_img(Ali,NOT_HOVER);
	make_button_img(Firna,NOT_HOVER);
	make_button_img(Cahya,NOT_HOVER);
	make_button_img(Aldo,NOT_HOVER);
	make_button_img(Back,NOT_HOVER);
	make_button_img(sound,NOT_HOVER);
	controller_about(Back,sound,Yohan,Ali,Firna,Cahya,Aldo,action);
}

void controller_about(struct button Back, struct button sound, struct button Yohan, struct button Ali, 
					  struct button Firna, struct button Cahya, struct button Aldo, int *action){
	int valid=0;
	int x=-1,y=-1;
	const char *temp_sound;
	int psound=0;
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(100);
		if(x>=Back.x && x<=Back.x+Back.width && y>=Back.y && y<=Back.y+Back.height){
			make_button_img(Back,HOVER);
			valid = 1;
			*action = 0;
		}
		else if(x>=Yohan.x && x<=Yohan.x+Yohan.width && y>=Yohan.y && y<=Yohan.y+Yohan.height){
			make_button_img(Yohan,HOVER);
		}
		else if(x>=Ali.x && x<=Ali.x+Ali.width && y>=Ali.y && y<=Ali.y+Ali.height){
			make_button_img(Ali,HOVER);
		}
		else if(x>=Firna.x && x<=Firna.x+Firna.width && y>=Firna.y && y<=Firna.y+Firna.height){
			make_button_img(Firna,HOVER);
		}
		else if(x>=Cahya.x && x<=Cahya.x+Cahya.width && y>=Cahya.y && y<=Cahya.y+Cahya.height){
			make_button_img(Cahya,HOVER);
		}
		else if(x>=Aldo.x && x<=Aldo.x+Aldo.width && y>=Aldo.y && y<=Aldo.y+Aldo.height){
			make_button_img(Aldo,HOVER);
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
