#include "Ali_171511035.h"
#include "Firna_171511040.h"

	//Variabel Global

	Puzzle Puzz_Final[5][5];							//Puzzle Goal
	Puzzle Puzz_Rand[5][5];								//Puzzle Yang Dimainkan
	Image Img[5*5];										//Tempat Menyimpan Potongan Gambar
	Image Thumbnail;									//Tempat Menyimpan Thumbnail Goal
	unsigned long Size;									//Menampung Ukuran Alokasi Memory untuk Gambar
	Times Game_Times;									//Waktu saat permainan berlangsung
	Button Up,Down,Left,Right,Sound,Exit,Reset,Solve;	//Button
	int X_Puzz,Y_Puzz;
	Pengguna Player,Temp_Pengguna;
	
//Inisialisasi Puzzle Yang akan dimainkan dan Goalnya
void Init_Puzz(int Puzzle_Size){
	
	//Variable Lokal
	int I,J,K=0;
	
	//Inisialisasi Semua Elemen Array 0, Untuk Menghindari Random Value
	for(I=0;I<5;I++){
		for(J=0;J<5;J++) Puzz_Final[I][J] = Puzz_Rand[I][J] = 0;
	}
	
	//Inisialisasi Elemen Array Increment Sesuai Ukuran Puzzle Size (3*3 4*4 5*5)
	for(I=0;I<Puzzle_Size;I++){
		for(J=0;J<Puzzle_Size;J++) Puzz_Final[I][J] = Puzz_Rand[I][J] = K+=1;
	}
}

//Save Potongan Gambar Kedalam Memory Berbentuk Array
void Save_Img_Memory(const char* Filename, const char* Thumbs,int Grid_Size,int Puzzle_Size){
	
	//Variable Lokal
	int I,J,K;
	
	//Alokasi Memory Untuk Penampung Gambar
	readimagefile(Filename,0,0,450,450);
	Size=imagesize(0,0,450/Puzzle_Size,450/Puzzle_Size);
	for(I=0;I<(25);I++){
		Img[I]=malloc(Size);
	}
	
	//Potong Gambar simpan Ke Array
	K=0;
	for(I=0;I<Puzzle_Size;I++){
		for(J=0;J<Puzzle_Size;J++){
			if (K==(Puzzle_Size*Puzzle_Size-1)) getimage(650,450,650+Grid_Size,450+Grid_Size,Img[K]);
			else getimage(J*Grid_Size,I*Grid_Size,(J*Grid_Size)+Grid_Size,(I*Grid_Size)+Grid_Size,Img[K]);
			K+=1;
		}
	}
    //Simpan Gambar Thumbnail
    clearviewport();
	readimagefile(Thumbs,0,0,100,100);
    Size=imagesize(0,0,100,100);
    Thumbnail=malloc(Size);
    getimage(0,0,100,100,Thumbnail);
	clearviewport();
	Draw_Puzz(150,3);
}

//Border Putih Untuk Area Kotak Kotak Puzzle
void Border_Puzz(int Grid_Size, int Puzzle_Size){
	
	//Variable Lokal
	int I,J;
	
	//Generate Rectangle dengan border putih
	for(I=0;I<Puzzle_Size;I++){
		for(J=0;J<Puzzle_Size;J++){
			rectangle(75+(I*Grid_Size),75+(J*Grid_Size),75+(I*Grid_Size)+Grid_Size,75+(J*Grid_Size)+Grid_Size);
		}
	}
}

//Draw Puzzle Berbentuk Gambar
void Draw_Puzz(int Grid_Size, int Puzzle_Size){
	
	//Variable Lokal
	boolean Found;
	int I,J,K;
	
	//penempatan thumbnail image
	putimage(625,200,Thumbnail,COPY_PUT);
	
	//mencocokan value array dengan indeks array gambar
	for(I=0;I<Puzzle_Size;I++){
		for(J=0;J<Puzzle_Size;J++){
			putimage(J*Grid_Size+75,I*Grid_Size+75,Img[Puzz_Rand[I][J]-1],COPY_PUT);
		}
	}
	
	//Menampilkan Garis Putih Kotak Kotak Puzzle
	Border_Puzz(Grid_Size,Puzzle_Size);
}

//Membuat Tampilan Button Berbentuk Gambar (Ketika Press / Tidak)
void Make_Button_Img(struct Button Button,int Style){
	
	if(Button.Image != NULL && Button.PRESS_Image != NULL){
		if(Style==NOT_PRESS) readimagefile( Button.Image, Button.X,Button.Y, Button.X+Button.Width, Button.Y+Button.Height);
		else readimagefile( Button.PRESS_Image, Button.X,Button.Y, Button.X+Button.Width, Button.Y+Button.Height);
	}
}

//Membuat Tampilan Button Untuk Halaman Game
void Draw_Button_Game(){
	Make_Button_Img(Up,NOT_PRESS);
	Make_Button_Img(Down,NOT_PRESS);
	Make_Button_Img(Left,NOT_PRESS);
	Make_Button_Img(Right,NOT_PRESS);
	Make_Button_Img(Reset,NOT_PRESS);
	Make_Button_Img(Solve,NOT_PRESS);
	Make_Button_Img(Exit,NOT_PRESS);	
}

void Controller_Game(int *Action, boolean *Cek_Sound,int Puzzle_Size){
	
	//variable lokal
	int Valid=0, Win=0;		//untuk mengatur looping controller (valid untuk looping Jika x,y mouse valid di button) dan win untuk game selesai		
	int X=-1,Y=-1;			//koordinat mouse
	int Movement=0;			//untuk Jumlah movement puzzle
	char Move[128]; 		//text movement
	int Temp_Action = *Action;
	char String_Score[30];
	
	//Inisialisasi waktu 0:0:0:0
	Game_Times.Msec = Game_Times.Sec = Game_Times.Min = Game_Times.Hour = 0;
	
	//Looping Controller mouse
	while(Win==0){
		while(Valid==0){
			
			//Tampilkan Movement text
			sprintf(Move,"Movement : %d",Movement);
			outtextxy(590,95,Move);
			
			//mendapatkan koordinat x,y ketika klik
			getmouseclick(WM_LBUTTONDOWN,X,Y);
			
			delay(200);
			Waktu(200);
			
			//Pengecekan Jika Keyboard UP DOWN LEFT RIGHT Tertekan
			if(kbhit()){
				char key;
				key = getch();
				switch(key){
					case KeyUp :
						Make_Button_Img(Up,PRESS);
						Movement_Array(KeyUp,Puzzle_Size,&Movement);
						Valid = 1;
						*Action = NO_ACT;
						break;
					case KeyDown :
						Make_Button_Img(Down,PRESS);
						Movement_Array(KeyDown,Puzzle_Size,&Movement);
						Valid = 1;
						*Action = NO_ACT;
						break;
					case KeyLeft :
						Make_Button_Img(Left,PRESS);
						Movement_Array(KeyLeft,Puzzle_Size,&Movement);
						Valid = 1;
						*Action = NO_ACT;
						break;
					case KeyRight :
						Make_Button_Img(Right,PRESS);
						Movement_Array(KeyRight,Puzzle_Size,&Movement);
						Valid = 1;
						*Action = NO_ACT;
						break;
					default:break;
				}
			}
			
			//Button Up
			if(X>=Up.X && X<=Up.X+Up.Width && Y>=Up.Y && Y<=Up.Y+Up.Height){
				Make_Button_Img(Up,PRESS);
				Movement_Array(KeyUp,Puzzle_Size,&Movement);
				Valid = 1;
				*Action = NO_ACT;
			}
			
			//Button Down
			else if(X>=Down.X && X<=Down.X+Down.Width && Y>=Down.Y && Y<=Down.Y+Down.Height){
				Make_Button_Img(Down,PRESS);
				Movement_Array(KeyDown,Puzzle_Size,&Movement);
				Valid = 1;
				*Action = NO_ACT;
			}
			
			//Button Left
			else if(X>=Left.X && X<=Left.X+Left.Width && Y>=Left.Y && Y<=Left.Y+Left.Height){
				Make_Button_Img(Left,PRESS);
				Movement_Array(KeyLeft,Puzzle_Size,&Movement);
				Valid = 1;
				*Action = NO_ACT;
			}
			
			//Button Right
			else if(X>=Right.X && X<=Right.X+Right.Width && Y>=Right.Y && Y<=Right.Y+Right.Height){
				Make_Button_Img(Right,PRESS);
				Movement_Array(KeyRight,Puzzle_Size,&Movement);
				Valid = 1;
				*Action = NO_ACT;
			}
			
			//Button Reset
			else if(X>=Reset.X && X<=Reset.X+Reset.Width && Y>=Reset.Y && Y<=Reset.Y+Reset.Height){
				Make_Button_Img(Reset,PRESS);
				Valid = 1;
				Win = -1;
				*Action = Temp_Action;
			}
			
			//Button Solve
			else if(X>=Solve.X && X<=Solve.X+Solve.Width && Y>=Solve.Y && Y<=Solve.Y+Solve.Height){
				Make_Button_Img(Solve,PRESS);
				Valid = 1;
			}
			
			//Button EXit
			else if(X>=Exit.X && X<=Exit.X+Exit.Width && Y>=Exit.Y && Y<=Exit.Y+Exit.Height){
				Make_Button_Img(Exit,PRESS);
				*Action=0;
				Valid = 1;
				Win = -1;
			}
			
			//Cheats ( For Testing )
			else if(X>=0 && X<= (0+25) && Y>=0 && Y<=(0+25))  Cheats(Puzzle_Size);
			
			//Button Sound
			else if(X>=Sound.X && X<=Sound.X+Sound.Width && Y>=Sound.Y && Y<=Sound.Y+Sound.Height){
				if(*Cek_Sound){
					PlaySound(TEXT(" "), NULL,SND_ASYNC);
					*Cek_Sound = false;
				}
				else {
					PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);
					*Cek_Sound = true;	
				}
				Valid = 1;
				Sound_Cek(Cek_Sound);
			}
		}
		
		//Jika tidak klik tombol exit Dan Reset 
		if(*Action == NO_ACT || *Action != B_EASY != B_MEDIUM != B_HARD ){ 
			Valid=0;
			delay(200);
			Waktu(200);
			Draw_Puzz(450/Puzzle_Size,Puzzle_Size);
			Draw_Button_Game();
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		
		//Cek Kemenangan
		Victory(&Valid, &Win,Puzzle_Size);
	}
	
	if ((Valid == 1) && Win == 1){
		*Action = ACT_END;
		
		if (Temp_Action == B_EASY) {
			printf("Easy");
			Player.Skor = ((1800/((Game_Times.Hour*3600)+(Game_Times.Min*60)+(Game_Times.Sec)))*100); 	
		}
		else if (Temp_Action == B_MEDIUM) {
			printf("Medium");
			Player.Skor = ((2700/((Game_Times.Hour*3600)+(Game_Times.Min*60)+(Game_Times.Sec)))*100); 
		}
		else if (Temp_Action == B_HARD) {
			printf("Hard");
			Player.Skor = ((3600/((Game_Times.Hour*3600)+(Game_Times.Min*60)+(Game_Times.Sec)))*100); 
		}
		
		//Ganti Tampilan Ke Win
		cleardevice();
		readimagefile("Assets/bg_utama_score.bmp", 0, 0, 800, 600);
		Write_Score(Temp_Action);
		sprintf(String_Score,"Name : %s",Player.Nama);
		outtextxy (281,283, String_Score);
		sprintf(String_Score,"Score : %d",Player.Skor);
		outtextxy (281,303, String_Score);
		getch();
	}
	
}

//Menghitung Waktu
void Waktu(int Delay){
	
	//var lokal
	char Time[128];
	
	//kalkulasi
	Game_Times.Msec = Game_Times.Msec + Delay;
	if (Game_Times.Msec>=1000) {
		Game_Times.Sec=Game_Times.Sec + 1;
		Game_Times.Msec=0;	
	}
	if (Game_Times.Sec>=60) {
		Game_Times.Min = Game_Times.Min + 1;
		Game_Times.Sec = 0;	
	}
	if (Game_Times.Min>=60) {
		Game_Times.Hour = Game_Times.Hour + 1;
		Game_Times.Min = 0;
	}
	
	//tampilkan waktu pengerJaan
	sprintf(Time,"Waktu : %d:%d:%d:%d",Game_Times.Hour,Game_Times.Min,Game_Times.Sec,Game_Times.Msec);
	outtextxy(590,115,Time); 
}

void Game_Menu(int *Action, boolean *Cek_Sound, char *Nama, int Puzzle_Size){
	
	//var lokal
	int Temp_Action = *Action;
	strcpy(Player.Nama, Nama);
	
	/* Inisialisasi Button */
	//Up
	Up.X=650;		Up.Y=350;
	Up.Width=50;	Up.Height=50;
	Up.Image="Assets/Up.bmp";
	Up.PRESS_Image="Assets/h_Up.bmp";
	
	//Down
	Down.X=650;		Down.Y=450;
	Down.Width=50;	Down.Height=50;
	Down.Image="Assets/Down.bmp";
	Down.PRESS_Image="Assets/h_Down.bmp";
	
	//Left 
	Left.X=600;		Left.Y=400;
	Left.Width=50;	Left.Height=50;
	Left.Image="Assets/Left.bmp";
	Left.PRESS_Image="Assets/h_Left.bmp";
	
	//Right
	Right.X=700;		Right.Y=400;
	Right.Width=50;		Right.Height=50;
	Right.Image="Assets/Right.bmp";
	Right.PRESS_Image="Assets/h_Right.bmp";
	
	//Sound
	Sound.X=740;		Sound.Y=540;
	Sound.Width=50;		Sound.Height=50;
	Sound.Image="Assets/Sound.bmp";
	Sound.PRESS_Image="Assets/h_Sound.bmp";
	
	//Reset
	Reset.X=250;		Reset.Y=550;
	Reset.Width=75;		Reset.Height=35;
	Reset.Image="Assets/reset.bmp";
	Reset.PRESS_Image="Assets/h_reset.bmp";
	
	//Solve
	Solve.X=375;		Solve.Y=550;
	Solve.Width=75;		Solve.Height=35;
	Solve.Image="Assets/solve.bmp";
	Solve.PRESS_Image="Assets/h_solve.bmp";
	
	//Exit
	Exit.X=125;			Exit.Y=550;
	Exit.Width=75;		Exit.Height=35;
	Exit.Image="Assets/g_exit.bmp";
	Exit.PRESS_Image="Assets/h_g_exit.bmp";	
	
	//Inisialisasi Puzzle
	Init_Puzz (Puzzle_Size);
	
	//Inisialisasi Gambar Puzzle
	Save_Img_Memory ( "Assets\\Puzzle.bmp", "Assets\\Thumbs.bmp", 450/Puzzle_Size, Puzzle_Size); 
	
	//Random Puzzle
	Random (Puzzle_Size);
	
	//Draw Interface Game
	readimagefile ( "Assets\\bg_game.bmp", 0, 0, 800, 600);	
	Draw_Puzz ( 450/Puzzle_Size, Puzzle_Size);	
	Draw_Button_Game ();
	Sound_Cek ( Cek_Sound );
	settextstyle(3, HORIZ_DIR, 1);
	outtextxy(590,75,Nama);
	Controller_Game ( Action, Cek_Sound, Puzzle_Size);
	
	//Dealoc Pointer Image
	De_Aloc_Img();
	
}

//Clear Memory untuk Gambar
void De_Aloc_Img(){
	int I;
	for(I=0;I<25;I++) free(Img[I]);
	free(Thumbnail);
}

//Untuk Mengatur Movement puzzle
void Movement_Array(int Control,int Puzzle_Size, int *Movement){
	int Temp_Puzz;
	switch(Control){
		//KeyUp
		case KeyUp:{
			if((X_Puzz-1)>=0){
				Temp_Puzz = Puzz_Rand[X_Puzz-1][Y_Puzz];
				Puzz_Rand[X_Puzz-1][Y_Puzz] = Puzz_Rand[X_Puzz][Y_Puzz];
				Puzz_Rand[X_Puzz][Y_Puzz] = Temp_Puzz;
				X_Puzz-=1;
				*Movement=*Movement+1;
			}break;
		}
		
		//KeyDown
		case KeyDown:{
			if((X_Puzz+1)<Puzzle_Size){
				Temp_Puzz = Puzz_Rand[X_Puzz+1][Y_Puzz];
				Puzz_Rand[X_Puzz+1][Y_Puzz] = Puzz_Rand[X_Puzz][Y_Puzz];
				Puzz_Rand[X_Puzz][Y_Puzz] = Temp_Puzz;
				X_Puzz+=1;
				*Movement=*Movement+1;
			}break;
		}
		
		//KeyLeft
		case KeyLeft:{
			if((Y_Puzz-1)>=0){
				Temp_Puzz = Puzz_Rand[X_Puzz][Y_Puzz-1];
				Puzz_Rand[X_Puzz][Y_Puzz-1] = Puzz_Rand[X_Puzz][Y_Puzz];
				Puzz_Rand[X_Puzz][Y_Puzz] = Temp_Puzz;
				Y_Puzz-=1;
				*Movement=*Movement+1;
			}break;
		}
		
		//KeyRight
		case KeyRight:{
			if((Y_Puzz+1)<Puzzle_Size){
				Temp_Puzz = Puzz_Rand[X_Puzz][Y_Puzz+1];
				Puzz_Rand[X_Puzz][Y_Puzz+1] = Puzz_Rand[X_Puzz][Y_Puzz];
				Puzz_Rand[X_Puzz][Y_Puzz] = Temp_Puzz;
				Y_Puzz+=1;
				*Movement=*Movement+1;
			}
		}
	}
}
