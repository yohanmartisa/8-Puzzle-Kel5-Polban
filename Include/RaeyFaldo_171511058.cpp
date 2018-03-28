#include "RaeyFaldo_171511058.h"
Button Easy, Medium, Hard;				//variabel bertipe Button dengan subvar-sbuvar untuk menyatakan tinggi lebar tombol
void Awal(){							//modul untuk menampilkan interface paling awal
		readimagefile("Assets/bg_blank.bmp",0,0,800,600);			//untuk menampilkan gambar backround
		while(!kbhit()){
			delay(500);
			readimagefile("Assets/press.bmp",200,500,600,545);		//untuk menampilkan gambar "press any key to continue"
			readimagefile("Assets/load_img1.bmp",325,250,470,410);	//untuk menampilkan gambar ayam
			
			delay(500);
			readimagefile("Assets/press_h.bmp",200,500,600,545);	//untuk menampilkan gambar
			delay(500);
			readimagefile("Assets/load_img2.bmp",325,250,470,410);	//untuk menampilkan gambar ayam yang berbeda
		}
	}
	
void Input_Nama(char *Nama){				// modul untuk input nama
	char C;									//variabel untuk menampung input dari keyboard (getch())
	int Input_Pos=0;						//variabel pointer
	int The_End=0;							//kondisi untuk keluar dari looping input dari keyboard
	int I;									//variabel yang digunakan untuk pengulnagan
	while(kbhit()) getch();
	for(I = 0; I < 11; I++) Nama[I] = 0;
	
	settextstyle(3, HORIZ_DIR, 4);
	do{										
	// pengulangan untuk menginput nama
		outtextxy (281,283, Nama);
		C = getch();	
		switch (C){
			case 8: 						
			// backspace 
          	if (Input_Pos){
          		Nama[Input_Pos] = 0;
             	Input_Pos--;
             	Nama[Input_Pos] = 0;
             	cleardevice();
             	readimagefile("Assets/bg_utama_level.bmp", 0, 0, 800, 600);
             	outtextxy (281,283, Nama);
			}break;
			
			case 13: The_End = 1; break;	
			// enter 
          	break;
          	
			default:						
			// selain tombol bacspace, enter, esc
	      		if(Input_Pos<10 && C==' '){
	      			Nama[Input_Pos] = '_';
	      			Input_Pos++;
	      			Nama[Input_Pos] = 0;
				  }
				else if (Input_Pos < 10 && C >= ' ' && C <= '~'){
	         		Nama[Input_Pos] = C;
	         		Input_Pos++;
	         		Nama[Input_Pos] = 0;
	      		  }
    	}
	}while (!The_End);						
	//pengulanag akan berhenti jika The_End tidak bernilai 0
}

void Controller_Difficult(int *Action, boolean *Cek_Sound){		
//modul untuk mengaktifkan tombol (jika suatu tombol diklik maka akan melakukan sesuatu)
	
	int Valid=0;	//untuk pengecekkan pengulangan
	int X=-1,Y=-1;	//sebagainilai defult untuk koordinat x dan y
	
	while(Valid==0){
		getmouseclick(WM_LBUTTONDOWN,X,Y);
		delay(200);
		if(X>=Easy.X && X<=Easy.X+Easy.Width && Y>=Easy.Y && Y<=Easy.Y+Easy.Height){
				Make_Button_Img(Easy,PRESS);
				Valid = 1;
				*Action = B_EASY;
		}else if(X>=Medium.X && X<=Medium.X+Medium.Width && Y>=Medium.Y && Y<=Medium.Y+Medium.Height){
				Make_Button_Img(Medium,PRESS);
				Valid = 1;
				*Action = B_MEDIUM;
		}else if(X>=Hard.X && X<=Hard.X+Hard.Width && Y>=Hard.Y && Y<=Hard.Y+Hard.Height){
				Make_Button_Img(Hard,PRESS);
			
				Valid = 1;
				*Action = B_HARD;
		}
		else if(X>=Sound.X && X<=Sound.X+Sound.Width && Y>=Sound.Y && Y<=Sound.Y+Sound.Height){
			if(*Cek_Sound){
				PlaySound(TEXT(" "), NULL,SND_ASYNC);
				*Cek_Sound = false;
			}
			else {
				PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
				*Cek_Sound = true;	
			}
			Sound_Cek(Cek_Sound);
		}
	}
}

void Menu_Difficult(int *Action, boolean *Cek_Sound, char *Nama){
	
	Easy.X = 125; 								//Koordinat X
	Easy.Y = 425; 								//Koordinat y
	Easy.Height = 50; 							//Tinggi Button
	Easy.Width = 150;							//Lebar Button
	Easy.Image = "Assets/Easy.bmp";				//Kalau Ada Gambar Buttonnya
	Easy.PRESS_Image = "Assets/h_Easy.bmp";		//gambar button yang sudah diklik
	
	Medium.X = 325; 							//Koordinat X
	Medium.Y = 425; 							//Koordinat y
	Medium.Height = 50; 						//Tinggi Button
	Medium.Width = 150;							//Lebar Button
	Medium.Image = "Assets/Medium.bmp";			//Kalau Ada Gambar Buttonnya
	Medium.PRESS_Image = "Assets/h_Medium.bmp";	//gambar button yang sudah diklik
	
	Hard.X = 525; 								//Koordinat X
	Hard.Y = 425; 								//Koordinat y
	Hard.Height = 50; 							//Tinggi Button
	Hard.Width = 150;							//Lebar Button
	Hard.Image = "Assets/Hard.bmp";				//Kalau Ada Gambar Buttonnya
	Hard.PRESS_Image = "Assets/h_Hard.bmp";		//gambar button yang sudah diklik
	
	Sound.X=740;		Sound.Y=540;
	Sound.Width=50;		Sound.Height=50;
	Sound.Image="Assets/Sound.bmp";
	Sound.PRESS_Image="Assets/h_Sound.bmp";
	
	readimagefile("Assets/bg_utama_level.bmp", 0, 0, 800, 600);
	Input_Nama(Nama);
	Sound_Cek(Cek_Sound);	
	Make_Button_Img(Easy,NOT_PRESS);	
	Make_Button_Img(Medium,NOT_PRESS);
	Make_Button_Img(Hard,NOT_PRESS);
	
	Controller_Difficult(Action, Cek_Sound);
}
