#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>
using namespace std;

int tlx,tly,brx,bry,px,py;

int width = GetSystemMetrics(SM_CXSCREEN);
int height = GetSystemMetrics(SM_CYSCREEN);
void point_clip()
{
    int wxmin,wymin,wxmax,wymax;
    wxmin=tlx;
    wxmax=brx;
    wymin=tly;
    wymax=bry;
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    if(px>=wxmin&&px<=wxmax)
        if(py>=wymin&&py<=wymax){
        	cout<<"The point is inside the clip window\n";
            circle(px,py,3);
            floodfill(px,py,YELLOW);
        }
        else
        	cout<<"The point is outside the clip window \nThe point is clipped\n ";
    else
        cout<<"The point is outside the clip window \nThe point is clipped\n ";
    getch();
    closegraph();
}
int main()
{
    printf("Enter the top left coordinate: ");
    scanf("%d%d",&tlx,&tly);
    printf("Enter the bottom right coordinate: ");
    scanf("%d%d",&brx,&bry);
    printf("\n Enter the point: ");
    scanf("%d%d",&px,&py);
    initwindow(width-20, height-20, "", -3, -3);
    setbkcolor(BLUE);
    setcolor(MAGENTA);
    rectangle(tlx,tly,brx,bry);
    point_clip();
}
