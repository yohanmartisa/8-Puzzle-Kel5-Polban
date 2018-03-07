#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>
#define CS_ORANGE COLOR(255,204,0)
#define CS_B_ORANGE COLOR(255,153,0)
#define CS_RED COLOR(255,51,0)
#define CS_B_RED COLOR(204,0,0)
#define keyUp 0x048
#define keyDown 0x050
#define keyLeft 0x04b
#define keyRight 0x04d

int puzz_final[3][3];
int puzz_rand[3][3];
int puzzle_size=3;
void *img[3*3];
void *thumbnail;
unsigned long size;

void kotak(int x,int y,int width,int height);
void make_button(int x,int y,int width,int height,int color,int color2);
void draw_sidemenu();
void controller();

void InitPuzz(){
	//generate puzzle array
	int i,j,k=0;
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++){
			puzz_final[i][j] = puzz_rand[i][j] = k+=1;
			printf("%d ",puzz_final[i][j]);}
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
			getimage(j*grid_size,i*grid_size,(j*grid_size)+grid_size,(i*grid_size)+grid_size,img[k]);
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

void DrawPuzz(int grid_size){
putimage(625,125,thumbnail,COPY_PUT);
int found,i,j,k;
for(i=0;i<3;i++){
			
		for(j=0;j<3;j++){
			found=false;
			for(k=1;k<(puzzle_size*puzzle_size);k++){
				if(puzz_rand[i][j]==k && not found){
					putimage(j*grid_size+75,i*grid_size+75,img[k-1],COPY_PUT);
					found=true;
				}
			}
		printf("%d ",puzz_rand[i][j]);
		}
		printf("\n");
	}
}
main(){
	
	typedef struct button{
		int width,height;
		int color,color2;
		int x,y;
	} B_Arrow;
	initwindow(800,600,"Game");
	InitPuzz();
	SaveImgMemory("Assets\\Puzzle.bmp","Assets\\Thumbs.bmp",450/3);

	readimagefile("Assets\\bg_game.bmp",0,0,800,600);
	DrawPuzz(450/3);
	rectangle(75,75,225,225);
	rectangle(225,75,375,225);
	rectangle(375,75,525,225);
	
	rectangle(75,225,225,375);
	rectangle(225,225,375,375);
	rectangle(375,225,525,375);
	
	rectangle(75,375,225,525);
	rectangle(225,375,375,525);
	rectangle(375,375,525,525);
	draw_sidemenu();
	controller();
	getch();	
}



void kotak(int x,int y,int width,int height){
	line(x,y,x+width,y);
	line(x+width,y,x+width,y+height);
	line(x+width,y+height,x,y+height);
	line(x,y+height,x,y);
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
	//floodfill(new_x+2,new_y+2,WHITE); // tengah
	setfillstyle(1,color2);
	floodfill(new_x-2,new_y,WHITE); //kiri
	floodfill(new_x+2,new_y+new_height+2,WHITE); //bawah
}
void draw_sidemenu(){
	
	make_button(575,250,75,75,CS_RED,CS_B_RED); // Random Key
	make_button(700,250,75,75,CS_RED,CS_B_RED); // Solve Key
	make_button(650,350,50,50,CS_ORANGE,CS_B_ORANGE); // UP Key
	make_button(650,450,50,50,CS_ORANGE,CS_B_ORANGE); // Down Key
	make_button(600,400,50,50,CS_ORANGE,CS_B_ORANGE); // Left Key
	make_button(700,400,50,50,CS_ORANGE,CS_B_ORANGE); // Right Key
	make_button(700,525,50,50,CS_ORANGE,CS_B_ORANGE); // Sound Key
	make_button(600,525,50,50,CS_RED,CS_B_RED); // Exit Key
	readimagefile("Assets\\sound.bmp",705,530,745,570);
	readimagefile("Assets\\exit.bmp",605,530,645,570);
	readimagefile("Assets\\up.bmp",655,355,695,395);
	readimagefile("Assets\\down.bmp",655,455,695,495);
	readimagefile("Assets\\left.bmp",605,405,645,445);
	readimagefile("Assets\\right.bmp",705,405,745,445);
}
void controller(){
	int valid=0;
	int win=0;
	char key;
	int sound=0;
	int x=-1,y=-1;
	while(win==0){
		while(valid==0){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			delay(100);
			if(x>=575 && x<=650 && y>=250 && y<=325){
				make_button(575,250,75,75,CS_B_RED,CS_RED); // Random Key
				valid = 1;
			}
			else if(x>=700 && x<=775 && y>=250 && y<=325){
				make_button(700,250,75,75,CS_B_RED,CS_RED); // Solve Key
				valid = 1;
			}
			else if(x>=650 && x<=700 && y>=350 && y<=400){
				make_button(650,350,50,50,CS_B_ORANGE,CS_ORANGE); // UP Key
				valid = 1;
				readimagefile("Assets\\h_up.bmp",655,355,695,395);
				PlaySound(TEXT("Assets\\move.wav"), NULL, SND_SYNC);
				//clearviewport();
				DrawPuzz(450/3);
			}
			else if(x>=650 && x<=700 && y>=450 && y<=500){
				make_button(650,450,50,50,CS_B_ORANGE,CS_ORANGE); // Down Key
				valid = 1;
				readimagefile("Assets\\h_down.bmp",655,455,695,495);
				PlaySound(TEXT("Assets\\move.wav"), NULL, SND_ASYNC);
			}
			else if(x>=600 && x<=650 && y>=400 && y<=450){		
				make_button(600,400,50,50,CS_B_ORANGE,CS_ORANGE); // Left Key
				valid = 1;
				readimagefile("Assets\\h_left.bmp",605,405,645,445);
				PlaySound(TEXT("Assets\\move.wav"), NULL, SND_ASYNC);
			}
			else if(x>=700 && x<=750 && y>=400 && y<=450){		
				make_button(700,400,50,50,CS_B_ORANGE,CS_ORANGE); // Right Key
				valid = 1;
				readimagefile("Assets\\h_right.bmp",705,405,745,445);
				PlaySound(TEXT("Assets\\move.wav"), NULL, SND_ASYNC);
			}
			else if(x>=700 && x<=750 && y>=525 && y<=575){
				sound=sound+1;
				printf("%d ",sound);
				if(sound%2==1){
					mciSendString("pause Assets\\intro.wav",0,0,0);
					
				}
				else mciSendString("resume Assets\\intro.wav",0,0,0);		
				make_button(700,525,50,50,CS_B_ORANGE,CS_ORANGE); // Sound Key
				valid = 1;
			}
			else if(x>=600 && x<=650 && y>=525 && y<=575){		
				make_button(600,525,50,50,CS_B_RED,CS_RED); // Exit Key
				valid = 1;
			}
		}
		valid=0;
		delay(500);
		draw_sidemenu();
		clearmouseclick(WM_LBUTTONDOWN);
	}
}
