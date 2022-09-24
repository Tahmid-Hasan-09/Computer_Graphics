#include<graphics.h>
#include<time.h>
#include <conio.h>
#include<stdio.h>
#include <dos.h>

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

int main()
{
	initwindow(screenWidth-20, screenHeight-20, "", -3, -3);

	time_t rawTime;
	struct tm * currentTime;
	char a[100];

	while(1)
	{
		rawTime = time(NULL);
		currentTime = localtime(&rawTime);
		strftime(a, 100, "%I:%M:%S",currentTime);

		setcolor(11);
		settextstyle(3, HORIZ_DIR, 10);
		outtextxy(screenWidth/2-200, screenHeight/2-100, a);

		strftime(a, 100, "%p", currentTime);
		settextstyle(3, HORIZ_DIR, 2);
		outtextxy(screenWidth/2+200, screenHeight/2-25, a);

		strftime(a, 100, "%a, %d %b, %Y", currentTime);
		settextstyle(3, HORIZ_DIR, 5);
		outtextxy(screenWidth/2-190, screenHeight/2+100, a);

		delay(1000);
		cleardevice();
	}

	getch();
	closegraph();
	return 0;
}
