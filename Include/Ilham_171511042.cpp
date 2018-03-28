#include "ilham_171511042.h"
FILE *In, *Out;

void Highscore_Menu(int *Action, boolean *Cek_Sound)
{
	readimagefile("Assets/bg_highscore.bmp",0,0,800,600);		// Menampilkan background
	rectangle(150,100,650,400);									// Membuat box highscore
	line(150,150,650,150);										// Memisahkan box highscore dan judul box
	setfillstyle(1,BLACK);										// Memberi fill berwarna hitam
	floodfill(155,155,WHITE);									// Memberi fill berwarna hitam pada box yang bordernya berwarna putih
	Draw_Button_And_List_Highscore(Action, Cek_Sound);			// Menggambar command button dan menampilkan list highscore
}

void Draw_Button_And_List_Highscore(int *Action, boolean *Cek_Sound){	

	//Button Back
	Back.X = 150;									// Koordinat X button back
	Back.Y = 425;									// Koordinat Y button back
	Back.Width = 150;								// Lebar button back
	Back.Height = 50;								// Tinggi button back
	Back.Image = "Assets/Back.bmp";					// Gambar button back
	Back.PRESS_Image = "Assets/h_Back.bmp";			// Gambar button back ketika di click / PRESS
	
	//Button Exit
	Exit.X = 500;									// Koordinat X button exit
	Exit.Y = 425;									// Koordinat Y button exit
	Exit.Width = 150;								// Lebar button exit
	Exit.Height = 50;								// Tinggi button exit
	Exit.Image = "Assets/Exit.bmp";					// Gambar button exit
	Exit.PRESS_Image = "Assets/h_exit.bmp";			// Gambar button exit ketika di click / PRESS
	
	//Button Sound
	Sound.X=740;									// Koordinat X button sound
	Sound.Y=540;									// Koordinat Y button sound
	Sound.Width=50;									// Lebar button sound
	Sound.Height=50;								// Tinggi button sound
	Sound.Image="Assets/sound.bmp"; 				// Gambar button sound
	Sound.PRESS_Image="Assets/h_sound.bmp";			// Gambar button sound ketika di click / PRESS
	
	Make_Button_Img(Back,NOT_PRESS);				// Membuat button back sesuai dengan spesifikasi
	Make_Button_Img(Exit,NOT_PRESS);				// Membuat button exit sesuai dengan spesifikasi
	Sound_Cek(Cek_Sound);							// Modul untuk mengecek apakah button sound di click atau tidak
	Show_Score();									// Modul untuk menampilkan highscore
	Controller_Skor(Action, Cek_Sound);				// Modul controller pada highscore
}

void Controller_Skor(int *Action, boolean *Cek_Sound){
	int Valid=0;									// 
	int X=-1,Y=-1;
	while(Valid==0){
		getmouseclick(WM_LBUTTONDOWN,X,Y);
		delay(100);
		if(X>=Back.X && X<=Back.X+Back.Width && Y>=Back.Y && Y<=Back.Y+Back.Height){
			Make_Button_Img(Back,PRESS);
			Valid = 1;
			*Action = NO_ACT;
		}
		else if(X>=Exit.X && X<=Exit.X+Exit.Width && Y>=Exit.Y && Y<=Exit.Y+Exit.Height){
			Make_Button_Img(Exit,PRESS);
			Valid = 1;
			*Action = B_EXIT;
		}
		else if(X>=Sound.X && X<=Sound.X+Sound.Width && Y>=Sound.Y && Y<=Sound.Y+Sound.Height){
			if(*Cek_Sound){
				PlaySound(TEXT(" "), NULL, SND_ASYNC);
				*Cek_Sound = false;
			}
			else {
				PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
				*Cek_Sound = true;	
			}
			Sound_Cek(Cek_Sound);
		}
	}
	delay(500);
	clearmouseclick(WM_LBUTTONDOWN);
}


void Write_Score(int Level)							// Modul untuk mencatat highscore ke file
{
	switch(Level){									// Switch case, untuk menkonversi kode level yg bertipe integer ke char
		case 11 : {									// Jika level = 11
			Player.Level = "EASY";						// Maka level game adalah easy
			break;
		}
		
		case 12 : {									// Jika level = 12
			Player.Level = "MEDIUM";					// Maka level game adalah medium
			break;
		}
		
		case 13 : {									// Jika level = 13
			Player.Level = "HARD";						// Maka level game adalah hard
			break;
		}
	}
	
	if((Out=fopen("highscore.dat","ab+"))==NULL)	// Mengakses (membuka) file dan mengecek apakah file tersebut bisa di buka atau tidak
	{
		printf("File tidak dapat dibuat!\r\n");			// Jika file tidak dapat dibuka, maka menampilkan informasi pada console app
		exit(1);										// Keluar dari program (game)
	}
	fwrite(&Player,sizeof(Player),1,Out);			// Mencatat (menyalin) dari Record Player ke file
	fclose(Out);									// Menutup file
}

void Show_Score()											// Modul untuk menampilkan Highscore dari file
{
	Sort_Score();											// Modul untuk menyortir dari skor terbesar ke terkecil
	Pengguna Temp;											/* Variabel Temp bertipe Pengguna berfungsi untuk menyimpan data 
																 sementara dari file untuk di tampilkan*/
	int Count=0;											/* Variabel Count bertipe Integer berfungsi untuk menghitung
																 berapa jumlah data yang telah di tampilkan*/
	char	Print_Nama[30],									// Variabel yg berfungsi menyimpan data dari hasil operasi sprintf dari Temp.Nama utk ditampilkan
			Print_Level[30],								// Variabel yg berfungsi menyimpan data dari hasil operasi sprintf dari Temp.Level utk ditampilkan
			Print_Score[30];								// Variabel yg berfungsi menyimpan data dari hasil operasi sprintf dari Temp.Score utk ditampilkan
	int	X_Score = 155,										// Variabel yg digunakan untuk menampilkan 
		Y_Score = 155;
	if((In=fopen("highscore.dat","rb"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
		//exit(1);
	}
	else{
		while((fread(&Temp,sizeof(Temp),1,In)) && Count<10){
			sprintf(Print_Nama,"%s",Temp.Nama);
			sprintf(Print_Level,"%s",Temp.Level);
			sprintf(Print_Score,"%d",Temp.Skor);
			outtextxy(X_Score, Y_Score, Print_Nama);
			outtextxy(X_Score+150, Y_Score, Print_Level);
			outtextxy(X_Score+250, Y_Score, Print_Score);
			Y_Score = Y_Score + 25;
			delay(200);
			Count++;
		}
		printf("\n");
		fclose(In);
	}
}

void Sort_Score(){
	if((Out=fopen("highscore.dat","rb+"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
	}
	else {
		Pengguna Temp;
		int Struct_Size;
		int File_Size;
		
		Struct_Size = sizeof(Player);
		fseek(Out, 0, SEEK_END);
		File_Size = ftell(Out);
		rewind(Out);
		  
		for (int I = 0; I < File_Size; I += Struct_Size){
		  for (int J = 0; J < File_Size - Struct_Size; J += Struct_Size){
		    fread(&Player, Struct_Size, 1, Out);
		    fread(&Temp, Struct_Size, 1, Out);
		    if (Player.Skor < Temp.Skor){
		      fseek(Out, -(Struct_Size * 2), SEEK_CUR);
		      fwrite(&Temp, Struct_Size, 1, Out);
		      fwrite(&Player, Struct_Size, 1, Out);
		      fseek(Out, -Struct_Size, SEEK_CUR);
		    }
		    else{
		      fseek(Out, -Struct_Size, SEEK_CUR);
		    }
		  }
		  rewind(Out);
		}
		fclose(Out);
	}
}
