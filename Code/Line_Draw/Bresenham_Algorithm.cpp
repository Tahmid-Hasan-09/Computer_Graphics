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
	
	//Algorithm Implementation Starts Here
	
	//Variable Declaration
	float x,y,x0,y0,x1,y1,dx,dy,m,stepsize,pk;
	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	
	dx=abs(x1-x0); //delta x
	dy=abs(y1-y0); //delta y
	
	if(dx>dy){ //Because for loop has to go through longest interval
		stepsize = dx;
	}else{
		stepsize = dy;
	}
	
	m = dy/dx; //Find Out Slope
	
	x=x0;
	y=y0;
	
	pk=2*dy-dx; //Starting Decision Parameter Formula
	
	//Printing x & y intermediate coordinates
	cout<<"x\ty"<<endl;	
    
    for(int i=0;i<=stepsize;i++)
    {
    	//Printing x & y intermediate coordinates
    	cout<<(int)(x)<<"\t"<<(int)(y)<<endl;
    	//Printing x & y original computer window intermediate coordinates
    	cout<<(windowWidth/2)+((int) (x))<<"\t"<<(windowHeight/2)-((int)(y))<<endl;
    	
        putpixel((windowWidth/2)+x,(windowHeight/2)-y,GREEN);//pixel by pixel line make
        
        if(m<1){
        	if(pk<0)			// Bresenham Algorithm Formula:
	        { 					// if(m<1)->if(p<0)->X(k+1) = Xk + 1 ; y(k+1) = No change/yk ; P(k+1)=pk+2dy
	        	x=x+1;          //			if(p>=0)->X(k+1) = Xk + 1 ; y(k+1) = yk + 1,,P(k+1)=pk+2dy-2dx
	        	y=y;            //if(m>1)->if(p<0)->X(k+1) = No change/Xk ; y(k+1) = yk + 1 ; P(k+1)=pk+2dx
	        	pk=pk+2*dy;     //			if(p>=0)->X(k+1) = Xk + 1 ; y(k+1) = yk + 1 ; P(k+1)=pk+2dx-2dy
			}				
			else
			{
				x=x+1;
	        	y=y+1;
	        	pk=pk+2*dy-2*dx;
			}
		}
		if(m>=1){
			if(pk<0)
	        {
	        	x=x;
	        	y=y+1;
	        	pk=pk+2*dx;
			}
			else
			{
				x=x+1;
	        	y=y+1;
	        	pk=pk+2*dx-2*dy;
			}
		}
        
        outtextxy((windowWidth/2)+x0,(windowHeight/2)-y0+10, "Starting point");
        outtextxy((windowWidth/2)+x1+10,(windowHeight/2)-y1-10, "Ending point");    	
	}

    getch();
    closegraph();
}
