#include <graphics.h>
#include <stdio.h>

typedef struct{
	int x;
	int y;
}point;

int x, y;
point A, B;

main(){
	int i, x1, y1, x2, y2, color, maxcolor;
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "test", -3, -3);
		
	A.x = 200;
	A.y = 200;
	B.x = 400;
	B.y = 200;
	
	for (i=0; i<4; i++){
		line(A.x, A.y, B.x, B.y);
		A.x = B.x;
		A.y = B.y;
		if (B.x == 400){
			if (B.y == 200){
				B.y = 400;
			} else B.x = 200;
		} else if (B.y == 400){
			B.y = 200;
		} else B.x = 400;
	}
	
	A.x = 10;
	A.y = 10;
	B.x = 150;
	B.y = 10;
	
	for (i=0; i<4; i++){
		line(A.x, A.y, B.x, B.y);
		A.x = B.x;
		A.y = B.y;
		if (B.x == 150){
			if (B.y == 10){
				B.y = 150;
			} else B.x = 10;
		} else if (B.y == 150){
			B.y = 10;
		} else B.x = 150;
	}
	
	A.x = 30;
	A.y = 30;
	B.x = 130;
	B.y = 30;
	
	for (i=0; i<4; i++){
		line(A.x, A.y, B.x, B.y);
		A.x = B.x;
		A.y = B.y;
		if (B.x == 130){
			if (B.y == 30){
				B.y = 130;
			} else B.x = 30;
		} else if (B.y == 130){
			B.y = 30;
		} else B.x = 130;
	}

	do{
		line(10, 10, 30, 30);
		line(150, 10, 130, 30);
		line(10, 150, 30, 130);
		line(150, 150, 130, 130);
		setfillstyle(1, LIGHTBLUE);
		floodfill(30,12, WHITE);
		floodfill(20,25, WHITE);	
		setfillstyle(1, LIGHTBLUE );
		floodfill(40,40, WHITE);
		setfillstyle(1, BLUE);
		floodfill(100,149, WHITE);
		floodfill(148,100, WHITE);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x > 0) && (x < 150) && (y > 0) && (y < 130)){
				setfillstyle(1, BLUE);
				floodfill(30,12, WHITE);
				floodfill(20,25, WHITE);
				setfillstyle(1, LIGHTBLUE);
				floodfill(100,149, WHITE);
				floodfill(148,100, WHITE);
			}	
		}
		delay(200);
	} while(3<4);
	getch();
}
