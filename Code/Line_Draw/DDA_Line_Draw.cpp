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
	
	//Variable Declaration
	float x,y,x0,y0,x1,y1,dx,dy,step,m;
	
	//dda algorithm
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	
	dx=abs(x1-x0); //delta x
	dy=abs(y1-y0); //delta y
	
	m = dy/dx;
	
	if(m<=1) // Same as if(m<=1)
	{
		step=dx;        //Formula:If(m<=1)->dx=1, dy = m -->X(k+1) = Xk + dx = Xk + 1,,y(k+1)=yk+m
		dx = 1;                 //If(m>1)->dy=1, dy = 1/m -->y(k+1) = yk+1,,X(k+1) = Xk+ (1/m)
		dy = m;
	}
	else
	{
		step=dy;
		dy = 1;
		dx = 1/m;
	}
	
	x=x0;
	y=y0;
	
	//Printing x & y intermediate coordinates
	//cout<<"x\ty"<<endl;	
    
    for(int i=0;i<=step;i++)
    {
    	//Printing x & y intermediate coordinates
    	//cout<<(int)(x+0.5)<<"\t"<<(int)(y+0.5)<<endl;//round=(int)(a+0.5)
    	//Printing x & y original computer window intermediate coordinates
    	//cout<<((int)(windowWidth/2))+((int) (x+0.5))<<"\t"<<((int)(windowHeight/2))-((int)(y+0.5))<<endl;
    	
    	
        putpixel(((int)(windowWidth/2))+((int) (x+0.5)),((int)(windowHeight/2))-((int)(y+0.5)),GREEN);
        
        outtextxy((windowWidth/2)+x0,(windowHeight/2)-y0+10, "Starting point");
        outtextxy((windowWidth/2)+x1+10,(windowHeight/2)-y1-10, "Ending point");

    	x=x+dx;
    	y=y+dy;
	}
    
    getch();
    closegraph();
}
