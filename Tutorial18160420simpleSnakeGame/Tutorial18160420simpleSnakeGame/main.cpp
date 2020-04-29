#include<iostream>
#include<time.h>
#include<conio.h>
#include<chrono>
#include<thread>
#include<Windows.h>

using namespace std;
bool gameOver;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score,speed;
int tailX[100], tailY[100], nTail;
enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	cout << "Enter game speed: ";
	cin >> speed;
	if (speed == NULL)speed = 100;
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(NULL));
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	nTail = 0;
	
	
}
void Draw()
{
	system("cls");
	cout << "Game score is " << score<<endl;
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
					
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)cout << "#";
			if (i == y && j == x)cout << "O";
			else if (i == fruitY && j == fruitX)cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
										
				}
				if (!print)
					cout << " ";
				
			}
			if (j == width - 1)cout << "#" << endl;
		}
		
	}
	
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;

}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
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
		case 'x':
			gameOver = true;
			break;
		}
	}

}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		for (int j = 1; j < nTail; j++)
		{

		}
	}

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
	/*if (x > width-1 || x<0 || y>height-1 || y < 0)
	{
		gameOver = true;
	}*/
	if (x >= width)x = 0; else if (x < 0)x = width - 1;
	if (y >= height)y = 0; else if (y < 0)y = height - 1;
	for (int i = 0; i < nTail ; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	
	if (x == fruitX && y== fruitY)
	{
		
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int main()
{
	
	char yn = 'q';
		while (yn != 'y')
		{

			Setup();
			while (!gameOver)
			{
				Draw();
				Input();
				Logic();
				Sleep(speed);
				//this_thread::sleep_for(chrono::milliseconds(speed));
			}
			cout << "If you want to exit again press 'y' ";
			cin >> yn;
		}
	system("pause");
	return 0;
}