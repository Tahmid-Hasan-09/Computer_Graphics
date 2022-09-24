//Translation of circle from simple circle drawing
//translation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

//window size measurement and initialization
DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN); //DWORD is a 32-bit unsigned integer
DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN); //width,height of the screen of the primary display monitor, in pixels
	
void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

void circle_translation(float r, float xc, float yc, float tx, float ty)
{
	// int initwindow(int width, int height, const char* title="Windows BGI", int left=0, int top=0);
	initwindow(screenWidth-20,screenHeight-20,"circle_translation",-3,-3);
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
	//line before translation
	setcolor(CYAN);
	setlinestyle(0, 0, 4); //void setlinestyle(int linestyle, unsigned pattern, int thickness);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
	
    outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before translation");
	//calculating the translated coordinates
	xc=xc+tx;
	yc=yc+ty;

	setcolor(GREEN);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
    outtextxy((screenWidth/2)+xc+60,(screenHeight/2)-yc-10, "After translation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
}

int main(){

	float r,xc,yc,tx,ty;

	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the value of translation factor (tx,ty): ";
	cin>>tx>>ty;

	circle_translation(r, xc, yc, tx, ty);

	getch();
	closegraph();
}
