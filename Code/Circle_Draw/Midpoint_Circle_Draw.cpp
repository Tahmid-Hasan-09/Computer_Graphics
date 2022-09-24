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
	//int gd=DETECT,gm;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	float windowWidth = screenWidth/1.1;
	float windowHeight = screenHeight/1.1;
	initwindow(windowWidth, windowHeight, "", 40, 40);
	
	//graph plotting function call
	plotgraph(windowWidth, windowHeight);
	
	//Algorithm implementation Starts Here
	
	//Variable Declaration 
	float x,y,r,xc,yc,x1,y1,dx,dy,pk;
	
	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	
	
	x=0;
	y=r;
	
	if(r- (int)r==0.0) //If radius is an integer,then pk = 1-r
	{
		pk=1-r;        //initial value of decision parameter pk
	}
	else
	{
		pk=(5.0/4.0-r);
	}
	
	
//	cout<<"x\ty"<<endl;	
    
    while(x<=y)
    {
        putpixel((windowWidth/2)+(xc+x),(windowHeight/2)-(yc+y),GREEN);
        putpixel((windowWidth/2)+(xc+x),(windowHeight/2)-(yc-y),GREEN);
        putpixel((windowWidth/2)+(xc-x),(windowHeight/2)-(yc+y),GREEN);
        putpixel((windowWidth/2)+(xc-x),(windowHeight/2)-(yc-y),GREEN);
        putpixel((windowWidth/2)+(xc+y),(windowHeight/2)-(yc+x),GREEN);  
        putpixel((windowWidth/2)+(xc+y),(windowHeight/2)-(yc-x),GREEN);
        putpixel((windowWidth/2)+(xc-y),(windowHeight/2)-(yc+x),GREEN);
        putpixel((windowWidth/2)+(xc-y),(windowHeight/2)-(yc-x),GREEN);
        
        if(pk<0) //Midpoint is inside the circle,y as y same(upper side) selected
        {
        	x=x+1;
        	y=y;
        	pk=pk+2*x+1; //2nd Decision Parameter,P(k+1) = Pk + 2X(k+1)+1
		}
		else //(pk>=0)
		{
			x=x+1;
        	y=y-1; //Midpoint is outside the circle,y as y-1 (inner/lower side) selected
        	pk=pk+2*x+1-2*y; //2nd Decision Parameter,P(k+1) = Pk + 2X(k+1)+1 - 2y(k+1)
		}
	
	}
	
	putpixel((windowWidth/2)+xc,(windowHeight/2)-yc,RED); //Make a red dot as circle center
    outtextxy((windowWidth/2)+xc,(windowHeight/2)-yc+10, "Center");

    getch();
    closegraph();
}
