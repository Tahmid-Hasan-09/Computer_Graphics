//Rotation Line draw
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

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
int main(){
	
	float x,y,x0,y0,x1,y1,angle,radian;
	
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",30,30);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
		
	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
	radian=3.14/180;
	
	//before rotation
	setcolor(RED);
	setlinestyle(0, 0, 4); //void setlinestyle(int linestyle, unsigned pattern, int thickness);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before rotation");
    
    //after rotation
    x0=x0*cos(angle*radian)-y0*sin(angle*radian); //x' = xcos@ - ysin@
    y0=x0*sin(angle*radian)+y0*cos(angle*radian); //y' = xsin@ + ycos@
    x1=x1*cos(angle*radian)-y1*sin(angle*radian);
    y1=x1*sin(angle*radian)+y1*cos(angle*radian);
    
    setcolor(GREEN);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);    
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After rotation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
	

}
