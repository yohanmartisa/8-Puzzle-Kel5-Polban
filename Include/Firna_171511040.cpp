#include "Firna_171511040.h"
Button Play,Score,About;

void Main_Menu(int *Action, boolean *Cek_Sound){		// modul untuk menampilkan menu utama
	
	// Button Play
	Play.X = 325; 							//Koordinat x
	Play.Y = 250; 							//Koordinat y
	Play.Height = 50; 						//Tinggi Button
	Play.Width = 150;						//Lebar Button
	Play.Image = "Assets/play.BMP";			//gambar tombol play tidak tertekan
	Play.PRESS_Image = "Assets/h_play.BMP";	//gambar tombol play tertekan
		
	// Button Scores	
	Score.X = 325; 								//Koordinat x
	Score.Y = 325; 								//Koordinat y
	Score.Height = 50; 							//Tinggi Button
	Score.Width = 150;							//Lebar Button
	Score.Image = "Assets/Score.BMP";			//gambar tombol play tidak tertekan
	Score.PRESS_Image = "Assets/h_Score.BMP";	//gambar tombol play tertekan
	
	// Button About Us
	About.X = 325; 								//Koordinat x
	About.Y = 400; 								//Koordinat y
	About.Height = 50; 							//Tinggi Button
	About.Width = 150;							//Lebar Button
	About.Image = "Assets/About.BMP";			//gambar tombol play tidak tertekan
	About.PRESS_Image = "Assets/h_About.BMP";	//gambar tombol play tertekan
	
	// Button Exit
	Exit.X = 325; 								//Koordinat x
	Exit.Y = 475; 								//Koordinat y
	Exit.Height = 50; 							//Tinggi Button
	Exit.Width = 150;							//Lebar Button
	Exit.Image = "Assets/Exit.BMP";				//gambar tombol play tidak tertekan
	Exit.PRESS_Image = "Assets/h_Exit.BMP";		//gambar tombol play tertekan
	
	//Button Sound
	Sound.X=740;								//Koordinat x
	Sound.Y=540;								//Koordinat y
	Sound.Width=50;								//Tinggi Button
	Sound.Height=50;							//Lebar Button
	Sound.Image="Assets/sound.bmp";				//gambar tombol play tidak tertekan
	Sound.PRESS_Image="Assets/h_sound.bmp";		//gambar tombol play tertekan
	
	readimagefile("Assets/bg_utama.BMP", 0, 0, 800, 600);		//menampilkan background
	Make_Button_Img(Play,NOT_PRESS);							//menampilkan tampilan awal tombol dengan kondisi tidak tertekan
	Make_Button_Img(Score,NOT_PRESS);							//menampilkan tampilan awal tombol dengan kondisi tidak tertekan
	Make_Button_Img(About,NOT_PRESS);							//menampilkan tampilan awal tombol dengan kondisi tidak tertekan
	Make_Button_Img(Exit,NOT_PRESS);							//menampilkan tampilan awal tombol dengan kondisi tidak tertekan
	Make_Button_Img(Sound,NOT_PRESS);							//menampilkan tampilan awal tombol dengan kondisi tidak tertekan
	
	//pengecekan tombol sound
	Sound_Cek(Cek_Sound);							//modul  untuk cek tombol sedang tertekan atau tidak
	Controller_Menu_Utama(Action, Cek_Sound);		//modul untuk mengatur alur tombol ketika di klik
}

void Controller_Menu_Utama(int *Action, boolean *Cek_Sound){	//modul untuk mengatur alur tombol ketika di klik
	//deklarasi variabel lokal
	int Valid=0;		//kondisi yang sesuai koordinatnya, agar keluar dari looping apabila mencapai suatu kondisi tertentu
	int X=-1,Y=-1;		//assign awal untuk koordinat x dan y
	
	//program
	while(Valid==0){
		getmouseclick(WM_LBUTTONDOWN,X,Y);
		delay(200);
		if(X>=Play.X && X<=Play.X+Play.Width && Y>=Play.Y && Y<=Play.Y+Play.Height){	// cek sedang menekan tombol play atau tidak
			Valid = 1;
			*Action = B_LEVEL;
			Make_Button_Img(Play,PRESS);
		} else if ((X>=Score.X && X<=Score.X+Score.Width && Y>=Score.Y && Y<=Score.Y+Score.Height)){	// cek sedang menekan tombol score atau tidak
			Valid = 1;
			*Action = B_SCORE;
			Make_Button_Img(Score,PRESS);
		} else if ((X>=About.X && X<=About.X+About.Width && Y>=About.Y && Y<=About.Y+About.Height)){	// cek sedang menekan tombol about atau tidak
			Valid = 1;
			*Action = B_ABOUT;
			Make_Button_Img(About,PRESS);
		} else if ((X>=Exit.X && X<=Exit.X+Exit.Width && Y>=Exit.Y && Y<=Exit.Y+Exit.Height)){		// cek sedang menekan tombol exit atau tidak
			Valid = 1;
			*Action = B_EXIT;
			Make_Button_Img(Exit,PRESS);
		}
		else if(X>=Sound.X && X<=Sound.X+Sound.Width && Y>=Sound.Y && Y<=Sound.Y+Sound.Height){		// cek sedang menekan tombol sound atau tidak
		
			if(*Cek_Sound){			//kondisi tombol sedang tidak tertekan
				PlaySound(TEXT(" "), NULL, SND_ASYNC);
				*Cek_Sound = false;
			}
			else {												//kondisi tombol sedang tertekan
				PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
				*Cek_Sound = true;	
			}
			Sound_Cek(Cek_Sound);
		}
	}
	delay(200);
}
	
void Random (int Puzzle_Size){		//modul untuk me random puzzle
	//deklarasi variabel lokal
	int I,J;
	int T;
	
	//program
	srand(time(NULL));	//puzzle di random berdasarkan waktu
	for (I = 0; I < Puzzle_Size; I++) {
		int Rand_I = I + rand() / (RAND_MAX / (Puzzle_Size - I) + 1);
		for (J=0; J<Puzzle_Size; J++){
        	int Rand_J = J + rand() / (RAND_MAX / (Puzzle_Size - J) + 1);
        	T = Puzz_Rand[Rand_I][Rand_J];
			Puzz_Rand[Rand_I][Rand_J] = Puzz_Rand[I][J];
			Puzz_Rand[I][J] = T;
			if (Puzz_Rand[I][J] == Puzzle_Size*Puzzle_Size){
				X_Puzz=I;
				Y_Puzz=J;
			}
        }
    }
}

void Victory(int *Valid, int *Win,int Puzzle_Size){
	//deklarasi variabel lokal
	int I, J, K;
	K = 0;
	
	//program
	for(I=0;I<Puzzle_Size;I++){
		for(J=0;J<Puzzle_Size;J++){
			if(Puzz_Rand[I][J]==Puzz_Final[I][J]){
				K++;
			}
		}
	}
	if (K == Puzzle_Size*Puzzle_Size){		//kondisi apakah total yang sama telah sesuai dengan jumlah puzzle size nya
		*Valid = 1;
		*Win = 1;
	}
}

void Cheats(int Puzzle_Size){		//modul untuk mempermudah jalannya tracing
	//deklarasi variabel lokal
	int I,J;
	
	//program
	for(I=0;I<5;I++){
		for(J=0;J<5;J++){
			Puzz_Rand[I][J] = Puzz_Final[I][J];
		}
	}
	Puzz_Rand[Puzzle_Size-1][Puzzle_Size-1] = Puzzle_Size*Puzzle_Size-Puzzle_Size;
	Puzz_Rand[Puzzle_Size-2][Puzzle_Size-1] = Puzzle_Size*Puzzle_Size-(Puzzle_Size*2);
	Puzz_Rand[Puzzle_Size-3][Puzzle_Size-1] = Puzzle_Size*Puzzle_Size;
	X_Puzz=Puzzle_Size-3;
	Y_Puzz=Puzzle_Size-1;
}

void Sound_Cek(boolean *Cek_Sound){		//modul  untuk cek tombol sedang tertekan atau tidak
	//program
	if (*Cek_Sound == false){
		Make_Button_Img(Sound,PRESS);
	} else {
		Make_Button_Img(Sound,NOT_PRESS);
	}
}
