#include <bits/stdc++.h>
#include <graphics.h>
#define UP VK_UP 
#define DOWN VK_DOWN
#define RIGHT VK_RIGHT
#define LEFT VK_LEFT

using namespace std;
class chip 
{
	private:
		double x,y,w;
		char str[2];
	public:
		chip(double,double,double,int);
		void show();
		void hide();
		void move(double,double);
};
class field 
{
	private:
		chip*chips[8];
		int pos[3][3];
		double x,y,w,f;
		int zeroX,zeroY;
	public:
		field(double,double,double);
		~field();
		void show();
		void shake();
		void act(int);
};
chip::chip(double xx,double yy,double ww,int n)
{
	x=xx;
	y=yy;
	w=ww;
	sprintf(str,"%2d",n+1);
}
void chip::show()
{
	bar(x,y,x+w,y+w);
	rectangle(x,y,x+w-1,y+w-1);
	outtextxy(x+w/3,y+w/3,str);
}
void chip::hide()
{
	setfillstyle(SOLID_FILL,YELLOW);
	bar(x,y,x+w,y+w);
	setfillstyle(SOLID_FILL,WHITE);
}
void chip::move(double dx,double dy)
{
	hide();
	x+=dx;
	y+=dy;
	show();
}
field::field(double xx,double yy,double ww) 
{
	x=xx+ww/10;
	y=yy+ww/10;
	w=ww*4/5;
	f=ww/10;
	for(int i=0;i<3;i++)
		for (int j=0; j<3&&i*j<4;j++)
		{
			chips[i*3+j]=new chip(x+j*w/3,y+i*w/3,w/3,i*3+j);
			pos[i][j]=i*3+j;
		}
	pos[2][2]=0;
	zeroX=2; 
	zeroY=2;
}
field::~field(){ for (int i=0; i<8;i++) delete chips[i]; }
void field::show()
{
	setfillstyle(SOLID_FILL,YELLOW);
	bar(x-f,y-f,x+w+f,y+w+f);
	rectangle(x-f,y-f,x+w+f-1,y+w+f-1);
	rectangle(x-1,y-1,x+w,y+w);
	setfillstyle(SOLID_FILL,WHITE);
	for(int i=0;i<8;i++)
		chips[i]->show();
}

void field::act(int key)
{
	
	double frames=10,dx=0,dy=0;
	int i;
	if (key==DOWN&&zeroY!=0) 
	{
		dy=w/3/frames; 
		i=pos[zeroY-1][zeroX];
		pos[zeroY][zeroX]=pos[zeroY-1][zeroX];
		pos[zeroY-1][zeroX]=0;
		zeroY--;
	}
	else if (key==UP&&zeroY!=2)
	{
		dy=-w/3/frames;
		i=pos[zeroY+1][zeroX];
		pos[zeroY][zeroX]=pos[zeroY+1][zeroX];
		pos[zeroY+1][zeroX]=0;
		zeroY++;
	}
	else if (key==RIGHT&&zeroX!=0)
	{
		dx=w/3/frames;
		i=pos[zeroY][zeroX-1];
		pos[zeroY][zeroX]=pos[zeroY][zeroX-1];
		pos[zeroY][zeroX-1]=0;
		zeroX--;
	}
	else if (key==LEFT&&zeroX!=2)
	{
		dx=-w/3/frames;
		i=pos[zeroY][zeroX+1];
		pos[zeroY][zeroX]=pos[zeroY][zeroX+1];
		pos[zeroY][zeroX+1]=0;
		zeroX++;
	} else return;
	for(double j=0;j<frames;j++) 
	{
		chips[i]->move(dx,dy);
		delay(20);
	}
}

int main()
{
	srand(time(NULL));
	field F(150,90,280);
	
	
	initwindow(640,480);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	
	
	
	/*int gdriver = DETECT, gmode;
 	initgraph(&gdriver,&gmode,"");*/
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT,0,2);
	F.show();
	while(true) 
	{
		getch();
		if (GetKeyState(UP)<0) F.act(UP);
		if (GetKeyState(DOWN)<0) F.act(DOWN); 
		if (GetKeyState(RIGHT)<0) F.act(RIGHT);
		if (GetKeyState(LEFT)<0) F.act(LEFT);
	}
	
	return 0;
}
