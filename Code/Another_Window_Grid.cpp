#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void plotgraph(int windowWidth, int windowHeight){
	
	for(int i = windowWidth / 2, j = windowWidth / 2;i < windowWidth || j >= 0; i = i + 25, j = j - 25){
		////plotting origin X axes
		if(i == windowWidth / 2) {
			setcolor(RED);
			line(i,0,i,windowHeight);
		}
		else {
			setcolor(WHITE);
			line(i,0,i,windowHeight);
			line(j,0,j,windowHeight);
		}
	}
	
	for(int i = windowHeight / 2, j = windowHeight / 2;i < windowHeight || j >= 0; i = i + 25, j = j - 25){
		if(i == windowHeight / 2) {
			//plotting origin Y axes
			setcolor(RED);
			line(0,i,windowWidth,i);
		}
		else {
			setcolor(WHITE);
			line(0,i,windowWidth,i);
			line(0,j,windowWidth,j);
		}
	}
	//plotting Coordinate origin axes
	outtextxy((windowWidth/2)+5,(windowHeight/2)+5, "(0,0)");
}

int main()
{
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	float windowWidth = screenWidth/1.1;
	float windowHeight = screenHeight/1.1;
	initwindow(windowWidth, windowHeight, "", 40, 40);
	
	//graph plotting function call
	plotgraph(windowWidth, windowHeight);

    getch();
    closegraph();
}
