#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <MMSystem.h>

int m, n, i;

main(){
	initwindow (800, 600, "Halaman Utama", 0, 0);

	readimagefile("../Assets/bg_utama.BMP", 0, 0, 800, 600);
	
	getch();
}
