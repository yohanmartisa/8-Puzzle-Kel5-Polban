#include "ilham_171511042.h"
FILE *in, *out;

void HighScore_Menu(int *action, boolean *ceksound)
{
	readimagefile("Assets/bg_highscore.bmp",0,0,800,600);
	rectangle(150,100,650,400);
	line(150,150,650,150);
	setfillstyle(1,BLACK);
	floodfill(155,155,WHITE);
	Draw_Button_HighScore(action, ceksound);	
}

void Draw_Button_HighScore(int *action, boolean *ceksound){	

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
	soundcek(ceksound);
	Show_Score();
	controller_Skor(action, ceksound);
}

void controller_Skor(int *action, boolean *ceksound){
	int valid=0;
	int x=-1,y=-1;
	int psound=0;
	while(valid==0){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		delay(100);
		if(x>=Back.x && x<=Back.x+Back.width && y>=Back.y && y<=Back.y+Back.height){
			make_button_img(Back,HOVER);
			valid = 1;
			*action = NO_ACT;
		}
		else if(x>=Exit.x && x<=Exit.x+Exit.width && y>=Exit.y && y<=Exit.y+Exit.height){
			make_button_img(Exit,HOVER);
			valid = 1;
			*action = B_EXIT;
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
	delay(500);
	clearmouseclick(WM_LBUTTONDOWN);
}


void Write_Score(int level)
{
	switch(level){
		case 11 : {
			player.level = "EASY";
			break;
		}
		
		case 12 : {
			player.level = "MEDIUM";
			break;
		}
		
		case 13 : {
			player.level = "HARD";
			break;
		}
	}
	
	if((out=fopen("highscore.dat","ab+"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
		exit(1);
	}
	fwrite(&player,sizeof(player),1,out);	
	fclose(out);
}

void Show_Score()
{
	Sort_Score();
	Pengguna temp;
	int count=0;
	char print[30],printnama[30],printlevel[30],printscore[30];
	int xnama = 155, yscore = 155, xscore = 485, xlevel = 320;
	if((in=fopen("highscore.dat","rb"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
		//exit(1);
	}
	else{
		while((fread(&temp,sizeof(temp),1,in)) && count<10){
//			sprintf(print, "%s \t\t\t %s \t\t\t %d", temp.nama, temp.level, temp.skor);
		
			//outtextxy(xnama, yscore, print);
			sprintf(printnama,"%s",temp.nama);
			sprintf(printlevel,"%s",temp.level);
			sprintf(printscore,"%d",temp.skor);
			outtextxy(xnama, yscore, printnama);
			outtextxy(xnama+150, yscore, printlevel);
			outtextxy(xnama+250, yscore, printscore);
			yscore = yscore + 25;
			delay(200);
			count++;
		}
		printf("\n");
		fclose(in);
	}
}

void Sort_Score(){
	if((out=fopen("highscore.dat","rb+"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
	}
	else {
		Pengguna temp;
		int structSize;
		int fileSize;
		
		structSize = sizeof(player);
		fseek(out, 0, SEEK_END);
		fileSize = ftell(out);
		rewind(out);
		  
		for (int i = 0; i < fileSize; i += structSize){
		  for (int j = 0; j < fileSize - structSize; j += structSize){
		    fread(&player, structSize, 1, out);
		    fread(&temp, structSize, 1, out);
		    if (player.skor < temp.skor){
		      fseek(out, -(structSize * 2), SEEK_CUR);
		      fwrite(&temp, structSize, 1, out);
		      fwrite(&player, structSize, 1, out);
		      fseek(out, -structSize, SEEK_CUR);
		    }
		    else{
		      fseek(out, -structSize, SEEK_CUR);
		    }
		  }
		  rewind(out);
		}
		fclose(out);
	}
}
