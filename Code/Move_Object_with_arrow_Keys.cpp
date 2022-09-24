#include<graphics.h>
#include<iostream>

using namespace std;

int main()
{
	//int gd=DETECT,gm;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");

	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	int x=100,y=100;
	
	while(1)
	{
		cleardevice();
		circle(x,y,50);
		if(GetAsyncKeyState(VK_RIGHT)){
			x += 10;
		}
		else if (GetAsyncKeyState(VK_LEFT)){
			x -= 10;
		}
		else if (GetAsyncKeyState(VK_DOWN)){
			y += 10;
		}
		else if (GetAsyncKeyState(VK_UP)){
			y -= 10;
		}
		if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
		
		delay(10);
	}
	
	getch();
	closegraph();
}
