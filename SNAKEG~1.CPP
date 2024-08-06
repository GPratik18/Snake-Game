#include <iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
//#include<windows.h>
//using namespace std;
int gameOver;
const int width = 50;
const int height = 20;
int x, y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
	gameOver = 0;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = random(width);
	fruitY = random(height);
	score = 0;
}
void Draw()
{
	clrscr();
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (i = 0;i < height;i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
				cout << " ";
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score:  " << score << endl;
}
void Input()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		//case 'x':
		//	gameOver = 1;
		//	break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x<0 || x>width || y<0 || y>height)
		gameOver = 1;
	if (x == fruitX && y == fruitY)
	{
		nTail++;
		score += 10;
		fruitX = random(width);
		fruitY = random(height);
	}
}
int main()
{
	randomize();
	Setup();
	while (!gameOver)
	{
		//delay(400);
		Draw();
		Input();
		delay(400);
		Logic();
	}
	//system("cls");
	cout << "===== GAME OVER ========";
	return 0;
}