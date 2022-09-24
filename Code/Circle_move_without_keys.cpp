#include<graphics.h>
#include<iostream>
using namespace std;

int main(){
	
	//int gd=DETECT,gm;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	cout<<screenWidth<<screenHeight;
	initwindow(screenWidth/1.5,screenHeight/1.5);
	
	for(int i = 0;i<screenHeight/1.5-100;i++){
		circle(100+i,200+i,100);
		delay(10);
		cleardevice();
	}
	
	getch();
}
