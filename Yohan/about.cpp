#include <graphics.h>
#include <stdio.h>

#include <stdlib.h>


#include <conio.h>



main(){
	int left,top,right,bottom,x,y;
	initwindow(800,600,"about");
	//kotak judul
	rectangle(225,50,575,125);
		outtextxy(375,80,"ABOUT US");

	//kotak identitas
	rectangle(75,150,225,350);
	line(75,300,225,300);
	
	rectangle(325,150,475,350);
	line(325,300,475,300);
	
	rectangle(575,150,725,350);
	line(575,300,725,300);
	
	rectangle(200,375,350,575);
	line(200,525,350,525);
	rectangle(450,375,600,575);
	line(450,525,600,525);
	//kotak tombol
	rectangle(50,500,125,550);
	rectangle(40,490,135,560);
	outtextxy(70,515,"<------");
	//line pada tombol BACK
	line(50,500,40,490)	;
	line(125,500,135,490);
	line(50,550,40,560);
	line(125,550,135,560);
	//tombol suara
	rectangle(725,500,775,550);
	rectangle(715,490,785,560);
	//read image
	
	readimagefile("E:/polban/proyek/proyek 2/1.jpg",725,500,775,550);

	//desain tombol
	do{
	
		setfillstyle(SOLID_FILL,LIGHTRED);

		
		floodfill(55,510,WHITE);
		floodfill(46,495,WHITE);
		floodfill(44,495,WHITE);
				setfillstyle(1,RED);
		floodfill(127,555,WHITE);
		floodfill(132,555,WHITE);
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN,x,y);
				setfillstyle(1,RED);

		
		floodfill(55,510,WHITE);
		floodfill(46,495,WHITE);
		floodfill(44,495,WHITE);
				setfillstyle(SOLID_FILL,LIGHTRED);
		floodfill(127,555,WHITE);
		floodfill(132,555,WHITE);

		}
	
	delay(300);
}while(3<4);
		


	
	
	
	getch();
	closegraph();
	
}
