#include <graphics.h>
#include <stdio.h>

int x, y;

main(){
	initwindow (800, 600, "Halaman Utama", 0, 0);
	
	// Pemasangan Logo
	readimagefile("Assets/Gambar/LOGO.JPG", 200, 50, 600, 150);
	
	// Button Play
	rectangle (325, 250, 475, 300);	// Kotak Terluar
	rectangle (335, 260, 465, 290);	// Kotak Terdalam
	line (325, 250, 335, 260);		// Garis yang menghubungkan kotak luar dan dalam
	line (475, 300, 465, 290);
	line (475, 250, 465, 260);
	line (325, 300, 335, 290);
	setfillstyle(1, LIGHTBLUE);		// Pemberian effect button
	floodfill (330,251, WHITE);
	floodfill (326,260, WHITE);
	setfillstyle (1, BLUE);
	floodfill (470, 261, WHITE);
	floodfill (450, 295, WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(370,265,"Play");	// Pemberian teks

	// Button Scores
	rectangle (325, 325, 475, 375);	// Kotak Terluar
	rectangle (335, 335, 465, 365);	// Kotak Terdalam
	line (325, 325, 335, 335);		// Garis yang menghubungkan kotak luar dan dalam
	line (475, 375, 465, 365);
	line (475, 325, 465, 335);
	line (325, 375, 335, 365);
	setfillstyle(1, LIGHTBLUE);		// Pemberian effect button
	floodfill (330, 326, WHITE);
	floodfill (326, 335, WHITE);
	setfillstyle(1, BLUE);
	floodfill (470, 336, WHITE);
	floodfill (450, 370, WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(355,340,"Scores");	// Pemberian teks
	
	// Button About Us
	rectangle (325, 400, 475, 450);	// Kotak Terluar
	rectangle (335, 410, 465, 440);	// Kotak Terdalam
	line (325, 400, 335, 410);		// Garis yang menghubungkan kotak luar dan dalam
	line (475, 450, 465, 440);
	line (475, 400, 465, 410);
	line (325, 450, 335, 440);
	setfillstyle(1, LIGHTBLUE);		// Pemberian effect button
	floodfill (330, 401, WHITE);
	floodfill (326, 410, WHITE);
	setfillstyle (1, BLUE);
	floodfill (470, 411, WHITE);
	floodfill (450, 445, WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);	// Pemberian teks
	outtextxy(342,416,"About Us");	
	
	// Button Exit
	rectangle (325, 475, 475, 525);	// Kotak Terluar
	rectangle (335, 485, 465, 515);	// Kotak Terdalam
	line (325, 475, 335, 485);		// Garis yang menghubungkan kotak luar dan dalam
	line (475, 525, 465, 515);
	line (475, 475, 465, 485);
	line (325, 525, 335, 515);
	setfillstyle(1, LIGHTBLUE);		// Pemberian effect button
	floodfill (330, 476, WHITE);
	floodfill (326, 485, WHITE);
	setfillstyle (1, BLUE);
	floodfill (470, 486, WHITE);
	floodfill (450, 520, WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);	// Pemberian teks
	outtextxy(370,489,"Exit");	

	getch();
}
