#include "Yohan_171511033.h"

Button Back,Ali,Firna,Cahya,Yohan,Aldo;
	
void About_Menu(int *Action, boolean *Cek_Sound){
	//mengatur ukuran ,lokasi ,dan memasukan gambar tombol back
	Back.X = 10; 		Back.Y = 540;                           //memasukan lokasi gambar
	Back.Width = 150; 	Back.Height = 50;					    //mengatur tinggi dan lebar gambar
	Back.Image = "Assets/back.bmp";								//memasukan gambar tombol back 1
	Back.Hover_Image = "Assets/h_back.bmp";					    //memasukan gambar tombol back 2
	//mengatur ukuran ,lokasi ,dan memasukan gambar tombol sound
	Sound.X=740;		Sound.Y=540;                           //memasukan lokasi gambar
	Sound.Width=50;		Sound.Height=50;					   //mengatur tinggi dan lebar gambar
	Sound.Image="Assets/sound.bmp";							   //memasukan gambar tombol sound 1
	Sound.Hover_Image="Assets/h_sound.bmp";					   //memasukan gambar tombol sound 2
	//mengatur ukuran ,lokasi ,dan memasukan gambar anggota yohan
	Yohan.X=75;		Yohan.Y=150;							   //memasukan lokasi gambar
	Yohan.Image="Assets/171511033.jpg";						   //memasukan foto yohan 
	Yohan.Hover_Image="Assets/171511033.jpg";
	//mengatur ukuran ,lokasi ,dan memasukan gambar anggota ali
	Ali.X=325;		Ali.Y=150;								  //memasukan lokasi gambar
	Ali.Image="Assets/171511035.jpg";						  //memasukan foto ali 	
	Ali.Hover_Image="Assets/171511035.jpg";
	//mengatur ukuran ,lokasi ,dan memasukan gambar anggota firna
	Firna.X=575;		Firna.Y=150;						  //memasukan lokasi gambar
	Firna.Image="Assets/171511040.jpg";						  //memasukan foto firna
	Firna.Hover_Image="Assets/171511040.jpg";
	//mengatur ukuran ,lokasi ,dan memasukan gambar anggota cahya
	Cahya.X=200;		Cahya.Y=375;						  //memasukan lokasi gambar
	Cahya.Image="Assets/171511042.jpg";						   //memasukan foto cahya
	Cahya.Hover_Image="Assets/171511042.jpg";
	//mengatur ukuran ,lokasi ,dan memasukan gambar anggota aldo
	Aldo.X=450;		Aldo.Y=375;								  //memasukan lokasi gambar
	Aldo.Image="Assets/171511058.jpg";						  //memasukan foto aldo
	Aldo.Hover_Image="Assets/171511058.jpg";
	
	Yohan.Width = Yohan.Height = Ali.Width = Ali.Height = Firna.Width = Firna.Height = 
	Cahya.Width = Cahya.Height = Aldo.Width = Aldo.Height = 150 ;						//mengatur tinggi dan lebar gambar anggota kelompok
	
	readimagefile("Assets/bg_about.bmp",0,0,800,600);		  //memasukan gambar background dan mengatur lokasi dan ukuran gambar
	//untuk mengubah gambar saat diklik pada tombol 	
	Make_Button_Img(Yohan,NOT_HOVER);
	Make_Button_Img(Ali,NOT_HOVER);
	Make_Button_Img(Firna,NOT_HOVER);
	Make_Button_Img(Cahya,NOT_HOVER);
	Make_Button_Img(Aldo,NOT_HOVER);
	Make_Button_Img(Back,NOT_HOVER);
	
	Sound_Cek(Cek_Sound);										//untuk mengecek tombol sound
	Controller_About(Action, Cek_Sound);						//pindah ke modul Controller_About
}

void Controller_About(int *Action, boolean *Cek_Sound){
	
	//Var Lokal
	int Valid=0;
	int X=-1,Y=-1;
	
	//Looping Controller Mouse
	while(Valid==0){
		getmouseclick(WM_LBUTTONDOWN,X,Y);				   //agar suatu area dapat diklik 
		delay(100);										   //menunda waktu saat diklik
		if(X>=Back.X && X<=Back.X+Back.Width && Y>=Back.Y && Y<=Back.Y+Back.Height){
			Make_Button_Img(Back,HOVER);
			Valid = 1;									   //parameter agar keluar dari looping
			*Action = NO_ACT;							   
		}
		//aksi yang dilakukan ketika mengklik area Yohan
		else if(X>=Yohan.X && X<=Yohan.X+Yohan.Width && Y>=Yohan.Y && Y<=Yohan.Y+Yohan.Height){
			Make_Button_Img(Yohan,HOVER);
		}
		//aksi yang dilakukan ketika mengklik area Ali
		else if(X>=Ali.X && X<=Ali.X+Ali.Width && Y>=Ali.Y && Y<=Ali.Y+Ali.Height){
			Make_Button_Img(Ali,HOVER);
		}
		//aksi yang dilakukan ketika mengklik area Firna		
		else if(X>=Firna.X && X<=Firna.X+Firna.Width && Y>=Firna.Y && Y<=Firna.Y+Firna.Height){
			Make_Button_Img(Firna,HOVER);
		}
		//aksi yang dilakukan ketika mengklik area Cahya
		else if(X>=Cahya.X && X<=Cahya.X+Cahya.Width && Y>=Cahya.Y && Y<=Cahya.Y+Cahya.Height){
			Make_Button_Img(Cahya,HOVER);
		}
		//aksi yang dilakukan ketika mengklik area Aldo		
		else if(X>=Aldo.X && X<=Aldo.X+Aldo.Width && Y>=Aldo.Y && Y<=Aldo.Y+Aldo.Height){
			Make_Button_Img(Aldo,HOVER);
		}
		//aksi yang dilakukan ketika mengklik area Sound	
		else if(X>=Sound.X && X<=Sound.X+Sound.Width && Y>=Sound.Y && Y<=Sound.Y+Sound.Height){
				if(*Cek_Sound){
					PlaySound(TEXT(" "), NULL, SND_ASYNC);
					*Cek_Sound = false;
				}
				else {
					PlaySound(TEXT("Assets\\intro.wav"), NULL, SND_LOOP | SND_ASYNC);		//agar musik dapat dijalanka
					*Cek_Sound = true;
				}
				Sound_Cek(Cek_Sound);
			}
	}
	delay(500);							//menunda waktu saat diklik
	clearmouseclick(WM_LBUTTONDOWN);    //untuk memberi nilai default pada X dan Y
}
