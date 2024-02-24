#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#define UPB 20
#define LFB 20
#define DNB 300
#define RTB 300
int snakeposx=23, snakeposy=23;
int p=0;
int dir=6;
void goup()
{
	dir=8;
}
void godown()
{
	dir=2;
}
void goleft()
{
	dir=4;
}
void goright()
{
	dir=6;
}
void pause()
{
	if(p)
	{
		p=0;
	}
	else
	{
		p=1;
		while(getch()!='p'){}
	}
}
void snakemove()
{
     switch(dir)
     {
	case 6:
	snakeposx+=5;
	break;
	case 8:
	snakeposy-=5;
	break;
	case 2:
	snakeposy+=5;
	break;
	case 4:
	snakeposx-=5;
	break;
     }

}
int isGameOver()
{
	if(snakeposx>LFB && snakeposx<RTB && snakeposy>UPB && snakeposy<DNB)
	{
		return 1;
	}
	return 0;
}
void snake(int c1,int c2)
{
	setcolor(15);
	circle(c1,c2,2);
}
void setBoard()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:/TURBOC3/BGI/");
	setcolor(10);
	rectangle(UPB,LFB,DNB,RTB);

}
void board()
{
	setfillstyle(SOLID_FILL,0);
	int poly[]= {UPB,LFB,UPB,RTB,DNB,RTB,DNB,LFB};
	fillpoly(4,poly);
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w':goup();break;
			case 's':godown();break;
			case 'd':goright();break;
			case 'a':goleft();break;
			case 'p':pause();
			    break;

		}
	}
}

void main()
{
	clrscr();
	setBoard();
	while(isGameOver())
	{
		board();
		snake(snakeposx,snakeposy);
		delay(200);
		input();
		snakemove();
	}
	getch();
	closegraph();
}