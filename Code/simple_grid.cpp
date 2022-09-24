#include<graphics.h>
#include<iostream>
using namespace std;

void plotgraph(int windowWidth,int windowHeight){
	for(int i = 25;i<windowWidth;i=i+25){
		if(i == windowWidth/2){
			setcolor(RED);
			line(i,0,i,windowHeight);
		}else{
			setcolor(WHITE);
			line(i,0,i,windowHeight);
		}		
	}	
}

int main(){
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth/1.3, screenHeight/1.3, "", 1, 5);
	plotgraph(screenWidth/1.3, screenHeight/1.3);
	
	getch();
	closegraph();
}
