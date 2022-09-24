//Translation of triangle using  starting and ending points
//translation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	
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
	setcolor(GREEN);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

void triangle_translation(float x0, float y0, float x1, float y1, float x2, float y2, float tx, float ty)
{
	initwindow(screenWidth-20,screenHeight-20,"",-3,-3);
	plotgraph(screenWidth,screenHeight);
	
	float x,y;
	int i;
	
	//line before translation
	setcolor(CYAN);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x0,(screenHeight/2)-y0);
	
    outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before translation");
	//calculating the translated coordinates
	x0=x0+tx;
	y0=y0+ty;
	x1=x1+tx;
	y1=y1+ty;
	x2=x2+tx;
	y2=y2+ty;

	setcolor(YELLOW);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x0,(screenHeight/2)-y0);
	
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After translation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
}

int main(){

	
	
	float x0,y0,x1,y1,x2,y2,tx,ty;

	cout<<"Enter the value of first point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the value of second point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of third point (x2,y2): ";
	cin>>x2>>y2;
	cout<<"Enter the value of translation factor (tx,ty): ";
	cin>>tx>>ty;
	
	triangle_translation(x0, y0, x1, y1, x2, y2, tx, ty);

	getch();
	closegraph();
}
