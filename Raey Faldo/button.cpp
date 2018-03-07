#include <stdio.h>
#include <graphics.h>

//POINT tempcursor;
//int xx, yy;
main()

{
	int i, x, y;

	struct titik
	{
		int x, y;
	}A, B, C, D, E, F, G, H;
	
//	struct garis
//	{
//		titik A, B, C, D;
//	}AB, BC;
	
	/*struct kotak
	{
		titik.x;
		titik.y;
	}L1, L2, L3, L4;*/
	
	initwindow(800, 600, "tombol");
	
	A.x = 300;
	A.y = 200;
	
	B.x = 500;
	B.y = 200;
	
	C.x = 500;
	C.y = 400;
	
	D.x = 300;
	D.y = 400;
	
	E.x = 325;
	E.y = 225;
	
	F.x = 475;
	F.y = 225;
	
	G.x = 475;
	G.y = 375;
	
	H.x = 325;
	H.y = 375;
	
	line(A.x, A.y, B.x, B.y);
	line(B.x, B.y, C.x, C.y);
	line(C.x, C.y, D.x, D.y);
	line(D.x, D.y, A.x, A.y);
	
	line(E.x, E.y, F.x, F.y);
	line(F.x, F.y, G.x, G.y);
	line(G.x, G.y, H.x, H.y);
	line(H.x, H.y, E.x, E.y);
	
	line(A.x, A.y, E.x, E.y);
	line(B.x, B.y, F.x, F.y);
	line(C.x, C.y, G.x, G.y);
	line(D.x, D.y, H.x, H.y);
	
	do{
	setfillstyle(1, LIGHTRED); //tengah
	floodfill(400, 300, WHITE); 
	
	setfillstyle(1, RED); //kanan
	floodfill(476, 300, WHITE);
	
	setfillstyle(1, RED); // bawah
	floodfill(475, 376, WHITE);
	
	setfillstyle(1, LIGHTRED); // kiri
	floodfill(324, 375, WHITE);
	
	setfillstyle(1, LIGHTRED); // atas
	floodfill(325, 224, WHITE);
	
	//getch();
	
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(((x > 300 && x < 500) && (y > 200 && y < 400)))
		{
			//getch();
			setfillstyle(1, RED); 		//tengah
			floodfill(400, 300, WHITE); 
	
			setfillstyle(1, LIGHTRED); 	//kanan
			floodfill(476, 300, WHITE);
	
			setfillstyle(1, LIGHTRED); 	// bawah
			floodfill(475, 376, WHITE);
	
			setfillstyle(1, RED); 		// kiri
			floodfill(324, 375, WHITE);
	
			setfillstyle(1, RED); 		// atas
			floodfill(325, 224, WHITE);
		}
	}
	delay(200);
	}while(3<4);
	
	
//	do{
//		GetCursorPos(&tempcursor);
//		xx = tempcursor.x;
//		yy = tempcursor.y;
//		
//		if(GetASyn)
//	}
	
	getch();
	
}
