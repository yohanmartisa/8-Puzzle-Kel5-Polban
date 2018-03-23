#include "RaeyFaldo_171511058.h"
button easy,medium,hard;
void awal(){
		readimagefile("Assets/bg_blank.bmp",0,0,800,600);
		while(!kbhit()){
			delay(500);
			readimagefile("Assets/press.bmp",200,500,600,545);
			readimagefile("Assets/load_img1.bmp",325,250,470,410);
			
			delay(500);
			readimagefile("Assets/press_h.bmp",200,500,600,545);
			delay(500);
			readimagefile("Assets/load_img2.bmp",325,250,470,410);
		}
	}
	
void input_nama(char *nama){
	char c;
	int input_pos=0, the_end=0,i;
	while(kbhit()) getch();
	for(i = 0; i < 11; i++) nama[i] = 0;
	
	settextstyle(3, HORIZ_DIR, 4);
	do{		
		outtextxy (281,283, nama);
		c = getch();	
		switch (c){
			case 8: 						/* backspace */
          	if (input_pos){
          		nama[input_pos] = 0;
             	input_pos--;
             	nama[input_pos] = 0;
             	cleardevice();
             	readimagefile("Assets/bg_utama_level.bmp", 0, 0, 800, 600);
             	outtextxy (281,283, nama);
			}break;
			case 13: the_end = 1; break;	/* return */
			case 27: 						/* Escape = Abort */
          		nama[0] = 0;
          		the_end = 1;
          	break;
			default:
	      		if(input_pos<10 && c==' '){
	      			nama[input_pos] = '_';
	      			input_pos++;
	      			nama[input_pos] = 0;
				  }
				else if (input_pos < 10 && c >= ' ' && c <= '~'){
	         		nama[input_pos] = c;
	         		input_pos++;
	         		nama[input_pos] = 0;
	      		  }
    	}
	}while (!the_end);
}

void controller_difficult(int *action, boolean *ceksound){
	int valid=0;
	int x=-1,y=-1;
	int psound=0;
	
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(200);
		if(x>=easy.x && x<=easy.x+easy.width && y>=easy.y && y<=easy.y+easy.height){
				make_button_img(easy,HOVER);
				valid = 1;
				*action = B_EASY;
		}else if(x>=medium.x && x<=medium.x+medium.width && y>=medium.y && y<=medium.y+medium.height){
				make_button_img(medium,HOVER);
			
				valid = 1;
				*action = B_MEDIUM;
		}else if(x>=hard.x && x<=hard.x+hard.width && y>=hard.y && y<=hard.y+hard.height){
				make_button_img(hard,HOVER);
			
				valid = 1;
				*action = B_HARD;
		}
		else if(x>=sound.x && x<=sound.x+sound.width && y>=sound.y && y<=sound.y+sound.height){
			psound=psound+1;
			if((psound%2==1) && (*ceksound == true)){
				mciSendString("pause myMidi",0,0,0);
				make_button_img(sound,HOVER);
				*ceksound = false;
			}
			else {
				make_button_img(sound,NOT_HOVER);
				mciSendString("resume myMidi",0,0,0);
				*ceksound = true;	
			}
		}
	}
}

void Menu_Difficult(int *action, boolean *ceksound, char *nama){
	
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
	medium.width = 150;		//Lebar Button
	medium.image = "Assets/Medium.bmp";		//Kalau Ada Gambar Buttonnya
	medium.hover_image = "Assets/h_Medium.bmp";
	
	hard.x = 525; 		//Koordinat x
	hard.y = 425; 		//Koordinat y
	hard.height = 50; 	//Tinggi Button
	hard.width = 150;	//Lebar Button
	hard.image = "Assets/Hard.bmp";		//Kalau Ada Gambar Buttonnya
	hard.hover_image = "Assets/h_Hard.bmp";
	
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	readimagefile("Assets/bg_utama_level.bmp", 0, 0, 800, 600);
	input_nama(nama);
	soundcek(ceksound);	
	make_button_img(easy,NOT_HOVER);
	make_button_img(medium,NOT_HOVER);
	make_button_img(hard,NOT_HOVER);
	
	controller_difficult(action, ceksound);
}
