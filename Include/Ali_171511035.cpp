#include "Ali_171511035.h"
#include "Firna_171511040.h"

	//Variabel Global

	puzzle puzz_final[5][5];							//Puzzle Goal
	puzzle puzz_rand[5][5];								//Puzzle Yang Dimainkan
	image img[5*5];										//Tempat Menyimpan Potongan Gambar
	image thumbnail;									//Tempat Menyimpan Thumbnail Goal
	unsigned long size;									//Menampung Ukuran Alokasi Memory untuk Gambar
	times game_times;									//Waktu saat permainan berlangsung
	button up,down,left,right,sound,Exit,reset,solve;	//Button
	int x_puzz,y_puzz;
	Pengguna player,temp;
	
//Inisialisasi Puzzle Yang akan dimainkan dan Goalnya
void InitPuzz(int puzzle_size){
	
	//Variable Lokal
	int i,j,k=0;
	
	//Inisialisasi Semua Elemen Array 0, Untuk Menghindari Random Value
	for(i=0;i<5;i++){
		for(j=0;j<5;j++) puzz_final[i][j] = puzz_rand[i][j] = 0;
	}
	
	//Inisialisasi Elemen Array Increment Sesuai Ukuran Puzzle Size (3*3 4*4 5*5)
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++) puzz_final[i][j] = puzz_rand[i][j] = k+=1;
	}
}

//Save Potongan Gambar Kedalam Memory Berbentuk Array
void SaveImgMemory(const char* filename, const char* thumbs,int grid_size,int puzzle_size){
	
	//Variable Lokal
	int i,j,k;
	
	//Alokasi Memory Untuk Penampung Gambar
	readimagefile(filename,0,0,450,450);
	size=imagesize(0,0,450/puzzle_size,450/puzzle_size);
	for(i=0;i<(25);i++){
		img[i]=malloc(size);
	}
	
	//Potong Gambar simpan Ke Array
	k=0;
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++){
			if (k==(puzzle_size*puzzle_size-1)) getimage(650,450,650+grid_size,450+grid_size,img[k]);
			else getimage(j*grid_size,i*grid_size,(j*grid_size)+grid_size,(i*grid_size)+grid_size,img[k]);
			k+=1;
		}
	}
	
    //Simpan Gambar Thumbnail
    clearviewport();
	readimagefile(thumbs,0,0,100,100);
    size=imagesize(0,0,100,100);
    thumbnail=malloc(size);
    getimage(0,0,100,100,thumbnail);
	clearviewport();
}

//Border Putih Untuk Area Kotak Kotak Puzzle
void BorderPuzz(int grid_size, int puzzle_size){
	
	//Variable Lokal
	int i,j;
	
	//Generate Rectangle dengan border putih
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++){
			rectangle(75+(i*grid_size),75+(j*grid_size),75+(i*grid_size)+grid_size,75+(j*grid_size)+grid_size);
		}
	}
}

//Draw Puzzle Berbentuk Gambar
void DrawPuzz(int grid_size, int puzzle_size){
	
	//Variable Lokal
	boolean found;
	int i,j,k;
	
	//penempatan thumbnail image
	putimage(625,200,thumbnail,COPY_PUT);
	
	//mencocokan value array dengan indeks array gambar
	for(i=0;i<puzzle_size;i++){
		for(j=0;j<puzzle_size;j++){
			found=false;
			for(k=1;k<=(puzzle_size*puzzle_size);k++){
				if(puzz_rand[i][j]==k && not found){
					putimage(j*grid_size+75,i*grid_size+75,img[k-1],COPY_PUT);
					found=true;
				}
			}
		}
	}
	
	//Menampilkan Garis Putih Kotak Kotak Puzzle
	BorderPuzz(grid_size,puzzle_size);
}

//Membuat Tampilan Button Berbentuk Gambar (Ketika Press / Tidak)
void make_button_img(struct button Button,int style){
	
	if(Button.image != NULL && Button.hover_image != NULL){
		if(style==NOT_HOVER) readimagefile( Button.image, Button.x,Button.y, Button.x+Button.width, Button.y+Button.height);
		else readimagefile( Button.hover_image, Button.x,Button.y, Button.x+Button.width, Button.y+Button.height);
	}
}

//Membuat Tampilan Button Untuk Halaman Game
void DrawButtonGame(){
	make_button_img(up,NOT_HOVER);
	make_button_img(down,NOT_HOVER);
	make_button_img(left,NOT_HOVER);
	make_button_img(right,NOT_HOVER);
	make_button_img(reset,NOT_HOVER);
	make_button_img(solve,NOT_HOVER);
	make_button_img(Exit,NOT_HOVER);	
}

void controller_game(int *action, boolean *ceksound,int puzzle_size){
	
	//variable lokal
	int valid=0, win=0;		//untuk mengatur looping controller (valid untuk looping jika x,y mouse valid di button) dan win untuk game selesai		
	int psound=0;			//untuk mengatur gambar button sound mute atau tidak
	int x=-1,y=-1;			//koordinat mouse
	int movement=0;			//untuk jumlah movement puzzle
	char move[128]; 		//text movement
	int temp_action = *action;
	char string_score[30];
	
	//Inisialisasi waktu 0:0:0:0
	game_times.msec = game_times.sec = game_times.min = game_times.hour = 0;
	
	//Looping Controller mouse
	while(win==0){
		while(valid==0){
			
			//Tampilkan Movement text
			sprintf(move,"Movement : %d",movement);
			outtextxy(590,95,move);
			
			//mendapatkan koordinat x,y ketika klik
			getmouseclick(WM_LBUTTONDOWN,x,y);
			
			delay(200);
			waktu(200);
			
			//Button Up
			if(x>=up.x && x<=up.x+up.width && y>=up.y && y<=up.y+up.height){
				make_button_img(up,HOVER);
				Movement(KeyUp,puzzle_size,&movement);
				valid = 1;
				*action = NO_ACT;
			}
			
			//Button Down
			else if(x>=down.x && x<=down.x+down.width && y>=down.y && y<=down.y+down.height){
				make_button_img(down,HOVER);
				Movement(KeyDown,puzzle_size,&movement);
				valid = 1;
				*action = NO_ACT;
			}
			
			//Button Left
			else if(x>=left.x && x<=left.x+left.width && y>=left.y && y<=left.y+left.height){
				make_button_img(left,HOVER);
				Movement(KeyLeft,puzzle_size,&movement);
				valid = 1;
				*action = NO_ACT;
			}
			
			//Button Right
			else if(x>=right.x && x<=right.x+right.width && y>=right.y && y<=right.y+right.height){
				make_button_img(right,HOVER);
				Movement(KeyRight,puzzle_size,&movement);
				valid = 1;
				*action = NO_ACT;
			}
			
			//Button Reset
			else if(x>=reset.x && x<=reset.x+reset.width && y>=reset.y && y<=reset.y+reset.height){
				make_button_img(reset,HOVER);
				valid = 1;
				win = -1;
				*action = temp_action;
			}
			
			//Button Solve
			else if(x>=solve.x && x<=solve.x+solve.width && y>=solve.y && y<=solve.y+solve.height){
				make_button_img(solve,HOVER);
				valid = 1;
			}
			
			//Button Exit
			else if(x>=Exit.x && x<=Exit.x+Exit.width && y>=Exit.y && y<=Exit.y+Exit.height){
				make_button_img(Exit,HOVER);
				*action=0;
				valid = 1;
				win = -1;
			}
			
			//Cheats ( For Testing )
			else if(x>=0 && x<= (0+25) && y>=0 && y<=(0+25))  cheats (puzzle_size);
			
			//Button Sound
			else if(x>=sound.x && x<=sound.x+sound.width && y>=sound.y && y<=sound.y+sound.height){
				psound=psound+1;
				if((psound%2==1) && (*ceksound == true)){
					mciSendString("pause myMidi",0,0,0);
					make_button_img(sound,HOVER);
					*ceksound = false;
				}
				else {
					mciSendString("resume myMidi",0,0,0);
					make_button_img(sound,NOT_HOVER);
					*ceksound = true;	
				}
				valid = 1;
			}
		}
		
		//Jika tidak klik tombol exit Dan Reset 
		if(*action == NO_ACT || *action != B_EASY != B_MEDIUM != B_HARD ){ 
			valid=0;
			delay(200);
			waktu(200);
			DrawPuzz(450/puzzle_size,puzzle_size);
			DrawButtonGame();
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		
		//Cek Kemenangan
		victory(&valid, &win,puzzle_size);
	}
	
	if ((valid == 1) && win == 1){
		*action = ACT_END;
		
		if (temp_action == B_EASY) {
			printf("Easy");
			player.skor = ((1800/((game_times.hour*3600)+(game_times.min*60)+(game_times.sec)))*100); 	
		}
		else if (temp_action == B_MEDIUM) {
			printf("Medium");
			player.skor = ((2700/((game_times.hour*3600)+(game_times.min*60)+(game_times.sec)))*100); 
		}
		else if (temp_action == B_MEDIUM) {
			printf("Hard");
			player.skor = ((3600/((game_times.hour*3600)+(game_times.min*60)+(game_times.sec)))*100); 
		}
		
		//Ganti Tampilan Ke Win
		cleardevice();
		readimagefile("Assets/bg_utama_score.bmp", 0, 0, 800, 600);
		Write_Score(temp_action);
		sprintf(string_score,"Name : %s",player.nama);
		outtextxy (281,283, string_score);
		sprintf(string_score,"Score : %d",player.skor);
		outtextxy (281,303, string_score);
		getch();
	}
	
}

//Menghitung Waktu
void waktu(int Delay){
	
	//var lokal
	char time[128];
	
	//kalkulasi
	game_times.msec = game_times.msec + Delay;
	if (game_times.msec>=1000) {
		game_times.sec=game_times.sec + 1;
		game_times.msec=0;	
	}
	if (game_times.sec>=60) {
		game_times.min = game_times.min + 1;
		game_times.sec = 0;	
	}
	if (game_times.min>=60) {
		game_times.hour = game_times.hour + 1;
		game_times.min = 0;
	}
	
	//tampilkan waktu pengerjaan
	sprintf(time,"Waktu : %d:%d:%d:%d",game_times.hour,game_times.min,game_times.sec,game_times.msec);
	outtextxy(590,115,time); 
}

void game_menu(int *action, boolean *ceksound, char *nama, int puzzle_size){
	
	//var lokal
	int temp_action = *action;
	strcpy(player.nama, nama);
	
	/* Inisialisasi Button */
	//Up
	up.x=650;		up.y=350;
	up.width=50;	up.height=50;
	up.image="Assets/up.bmp";
	up.hover_image="Assets/h_up.bmp";
	
	//Down
	down.x=650;		down.y=450;
	down.width=50;	down.height=50;
	down.image="Assets/down.bmp";
	down.hover_image="Assets/h_down.bmp";
	
	//Left 
	left.x=600;		left.y=400;
	left.width=50;	left.height=50;
	left.image="Assets/left.bmp";
	left.hover_image="Assets/h_left.bmp";
	
	//Right
	right.x=700;		right.y=400;
	right.width=50;		right.height=50;
	right.image="Assets/right.bmp";
	right.hover_image="Assets/h_right.bmp";
	
	//Sound
	sound.x=740;		sound.y=540;
	sound.width=50;		sound.height=50;
	sound.image="Assets/sound.bmp";
	sound.hover_image="Assets/h_sound.bmp";
	
	//Reset
	reset.x=250;		reset.y=550;
	reset.width=75;		reset.height=35;
	reset.image="Assets/reset.bmp";
	reset.hover_image="Assets/h_reset.bmp";
	
	//Solve
	solve.x=375;		solve.y=550;
	solve.width=75;		solve.height=35;
	solve.image="Assets/solve.bmp";
	solve.hover_image="Assets/h_solve.bmp";
	
	//Exit
	Exit.x=125;		Exit.y=550;
	Exit.width=75;		Exit.height=35;
	Exit.image="Assets/g_exit.bmp";
	Exit.hover_image="Assets/h_g_exit.bmp";	
	
	//Inisialisasi Puzzle
	InitPuzz ( puzzle_size );
	
	//Inisialisasi Gambar Puzzle
	SaveImgMemory ( "Assets\\Puzzle.bmp", "Assets\\Thumbs.bmp", 450/puzzle_size, puzzle_size); 
	
	//Random Puzzle
	random (puzzle_size);
	
	//Draw Interface Game
	readimagefile ( "Assets\\bg_game.bmp", 0, 0, 800, 600);	
	DrawPuzz ( 450/puzzle_size, puzzle_size);	
	DrawButtonGame ();
	soundcek ( ceksound );
	settextstyle(3, HORIZ_DIR, 1);
	outtextxy(590,75,nama);
	controller_game ( action, ceksound, puzzle_size);
	
	//Dealoc Pointer Image
	DeAlocGambar();
	
}

//Clear Memory untuk Gambar
void DeAlocGambar(){
	int i;
	for(i=0;i<25;i++) free(img[i]);
	free(thumbnail);
}

//Untuk Mengatur Movement puzzle
void Movement(int Control,int puzzle_size, int *movement){
	int temp_puzz;
	switch(Control){
		
		//KeyUp
		case KeyUp:{
			if((x_puzz-1)>=0){
				temp_puzz = puzz_rand[x_puzz-1][y_puzz];
				puzz_rand[x_puzz-1][y_puzz] = puzz_rand[x_puzz][y_puzz];
				puzz_rand[x_puzz][y_puzz] = temp_puzz;
				x_puzz-=1;
				*movement=*movement+1;
			}break;
		}
		
		//KeyDown
		case KeyDown:{
			if((x_puzz+1)<puzzle_size){
				temp_puzz = puzz_rand[x_puzz+1][y_puzz];
				puzz_rand[x_puzz+1][y_puzz] = puzz_rand[x_puzz][y_puzz];
				puzz_rand[x_puzz][y_puzz] = temp_puzz;
				x_puzz+=1;
				*movement=*movement+1;
			}break;
		}
		
		//KeyLeft
		case KeyLeft:{
			if((y_puzz-1)>=0){
				temp_puzz = puzz_rand[x_puzz][y_puzz-1];
				puzz_rand[x_puzz][y_puzz-1] = puzz_rand[x_puzz][y_puzz];
				puzz_rand[x_puzz][y_puzz] = temp_puzz;
				y_puzz-=1;
				*movement=*movement+1;
			}break;
		}
		
		//KeyRight
		case KeyRight:{
			if((y_puzz+1)<puzzle_size){
				temp_puzz = puzz_rand[x_puzz][y_puzz+1];
				puzz_rand[x_puzz][y_puzz+1] = puzz_rand[x_puzz][y_puzz];
				puzz_rand[x_puzz][y_puzz] = temp_puzz;
				y_puzz+=1;
				*movement=*movement+1;
			}
		}
	}
}
