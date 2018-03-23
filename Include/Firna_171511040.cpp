#include "Firna_171511040.h"
button Play,Score,About;

void Main_Menu(int *action, boolean *ceksound){
	
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
	
	//pengecekan tombol sound
	soundcek(ceksound);
	controller_menu_utama(action, ceksound);
}

void controller_menu_utama(int *action, boolean *ceksound){
	int valid=0;
	int x=-1,y=-1;
	int psound=0;
	
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(200);
		if(x>=Play.x && x<=Play.x+Play.width && y>=Play.y && y<=Play.y+Play.height){
			valid = 1;
			*action = B_LEVEL;
			make_button_img(Play,HOVER);
		} else if ((x>=Score.x && x<=Score.x+Score.width && y>=Score.y && y<=Score.y+Score.height)){
			valid = 1;
			*action = B_SCORE;
			make_button_img(Score,HOVER);
		} else if ((x>=About.x && x<=About.x+About.width && y>=About.y && y<=About.y+About.height)){
			valid = 1;
			*action = B_ABOUT;
			make_button_img(About,HOVER);
		} else if ((x>=Exit.x && x<=Exit.x+Exit.width && y>=Exit.y && y<=Exit.y+Exit.height)){
			valid = 1;
			*action = B_EXIT;
			make_button_img(Exit,HOVER);
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
	delay(200);
}
	
void random (int puzzle_size){
	int i,j;
	int t;
	srand(time(NULL));
	for (i = 0; i < puzzle_size; i++) {
		int rand_i = i + rand() / (RAND_MAX / (puzzle_size - i) + 1);
		for (j=0; j<puzzle_size; j++){
        	int rand_j = j + rand() / (RAND_MAX / (puzzle_size - j) + 1);
        	t = puzz_rand[rand_i][rand_j];
			puzz_rand[rand_i][rand_j] = puzz_rand[i][j];
			puzz_rand[i][j] = t;
			if (puzz_rand[i][j] == puzzle_size*puzzle_size){
				x_puzz=i;
				y_puzz=j;
			}
        }
    }
}

void victory(int *valid, int *win,int puzzle_size){
	int i, j, k;
	k = 0;
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++){
			if(puzz_rand[i][j]==puzz_final[i][j]){
				k++;
			}
		}
	}
	if (k == puzzle_size*puzzle_size){
		*valid = 1;
		*win = 1;
	}
}

void cheats(int puzzle_size){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			puzz_rand[i][j] = puzz_final[i][j];
		}
	}
	puzz_rand[puzzle_size-1][puzzle_size-1] = puzzle_size*puzzle_size-puzzle_size;
	puzz_rand[puzzle_size-2][puzzle_size-1] = puzzle_size*puzzle_size-(puzzle_size*2);
	puzz_rand[puzzle_size-3][puzzle_size-1] = puzzle_size*puzzle_size;
	x_puzz=puzzle_size-3;
	y_puzz=puzzle_size-1;
}

void soundcek(boolean *ceksound){
	if (*ceksound == false){
		make_button_img(sound,HOVER);
	} else {
		make_button_img(sound,NOT_HOVER);
	}
}
