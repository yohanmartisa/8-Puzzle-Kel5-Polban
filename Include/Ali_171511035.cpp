#include "Ali_171511035.h"

puzzle puzz_final[puzzle_size][puzzle_size];
puzzle puzz_rand[puzzle_size][puzzle_size];
image img[puzzle_size*puzzle_size];
image thumbnail;
unsigned long size;
times game_times;

void InitPuzz()
{
	//generate puzzle array
	int i,j,k=0;
	for(i=0;i<puzzle_size;i++)
	{
		for(j=0;j<puzzle_size;j++)
		{
			puzz_final[i][j] = puzz_rand[i][j] = k+=1;
			printf("%d ",puzz_final[i][j]);
		}
		printf("\n");
	}
}

void SaveImgMemory(const char* filename, const char* thumbs,int grid_size){
	int i,j,k=0;
	readimagefile(filename,0,0,450,450);
	size=imagesize(0,0,450,450);
	
	for(i=0;i<(3*3);i++){
		img[i]=malloc(size);
	}
	
	k=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (k==8){
				getimage(650,450,650+grid_size,450+grid_size,img[k]);
			}
			else getimage(j*grid_size,i*grid_size,(j*grid_size)+grid_size,(i*grid_size)+grid_size,img[k]);
			k+=1;
		}
	}
    clearviewport();
    //thumbnail
    readimagefile(thumbs,0,0,100,100);
    size=imagesize(0,0,600,600);
    thumbnail=malloc(size);
    getimage(0,0,100,100,thumbnail);
	clearviewport();
}

void BorderPuzz(){
	rectangle(75,75,225,225);
	rectangle(225,75,375,225);
	rectangle(375,75,525,225);
		
	rectangle(75,225,225,375);
	rectangle(225,225,375,375);
	rectangle(375,225,525,375);
	
	rectangle(75,375,225,525);
	rectangle(225,375,375,525);
	rectangle(375,375,525,525);
}
void DrawPuzz(int grid_size){
putimage(625,200,thumbnail,COPY_PUT);
int found,i,j,k;
for(i=0;i<3;i++){
			
		for(j=0;j<3;j++){
			found=false;
			for(k=1;k<=(puzzle_size*puzzle_size);k++){
				if(puzz_rand[i][j]==k && not found){
					putimage(j*grid_size+75,i*grid_size+75,img[k-1],COPY_PUT);
					found=true;
				}
			}
		printf("%d ",puzz_rand[i][j]);
		}
		printf("\n");
	}
	BorderPuzz();
}

void kotak(int x,int y,int width,int height){
	line(x,y,x+width,y);
	line(x+width,y,x+width,y+height);
	line(x+width,y+height,x,y+height);
	line(x,y+height,x,y);
}
void make_button_img(struct button Button,int style){
	if(Button.image != NULL && Button.hover_image != NULL){
		if(style==NOT_HOVER) readimagefile(Button.image,Button.x,Button.y,Button.x+Button.width,Button.y+Button.height);
		else readimagefile(Button.hover_image,Button.x,Button.y,Button.x+Button.width,Button.y+Button.height);
	}
}
void make_button(int x,int y,int width,int height,int color,int color2){
	int temp_x,temp_y;
	int new_x,new_y,new_width,new_height;
	kotak(x,y,width,height);
	temp_x = x;
	temp_y = y;
	new_x=temp_x+(width*10/100);
	new_y=temp_y+(width*10/100);
	temp_x = new_x - temp_x;
	temp_y = new_y - temp_y;
	new_width = width-temp_x*2;
	new_height = height-temp_y*2;
	kotak(new_x,new_y,new_width,new_height);
	line(x,y,new_x,new_y); //sudut kiri
	line(x+temp_x,temp_y+new_height+y,x,y+height); //sudut kiri bawah
	line(width+x,y,new_x+new_width,new_y); //sudut kanan atas
	line(width+x,y+height,new_x+new_width,new_y+new_height); //sudut kanan bawah
	//Pewarnaan
	setfillstyle(1,color);
	floodfill(new_x+2,new_y-2,WHITE); //atas
	floodfill(new_x+new_width+2,new_y,WHITE); //kanan
	floodfill(new_x+2,new_y+2,WHITE); // tengah
	setfillstyle(1,color2);
	floodfill(new_x-2,new_y,WHITE); //kiri
	floodfill(new_x+2,new_y+new_height+2,WHITE); //bawah
}
void draw_sidemenu(struct button up,struct button down,struct button left,
				   struct button right,struct button sound,struct button reset,
				   struct button solve,struct button exit){
				   	
	make_button_img(up,NOT_HOVER);
	make_button_img(down,NOT_HOVER);
	make_button_img(left,NOT_HOVER);
	make_button_img(right,NOT_HOVER);
	make_button_img(sound,NOT_HOVER);
	make_button_img(reset,NOT_HOVER);
	make_button_img(solve,NOT_HOVER);
	make_button_img(exit,NOT_HOVER);
	
}
void controller_game(struct button up,struct button down,struct button left,
				struct button right,struct button sound,struct button reset,
				struct button solve,struct button exit,int *action){
	int valid=0;
	int win=0;
	int psound=0;
	int x=-1,y=-1;
	int score=0;
	char sc[128];
	const char *temp_sound;
	game_times.msec = game_times.sec = game_times.min = game_times.hour = 0;
	
	while(win==0){
		while(valid==0){
			sprintf(sc,"Score : %d",score);
			outtextxy(590,75,sc);
			getmouseclick(WM_LBUTTONDOWN,x,y);
			delay(200);
			waktu(200);
			if(x>=up.x && x<=up.x+up.width && y>=up.y && y<=up.y+up.height){
				make_button_img(up,HOVER);
				score=score+1;
				valid = 1;
			}
			else if(x>=down.x && x<=down.x+down.width && y>=down.y && y<=down.y+down.height){
				make_button_img(down,HOVER);
				score=score+1;
				valid = 1;
			}
			else if(x>=left.x && x<=left.x+left.width && y>=left.y && y<=left.y+left.height){
				make_button_img(left,HOVER);
				score=score+1;
				valid = 1;
			}
			else if(x>=right.x && x<=right.x+right.width && y>=right.y && y<=right.y+right.height){
				make_button_img(right,HOVER);
				score=score+1;
				valid = 1;
			}
			else if(x>=reset.x && x<=reset.x+reset.width && y>=reset.y && y<=reset.y+reset.height){
				make_button_img(reset,HOVER);
				valid = 1;
			}
			else if(x>=solve.x && x<=solve.x+solve.width && y>=solve.y && y<=solve.y+solve.height){
				make_button_img(solve,HOVER);
				valid = 1;
			}
			else if(x>=exit.x && x<=exit.x+exit.width && y>=exit.y && y<=exit.y+exit.height){
				make_button_img(exit,HOVER);
				*action=0;
				valid = 1;
				win = -1;
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
			if(action != 0){ //Jika tidak klik tombol exit
				valid=0;
				delay(200);
				waktu(200);
				draw_sidemenu(up,down,left,right,sound,reset,solve,exit);
				clearmouseclick(WM_LBUTTONDOWN);	
			}
		}
}
void waktu(int Delay){
	char time[128];
	game_times.msec = game_times.msec + 200;
	if (game_times.msec>=1000) {
		game_times.sec=game_times.sec + 1;
		game_times.msec=0;	
	}
	if (game_times.sec>=60) {
		game_times.min = game_times.min + 1;
		game_times.sec = 0;	
	}
	if (game_times.min>=60) {
		game_times.hour = game_times.hour + 1;
		game_times.min = 0;
	}
	sprintf(time,"Waktu : %d:%d:%d:%d",game_times.hour,game_times.min,game_times.sec,game_times.msec);
	outtextxy(590,90,time); 
}
void game_menu(int *action){
	button up,down,left,right,sound,exit,reset,solve;
	
	InitPuzz();
	cleardevice();
	SaveImgMemory("Assets\\Puzzle.bmp","Assets\\Thumbs.bmp",450/3);
//	mciSendString("open Assets\\intro.wav type waveaudio alias myMidi",NULL,0,NULL);
//	mciSendString("play myMidi notify",NULL,0,NULL);
	readimagefile("Assets\\bg_game.bmp",0,0,800,600);
	DrawPuzz(450/3);
	
	//Button Up
	up.x=650;		up.y=350;
	up.width=50;	up.height=50;
	up.image="Assets/up.bmp";
	up.hover_image="Assets/h_up.bmp";
	
	//Button Down
	down.x=650;		down.y=450;
	down.width=50;	down.height=50;
	down.image="Assets/down.bmp";
	down.hover_image="Assets/h_down.bmp";
	
	//Button Left 
	left.x=600;		left.y=400;
	left.width=50;	left.height=50;
	left.image="Assets/left.bmp";
	left.hover_image="Assets/h_left.bmp";
	
	//Button Right
	right.x=700;		right.y=400;
	right.width=50;		right.height=50;
	right.image="Assets/right.bmp";
	right.hover_image="Assets/h_right.bmp";
	
	//Button Sound
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	//Button Reset
	reset.x=250;		reset.y=550;
	reset.width=75;		reset.height=35;
	reset.image="Assets/reset.bmp";
	reset.hover_image="Assets/h_reset.bmp";
	
	//Button Solve
	solve.x=375;		solve.y=550;
	solve.width=75;		solve.height=35;
	solve.image="Assets/solve.bmp";
	solve.hover_image="Assets/h_solve.bmp";
	
	//Button Exit
	exit.x=125;		exit.y=550;
	exit.width=75;		exit.height=35;
	exit.image="Assets/g_exit.bmp";
	exit.hover_image="Assets/h_g_exit.bmp";
	
	draw_sidemenu(up,down,left,right,sound,reset,solve,exit);
	controller_game(up,down,left,right,sound,reset,solve,exit,&(*action));
	
	//PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
	//mciSendString("play ""Assets\\intro.wav"" repeat",NULL,0,NULL);

}
