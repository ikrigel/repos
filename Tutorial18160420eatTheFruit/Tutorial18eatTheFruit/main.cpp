#include<iostream>
#include<time.h>
#include<conio.h>
#include<chrono>
#include<thread>

using namespace std;
bool gameOver;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score, speed;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup()
{
	cout << "Enter game speed: ";
	cin >> speed;
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(NULL));
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	cout << "Game score is " << score << endl;
	for (int i = 0; i < width + 2; i++)
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
			else cout << " "; //(j > 0 && j < width - 1) cout << " ";
			if (j == width - 1)cout << "#" << endl;
		}

	}

	for (int i = 0; i < width + 2; i++)
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
	if (x > width - 1 || x<0 || y>height - 1 || y < 0)
	{
		gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
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
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
		cout << "If you want to exit again press 'y' ";
		cin >> yn;
	}
	system("pause");
	return 0;
}