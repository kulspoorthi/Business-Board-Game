#include<graphics.h>
#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
#include<iomanip>
#include<stdlib.h>
#include<ctime>
#include <cstdlib>
#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

using namespace std;
void gameboard(int no_players);
void playerdetails();
void playerPoints(char np[1], char *tokenColor[7]);
void readGameFile(char np[1]);
int dice(int fdie, int sdie);
int dieroll(void);
void tokenPosition(int i, int index, int no_players);
void clearTokens(int i, int index, int no_players);
void greeting(int pnum);
void displayPlayerDet(int i);
void updateSiteFile(int i, int index, char *site[20]);

#define MAX 36
class GameBoard
{
	public: 
		char player[8], tColor[9], amt[7], buffer[100], b_buffer[100];
};

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;
	
	if(!RegisterClassW(&wc))
		return -1;
	
	CreateWindowW (L"myWindowClass", L"GameBoard", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0,0, 1000,800,
					NULL, NULL, NULL,NULL);
	
	MSG msg = {0};
	while(GetMessage((&msg), NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}	
	return 0;
}
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int val;
	switch(msg)
	{
		case WM_COMMAND :          //WHen FIle menu option is clicked
		
			break;
		case WM_CREATE:
			playerdetails();
			
			getch();
			closegraph();
			break;
		case WM_DESTROY:          //cross button to close
			PostQuitMessage(0);    
			break;  
		default:
			return DefWindowProcW (hWnd, msg, wp, lp);
	}
}

//void AddControls(HWND hWnd)
//{	
//	CreateWindowW(L"Button", L"Player 1", WS_VISIBLE | WS_CHILD, 25, 25, 90, 25, hWnd, (HMENU)GENERATE_BUTTON, NULL, NULL );
//	
////	hOut = CreateWindowW (L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100,200, 300,200, hWnd, NULL, NULL, NULL);
////	hLogo = CreateWindowW (L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 60, 100,100, hWnd, NULL, NULL, NULL);
////	SendMessageW (hLogo, STM_SETIMAGE, IMAGE_BITMAP , (LPARAM) hLogoImage);
//}
void gameboard(int no_players)
{
	char np[1]; 
	sprintf(np,"%d",no_players);
	delay(150);	
	initwindow(1000,800,"Business");
	setbkcolor(WHITE);
	cleardevice();
	
	setcolor(BLACK);
	rectangle(100,100,700,700);
	rectangle(200,200,600,600);	
		
	readimagefile("businessimag2.jpg", 203,203,597,597);	
	
	setcolor(BLACK);	
	line(200,100,200,200);
	line(200,200,100,200);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	floodfill(150,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(120,120, "Water");
	outtextxy(120,135, "World");
	outtextxy(118,150, "Resort");
	
	line(600,100,600,200);
	line(600,200,700,200);
	setfillstyle(SLASH_FILL, LIGHTGRAY);
	floodfill(650,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(630,140, "JAIL");
	
	line(700,600,600,600);
	line(600,600,600,700);
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(650,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(620,630, "Sports");
	outtextxy(622,650, "Club");
	
	line(100,600,200,600);
	line(200,600,200,700);
	setfillstyle(SOLID_FILL, LIGHTRED);
	floodfill(150,650,BLACK);
	readimagefile("uparrow.jpg", 120,630,170,670);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(133,610, "GO");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(102,677, "Collect 1200");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);	
	outtextxy(105,687, "As you pass");
	
	for(int x=250;x<=600;x+=50)
	{
		int y1=100;
	    int y2=200;
	    line(x,y1,x,y2);		
	}
		for(int y=250;y<=600;y+=50)
	{
		int x1=100;
	    int x2=200;
	    line(x1,y,x2,y);		
	}
		for(int x=250;x<=600;x+=50)
	{
		int y1=600;
	    int y2=700;
	    line(x,y1,x,y2);		
	}
		for(int y=250;y<=600;y+=50)
	{
		int x1=600;
	    int x2=700;
	    line(x1,y,x2,y);		
	}
	
	//Entering Cities
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(225,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(215,170, "Delhi");

	setfillstyle(SOLID_FILL, GREEN);
	floodfill(275,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(265,202, "Chandigar");
	
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(310,195, "Electric");
	outtextxy(325,195, "CO.");

	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(375,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(365,180, "Chance");
	
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(425,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(415,180, "Shimla");
	
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(475,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(465,195, "Amritsar");
	
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(515,185, "B.E.S.T");	
	
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(575,150,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(565,195, "Srinagar");	
	
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(650,225,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(630,215, "Agra");		
	
	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(650,275,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(600,265, "Community");
	outtextxy(620,280, "Chest");		
	
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(650,325,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(620,315, "Kanpur");	
	
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(650,375,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(620,365, "Patna");
	
	setfillstyle(SOLID_FILL, RED);
	floodfill(650,425,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(598,415, "Darjeling");		
	
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(630,460, "Air");
	outtextxy(620,475, "India");

	setfillstyle(SOLID_FILL, RED);
	floodfill(650,525,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(610,515, "Kolkata");
	
	setfillstyle(SOLID_FILL, RED);
	floodfill(650,575,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(602,565, "Hyderbad");

	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(575,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(565,690, "Chennai");	

	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(525,650,BLACK);	
	setcolor(BLACK);	
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(515,690, "Chance");		

	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(475,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(465,699, "Banglore");
	
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(410,690, "Wealth");	
	outtextxy(425,680, "Tax");	
	
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(375,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(365,680, "Ooty");	
	
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(325,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(315,680, "Pune");

	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(255,680, "Motor");	
	outtextxy(273,680, "Boat");
	
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(225,650,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, VERT_DIR, 1);
	outtextxy(215,670, "Goa");

	setfillstyle(SOLID_FILL, RED);
	floodfill(150,575,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(115,570, "Mumbai");

	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(150,525,BLACK);	
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(102,510, "Community");
	outtextxy(115,525, "Chest");

	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(105,460, "Railway");

	setfillstyle(SOLID_FILL, RED);
	floodfill(150,425,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(103,420, "Ahmedabad");

	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(115,360, "Income");
	outtextxy(115,375, "Tax");

	setfillstyle(SOLID_FILL, BLUE);
	floodfill(150,325,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(115,320, "Indore");

	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(115,260, "Water");
	outtextxy(115,275, "Works");

	setfillstyle(SOLID_FILL, BLUE);
	floodfill(150,225,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(115,220, "Jaipur");
	
	setcolor(BLACK);
	rectangle(753,1,997,30);
	setfillstyle(SOLID_FILL, RED);
	floodfill(875,15,BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(800,7, "PLAYER DETAILS");

	setcolor(BLACK);
	rectangle(753,32,997,62);
 	setfillstyle(SOLID_FILL, WHITE);
	floodfill(876,47,BLACK);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
	outtextxy(756,36, "NUMBER OF PLAYERS: ");
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(970,36, np);	
//	int no_players = atoi(np);                    //Converting char to int

	int x1 = 753, y1 = 70, x2 = 997, y2 = 100;

	rectangle(x1,y1,x2,y2);
	setfillstyle(SOLID_FILL, RED);
	floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);	
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
	outtextxy(756,76, " PLAYERS ");
	outtextxy(876,76, " POINTS ");
	
	char *tokenColor[7];
	tokenColor[0] = "0";
	for(int i =1; i<=no_players; i++)
	{	
		setcolor(BLACK);	
		y1+=32; y2+=32;
		rectangle(x1,y1,x2,y2);
		settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
		if(i==1)
		{
			setfillstyle(SOLID_FILL, LIGHTRED);
			floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);
			outtextxy(759,y1+6, "Player1");
			tokenColor[i] = "Red";			
		}
		if(i==2)
		{			
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);
			outtextxy(759,y1+6, "Player2");
			tokenColor[i] = "Green";
		}
		if(i==3)
		{			
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);
			outtextxy(759,y1+6, "Player3");
			tokenColor[i] = "Blue";
		}		
		if(i==4)
		{			
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);
			outtextxy(759,y1+6, "Player4");
			tokenColor[i] = "Yellow";
		}
		if(i==5)
		{			
			setfillstyle(SOLID_FILL, MAGENTA);
			floodfill(abs((x1+x2)/2),abs((y1+y2)/2),BLACK);
			outtextxy(759,y1+6, "Player5");
			tokenColor[i] = "Magenta";
		}				
	}
	rectangle(x1,y1+36,x2,y2+40);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(759,y2+13, "Tokens: ");
		
	int cx = 828, cy= y2+23;	              //To display tokens
	for(int i=0;i<no_players; i++)
	{
		cx = cx+30;
		if(i==0){
			setcolor(BLACK);
			circle(cx,cy,10);
			setfillstyle(SOLID_FILL, LIGHTRED);
			floodfill(cx,cy,BLACK);
		}
		if(i==1){
			setcolor(BLACK);
			circle(cx,cy,10);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(cx,cy,BLACK);		
		}
		if(i==2){
			setcolor(BLACK);
			circle(cx,cy,10);
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			floodfill(cx,cy,BLACK);
		}	
		if(i==3){
			setcolor(BLACK);
			circle(cx,cy,10);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(cx,cy,BLACK);
		}	
		if(i==4){
			setcolor(BLACK);
			circle(cx,cy,10);
			setfillstyle(SOLID_FILL, MAGENTA);
			floodfill(cx,cy,BLACK);
		}
	}		
//		setcolor(BLACK);
//		rectangle(770,725,970,775);
//		setfillstyle(SOLID_FILL, GREEN);
//		floodfill(875,773,BLACK);
//		settextstyle(BOLD_FONT, HORIZ_DIR, 2);	
//		outtextxy(790,740, "ROLL THE DICE");			
		
		playerPoints(np, tokenColor);
		
		setcolor(BLACK);
		rectangle(753,310,997,340);
		setfillstyle(SOLID_FILL, RED);
		floodfill(875,320, BLACK);
		setcolor(BLACK);		
		outtextxy(805,316, "SITE DETAILS");	
		
		//Black Background
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(50,50,BLACK);						
		readGameFile(np);
}

int dieroll(void) {
	int ran;
	srand(time(NULL));
	ran = rand()%6+1;
	return ran;
}
int dice(int fdie, int sdie) { 	
    return sdie + fdie;
}
void tokenPosition(int i, int index, int no_players)
{
	switch(index)
		{
			case 1:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,588,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,588,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,560,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,560,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,588,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,588,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,560,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,560,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,575,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,575,MAGENTA);
					break;
				}
				break;
			case 2: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,538,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,538,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,510,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,510,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,538,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,538,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,510,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,510,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,525,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,525,MAGENTA);
					break;
				}break;
			case 3:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,488,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,488,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,460,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,460,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,488,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,488,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,460,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,460,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,475,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,475,MAGENTA);
					break;
				}
				break;
			case 4: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,438,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,438,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,410,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,410,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,438,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,438,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,410,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,410,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,425,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,425,MAGENTA);
					break;
				}
				break;
			case 5:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,388,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,388,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,360,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,360,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,388,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,388,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,360,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,360,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,375,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,375,MAGENTA);
					break;
				}
				break;
			case 6: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,338,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,338,LIGHTRED);
					break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,310,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,310,GREEN);
					break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,338,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,338,LIGHTBLUE);
					break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,310,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,310,YELLOW);
					break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,325,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,325,MAGENTA);
					break;
				}
				break;
			case 7:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,288,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,288,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,260,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,260,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,288,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,288,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,260,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,260,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,275,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,275,MAGENTA); break;
				}
				break;
			case 8: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,238,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,238,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,210,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,210,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,238,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,238,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,210,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,210,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,225,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,225,MAGENTA); break;
				}
				break;
			case 9:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(90,188,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(90,188,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(90,160,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(90,160,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(60,188,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(60,188,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(60,160,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(60,160,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(75,175,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(75,175,MAGENTA); break;
				}
				break;
			case 10:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(240,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(240,88,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(240,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(240,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(210,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(210,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(210,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(210,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(225,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(225,75,MAGENTA); break;
				}
				break;
			case 11:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(290,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(290,88,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(290,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(290,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(260,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(260,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(260,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(260,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(275,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(275,75,MAGENTA); break;
				}
				break;
			case 12:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(340,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(340,88,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(340,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(340,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(310,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(310,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(310,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(310,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(325,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(325,75,MAGENTA); break;
				}
				break;
			case 13:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(390,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(390,88,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(390,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(390,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(360,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(360,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(360,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(360,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(375,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(375,75,MAGENTA); break;
				}
				break;
			case 14:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(440,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(440,88,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(440,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(440,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(410,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(410,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(410,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(410,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(425,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(425,75,MAGENTA); break;
				}
				break;
			case 15:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(490,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(490,88,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(490,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(490,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(460,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(460,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(460,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(460,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(475,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(475,75,MAGENTA); break;
				}
				break;
			case 16:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(540,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(540,88,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(540,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(540,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(510,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(510,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(510,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(510,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(525,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(525,75,MAGENTA); break;
				}
				break;
			case 17:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(590,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(590,88,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(590,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(590,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(560,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(560,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(560,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(560,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(575,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(575,75,MAGENTA); break;
				}
				break;
			case 18:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(680,88,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(680,88,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(680,60,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(680,60,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(640,88,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(640,88,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(640,60,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(640,60,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(650,75,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(650,75,MAGENTA); break;
				}
				break;
			case 19:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,238,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,238,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,210,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,210,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,238,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,238,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,210,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,210,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,175,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,175,MAGENTA); break;
				}
				break;
			case 20: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,288,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,288,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,260,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,260,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,288,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,288,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,260,	9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,260,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,275,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,275,MAGENTA); break;
				}
				break;
			case 21:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,338,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,338,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,310,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,310,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,338,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,338,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,310,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,310,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,325,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,325,MAGENTA); break;
				}
				break;
			case 22: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,388,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,388,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,360,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,360,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,388,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,388,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,360,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,360,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,375,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,375,MAGENTA); break;
				}
				break;
			case 23: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,438,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,438,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,410,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,410,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,438,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,438,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,410,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,410,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,425,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,425,MAGENTA); break;
				}
				break;
			case 24: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,488,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,488,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,460,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,460,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,488,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,488,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,460,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,460,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,475,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,475,MAGENTA); break;
				}
				break;
			case 25: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,538,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,538,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,510,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,510,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,538,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,538,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,510,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,510,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,525,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,525,MAGENTA); break;
				}
				break;
			case 26: 
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,588,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,588,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,560,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,560,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(740,588,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,588,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,560,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,560,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(725,575,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,575,MAGENTA); break;
				}
				break;
			case 27:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(710,668,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(710,668,LIGHTRED);	
					break;	
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(710,640,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(710,640,GREEN);
					break;
				}
				if(i==3)
				{
					setcolor(LIGHTBLUE);
					circle(740,668,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(740,668,LIGHTBLUE);
					break;	
				}
				if(i==4)
				{
					setcolor(YELLOW);
					circle(740,640,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(740,640,YELLOW);
					break;
				}
				if(i==5)
				{
					setcolor(MAGENTA);
					circle(725,653,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(725,653,MAGENTA);
					break;
				}
				break;
			case 28:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(590,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(590,710,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(590,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(590,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(560,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(560,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(560,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(560,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(575,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(575,725,MAGENTA); break;
				}
				break;
			case 29:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(540,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(540,710,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(540,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(540,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(510,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(510,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(510,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(510,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(525,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(525,725,MAGENTA); break;
				}
				break;
			case 30:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(490,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(490,710,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(490,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(490,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(460,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(460,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(460,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(460,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(475,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(475,725,MAGENTA); break;
				}
				break;
			case 31:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(440,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(440,710,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(440,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(440,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(410,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(410,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(410,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(410,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(425,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(425,725,MAGENTA); break;
				}
				break;
			case 32:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(390,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(390,710,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(390,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(390,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(360,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(360,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(360,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(360,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(375,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(375,725,MAGENTA); break;
				}
				break;
			case 33:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(340,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(340,710,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(340,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(340,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(310,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(310,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(310,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(310,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(325,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(325,725,MAGENTA); break;
				}
				break;
			case 34:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(290,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(290,710,LIGHTRED); break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(290,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(290,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(260,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(260,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(260,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(260,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(275,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(275,725,MAGENTA); break;
				}
				break;
			case 35:
				if(i==1)
				{
					setcolor(LIGHTRED);
					circle(240,710,9);
					setfillstyle(SOLID_FILL, LIGHTRED);
					floodfill(240,710,LIGHTRED);break;
				}
				if(i==2)
				{
					setcolor(GREEN);
					circle(240,740,9);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(240,740,GREEN); break;
				}
				if(i==3){
					setcolor(LIGHTBLUE);
					circle(210,710,9);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(210,710,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(210,740,9);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(210,740,YELLOW); break;
				}
				if(i==5){
					setcolor(MAGENTA);
					circle(225,725,9);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(225,725,MAGENTA); break;
				}
				break;
			
		}
	}
void clearTokens(int i, int index, int no_players)
{
	switch(index)
		{
			case 1:
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,588,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,588,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,560,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,560,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,588,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,588,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,560,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,560,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,575,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,575,BLACK);
					break;
				}
				break;
			case 2: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,538,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,538,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,510,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,510,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,538,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,538,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,510,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,510,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,525,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,525,BLACK);
					break;
				}
				break;
			case 3:
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,488,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,488,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,460,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,460,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,488,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,488,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,460,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,460,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,475,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,475,BLACK);
					break;
				}
				break;
			case 4: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,438,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,438,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,410,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,410,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,438,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,438,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,410,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,410,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,425,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,425,BLACK);
					break;
				}
				break;
			case 5:
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,388,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,388,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,360,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,360,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,388,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,388,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,360,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,360,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,375,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,375,BLACK);
					break;
				}
				break;
			case 6: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,338,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,338,BLACK);
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,310,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,310,BLACK);
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,338,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,338,BLACK);
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,310,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,310,BLACK);
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,325,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,325,BLACK);
					break;
				}
				break;
			case 7:
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,288,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,288,BLACK); 
					break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,260,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,260,BLACK); 
					break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,288,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,288,BLACK); 
					break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,260,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,260,BLACK); 
					break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,275,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,275,BLACK); 
					break;
				}
				break;
			case 8: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,238,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,238,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,210,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,210,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,238,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,238,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,210,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,210,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,225,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,225,BLACK); break;
				}
				break;
			case 9:
				if(i==1)
				{
					setcolor(BLACK);
					circle(90,188,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,188,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(90,160,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(90,160,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(60,188,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,188,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(60,160,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(60,160,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(75,175,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(75,175,BLACK); break;
				}
				break;
			case 10:
				if(i==1)
				{
					setcolor(BLACK);
					circle(240,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(240,88,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(240,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(240,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(210,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(210,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(210,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(210,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(225,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(225,75,BLACK); break;
				} break;
			case 11:
				if(i==1)
				{
					setcolor(BLACK);
					circle(290,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(290,88,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(290,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(290,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(260,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(260,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(260,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(260,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(275,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(275,75,BLACK); break;
				}
			    break;
			case 12:
				if(i==1)
				{
					setcolor(BLACK);
					circle(340,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(340,88,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(340,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(340,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(310,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(310,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(310,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(310,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(325,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(325,75,BLACK); break;
				}
				break;
			case 13:
				if(i==1)
				{
					setcolor(BLACK);
					circle(390,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(390,88,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(390,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(390,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(360,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(360,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(360,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(360,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(375,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(375,75,BLACK); break;
				}
				break;
			case 14:
				if(i==1)
				{
					setcolor(BLACK);
					circle(440,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(440,88,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(440,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(440,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(410,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(410,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(410,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(410,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(425,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(425,75,BLACK); break;
				}
				break;
			case 15:
				if(i==1)
				{
					setcolor(BLACK);
					circle(490,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(490,88,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(490,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(490,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(460,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(460,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(460,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(460,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(475,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(475,75,BLACK); break;
				}
				break;
			case 16:
				if(i==1)
				{
					setcolor(BLACK);
					circle(540,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(540,88,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(540,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(540,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(510,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(510,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(510,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(510,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(525,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(525,75,BLACK); break;
				}
				break;
			case 17:
				if(i==1)
				{
					setcolor(BLACK);
					circle(590,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(590,88,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(590,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(590,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(560,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(560,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(560,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(560,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(575,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(575,75,BLACK); break;
				}
				break;
			case 18:
				if(i==1)
				{
					setcolor(BLACK);
					circle(680,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(680,88,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(680,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(680,60,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(640,88,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(640,88,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(640,60,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(640,60,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(650,75,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(650,75,BLACK); break;
				}
				break;
			case 19:
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,238,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,238,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,210,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,210,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,238,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,238,BLACK); break;
				}
				if(i==4){
					setcolor(YELLOW);
					circle(740,210,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,210,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,175,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,175,BLACK); break;
				}
				break;
			case 20: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,288,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,288,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,260,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,260,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,288,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,288,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,260,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,260,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,275,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,275,BLACK); break;
				}
				break;
			case 21:
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,338,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,338,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,310,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,310,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,338,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,338,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,310,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,310,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,325,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,325,BLACK); break;
				}
				break;
			case 22: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,388,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,388,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,360,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,360,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,388,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,388,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,360,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,360,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,375,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,375,BLACK); break;
				}
				break;
			case 23: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,438,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,438,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,410,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,410,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,438,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,438,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,410,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,410,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,425,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,425,BLACK); break;
				}
				break;
			case 24: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,488,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,488,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,460,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,460,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,488,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,488,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,460,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,460,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,475,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,475,BLACK); break;
				}
				break;
			case 25: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,538,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,538,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,510,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,510,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,538,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,538,LIGHTBLUE); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,510,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,510,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,525,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,525,BLACK); break;
				}
				break;
			case 26: 
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,588,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,588,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,560,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,560,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(740,588,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,588,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(740,560,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,560,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(725,575,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,575,BLACK); break;
				}
				break;
			case 27:
				if(i==1)
				{
					setcolor(BLACK);
					circle(710,668,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,668,BLACK);	
					break;	
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(710,640,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(710,640,BLACK);
					break;
				}
				if(i==3)
				{
					setcolor(BLACK);
					circle(740,668,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,668,BLACK);
					break;	
				}
				if(i==4)
				{
					setcolor(BLACK);
					circle(740,640,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(740,640,BLACK);
					break;
				}
				if(i==5)
				{
					setcolor(BLACK);
					circle(725,653,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(725,653,BLACK);
					break;
				}
				break;
			case 28:
				if(i==1)
				{
					setcolor(BLACK);
					circle(590,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(590,710,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(590,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(590,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(560,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(560,740,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(560,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(560,710,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(575,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(575,725,BLACK); break;
				}
				break;
			case 29:
				if(i==1)
				{
					setcolor(BLACK);
					circle(540,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(540,710,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(540,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(540,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(510,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(510,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(510,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(510,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(525,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(525,725,BLACK); break;
				}
				break;
			case 30:
				if(i==1)
				{
					setcolor(BLACK);
					circle(490,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(490,710,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(490,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(490,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(460,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(460,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(460,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(460,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(475,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(475,725,BLACK); break;
				}
				break;
			case 31:
				if(i==1)
				{
					setcolor(BLACK);
					circle(440,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(440,710,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(440,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(440,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(410,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(410,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(410,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(410,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(425,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(425,725,BLACK); break;
				}
				break;
			case 32:
				if(i==1)
				{
					setcolor(BLACK);
					circle(390,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(390,710,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(390,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(390,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(360,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(360,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(360,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(360,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(375,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(375,725,BLACK); break;
				}
				break;
			case 33:
				if(i==1)
				{
					setcolor(BLACK);
					circle(340,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(340,710,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(340,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(340,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(310,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(310,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(310,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(310,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(325,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(325,725,BLACK); break;
				}
				break;
			case 34:
				if(i==1)
				{
					setcolor(BLACK);
					circle(290,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(290,710,BLACK); break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(290,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(290,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(260,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(260,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(260,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(260,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(275,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(275,725,BLACK); break;
				}
				break;
			case 35:
				if(i==1)
				{
					setcolor(BLACK);
					circle(240,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(240,710,BLACK);break;
				}
				if(i==2)
				{
					setcolor(BLACK);
					circle(240,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(240,740,BLACK); break;
				}
				if(i==3){
					setcolor(BLACK);
					circle(210,710,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(210,710,BLACK); break;
				}
				if(i==4){
					setcolor(BLACK);
					circle(210,740,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(210,740,BLACK); break;
				}
				if(i==5){
					setcolor(BLACK);
					circle(225,725,9);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(225,725,BLACK); break;
				}
				break;			
		}
	}
void greeting(int pnum) {
	if(pnum == 1) {
		std::cout << "Please press \"ENTER\" to roll the die.";
		
	} else {
		std::cout << "Please press \"ENTER\" again to roll the second die."<<endl;
	}
	std::cin.ignore();
}



void readGameFile(char np[])
{	
	int a[MAX], key[36];                        // Creating index for hash table		
	for(int i=0;i<36;i++)
	{
		a[i] = -1;
		key[i] = i%36;                 //Generating keys
	}
	
	char *site[36] = {"Start", "Mumbai", "Community Chest", "Railway", "Ahmedabad",
	"Income Tax", "Indore", "Water Works", "Jaipur", "Water World Resort", "Delhi",
	"Chandigarh","ElectricCo.", "Chance", "Simla", "Amritsar", "BEST", "Srinagar",
	"Jail", "Agra", "Community Chest","Kanpur", "Patna", "Darjeeling", "Air India",
	"Kolkata", "Hyderabad", "Sports Club", "Chennai", "Chance", "Bangalore",
	"Wealth Tax","Ooty", "Pune", "MotorBoat", "Goa"};
	
	int siteRate[36] = {0,8500,0,9500,4000,0,1500,3200,3000,0,6000,2500,2500,0,2200,
	3300,3500,5000,0,2500,0,4000,2000,2500,10500,6500,3500,0,7000,0,4000,0,2500,3000,
	5500,4000};
	
	int siteRent[36] = {0,1200,0,1000,400,0,200,500,250,0,750,200,3500,0,200,500,
	600,550,0,200,0,400,150,200,1200,800,300,0,900,0,400,0,200,300,3500,400};
	
	int rentH1[36] = {0,4000,0,0,1500,0,900,0,1500,0,3000,900,0,0,1000,1500,0,
	3500,0,900,0,1500,800,1200,0,3200,1200,0,3500,0,1500,0,1000,1200,0,2200};
	
	int rentH2[36] = {0,5500,0,0,3000,0,1600,0,2750,0,4300,1600,0,0,2750,3500,
	0,5000,0,1600,0,3000,2000,2000,0,4500,3000,0,5000,0,3500,0,2250,2000,0,3500};
	
	int rentH3[36] = {0,7000,0,0,4200,0,2500,0,4000,0,5500,2500,0,0,4500,5000,0,
	7000,0,2500,0,4500,3000,3500,0,6500,4500,0,7000,0,4500,0,3500,4500,0,5000};
	
	int rentHotel[36] = {0,9000,0,0,5000,0,3500,0,5500,0,7500,3500,0,0,6000,7000,
	0,8000,0,3500,0,5500,4500,5000,0,8000,6000,0,8500,0,5500,0,4500,5500,0,6500};
	
	int houseRate[36] = {0,7500,0,0,4500,0,4000,0,4000,0,5000,3000,0,0,3500,6000,
	0,6000,0,3000,0,4500,2500,3000,0,6000,5000,0,6500,0,4500,0,3000,4000,0,4500};
	
	int hotelRate[36] = {0,7500,0,0,4500,0,4000,0,4000,0,5000,3000,0,0,3500,6000,
	0,6000,0,3000,0,4500,2500,3000,0,6000,5000,0,6500,0,4500,0,3000,4000,0,4500};
	
	int mrtgVal[36] = {0,4250,0,4750,2000,0,1250,1600,1500,0,3000,1250,1250,0,
	1100,3000,1750,2500,0,1250,0,2000,1000,1250,5250,3250,1750,0,3500,0,2000,0,1250,
	1500,2750,2000};
	
	ofstream file1;
	file1.open("GameBoardDetails.txt", ios::app | ios::out);
	for(int i=0;i<36;i++)
		{
			file1<<key[i]<<"-"<<site[i] <<"-"<<siteRate[i]<<"-"<<siteRent[i]<<"-"<<
			rentH1[i]<<"-"<<rentH2[i] <<"-"<<rentH3[i]<<"-"<<rentHotel[i]<<"-"<<
			houseRate[i]<<"-"<<hotelRate[i]<<"-"<<mrtgVal[i]<<endl;
		}	
		file1.close();	
		
		fstream file2;
		int no_players = atoi(np);
		
		int i,j,pos[no_players+1], index, playerturn, placeacquire[36], owner[36], newRent[36], pay;
		int sitecount[no_players+1], housecount[36], hotelcount[36], currentBal[no_players], BankBal;
		int No_Sites[no_players], No_ofHouses[no_players], No_ofHotels[no_players];
		char answer;
		int dief, die1, die2, balance[no_players+1], b_credit, b_debit, p_credit[no_players], p_debit[no_players];
		char *playerNum;
		
		char player[8], tColor[9],  amt[7]; 
		GameBoard tokenNum[no_players+1], tokenColor[no_players+1], amount[no_players+1];
		GameBoard b;
		
		char C_BankBal[8], C_currentBal[36], CB_credit[8], CB_debit[8], CP_credit[no_players], CP_debit[no_players], C_owner[36];
		
		int prevIndex[no_players];                            // to clear the tokens
		int p_housecount[no_players+1], p_hotelcount[no_players+1];
		 char C_No_Sites[no_players+1], C_No_ofHouses[no_players+1], C_No_ofHotels[no_players+1];
		 
		for(i=1;i<=no_players;i++)
		{
			if(i==1)
			{
				setcolor(LIGHTRED);
				circle(90,668,9);
				setfillstyle(SOLID_FILL, LIGHTRED);
				floodfill(90,668,LIGHTRED);
			}
			if(i==2)
			{
				setcolor(GREEN);
				circle(90,640,9);
				setfillstyle(SOLID_FILL, GREEN);
				floodfill(90,640,GREEN);
			}
			if(i==3)
			{
				setcolor(LIGHTBLUE);
				circle(60,668,9);
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				floodfill(60,668,LIGHTBLUE);
			}
			if(i==4)
			{
				setcolor(YELLOW);
				circle(60,640,9);
				setfillstyle(SOLID_FILL, YELLOW);
				floodfill(60,640,YELLOW);
			}
			if(i==5)
			{
				setcolor(MAGENTA);
				circle(75,653,9);
				setfillstyle(SOLID_FILL, MAGENTA);
				floodfill(75,653,MAGENTA);
			}
		}
				
		file2.open("playerDetails.txt");
		file2<<"Player_id|TokenColor|Position|CurrentBalance|No_Sites|No_ofHouses|No_ofHotels"<<endl;
		file2.close();
		
		fstream file3;
		file3.open("playerPoints.txt",ios::in);
	    
		i=0;
		while(!file3.eof())
		{
			file3.getline(tokenNum[i].player, 8, '|');
			file3.getline(tokenColor[i].tColor, 9, '|');
			file3.getline(amount[i].amt, 7, '\n');	
			balance[i] = atoi(amount[i].amt);
			i++;		
		}
		file3.close();
		
		
		BankBal = balance[0];
		
		for(i=1;i<=no_players;i++)
		{
			currentBal[i] = balance[0];
			pos[i] = 0;	
			prevIndex[i] = 0;	
			sitecount[i] = 0;
			p_housecount[i] = 0;  p_hotelcount[i]=0;	
		}		
		
		for(i=0;i<36;i++)
		{
			placeacquire[i]=0; owner[i]=0;
			newRent[i]=0;			
			housecount[i] = 0;	hotelcount[i] = 0;
		}
	
		char diceValue[1], turnMention[1];	
		setcolor(WHITE);
		rectangle(753,345,997,665);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(876,505,WHITE);		 		
		
		for(;;)
		{
		for(i=1;i<=no_players;i++)
		{	
			cout << "\n+------------------------------------------------------------------+"<<endl;
			cout<<"\nPLAYER "<<i<<" Turn. Roll your die!"<<endl;			
			setcolor(CYAN);					
			rectangle(760,700,980,770);
			setfillstyle(SOLID_FILL, CYAN);
			floodfill(870,735,CYAN);
			
			setcolor(BLACK);
			sprintf(turnMention, "%d", i);
			settextstyle(BOLD_FONT, HORIZ_DIR, 1);
			outtextxy(790,710, "Turn:");
			char str[40] = "Player ";
			sprintf(turnMention, "%d", i);
			strcat(str,turnMention);
			outtextxy(870,710, str);
			outtextxy(945,710, turnMention);			
			
			greeting(1);
			die1 = dieroll();
			greeting(2);	
			die2 = dieroll();	
				
			dief = dice(die1, die2);						
			cout<<"Dice Value: "<<dief<<endl;
			outtextxy(810,745,"              ");
			sprintf(diceValue, "%d", dief);
			settextstyle(BOLD_FONT, HORIZ_DIR, 1);			 
			outtextxy(810,745,"Dice Value: ");		
			outtextxy(940,745, diceValue);			
			
			if(prevIndex[i] != 0)
				clearTokens(i, prevIndex[i], no_players);      //Clearing previous token positions
				
			for(j=1;j<=dief;j++)
			{
				pos[i] = pos[i] + 1;
				if(pos[i] > 35)
					{
						pos[i] = 1;							
						continue;
					}
			}
			index=pos[i];
			prevIndex[i] = index;	
			char C_index[10];
			sprintf(C_index, "%d", index);
				
			tokenPosition(i, index, no_players);
			
			char C_siteRate[36], C_siteRent[36], C_rentH1[36], C_rentH2[36], 
			C_rentH3[36], C_rentHotel[36], C_houseRate[36], C_hotelRate[36], 
			C_mrtgVal[36], C_houseCount[36];
		
			sprintf(C_siteRate, "%d",siteRate[index]);
		    sprintf(C_siteRent, "%d",siteRent[index]);
		 	sprintf(C_rentH1, "%d",rentH1[index]);
			sprintf(C_rentH2, "%d", rentH2[index]);
			sprintf(C_rentH3, "%d", rentH3[index]);
			sprintf(C_rentHotel, "%d", rentHotel[index]);
			sprintf(C_houseRate, "%d",houseRate[index]);
			sprintf(C_hotelRate, "%d",hotelRate[index]);
			sprintf(C_mrtgVal, "%d", mrtgVal[index]);			
	
			switch(index)
			{
				case 1:
				case 4:
				case 6:
				case 8:
				case 10:
				case 11:
				case 14:
				case 15:
				case 17:
				case 19:
				case 21:
				case 22:
				case 23:
				case 25:
				case 26:
				case 28:
				case 30:
				case 32:
				case 33:
				case 35:cout<<"\nYou have reached \""<<site[index]<<"\" Position: "<<endl;						 
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
											
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);
							outtextxy(765,446, "1 House Rent:");
							outtextxy(920,446, C_rentH1);
							outtextxy(765,478, "2 House Rent:");
							outtextxy(920,478, C_rentH2);
							outtextxy(765,510, "3 House Rent:");
							outtextxy(920,510, C_rentH3);							
							outtextxy(765,542, "Hotel Rent:");
							outtextxy(920,542, C_rentHotel);							
							setcolor(BLUE);
							outtextxy(765,574, "House Cost:");
							outtextxy(920,574, C_houseRate);
							outtextxy(765,602, "Hotel Cost:");
							outtextxy(920,602, C_hotelRate);	
							setcolor(DARKGRAY);
							outtextxy(765,634, "Mortgage Value:");
							outtextxy(940,634,C_mrtgVal);													
							
//							cout<<"Do you want to buy a site? Y/N"<<endl;
//							cin>>answer;
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{								
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");															
								
								sitecount[i] = sitecount[i] +1;
								sprintf(C_No_Sites, "%d", sitecount[i]);
								
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"\nPlayer "<<i<<" bought site at "<<site[index]<<endl;
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
				   				sprintf(C_owner, "%d", owner[index]);
								newRent[index] = siteRent[index];		
								
								updateSiteFile(i, index, site);
								
								
							}
							else if( val == IDNO)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");		
								cout<<"Rent to be paid is Rs. "<<siteRent[index]<<endl<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRent[index]; p_credit[i] = 0;
								b_credit = siteRent[index]; b_debit = 0;
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
									
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;		
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
						else if(placeacquire[index]==i)               //Player[i] has acquired the place
						{							
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");					
							if(housecount[index]<3)
							{
								int count;
							
							char str1[40] = "Do you want to buy a house at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
									if(housecount[index]==0)
									{
										cout<<"How many house do you want to buy?: "<<endl;										
										cin>>count;
										char C_count[20];
										housecount[index] = count;
										
										sprintf(C_houseCount, "%d", housecount[index]);									
										cout<<count;
										p_housecount[i] = p_housecount[i] + count;
										sprintf(C_No_ofHouses, "%d", p_housecount[i]);
										
										switch(housecount[index])
					 					{
										case 1: currentBal[i]=currentBal[i]-houseRate[index];
										BankBal=BankBal + houseRate[index];
										newRent[index] = rentH1[index];										
										cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
										outtextxy(765,446, "Player");
										outtextxy(845,446, turnMention);
										outtextxy(860,446, "has");
										outtextxy(900,446, C_houseCount) ;
										outtextxy(765,478, "houses at");
										outtextxy(765,510, site[index]);	
										p_debit[i] = houseRate[index]; p_credit[i] = 0;
										b_credit = houseRate[index]; b_debit = 0;																														
										break;
										
										case 2: currentBal[i]=currentBal[i]-(2 * houseRate[index]);
										BankBal=BankBal + (2 * houseRate[index]);
										newRent[index] = rentH2[index];
										cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
										outtextxy(765,446, "Player");
										outtextxy(845,446, turnMention);
										outtextxy(860,446, "has");
										outtextxy(900,446, C_houseCount) ;
										outtextxy(765,478, "houses at");
										outtextxy(765,510, site[index]);
										delay(200);
										p_debit[i] = 2 * houseRate[index]; p_credit[i] = 0;
										b_credit = 2 * houseRate[index]; b_debit = 0;
										
										break;
										
										case 3: currentBal[i]=currentBal[i]-(3 * houseRate[index]);
										BankBal=BankBal + (3 * houseRate[index]);
										newRent[index] = rentH3[index];
										cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
										outtextxy(765,446, "Player");
										outtextxy(845,446, turnMention);
										outtextxy(860,446, "has");
										outtextxy(900,446, C_houseCount) ;
										outtextxy(765,478, "houses at");
										outtextxy(765,510, site[index]);
										delay(200);
										p_debit[i] = 3 * houseRate[index]; p_credit[i] = 0;
										b_credit = 3 * houseRate[index]; b_debit = 0;
																		
										break;
										}									
									}
									else if(housecount[index]==1)
									{
										outtextxy(765,350, "                     ");	
										outtextxy(765,382, "                     ");
										outtextxy(765,414, "                     ");
										outtextxy(765,446, "                     ");
										outtextxy(765,478, "                     ");
										outtextxy(765,510, "                     ");						
										outtextxy(765,542, "                     ");
										outtextxy(765,574, "                     ");
										outtextxy(765,602, "                     ");
										outtextxy(765,634, "                     ");				
										do{
											cout<<"You can buy 2 more Houses. How many house do you want to buy?: "<<endl;
											cin>>count;
											if(count>2){
												cout<<"You can buy 2 more Houses ONLY"<<endl;
												continue;
											}
											else{
												housecount[index] = housecount[index] + count;
												break;
											}														
										}while(housecount[index]<=3);
										p_housecount[i] = p_housecount[i] + count;
										sprintf(C_No_ofHouses, "%d", p_housecount[i]);
													
									switch(housecount[index])
									{
										case 2: currentBal[i]=currentBal[i]- houseRate[index];
												BankBal=BankBal + houseRate[index];
												newRent[index] = rentH2[index];
												cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
												outtextxy(765,446, "Player");
												outtextxy(845,446, turnMention);
												outtextxy(860,446, " has ");
												outtextxy(900,446, C_houseCount) ;
												outtextxy(765,478, "houses at");
												outtextxy(765,510, site[index]);
												p_debit[i] = houseRate[index]; p_credit[i] = 0;
												b_credit = houseRate[index]; b_debit = 0;
											
										break;
										case 3: currentBal[i]=currentBal[i]-(2 * houseRate[index]);
												BankBal=BankBal + (2 * houseRate[index]);
												newRent[index] = rentH3[index];
												cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
												outtextxy(765,446, "Player");
												outtextxy(845,446, turnMention);
												outtextxy(860,446, "has");
												outtextxy(900,446, C_houseCount) ;
												outtextxy(765,478, "houses at");
												outtextxy(765,510, site[index]);
												p_debit[i] = 2 * houseRate[index]; p_credit[i] = 0;
												b_credit = 2 * houseRate[index]; b_debit = 0;
												
										break;
										}														
									}
									else       //if housecount is already 2
									{
										outtextxy(765,350, "                     ");	
										outtextxy(765,382, "                     ");
										outtextxy(765,414, "                     ");
										outtextxy(765,446, "                     ");
										outtextxy(765,478, "                     ");
										outtextxy(765,510, "                     ");						
										outtextxy(765,542, "                     ");
										outtextxy(765,574, "                     ");
										outtextxy(765,602, "                     ");
										outtextxy(765,634, "                     ");		
										cout<<"You can buy 1 more House"<<endl;
										housecount[index] = housecount[index] + 1;
										
										p_housecount[i] = p_housecount[i] + 1;
										sprintf(C_No_ofHouses, "%d", p_housecount[i]);
										
										sprintf(C_houseCount, "%d", housecount[index]);														
										currentBal[i]=currentBal[i]- houseRate[index];
										BankBal=BankBal + houseRate[index];
										cout<<"Player "<<i<<" has "<< housecount[index]<<" number of houses at "<<site[index]<<endl;
										newRent[index] = rentH3[index];	
										outtextxy(765,446, "Player");
										outtextxy(845,446, turnMention);
										outtextxy(860,446, "has");
										outtextxy(900,446, C_houseCount) ;
										outtextxy(765,478, "houses at");
										outtextxy(765,510, site[index]);
										p_debit[i] = houseRate[index]; p_credit[i] = 0;
										b_credit = houseRate[index]; b_debit = 0;
																														
									}
																						
								}
									else if (val == IDNO){      //if no to building houses
											continue;
										}												
																							
								}
							else if(hotelcount[index]<1)
									{
										cout<<"Do you want to buy a hotel? Y/N"<<endl;
										cin>>answer;
										if(answer=='Y' || answer =='y')
										{
											currentBal[i]=currentBal[i]-hotelRate[index];
											BankBal=BankBal + hotelRate[index];
											newRent[index] = rentHotel[index];
											
											p_hotelcount[i] = p_hotelcount[i] +1;
											sprintf(C_No_ofHotels, "%d", p_hotelcount[i]);
											outtextxy(765,446, "Player ");
											outtextxy(845,446, turnMention);
											outtextxy(765,478, " bought hotel at");										
											outtextxy(765,510, site[index]);
											p_debit[i] = houseRate[index]; p_credit[i] = 0;
											b_credit = houseRate[index]; b_debit = 0;										
										}
										else{       // if no to building hotel
											continue;
										}
										
									}												
							else{
								cout<<"You have already built 3 houses and a hotel"<<endl;
								outtextxy(765,446, "You have already built");
								outtextxy(765,478, "3 houses and a hotel");
								delay(200);
								}			
									}
							else{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"Rent to be paid= "<<newRent[index]<<" to player "<<owner[index]<<endl;
								currentBal[i] = currentBal[i]-newRent[index];
								currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
								setcolor(BLACK);
								
								sprintf(C_owner, "%d", owner[index]);
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to Player ";
								strcat(b,C_owner);
								strcat(a,b);
								MessageBox(NULL, a, str , MB_OK);
								
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);
								p_debit[i] = newRent[index]; p_credit[i] = 0;
								b_credit = newRent[index]; b_debit = 0;
							}										
						break;
						
						case 3: cout<<"You have reached "<<site[index]<<endl;
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");																
								
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);							
							outtextxy(765,446, "Mortgage Value:");
							outtextxy(920,446,C_mrtgVal);													
							
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");														
								
								sitecount[i] = sitecount[i] +1;
								sprintf(C_No_Sites, "%d", sitecount[i]);
								
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								
								cout<<"Player "<<i<<" bought site at "<<site[index]<<endl;
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
								newRent[index] = siteRent[index];
								if(placeacquire[16] == i)
								{
									newRent[index] = 1350;
									p_debit[i] = siteRate[index]; p_credit[i] = 0;
									b_credit = newRent[index]; b_debit = 0;
								}																					
							}
							else if (val ==IDNO){ 
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
									
								cout<<"Rent to be paid = "<<siteRent[index]<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];	
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;	
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
									
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
								else if(placeacquire[index]==i) 
								{
									continue;
								}
								else{
									outtextxy(765,350, "                     ");	
									outtextxy(765,382, "                     ");
									outtextxy(765,414, "                     ");
									outtextxy(765,446, "                     ");
									outtextxy(765,478, "                     ");
									outtextxy(765,510, "                     ");						
									outtextxy(765,542, "                     ");
									outtextxy(765,574, "                     ");
									outtextxy(765,602, "                     ");
									outtextxy(765,634, "                     ");	
									cout<<"Rent to be paid = "<<newRent[index]<<" to player "<<owner[index]<<endl;
									currentBal[i] = currentBal[i]-newRent[index];
									currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
									p_debit[i] = newRent[index]; p_credit[i] = 0;
									b_credit = newRent[index]; b_debit = 0;
									
									sprintf(C_owner, "%d", owner[index]);
								
									char a[30] = "Rent to be paid is Rs. ";
									strcat(a,C_siteRent);
									char b[20] = " to Player ";
									strcat(b,C_owner);
									strcat(a,b);
									MessageBox(NULL, a, str , MB_OK);
									
									setcolor(BLACK);
									outtextxy(765,446, "Rent to be paid");
									outtextxy(765,478, " is ");
									outtextxy(775,478, C_siteRent);
								}
								break;	
								
						case 7: cout<<"You have reached "<<site[index]<<endl;
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
											
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);							
							outtextxy(765,446, "Mortgage Value:");
							outtextxy(920,446,C_mrtgVal);													
							
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								
								sitecount[i] = sitecount[i] +1;
								sprintf(C_No_Sites, "%d", sitecount[i]);
 
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"Player "<<i<<" bought site at "<<site[index]<<endl;
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
								newRent[index] = siteRent[index];
								if(placeacquire[24] == i)
										{
											newRent[index] = 1000;
											p_debit[i] = siteRate[index]; p_credit[i] = 0;
											b_credit = newRent[index]; b_debit = 0;
										}																
							}
							else if(val == IDNO){
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"Rent to be paid = "<<siteRent[index]<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];	
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
								
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;		
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
								else if(placeacquire[index]==i) 
								{
									continue;
								}
								else
							{
								outtextxy(765,350, "                    ");	
								outtextxy(765,382, "                    ");
								outtextxy(765,414, "                    ");
								outtextxy(765,446, "                    ");
								outtextxy(765,478, "                    ");
								outtextxy(765,510, "                    ");						
								outtextxy(765,542, "                    ");
								outtextxy(765,574, "                    ");
								outtextxy(765,602, "                    ");
								outtextxy(765,634, "                    ");	
								cout<<"Rent to be paid = "<<newRent[index]<<" to player "<<owner[index]<<endl;
								currentBal[i] = currentBal[i]-newRent[index];
								currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
								
								p_debit[i] = newRent[index]; p_credit[i] = 0;
								p_debit[owner[index]] = 0; p_credit[owner[index]] = newRent[index];
								
								sprintf(C_owner, "%d", owner[index]);
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to Player ";
								strcat(b,C_owner);
								strcat(a,b);
								MessageBox(NULL, a, str , MB_OK);
								
								setcolor(BLACK);
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);
								}
								break;
								
						case 12:
						case 34:cout<<"You have reached "<<site[index]<<endl;
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
											
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);							
							outtextxy(765,446, "Mortgage Value:");
							outtextxy(920,446,C_mrtgVal);													
							
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");														
								 
								sitecount[i] = sitecount[i] +1; 
								sprintf(C_No_Sites, "%d", sitecount[i]);
  
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"Player "<<i<<" bought site at "<<site[index]<<endl;
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
								newRent[index] = siteRent[index];
								if(placeacquire[24] == i)
								{
									newRent[index] = 1000;
									p_debit[i] = siteRate[index]; p_credit[i] = 0;
									b_credit = newRent[index]; b_debit = 0;
								}
									
								cout<<"Current Balance = "<<currentBal[i];
								cout<<"\tBank Balance = "<<BankBal<<endl;																		
							}
							else if(val == IDNO){
								outtextxy(765,350, "                    ");	
								outtextxy(765,382, "                    ");
								outtextxy(765,414, "                    ");
								outtextxy(765,446, "                    ");
								outtextxy(765,478, "                    ");
								outtextxy(765,510, "                    ");						
								outtextxy(765,542, "                    ");
								outtextxy(765,574, "                    ");
								outtextxy(765,602, "                    ");
								outtextxy(765,634, "                    ");	
									
								cout<<"Rent to be paid = "<<siteRent[index]<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = newRent[index]; p_credit[i] = 0;
								b_credit = newRent[index]; b_debit = 0;	
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;	
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
									
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
								else if(placeacquire[index]==i) 
								{
									continue;
								}
								else{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"Rent to be paid = "<<newRent[index]<<" to player "<<owner[index]<<endl;
								currentBal[i] = currentBal[i]-newRent[index];
								currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
								p_debit[i] = newRent[index]; p_credit[i] = 0;
								p_debit[owner[index]] = 0; p_credit[owner[index]] = newRent[index];
								
								sprintf(C_owner, "%d", owner[index]);
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to Player ";
								strcat(b,C_owner);
								strcat(a,b);
								MessageBox(NULL, a, str , MB_OK);
								
								setcolor(BLACK);
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);
								}
								break;
									
					case 16:cout<<"You have reached "<<site[index]<<endl;
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
											
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);							
							outtextxy(765,446, "Mortgage Value:");
							outtextxy(920,446,C_mrtgVal);													
							
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");														
								
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"Player "<<i<<" bought site at "<<site[index]<<endl;
								
								sitecount[i] = sitecount[i] +1; 
								sprintf(C_No_Sites, "%d", sitecount[i]);
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
								newRent[index] = siteRent[index];
								if(placeacquire[16] == i)
								{
									newRent[index] = 1500;
									p_debit[i] = newRent[index]; p_credit[i] = 0;
									b_credit = newRent[index]; b_debit = 0;
									}																		
							}
							else if(val == IDNO){
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"Rent to be paid = "<<siteRent[index]<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;	
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;		
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
								
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
								else if(placeacquire[index]==i) 
								{
									continue;
								}
								else{
									outtextxy(765,350, "                     ");	
									outtextxy(765,382, "                     ");
									outtextxy(765,414, "                     ");
									outtextxy(765,446, "                     ");
									outtextxy(765,478, "                     ");
									outtextxy(765,510, "                     ");						
									outtextxy(765,542, "                     ");
									outtextxy(765,574, "                     ");
									outtextxy(765,602, "                     ");
									outtextxy(765,634, "                     ");	
									cout<<"Rent to be paid = "<<newRent[index]<<" to player "<<owner[index]<<endl;
									currentBal[i] = currentBal[i]-newRent[index];
									currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
									p_debit[i] = newRent[index]; p_credit[i] = 0;
									p_debit[owner[index]] = 0; p_credit[owner[index]] = newRent[index];
								
									sprintf(C_owner, "%d", owner[index]);
								
									char a[30] = "Rent to be paid is Rs. ";
									strcat(a,C_siteRent);
									char b[20] = " to Player ";
									strcat(b,C_owner);
									strcat(a,b);
									MessageBox(NULL, a, str , MB_OK);
								
									setcolor(BLACK);
									outtextxy(765,446, "Rent to be paid");
									outtextxy(765,478, " is ");
									outtextxy(775,478, C_siteRent);
								}
								break;
					case 24:cout<<"You have reached "<<site[index]<<endl;
						if(placeacquire[index]==0)                 //No player has acquired the place
						{		
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
											
							setcolor(BLACK);
							settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
							outtextxy(765,350, "Site:");			 
							outtextxy(820,350,site[index]);	
							outtextxy(765,382, "Site Rate:");	
							outtextxy(890,382,C_siteRate);							
							setcolor(RED);
							outtextxy(765,414, "Site Rent:");	
							outtextxy(890,414, C_siteRent);							
							outtextxy(765,446, "Mortgage Value:");
							outtextxy(920,446,C_mrtgVal);													
							
							char str1[40] = "Do you want to buy a site at ";
							char str2[10]= "?";							
							strcat(str1, site[index]);
							strcat(str1, str2);
							
							int val = MessageBox(NULL,str1, str , MB_YESNO);
							if(val == IDYES)
							{
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								
								sitecount[i] = sitecount[i] +1; 
								sprintf(C_No_Sites, "%d", sitecount[i]);
								
								cout<<"Site Rate = Rs. "<<siteRate[index]<<endl;
								outtextxy(765,414, "Site Rate = ");
								outtextxy(890,414, C_siteRate);
								placeacquire[index] = i;
								currentBal[i] = currentBal[i] - siteRate[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;
								cout<<"Player "<<i<<" bought site at "<<site[index]<<endl;
								
								sprintf(turnMention, "%d", i);
								setcolor(BLACK);
								outtextxy(765,446, "Player");
								outtextxy(845,446, turnMention);
								outtextxy(860,446, "bought site");
								outtextxy(765,478, "at");
								outtextxy(810,478, site[index]);
								delay(200);
								
				   				owner[index] = i;
								newRent[index] = siteRent[index];
								if(placeacquire[16] == i)
								{
									newRent[index] = 1500;
									p_debit[i] = siteRate[index]; p_credit[i] = 0;
									b_credit = newRent[index]; b_debit = 0;
								}																			
							}
							else if(val == IDNO){
								outtextxy(765,350, "                     ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"Rent to be paid = "<<siteRent[index]<<endl;
								currentBal[i] = currentBal[i] - siteRent[index];
								BankBal = BankBal + siteRate[index];
								p_debit[i] = siteRate[index]; p_credit[i] = 0;
								b_credit = siteRate[index]; b_debit = 0;	
								cout<<"Rent of Rs. "<<	siteRate[index] <<" paid to Bank."<<endl;		
								
								char a[30] = "Rent to be paid is Rs. ";
								strcat(a,C_siteRent);
								char b[20] = " to the bank.";
								strcat(a,b);
								MessageBox(NULL,a, str , MB_OK);
								
								outtextxy(765,446, "Rent to be paid");
								outtextxy(765,478, " is ");
								outtextxy(775,478, C_siteRent);	
								delay(200);																					
							}
						}
								else if(placeacquire[index]==i) 
								{
									continue;
								}
								else{
									outtextxy(765,350, "                     ");	
									outtextxy(765,382, "                     ");
									outtextxy(765,414, "                     ");
									outtextxy(765,446, "                     ");
									outtextxy(765,478, "                     ");
									outtextxy(765,510, "                     ");						
									outtextxy(765,542, "                     ");
									outtextxy(765,574, "                     ");
									outtextxy(765,602, "                     ");
									outtextxy(765,634, "                     ");	
									cout<<"Rent to be paid = "<<newRent[index]<<" to player "<<owner[index]<<endl;
									currentBal[i] = currentBal[i]-newRent[index];
									currentBal[owner[index]] = currentBal[owner[index]] + newRent[index];
									p_debit[i] = newRent[index]; p_credit[i] = 0;
									p_debit[owner[index]] = 0; p_credit[owner[index]] = newRent[index];
									
									sprintf(C_owner, "%d", owner[index]);
								
									char a[30] = "Rent to be paid is Rs. ";
									strcat(a,C_siteRent);
									char b[20] = " to Player ";
									strcat(b,C_owner);
									strcat(a,b);
									MessageBox(NULL, a, str , MB_OK);
									
									setcolor(BLACK);
									outtextxy(765,446, "Rent to be paid");
									outtextxy(765,478, " is ");
									outtextxy(775,478, C_siteRent);
								}
								break;			
						
						case 2:
						case 20:
							cout<<"You have reached the community Chest."<<endl;
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
							switch(dief)
							{
								case 2: cout<<"You will receive dividend on shares on Rs. 2500/-"<<endl;
								MessageBox(NULL, "You will receive dividend on shares on Rs. 2500/-", "Community Chest", MB_OK);
										currentBal[i] = currentBal[i]+2500;
										BankBal=BankBal-2500; 
										p_debit[i] = 0 ; p_credit[i] = 2500;
										b_credit = 0 ; b_debit = 2500;
										outtextxy(765,414, "You will receive");
										outtextxy(765,446, "dividend on shares");
										outtextxy(765,478, "on Rs. 2500/-");
										break;
								case 4:	cout<<"You will receive a prize worth Rs.3000/- for best performance in export."<<endl;
								MessageBox(NULL, "You will receive a prize worth Rs.3000/- for best performance in export.", "Community Chest", MB_OK);
										currentBal[i] = currentBal[i]+3000;
										BankBal=BankBal-3000;
										p_debit[i] = 0; p_credit[i] = 3000;
										b_credit = 0; b_debit = 3000;			
										outtextxy(765,414, "You will receive");
										outtextxy(765,446, "a prize worth");
										outtextxy(765,478, "Rs.3000/- for best");	
										outtextxy(765,510, "performance in export.");						
										break;
								case 6: cout<<"You are getting a tax refund of Rs.2000/-."<<endl;
								MessageBox(NULL, "You are getting a tax refund of Rs.2000/-.", "Community Chest", MB_OK);
										currentBal[i] = currentBal[i]+2000;
										BankBal=BankBal-2000;
										p_debit[i] = 0; p_credit[i] = 2000;
										b_credit = 0; b_debit = 2000;
										cout<<"Current Balance = "<<currentBal[i]<<endl;
										cout<<"Bank Balance = "<<BankBal<<endl;
										outtextxy(765,414, "You are getting a");
										outtextxy(765,446, "tax refund of");
										outtextxy(765,478, "Rs.2000/-.");
										break;
								case 8: cout<<"Go back three spaces, cannot play next turn."<<endl;
								MessageBox(NULL, "Go back three spaces, cannot play next turn.", "Community Chest", MB_OK);
										pos[i]=pos[i]-3;
										cout<<"You Cannot Play Next Turn";
										outtextxy(765,414, "Go back three");
										outtextxy(765,446, "spaces, cannot");
										outtextxy(765,478, "play next turn.");
										break;
								case 10:cout<<"You will receive fixed deposit matures Rs.500/-"<<endl;	
								MessageBox(NULL, "You will receive fixed deposit matures Rs.500/-", "Community Chest", MB_OK);										
										currentBal[i] = currentBal[i]+500;
										BankBal=BankBal-500;
										p_debit[i] = 0; p_credit[i] = 500;
										b_credit = 0; b_debit = 500;
										outtextxy(765,414, "You will receive");
										outtextxy(765,446, "fixed deposit");
										outtextxy(765,478, "matures Rs.500/-");
										break;
								case 12:cout<<"You have won the crossword competition prize of Rs. 3000/-"<<endl;
								MessageBox(NULL, "You have won the crossword competition prize of Rs. 3000/-", "Community Chest", MB_OK);
										currentBal[i] = currentBal[i]+3000;
										BankBal=BankBal-3000;
										p_debit[i] = 0; p_credit[i] = 3000;
										b_credit = 0; b_debit = 3000;
										outtextxy(765,414, "You have won the");
										outtextxy(765,446, "crossword competition");
										outtextxy(765,478, "prize of Rs. 3000/-");
										break;
								case 3: cout<<"Pay Rs.800/- to the bank as school and medical fees."<<endl;
								MessageBox(NULL, "Pay Rs.800/- to the bank as school and medical fees.", "Community Chest", MB_OK);
										currentBal[i]=currentBal[i]-800;
										BankBal=BankBal+800;
										p_debit[i] = 800; p_credit[i] = 0;
										b_credit = 800; b_debit = 0;
										outtextxy(765,414, "Pay Rs.800/- to");
										outtextxy(765,446, "the bank as school");
										outtextxy(765,478, "and medical fees.");
										break;
								case 5: cout<<"Pay Rs.1200 to the bank for causing accident due to drinking under liquor influence."<<endl;
								MessageBox(NULL, "Pay Rs.1200 to the bank for causing accident due to drinking under liquor influence.", "Community Chest", MB_OK);
										currentBal[i]=currentBal[i]-1200;
										BankBal=BankBal+1200;
										p_debit[i] = 1200; p_credit[i] = 0;
										b_credit = 1200; b_debit = 0;
										outtextxy(765,414, "Pay Rs.1200 to the");
										outtextxy(765,446, "bank for causing");
										outtextxy(765,478, "accident due to");
										outtextxy(765,510, "drinking under liquor");
										outtextxy(765,532, "influence.");
										break;
								case 7: cout<<"Pay your Insurance Premium of Rs.1500 to the bank."<<endl;
								MessageBox(NULL, "Pay your Insurance Premium of Rs.1500 to the bank.", "Community Chest", MB_OK);
										currentBal[i]=currentBal[i]-1500;
										BankBal=BankBal+1500;
										p_debit[i] = 1500; p_credit[i] = 0;
										b_credit = 1500; b_debit = 0;
										outtextxy(765,414, "Pay your Insurance");
										outtextxy(765,446, "Premium of Rs.1500");
										outtextxy(765,478, "to the bank.");
										break;
								case 9: cout<<"Take a trip to the Water World Resort. Pay Rs.150/- as entry fee."<<endl;
								MessageBox(NULL, "Take a trip to the Water World Resort. Pay Rs.150/- as entry fee.", "Community Chest", MB_OK);
										currentBal[i]=currentBal[i]-150;
										BankBal=BankBal+150;
										p_debit[i] = 150; p_credit[i] = 0;
										b_credit = 150; b_debit = 0;
										pos[i]=9;
										outtextxy(765,414, "Take a trip to the");
										outtextxy(765,446, "Water World Resort.");
										outtextxy(765,478, " Pay Rs.150/- as");
										outtextxy(765,510, "entry fee.");
										break;
								case 11:cout<<"Go to the jail!"<<endl;
								MessageBox(NULL, "Go to the jail!", "Community Chest", MB_OK);
										pos[i]=18;
										outtextxy(765,414, "Go to the jail!");
										break;
									
								}
							break;
						case 13:
						case 29:cout<<"You have to take a Chance."<<endl;
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                    ");	
							switch(dief)
							{
							case 2: cout<<"Pay Rs.1000/- to the bank as doctor examination fees."<<endl;
							MessageBox(NULL, "Pay Rs.1000/- to the bank as doctor examination fees.", "Chance", MB_OK);
									currentBal[i]=currentBal[i]-1000;
									BankBal=BankBal+1000;
									p_debit[i] = 1000; p_credit[i] = 0;
									b_credit = 1000; b_debit = 0;
									outtextxy(765,414, "Pay Rs.1000/- to the");
								    outtextxy(765,446, "bank as doctor");
								    outtextxy(765,478, "examination fees.");
									break;
							case 4: cout<<"You have beared loss in office.Pay Rs.4000/- to the bank."<<endl;
							MessageBox(NULL,  "You have beared loss in office.Pay Rs.4000/- to the bank.", "Chance", MB_OK);
									currentBal[i]=currentBal[i]-4000;
									BankBal=BankBal+4000;
									p_debit[i] = 4000; p_credit[i] = 0;
									b_credit = 4000; b_debit = 0;
									outtextxy(765,414, "You have beared loss in");
								    outtextxy(765,446, "office.Pay Rs.4000/-");
								    outtextxy(765,478, "to the bank.");
									break;
							case 6:	cout<<"Pay Rs.500/- to the bank as parking offense."<<endl;
							MessageBox(NULL,  "Pay Rs.500/- to the bank as parking offense.", "Chance", MB_OK);
									currentBal[i]=currentBal[i]-500;
									BankBal=BankBal+500;
									p_debit[i] = 500; p_credit[i] = 0;
									b_credit = 500; b_debit = 0;
									outtextxy(765,414, "Pay Rs.500/- to the");
								    outtextxy(765,446, "bank as parking");
								    outtextxy(765,478, "offense.");
									break;
							case 8: cout<<"You have beared a loss in the share market. Pay Rs.1000/- to the bank."<<endl;
							MessageBox(NULL, "You have beared a loss in the share market. Pay Rs.1000/- to the bank.", "Chance", MB_OK);
									currentBal[i]=currentBal[i]-1000;
									BankBal=BankBal+1000;
									p_debit[i] = 1000; p_credit[i] = 0;
									b_credit = 1000; b_debit = 0;
									outtextxy(765,414, "You have beared a loss");
								    outtextxy(765,446, "in the share market.");
								    outtextxy(765,478, "Pay Rs.1000/-");
								    outtextxy(765,510, "to the bank.");
									break;
							case 10:cout<<"Pay Rs.2000/- to the bank as marriage celebration."<<endl;
							MessageBox(NULL, "Pay Rs.2000/- to the bank as marriage celebration.", "Chance", MB_OK);
									currentBal[i]=currentBal[i]-2000;
									BankBal=BankBal+2000;
									p_debit[i] = 2000; p_credit[i] = 0;
									b_credit = 2000; b_debit = 0;
									outtextxy(765,414, "Pay Rs.2000/- to the");
								    outtextxy(765,446, "bank as marriage");
								    outtextxy(765,478, "celebration.");
									break;
							case 12:cout<<"Make general repairs on all your properties. Pay Rs.100 for each house and Rs.200 for each hotel."<<endl;
							MessageBox(NULL,  "Make general repairs on all your properties. Pay Rs.100 for each house and Rs.200 for each hotel.", "Chance", MB_OK);
									pay=(housecount[index]*100)+(hotelcount[index]*200);
									currentBal[i]=currentBal[i]-pay;
									BankBal=BankBal+pay;
									p_debit[i] = pay; p_credit[i] = 0;
									b_credit = pay; b_debit = 0;
									outtextxy(765,414, "Make general repairs on");
								    outtextxy(765,446, "all your properties.");
								    outtextxy(765,478, "Pay Rs.100 for each");
								    outtextxy(765,510, "house and Rs.200 for");	
								    outtextxy(765,542, "each hotel.");
									break;
							case 3: cout<<"You will receive Rs.500/- as birthday gift from each player"<<endl;
							MessageBox(NULL, "You will receive Rs.500/- as birthday gift from each player", "Chance", MB_OK);
									pay=(no_players-1)*500;
									currentBal[i] = currentBal[i] + pay;									 
									p_debit[i] = 0; p_credit[i] = pay;								
									for(j=1;j<=no_players;j++){
									if(j==i){
										continue;
										}
									p_debit[j] = 500; p_credit[j] = 0;
									currentBal[j] = currentBal[j] - 500;
									}
									outtextxy(765,414, "You will receive");
									outtextxy(765,446, "Rs.500/- as birthday");
									outtextxy(765,478, "gift from each player");
									break;										
							case 5: cout<<"You will receive Rs.2000/- for being the man of the match!"<<endl;
							MessageBox(NULL,  "You will receive Rs.2000/- for being the man of the match!", "Chance", MB_OK);
									currentBal[i] = currentBal[i]+2000;
									BankBal=BankBal-2000; 
									p_debit[i] = 0; p_credit[i] = 2000;
									b_credit = 0; b_debit = 2000;
									outtextxy(765,414, "You will receive");
									outtextxy(765,446, "Rs.2000/- for being the");
									outtextxy(765,478, "man of the match!");
									break;
							case 7: cout<<"Go back to Mumbai. You will receive Rs.1500/- bonus as you pass the start point."<<endl;
							MessageBox(NULL,  "Go back to Mumbai. You will receive Rs.1500/- bonus as you pass the start point.", "Chance", MB_OK);
									currentBal[i] = currentBal[i]+1500;
									BankBal=BankBal-1500; 
									p_debit[i] = 0; p_credit[i] = 1500;
									b_credit = 0; b_debit = 1500;
									pos[i]=1;
									outtextxy(765,414, "Go back to Mumbai.");
									outtextxy(765,446, "You will receive");
									outtextxy(765,478, "Rs.1500/- bonus as you");
									outtextxy(765,510, "pass the start point.");
									break;
							case 9: cout<<"You will receive Rs.3000/- as sale of stocks"<<endl;
							MessageBox(NULL, "You will receive Rs.3000/- as sale of stocks","Chance", MB_OK);
									currentBal[i] = currentBal[i]+3000;
									BankBal = BankBal-3000; 
									p_debit[i] = 0; p_credit[i] = 3000;
									b_credit = 0; b_debit = 3000;
									outtextxy(765,414, "You will receive");
									outtextxy(765,446, "Rs.3000/- as sale of");
									outtextxy(765,478, "stocks");
									break;
							case 11:cout<<"You will receive Rs.1800/- as interest of shares"<<endl;
							MessageBox(NULL, "You will receive Rs.1800/- as interest of shares", "Chance", MB_OK);
									currentBal[i] = currentBal[i]+ 1800;
									BankBal=BankBal-1800; 
									p_debit[i] = 0; p_credit[i] = 1800;
									b_credit = 0; b_debit = 1800;
									outtextxy(765,414, "You will receive");
									outtextxy(765,446, "Rs.1800/- as interest");
									outtextxy(765,478, "of shares");
									break;
							}
						break;
						case 5:
							outtextxy(765,350, "                     ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
						cout<<"You have to pay the Income Tax! Pay Rs.50/- to the bank for every site owned."<<endl;
						MessageBox(NULL,  "You have to pay the Income Tax! Pay Rs.50/- to the bank for every site owned.", site[index], MB_OK);
								
								pay=sitecount[i]*50;
								currentBal[i]=currentBal[i]-pay;
								BankBal=BankBal+pay;
								p_debit[i] = pay; p_credit[i] = 0;
								b_credit = pay; b_debit = 0;
								outtextxy(765,414, "You have to pay the");
								outtextxy(765,446, "Income Tax! Pay Rs.50/-");
								outtextxy(765,478, "to the bank for every");
								outtextxy(765,510, "site owned.");
								break;
						case 9: 
								outtextxy(765,350, "                    ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");					
								cout<<"You have reached the Water World Resort. Pay Rs.150/- as entry fee."<<endl;
								MessageBox(NULL, "You have reached the Water World Resort. Pay Rs.150/- as entry fee.", site[index], MB_OK);
								
								currentBal[i]=currentBal[i]-150;
								BankBal=BankBal+150;
								p_debit[i] = 150; p_credit[i] = 0;
								b_credit = 150; b_debit = 0;
								outtextxy(765,414, "You have reached the");
								outtextxy(765,446, "Water World Resort.");
								outtextxy(765,478, "Pay Rs.150/- as");
								outtextxy(765,510, "entry fee.");
								break;
						case 18:outtextxy(765,350, "                    ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
						cout<<"You have reached the Jail. Pay Rs.500/- to get out."<<endl;
						MessageBox(NULL,  "You have reached the Jail. Pay Rs.500/- to get out.", site[index], MB_OK);
								
								currentBal[i]=currentBal[i]-500;
								BankBal=BankBal+500;
								p_debit[i] = 500; p_credit[i] = 0;
								b_credit = 500; b_debit = 0;
								outtextxy(765,414, "You have reached the");
								outtextxy(765,446, "Jail. Pay Rs.500/-");
								outtextxy(765,478, "to get out.");		
								break;		
						case 27: outtextxy(765,350, "                    ");	
							outtextxy(765,382, "                     ");
							outtextxy(765,414, "                     ");
							outtextxy(765,446, "                     ");
							outtextxy(765,478, "                     ");
							outtextxy(765,510, "                     ");						
							outtextxy(765,542, "                     ");
							outtextxy(765,574, "                     ");
							outtextxy(765,602, "                     ");
							outtextxy(765,634, "                     ");	
							cout<<"You have reached the Sports Club. Give Rs.100/- to each player."<<endl;
								MessageBox(NULL,  "You have reached the Sports Club. Give Rs.100/- to each player", site[index], MB_OK);
								
								pay=(no_players-1)*100;
								currentBal[i]=currentBal[i]-pay;
									for(j=1;j<=no_players;j++){
											if(j==1){
												continue;
											}
											currentBal[j]=currentBal[j]+100;
											p_debit[j] = 0; p_credit[j] = 100;
										}
								p_debit[i] = pay; p_credit[i] = 0;
							
								outtextxy(765,414, "You have reached the");
								outtextxy(765,446, "Sports Club. Give ");
								outtextxy(765,478, "Rs.100 to each player.");
								break;
								
						case 31: outtextxy(765,350, "                    ");	
								outtextxy(765,382, "                     ");
								outtextxy(765,414, "                     ");
								outtextxy(765,446, "                     ");
								outtextxy(765,478, "                     ");
								outtextxy(765,510, "                     ");						
								outtextxy(765,542, "                     ");
								outtextxy(765,574, "                     ");
								outtextxy(765,602, "                     ");
								outtextxy(765,634, "                     ");	
								cout<<"You have to pay the Wealth Tax!"<<endl;								
								MessageBox(NULL, "You have to pay the Wealth Tax!", site[index], MB_OK);
								
								pay=(p_housecount[i]*50)+(p_hotelcount[i]*200);
								currentBal[i]=currentBal[i]-pay;
								BankBal=BankBal+pay;
								p_debit[i] = pay; p_credit[i] = 0;
								b_credit = pay; b_debit = 0;
								outtextxy(765,414, "You have pay the");
								outtextxy(765,446, "Wealth Tax!");
								break;
						default:exit(0);
					}	
					
					cout<<"Current Balance = Rs. "<<currentBal[i];
				    cout<<"\t\tBank Balance = Rs. "<<BankBal<<endl;
							
					if(p_debit[i] ==0 && b_credit ==0)
					{
						cout<<"Player"<<i<<" Credit = Rs. "<<p_credit[i];
						cout<<"\t\tBankDebit = Rs."<<b_debit<<endl;
					}
					if(p_credit[i] ==0 && b_debit ==0)
					{
						cout<<"Player"<<i<<" Debit = Rs. "<<p_debit[i];
						cout<<"\t\tBankCredit = Rs. "<<b_credit<<endl;
					}
					
					displayPlayerDet(i);
					
					sprintf(CP_credit, "%d", p_credit[i]);
					sprintf(CP_debit, "%d", p_debit[i]);
					sprintf(CB_credit, "%d", b_credit);
					sprintf(CB_debit, "%d", b_debit);
					sprintf(C_currentBal, "%d", currentBal[i] );
					sprintf(C_BankBal, "%d", BankBal);
					
					char rupee[10] = "Rs. ";
					char points[20];
					strcat(rupee, C_currentBal);
					sprintf(points,"%s",rupee);												
					setcolor(BLACK);	
														
					if(i==1){
						outtextxy(876,108, points);
						fstream file4;
						file4.open("Player1.txt", ios::out|ios::app);						
						file4<<C_index<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<"|"<<endl;
						file4.close();
						fstream file5;
						file5.open("PropertyCount1.txt", ios::out);
						file5<<"Player1"<<"|"<<C_No_Sites<<"|"<<C_No_ofHouses<<"|"<<C_No_ofHotels<<endl;
						file5.close();
					}
					if(i==2){
						outtextxy(876,140, points);
						fstream file4;
						file4.open("Player2.txt", ios::out|ios::app);
							file4<<C_index<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<"|"<<endl;
						file4.close();
						fstream file5;
						file5.open("PropertyCount2.txt", ios::out);
						file5<<"Player2"<<"|"<<C_No_Sites<<"|"<<C_No_ofHouses<<"|"<<C_No_ofHotels<<endl;
						file5.close();
					}
					if(i==3){
						outtextxy(876,172, points);
						fstream file4;
						file4.open("Player3.txt", ios::out|ios::app);
							file4<<C_index<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<"|"<<endl;
						file4.close();
						fstream file5;
						file5.open("PropertyCount3.txt", ios::out);
						file5<<"Player3"<<"|"<<C_No_Sites<<"|"<<C_No_ofHouses<<"|"<<C_No_ofHotels<<endl;
						file5.close();
						
					}
					if(i==4){
						outtextxy(876,204, points);
						fstream file4;
						file4.open("Player4.txt", ios::out|ios::app);
							file4<<C_index<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<"|"<<endl;
						file4.close();
						fstream file5;
						file5.open("PropertyCount4.txt", ios::out);
						file5<<"Player4"<<"|"<<C_No_Sites<<"|"<<C_No_ofHouses<<"|"<<C_No_ofHotels<<endl;
						file5.close();
					}
					if(i==5){
						outtextxy(876,236, points);
						fstream file4;						
						file4.open("Player5.txt", ios::out|ios::app);
						file4<<C_index<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<"|"<<endl;
						file4.close();
						fstream file5;
						file5.open("PropertyCount5.txt", ios::out);
						file5<<"Player5"<<"|"<<C_No_Sites<<"|"<<C_No_ofHouses<<"|"<<C_No_ofHotels<<endl;
						file5.close();
					}					
					fstream file5;
					file5.open("BankDetails.txt", ios::app | ios::out);				
						file5<<"Player"<<i<<"|"<<site[index]<<C_currentBal<<"|"<<CP_credit<<"|"<<CP_debit<<endl;				
					file5.close();				
				}
				cout << "\n+------------------------------------------------------------------+"<<endl;
			}							
		
}
void updateSiteFile(int i, int index, char *site[20])
{
	if(i==1)
	{
		fstream file6;
		file6.open("SiteClaimP1.txt", ios::out|ios::app);
		file6<<index<<"|"<<site[index]<<endl;
		file6.close();
	}
	if(i==2)
	{
		fstream file6;
		file6.open("SiteClaimP2.txt", ios::out|ios::app);
		file6<<index<<"|"<<site[index]<<endl;
		file6.close();
	}
	if(i==3)
	{
		fstream file6;
		file6.open("SiteClaimP3.txt", ios::out|ios::app);
		file6<<index<<"|"<<site[index]<<endl;
		file6.close();
	}
	if(i==4)
	{
		fstream file6;
		file6.open("SiteClaimP4.txt", ios::out|ios::app);
		file6<<index<<"|"<<site[index]<<endl;
		file6.close();
	}
	if(i==5)
	{
		fstream file6;
		file6.open("SiteClaimP5.txt", ios::out|ios::app);
		file6<<index<<"|"<<site[index]<<endl;
		file6.close();
	}
}
void displayPlayerDet(int i)
{
	fstream file1;
	if(i==1)
	{
		file1.open("Player1.txt", ios::in);
		file1.close();
	}
	if(i==2)
	{
		file1.open("Player2.txt", ios::in);
		file1.close();
	}
	if(i==3)
	{
		file1.open("Player3.txt", ios::in);
		file1.close();
	}
	if(i==4)
	{
		file1.open("Player4.txt", ios::in);
		file1.close();
	}
	if(i==5)
	{
		file1.open("Player5.txt", ios::in);
		file1.close();
	}
}

void playerdetails()
{
	initwindow(1000,800,"Business");
	setbkcolor(BLACK);
	cleardevice();	
	delay(250);
	char np[1];
	
	for(int i=0;i<=10;i++)
	{
		cleardevice();
		setcolor(DARKGRAY);
		rectangle(200,200,800,574);
		rectangle(198,198,802,576);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(199,199,DARKGRAY);
		
		if(i==1) delay(250);
		if(i>=1)
		{
			setcolor(WHITE);
			settextstyle(BOLD_FONT, HORIZ_DIR, 7);
			outtextxy(260,250, "BUSINESS");
		}
		if(i==2) delay(150);
		if(i>=2)
		{
			setcolor(CYAN);
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			outtextxy(320,330, "A TRADE GAME"); 
		}
		if(i==3) delay(150);
		if(i>=3)
		{
			setcolor(LIGHTRED);
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(250,400, "A Game of Buying & Selling,"); 
			outtextxy(300,430,"Banking, Mortgaging");
		}
		if(i==4) delay(150);
		if(i>=4)
		{
			setcolor(LIGHTGRAY);
			line(600,250,600,522);
		}
		if(i==5) delay(150);
		if(i>=5)
		{
			setcolor(CYAN);
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			outtextxy(630,290, "MAIN MENU");
		}
		if(i==6) delay(150);
		if(i>=6)
		{
			setcolor(WHITE); 
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,340," 2 Players");
		}
		if(i==7) delay(150);
		if(i>=7)
		{
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,380," 3 Players");
		}
		if(i==8) delay(150);
		if(i>=8)
		{
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,420," 4 Players");
		}
		if(i==9) delay(150);
		if(i>=9)
		{
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,460," 5 Players");
		}
		if(i==10) delay(150);
		if(i>=10)
		{
			rectangle(675,520,760,550);
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			outtextxy(690,525,"NEXT");			
		}		swapbuffers();
	}				
	delay(50);
	int start = 0, refresh_menu = 0; int no_players;
	POINT CursorPosition;
	long click_x,click_y;
	while(start==0)
	{
		
		cleardevice();
		setcolor(DARKGRAY);
		rectangle(200,200,800,574);
		rectangle(198,198,802,576);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(199,199,DARKGRAY);
		setcolor(WHITE);
		settextstyle(BOLD_FONT, HORIZ_DIR, 7);
		outtextxy(260,250, "BUSINESS");
		setcolor(CYAN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(320,330, "A TRADE GAME"); 
		setcolor(LIGHTRED);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy(250,400, "A Game of Buying & Selling,"); 
		outtextxy(300,430,"Banking, Mortgaging");
		setcolor(LIGHTGRAY);
		line(600,250,600,522);
		setcolor(CYAN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(630,290, "MAIN MENU");
			setcolor(WHITE); 
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,340," 2 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,380," 3 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,420," 4 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,460," 5 Players");
		rectangle(675,520,760,550);
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			outtextxy(690,525,"NEXT");
					
		GetCursorPos(&CursorPosition);
		click_x = mousex();
		click_y = mousey();
		int click;
		if(GetAsyncKeyState(VK_LBUTTON))
		{	
			if(click_x>=635 && click_x<=760 && click_y>=340 && click_y<=365)
			{
				no_players = 2; 			
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,340,"> 2 Players");
				delay(150);
				click =1;
				break;
			} 							
			else if(click_x>=635 && click_x<=760 && click_y>=380 && click_y<=405)
			{   
				no_players = 3; 
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,380,"> 3 Players");
				delay(150);
				break;
			}	
			else if(click_x>=635 && click_x<=760 && click_y>=420 && click_y<=445)
			{
				no_players = 4; 
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,420,"> 4 Players");
				delay(150);
				break;
				}	
			else if(click_x>=635 && click_x<=760 && click_y>=460 && click_y<=485)
			{
				no_players = 5; click = 5;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,460,"> 5 Players");
				delay(150);			
				break;
			}
			else{
				continue;
			}								
		}
		delay(250);		
	}
	swapbuffers();
		while(start==0)
	{		
		cleardevice();
		setcolor(DARKGRAY);
		rectangle(200,200,800,574);
		rectangle(198,198,802,576);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(199,199,DARKGRAY);
		setcolor(WHITE);
		settextstyle(BOLD_FONT, HORIZ_DIR, 7);
		outtextxy(260,250, "BUSINESS");
		setcolor(CYAN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(320,330, "A TRADE GAME"); 
		setcolor(LIGHTRED);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy(250,400, "A Game of Buying & Selling,"); 
		outtextxy(300,430,"Banking, Mortgaging");
		setcolor(LIGHTGRAY);
		line(600,250,600,522);
		setcolor(CYAN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(630,290, "MAIN MENU");
			setcolor(WHITE); 
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,340," 2 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,380," 3 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,420," 4 Players");
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			outtextxy(640,460," 5 Players");
		rectangle(675,520,760,550);
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			outtextxy(690,525,"NEXT");	
					
		GetCursorPos(&CursorPosition);
		click_x = mousex();
		click_y = mousey();
		if(GetAsyncKeyState(VK_LBUTTON))
		{	
			if(click_x>=635 && click_x<=760 && click_y>=340 && click_y<=365 && no_players==3)
			{
				no_players = 2;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,340,"> 2 Players");
				setcolor(WHITE);
				outtextxy(640,380," 3 Players");
				delay(150);
				swapbuffers();
			} 
			else if(click_x>=635 && click_x<=760 && click_y>=340 && click_y<=365 && no_players == 4)
			{
				no_players = 2;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,340,"> 2 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,420," 4 Players");
				delay(150);
				swapbuffers();
			} 
			else if(click_x>=635 && click_x<=760 && click_y>=340 && click_y<=365 && no_players == 5)
			{
				no_players = 2;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,340,"> 2 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,460," 5 Players");
				delay(150);
				swapbuffers();
			}	
			else if(click_x>=635 && click_x<=760 && click_y>=380 && click_y<=405 && no_players==5)
			{   
				no_players = 3;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,380,"> 3 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,460," 5 Players");
				delay(150);
				swapbuffers();
			}
			else if(click_x>=635 && click_x<=760 && click_y>=380 && click_y<=405 && no_players==4)
			{   
				no_players = 3;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,380,"> 3 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,420," 4 Players");
				delay(150);
				swapbuffers();
			}
			else if(click_x>=635 && click_x<=760 && click_y>=380 && click_y<=405 && no_players==2)
			{   
				no_players = 3; 
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,380,"> 3 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,340," 2 Players");
				delay(150);
				swapbuffers();
			}							
			else if(click_x>=635 && click_x<=760 && click_y>=420 && click_y<=445 && no_players==5)
			{
				no_players = 4;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,420,"> 4 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,460," 5 Players");
				delay(150);
				swapbuffers();
			}
			else if(click_x>=635 && click_x<=760 && click_y>=420 && click_y<=445 && no_players==3)
			{
				no_players = 4;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,420,"> 4 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,380," 3 Players");
				delay(150);
				swapbuffers();
			}
				else if(click_x>=635 && click_x<=760 && click_y>=420 && click_y<=445 && no_players==2)
			{
				no_players = 4;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,420,"> 4 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,340," 2 Players");
				delay(150);
				swapbuffers();
				}	
			else if(click_x>=635 && click_x<=760 && click_y>=460 && click_y<=485 && no_players == 2)
			{
				no_players = 5;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,460,"> 5 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,340," 2 Players");
				delay(150);				
				swapbuffers();
			}
			else if(click_x>=635 && click_x<=760 && click_y>=460 && click_y<=485 && no_players == 3)
			{
				no_players = 5;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,460,"> 5 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,380," 3 Players");
				delay(150);				
				swapbuffers();
			}
			else if(click_x>=635 && click_x<=760 && click_y>=460 && click_y<=485 && no_players == 4)
			{
				no_players = 5;
				setcolor(CYAN);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(635,460,"> 5 Players");
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(640,420," 4 Players");
				delay(150);				
				swapbuffers();
			}
			else{
				break;
			}
											
		}
		delay(250);		
	}
	swapbuffers();
	while(start==0)
	{
		cleardevice();
		GetCursorPos(&CursorPosition);
		click_x = mousex();
		click_y = mousey();
		if(GetAsyncKeyState(VK_LBUTTON))
		{	
			if(click_x>=660 && click_x<=760 && click_y>=520 && click_y<=550)
			{
				start=1;
				setcolor(LIGHTGREEN);
				rectangle(675,520,760,550);
				settextstyle(BOLD_FONT, HORIZ_DIR, 3);
				outtextxy(690,525,"NEXT");
				delay(100);
				swapbuffers();
				closegraph();
				delay(50);
				gameboard(no_players);
				break;			
			}		
		}delay(150);
	}
	swapbuffers();	    
}
void playerPoints(char np[], char *tokenColor[7])
{
	cout << "+------------+------------------+-------------------+--------------+"<<endl;
	cout << "+-------------- WELCOME TO THE BUSINESS BOARD GAME! ---------------+"<<endl;
	cout << "+--------- A Game of Selling & Buying, Banking, Mortgaging --------+"<<endl;
	cout << "+------------+------------------+-------------------+--------------+"<<endl;
	cout<<endl;
	cout << "+--------------------------- RULES --------------------------------+"<<endl;
	cout << "\n+------------------------------------------------------------------+"<<endl<<endl;

	fstream f1;
	char playerNum[1]; 
	//	cout<<"Players' Files created"<<endl;		
	int no_players = atoi(np);
	int amt[no_players+1];
	for(int i=1;i<=no_players;i++)
	{
		char playerFile[11] = "Player";
		sprintf(playerNum, "%d",i);
		strcat(playerFile , playerNum);
		strcat(playerFile , ".txt");		
		f1.open(playerFile,ios::out);
		f1.close();
	}
	cout<<"Total Money = Rs.199800"<<endl;
	for(int i=0;i<=no_players;i++)
		amt[i] = (199800/(no_players+1));
	cout<<"\nAmount with each player initially:"<<endl;
	fstream file2;
	file2.open("playerPoints.txt",ios::out);
	cout<<"PlayerNum\tTokenColor\tInitialAmount\n";
	
	file2<<"Bank "<<"|"<<tokenColor[0]<<"|"<< amt[0]<<"\n";
	for(int i=1;i<=no_players;i++)
	{
		if(i==1)
		{
			file2<<"Player"<<i<<"|"<<tokenColor[i]<<"|"<<amt[i]<<"\n";
		    cout<<"Player"<<i<<"\t\t"<<tokenColor[i]<<"\t\t"<<amt[i]<<"\n";
		}
		if(i==2)
		{
			file2<<"Player"<<i<<"|"<<tokenColor[i]<<"|"<<amt[i]<<"\n";
		    cout<<"Player"<<i<<"\t\t"<<tokenColor[i]<<"\t\t"<<amt[i]<<"\n";
		}
		if(i==3)
		{
			file2<<"Player"<<i<<"|"<<tokenColor[i]<<"|"<<amt[i]<<"\n";
		    cout<<"Player"<<i<<"\t\t"<<tokenColor[i]<<"\t\t"<<amt[i]<<"\n";
		}
		if(i==4)
		{
			file2<<"Player"<<i<<"|"<<tokenColor[i]<<"|"<<amt[i]<<"\n";
		    cout<<"Player"<<i<<"\t\t"<<tokenColor[i]<<"\t\t"<<amt[i]<<"\n";
		}
		if(i==5)
		{
			file2<<"Player"<<i<<"|"<<tokenColor[i]<<"|"<<amt[i]<<"\n";
		    cout<<"Player"<<i<<"\t\t"<<tokenColor[i]<<"\t\t"<<amt[i]<<"\n";   	
		 }   
	}
	cout<<"Bank "<<"\t\t"<<"-"<<"\t\t"<<amt[0]<<"\n";
	 
	char playerAmt[20];
	sprintf(playerAmt,"%d",amt[0]);
	char rupee[20] = "Rs. ";
	strcat(rupee, playerAmt);
	sprintf(playerAmt,"%s",rupee);
	
	int x1 = 753, y1 = 70, x2 = 997, y2 = 100;
		
	for(int i =0; i<no_players; i++)
	{	
		setcolor(BLACK);	
		y1+=32; y2+=32;
		rectangle(x1,y1,x2,y2);
		settextstyle(BOLD_FONT, HORIZ_DIR, 1);	
		if(i==0)
		{		
			outtextxy(876,y1+6, playerAmt);
		}
		if(i==1)
		{			
			outtextxy(876,y1+6, playerAmt);
		}
		if(i==2)
		{			
			outtextxy(876,y1+6, playerAmt);
		}		
		if(i==3)
		{			
			outtextxy(876,y1+6, playerAmt);
		}
		if(i==4)
		{			
			outtextxy(876,y1+6, playerAmt);
		}				
				
	}
}


