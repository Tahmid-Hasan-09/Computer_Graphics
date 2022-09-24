#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

void countm(int *co_mo,int* inc) // co_mo : count move
{
    *inc+=5;
    settextstyle(0,HORIZ_DIR,0);
    setcolor(14);
    outtextxy(515,198,"MOVE");
    char arr[50];
    sprintf(arr,"%d",*co_mo);
    setcolor(3);
    outtextxy(520,220,arr);
    *co_mo=*co_mo+1;
}

void body() //figure
{
    setcolor(3);
    
    //Border
    line(0,5,650,5);
    line(0,475,650,475);
    line(2,0,2,475);
    line(635,0,635,475);
    
    //horizontal line
    line(0,100,450,100);  
    line(50,130,400,130);
    line(100,160,450,160);
    line(150,190,300,190);
    line(100,220,250,220);
    line(50,250,200,250);
    line(0,400,500,400);
    line(450,370,500,370);
    
    //vertical line
    line(0,100,0,400); 
    line(50,130,50,370);
    line(100,160,100,220);
    line(100,280,100,400);
    line(150,250,150,370);
    line(200,280,200,400);
    line(250,220,250,370);
    line(300,190,300,400);
    line(350,160,350,370);
    line(400,190,400,400);
    line(450,100,450,370);
    
    setcolor(14);
    circle(500,385,10);
    setcolor(WHITE);
}
int ball(int j,int k,int l)   //ball
{
    circle(j,k,l);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,14);
    floodfill(j,k,WHITE);
}
void condition(int *j,int *k, int *chk)
{
    if(*k==110)
    {
        if(*j<450 && *j>0) {
            *chk = 0;
        }
    }
    if(*j==10)
    {
        if(*k<400 && *k>100)
            *chk = 0;
    }
    if(*k==390)
    {
        if(*j<500 &&* j>0)
            *chk = 0;
    }
    if(*j==440)
    {
        if(*k>100 && *k<380)
            *chk = 0;
    }
    if(*k==380)
    {
        if(*j<500&& *j>440)
            *chk = 0;
    }
    if(*k>=120 && *k<=140 )
    {
        if(*j<410 && *j>40 && *k<=130)
            *chk = 0;
        if(*j<410 && *j>40 && *k>=130)
            *chk = 0;
    }
    if(*k>=150 && *k<=170 && *j>=90 &&* j<=450)
    {
        if(*k<=160) 
        *chk = 0;
    }
    if(*k>=180&&*k<=200&&*j>=140&&*j<=310)
    {
        if(*k>=190 ) 
        *chk = 0;
    }
    if(*k>=210&&*k<=230&&*j>=90&&*j<=260)
    {
        if(*k>=220) 
        *chk = 0;
    }
    if(*k<=260 && *k>=240 && *j<=210&& *j>40)
    {
        if(*k>=250) 
        *chk = 0;
    }
    if(*k<=370&&*k>=130&&*j<=60&&*j>=40)
    {
        if(*j<=50) 
        *chk = 0;
    }
    if(*k<=220&&*k>=160&&*j<=110&&*j>=90)
    {
        if(*j<=100)
        *chk = 0;
    }
    if(*k<=400&&*k>=280&&*j<=110&&*j>=90)
    {
        if(*j<=100) 
        *chk = 0;
    }
    if(*k<=370&&*k>=250&&*j<=160&&*j>=140)
    {
        if(*j<=150)
        *chk = 0;
    }
    if(*k<=400&&*k>=280&&*j<=210&&*j>=190)
    {
        if(*j<=200) 
        *chk = 0;
    }
    if(*k<=370&&*k>=220&&*j<=260&&*j>=240)
    {
        if(*j<=250) 
        *chk = 0;
    }
    if(*k<=400&&*k>=190&&*j<=310&&*j>=290)
    {
        if(*j<=300) 
        *chk = 0;
    }
    if(*k<=370&&*k>=160&&*j<=360&&*j>=340)
    {
        if(*j<=350)
        *chk = 0;
    }
    if(*k<=400&&*k>=190&&*j<=410&&*j>=390)
    {
        if(*j<=400) 
        *chk = 0;
    }
}

int start(int *p)
{
    int i,j=20,k=250,l=10,m=10,co_mo=0,inc=0, chk=1111;
    char c;
    cleardevice();

    body();          //draw the figure
    ball(j,k,l);     //draw the  ball

    countm(&co_mo,&inc);
    for(i=0; i<m++; i++)
    {
        condition(&j,&k,&chk); //cheacking condition
        if(chk == 0) {
        	setcolor(RED);
        	settextstyle(10,HORIZ_DIR,5);
        	outtextxy(220,240,"GAME OVER");
        	delay(3000);
        	settextstyle(0,HORIZ_DIR,0);
        	cleardevice();
        	char arr[50];
        	sprintf(arr,"%d",co_mo);
    		setcolor(14);
    		outtextxy(240,240,"Your Score is: ");
    		setcolor(3);
    		outtextxy(320,270,arr);
            delay(5000);
			return 0;
		}
        countm(&co_mo,&inc);
        c=getch();
        cleardevice();
        if(c==75||c=='a') j-=5;
        if(c==80||c=='s') k+=5;
        if(c==77||c=='d') j+=5;
        if(c==72||c=='w') k-=5;
        if(c==' ') return 0;
        *p=co_mo;
        body();        //draw the figure
        ball(j,k,l);   //draw the ball
        if(j>=500) {
        	setcolor(GREEN);
        	settextstyle(10,HORIZ_DIR,5);
        	outtextxy(160,240,"Congratulations!");
        	delay(3000);
        	settextstyle(0,HORIZ_DIR,0);
        	cleardevice();
        	char arr[50];
        	sprintf(arr,"%d",co_mo);
    		setcolor(14);
    		outtextxy(240,240,"Your Score is: ");
    		setcolor(3);
    		outtextxy(320,270,arr);
            delay(5000);
			return 1;
		} 
    }

    return 9999;
}
int main()
{
    int d=DETECT,g;
    int flag,point=0;
    initgraph(&d,&g,"C:\\TURBOC3\\BGI");
    
    //setaspectratio(1600, 900);
    flag=start(&point);

    getch();
    closegraph();
    return flag;
}
