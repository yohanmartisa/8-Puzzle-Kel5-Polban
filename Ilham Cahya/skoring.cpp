#include <graphics.h>
#include <conio.h>
#include <stdio.h>
   

int i, j, panjang, lebar, gdriver = DETECT, gmode, errorcode, varx, vary, x, y;
typedef struct{
	int x,y;
}point;

point A,B, TitikPusat;
void CreateButton(int varx, int vary, int panjang, int lebar);

int main()
{
	//initgraph(&gdriver, &gmode, "");
	initwindow(800,600);
	errorcode = graphresult();

	if (errorcode != grOk) {
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to exit:");
		getch();
		exit(1);
	}
	rectangle(150,100,650,400);
	settextstyle(BOLD_FONT,0,5);
	outtextxy(165,110,"H I G H   S C O R E");
	line(150,150,650,150);
	settextstyle(EUROPEAN_FONT,0,1);
	outtextxy(155,155,"1. Cahyahadi");
	CreateButton(150, 425, 200, 50);					// Membuat button dari line
	CreateButton(450, 425, 200, 50);					// Membuat button dari line
	settextstyle(EUROPEAN_FONT,0,1);
	outtextxy(165,440," M a i n    L a g i");
	outtextxy(465,440,"   K E L U A R   ");
	readimagefile("asset/gambar/SoundOn.jpg",725,525,775,575);
	
	while(!kbhit());					// Menunggu user menekan tombol
	closegraph();						// Menutup graph, kembali ke mode teks
	return 0;							// Keluar aplikasi
}


void CreateButton(int varx, int vary, int panjang, int lebar)
{
//	printf("Titik Pusat X = ");scanf("%d", &TitikPusat.x);
//	printf("Titik Pusat Y = ");scanf("%d", &TitikPusat.y);
//	printf("Panjang = ");scanf("%d", &panjang);
//	printf("Lebar = ");scanf("%d", &lebar);
	TitikPusat.x = varx;
	TitikPusat.y = vary;
	A.x=TitikPusat.x;		
	A.y=TitikPusat.y;
	B.x=TitikPusat.x+panjang;
	B.y=TitikPusat.y;
	for(i=0;i<4;i++)							// Membuat box besar
	{
//		delay(1000);
		line(A.x,A.y,B.x,B.y);
		if(A.x==TitikPusat.x)
		{
			if(A.y==TitikPusat.y)
			{
				A.x = TitikPusat.x + panjang;
				B.x = TitikPusat.x + panjang;
				B.y = TitikPusat.y + lebar;
			}else
			{
				A.y = TitikPusat.y;
				B.x = TitikPusat.x + panjang;
				B.y = TitikPusat.y;
			}
		}else if(A.y==TitikPusat.y)
		{
			A.y = TitikPusat.y + lebar;
			B.x = TitikPusat.x;
			B.y = TitikPusat.y + lebar;
		}else
		{
			A.x = TitikPusat.x;
			B.x = TitikPusat.x;
			B.y = TitikPusat.y;
		}
	}
	panjang = panjang - 20;						// Dirubah untuk menyesuaikan box kecil
	lebar = lebar - 20;
	TitikPusat.x = TitikPusat.x + 10;
	TitikPusat.y = TitikPusat.y + 10;
	A.x=TitikPusat.x;		
	A.y=TitikPusat.y;
	B.x=TitikPusat.x+panjang;
	B.y=TitikPusat.y;
	for(i=0;i<4;i++)							// Membuat box kecil dalam box besar
	{
//		delay(1000);
		line(A.x,A.y,B.x,B.y);
		if(A.x==TitikPusat.x)
		{
			if(A.y==TitikPusat.y)
			{
				A.x = TitikPusat.x + panjang;
				B.x = TitikPusat.x + panjang;
				B.y = TitikPusat.y + lebar;
			}else
			{
				A.y = TitikPusat.y;
				B.x = TitikPusat.x + panjang;
				B.y = TitikPusat.y;
			}
		}else if(A.y==TitikPusat.y)
		{
			A.y = TitikPusat.y + lebar;
			B.x = TitikPusat.x;
			B.y = TitikPusat.y + lebar;
		}else
		{
			A.x = TitikPusat.x;
			B.x = TitikPusat.x;
			B.y = TitikPusat.y;
		}
	}
	panjang = panjang + 20;					// Mendefaultkan nilai yang telah diubah untuk membuat box kecil
	lebar = lebar + 20;
	TitikPusat.x = TitikPusat.x - 10;
	TitikPusat.y = TitikPusat.y - 10;
	
	A.x=TitikPusat.x;						// Assign ke dalam variabel	
	A.y=TitikPusat.y;
	B.x=TitikPusat.x+10;
	B.y=TitikPusat.y+10;
	
	for(i=0;i<4;i++){						// Membuat garis pada setiap pojok box
		line(A.x,A.y,B.x,B.y);
		if(A.x==TitikPusat.x)
		{
			if(A.y==TitikPusat.y)
			{
				A.x = TitikPusat.x + panjang;
				B.x = TitikPusat.x + panjang - 10;
				B.y = TitikPusat.y + 10;
			}else if(A.y==TitikPusat.y)
			{
				B.x = TitikPusat.x + 10;
				B.y = TitikPusat.y + 10;
			}
		}else if(A.y==TitikPusat.y)
		{
			A.y = TitikPusat.y + lebar;
			B.x = TitikPusat.x + panjang - 10;
			B.y = TitikPusat.y + lebar - 10;
		}else{
			A.x = TitikPusat.x;
			B.x = TitikPusat.x + 10;
			B.y = TitikPusat.y + lebar - 10;
		}
	}
		/*	Memberi efek warna pada button	*/
		
	
	do
	{
		setfillstyle(1, RED);
		floodfill((TitikPusat.x+panjang/2),(TitikPusat.y+lebar/2),WHITE);		// Tengah
		setfillstyle(1, LIGHTRED);
		floodfill((TitikPusat.x+panjang/2),TitikPusat.y+5,WHITE);				// Atas
		setfillstyle(1, RED);
		floodfill(TitikPusat.x+panjang-5,(TitikPusat.y+lebar/2),WHITE);			// Kanan
		setfillstyle(1, RED);
		floodfill((TitikPusat.x+panjang/2),TitikPusat.y+lebar-5,WHITE);			// Bawah
		setfillstyle(1, LIGHTRED);
		floodfill(TitikPusat.x+5,(TitikPusat.y+lebar/2),WHITE);					// Kiri
		//getch();
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if((x>TitikPusat.x && x<TitikPusat.x+panjang) && (y>TitikPusat.y && y<TitikPusat.y+lebar))
			{
				setfillstyle(1, LIGHTRED);
				floodfill((TitikPusat.x+panjang/2),(TitikPusat.y+lebar/2),WHITE);		// Tengah
				setfillstyle(1, RED);
				floodfill((TitikPusat.x+panjang/2),TitikPusat.y+5,WHITE);				// Atas
				setfillstyle(1, LIGHTRED);
				floodfill(TitikPusat.x+panjang-5,(TitikPusat.y+lebar/2),WHITE);			// Kanan
				setfillstyle(1, LIGHTRED);
				floodfill((TitikPusat.x+panjang/2),TitikPusat.y+lebar-5,WHITE);			// Bawah
				setfillstyle(1, RED);
				floodfill(TitikPusat.x+5,(TitikPusat.y+lebar/2),WHITE);					// Kiri
			}
		}
		delay(150);
	}while(ismouseclick(WM_LBUTTONDOWN));
	//setfillstyle(1, RED);
	//floodfill(TitikPusat.x+10,TitikPusat.y+10,WHITE);
}
