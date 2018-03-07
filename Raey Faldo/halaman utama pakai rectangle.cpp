#include <stdio.h>
#include <graphics.h>

main()
{
	int x, y;
	
	initwindow(800, 600, "halaman utama play");
	
	//readimagefile("1520064079946.bmp",200,50,600,150);
	//readimagefile("gambarmute.bmp", 725, 525, 775, 575);
	
	rectangle(200,50,600,150);		// logo game
	
	rectangle(725,525,775,575);		// logo mute
	
	rectangle(275,250,525,325);		// input nama
	rectangle(285,285,515,315);

	rectangle(325,350,475,400);		// level
	
	rectangle(325,425,475,475);		// medium/tengah
	rectangle(335,435,465,465);
	line(325,425,335,435);
	line(475,475,465,465);
	line(475,425,465,435);
	line(325,475,335,465);
	
	rectangle(525,425,675,475);		// hard/kanan
	rectangle(535,435,665,465);
	line(525,425,535,435);
	line(675,425,665,435);
	line(675,475,665,465);
	line(525,475,535,465);
	
	rectangle(125,425,275,475);		// easy/kiri
	rectangle(135,435,265,465);
	line(125,475,135,465);
	line(125,425,135,435);
	line(275,475,265,465);
	line(275,425,265,435);
	
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(295,255, "Input your name");
	
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(358, 352, "Select");
	outtextxy(365, 372, "level");
	
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(358,437, "Medium");
	
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(570,437, "Hard");
	
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(175,437, "Easy");
	//warna
	do{
	//tengah
	setfillstyle(1, LIGHTRED); //tengah
	floodfill(336, 436, WHITE); 
	
	setfillstyle(1, RED); //kanan
	floodfill(466, 436, WHITE);
	
	setfillstyle(1, RED); // bawah
	floodfill(465, 466, WHITE);
	
	setfillstyle(1, LIGHTRED); // kiri
	floodfill(334, 465, WHITE);
	
	setfillstyle(1, LIGHTRED); // atas
	floodfill(335, 434, WHITE);
	
	//kanan
	setfillstyle(1, LIGHTRED); //tengah
	floodfill(536, 436, WHITE); 
	
	setfillstyle(1, RED); //kanan
	floodfill(666, 465, WHITE);
	
	setfillstyle(1, RED); // bawah
	floodfill(665, 466, WHITE);
	
	setfillstyle(1, LIGHTRED); // kiri
	floodfill(534, 435, WHITE);
	
	setfillstyle(1, LIGHTRED); // atas
	floodfill(535, 434, WHITE);
	
	// kiri
	setfillstyle(1, LIGHTRED); //tengah
	floodfill(136, 436, WHITE); 
	
	setfillstyle(1, RED); //kanan
	floodfill(266, 465, WHITE);
	
	setfillstyle(1, RED); // bawah
	floodfill(265, 466, WHITE);
	
	setfillstyle(1, LIGHTRED); // kiri
	floodfill(134, 435, WHITE);
	
	setfillstyle(1, LIGHTRED); // atas
	floodfill(135, 434, WHITE);
	
	
	
	
	//getch();
	
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(((x > 335 && x < 465) && (y > 435 && y < 465)))
		{
			//getch();
			// kotak tengah
//			settextstyle(8, HORIZ_DIR, 3);
//			outtextxy(358,437, "Medium");
			
			setfillstyle(1, RED); 		//tengah
			floodfill(336, 436, WHITE); 
	
			setfillstyle(1, LIGHTRED); 	//kanan
			floodfill(466, 436, WHITE);
	
			setfillstyle(1, LIGHTRED); 	// bawah
			floodfill(465, 466, WHITE);
	
			setfillstyle(1, RED); 		// kiri
			floodfill(334, 465, WHITE);
	
			setfillstyle(1, RED); 		// atas
			floodfill(335, 434, WHITE);
			
			
		}else if(((x > 535 && x < 665) && (y > 435 && y < 465)))
				{
					// kotak kanan
					setfillstyle(1, RED); 		//tengah
					floodfill(536, 436, WHITE); 
	
					setfillstyle(1, LIGHTRED); 	//kanan
					floodfill(666, 465, WHITE);
	
					setfillstyle(1, LIGHTRED); 	// bawah
					floodfill(665, 466, WHITE);
		
					setfillstyle(1, RED); 		// kiri
					floodfill(534, 435, WHITE);
	
					setfillstyle(1, RED); 		// atas
					floodfill(535, 434, WHITE);
				}else if(((x > 135 && x < 265) && (y > 435 && y < 465)))
						{
							// kotak kiri
							setfillstyle(1, RED); 		//tengah
							floodfill(136, 436, WHITE); 		
	
							setfillstyle(1, LIGHTRED); 	//kanan		
							floodfill(266, 465, WHITE);
	
							setfillstyle(1, LIGHTRED); 	// bawah
							floodfill(265, 466, WHITE);
		
							setfillstyle(1, RED); 		// kiri
							floodfill(134, 435, WHITE);
	
							setfillstyle(1, RED); 		// atas
							floodfill(135, 434, WHITE);
						}
	}delay(220);
	}while(3<4);
	
	//getch();

   

}
