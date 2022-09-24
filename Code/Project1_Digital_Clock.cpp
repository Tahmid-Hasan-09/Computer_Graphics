#include<iostream>
#include<graphics.h>
#include<time.h>
using namespace std;

int main(){
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	time_t rawTime;
	struct tm * currentTime;
	char a[100];
	
	while(1)
	{
		rawTime = time(NULL);
		currentTime = localtime(&rawTime);
		strftime(a,100,"%I:%M:%S",currentTime);
		
		setcolor(11);
		settextstyle(3,HORIZ_DIR,10);//settextstyle( int font, int direction, int charsize);
		outtextxy(100,100,a);
		
		strftime(a,100,"%p",currentTime);
		settextstyle(3,HORIZ_DIR,2);//settextstyle( int font, int direction, int charsize);
		outtextxy(600,8,a);
		
		strftime(a,100,"%a, %d %b, %Y",currentTime);
		settextstyle(3,HORIZ_DIR,5);//settextstyle( int font, int direction, int charsize);
		outtextxy(100,220,a);
		
		delay(1000);
	}		
	
	getch();
	closegraph();
}
