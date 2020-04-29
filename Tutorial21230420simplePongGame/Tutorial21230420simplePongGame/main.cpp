<<<<<<< HEAD
#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>

using namespace std;
enum eDir{STOP = 0, LEFT = 1, UPLEFT=2,DOWNLEFT=3,RIGHT=4,UPRIGHET=5,DOWNRIGHET=6};
class cBall
{
private:
	int x, y;
	int origionalX, origionalY;
	eDir direction;

public:
	cBall(int posX, int posY)
	{
		origionalX = posX;
		origionalY = posY;
		x = posX; y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = origionalX;	y = origionalY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDir() { return direction; }
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case RIGHT:
			x++;
			break;
		case UPRIGHET:
			x++; y--;
			break;
		case DOWNRIGHET:
			x++; y++;
			break;
		default:
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};
class cPaddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPaddle()
	{
		x = y = 0;// originalX = originalY;
	}
	cPaddle(int posX, int posY):cPaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY(){ return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
	friend ostream& operator<<(ostream& o, cPaddle c)
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}
};
class cGameManager
{
private:

	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle* player2;

public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 ='i';
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w; height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w-2, h / 2 - 3);
	}
	~cGameManager()
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle* player)
	{
		if (player == player1)score1++;
		else if (player == player2)score2++;
		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
		//Sleep(10);
		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "\xb2";
		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY();

				if (j == 0)
					cout << "\xb2";

				if (ballx == j && bally == i)
					cout << "\x6f";//ball drawing
				else if (player1x == j && player1y == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y == i)
					cout << "\xdb";//player2 paddle

				else if (player1x == j && player1y+1 == i)
					cout << "\xdb";//player1 paddle
				else if (player1x == j && player1y+2 == i)
					cout << "\xdb";//player1 paddle
				else if (player1x == j && player1y+3 == i)
					cout << "\xdb";//player1 paddle

				else if (player2x == j && player2y + 1 == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y + 2 == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y + 3 == i)
					cout << "\xdb";//player1 paddle

				else
					cout << " ";

				if (j == width - 1)
					cout << "\xb2";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;
		cout <<"Score 1: "<< score1<<"                      Score 2: "<<score2<<endl;

	}
	void Input()
	{
		ball->Move();

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		if (_kbhit())
		{
			char current = _getch();
			if (current == up1)
				if (player1y > 0)
					player1->moveUp();
			if (current == up2)
				if (player2y > 0)
					player2->moveUp();
			if (current == down1)
				if (player1y+4<height)
					player1->moveDown();
			if (current == down2)
			if (player2y+4 < height)
				player2->moveDown();

			if (ball->getDir() == STOP)
				ball->randomDirection();

			if (current == 'q')
				quit=true;
		}
	}
	void Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();
		
		//Left paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player1x + 1)
				if (bally == player1y + i)
					ball->changeDirection((eDir)((rand() % 3) + 4));

		//Right paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player2x - 1)
				if (bally == player2y + i)
					ball->changeDirection((eDir)((rand() % 3) + 1));
		//bottom wall
		if (bally == height - 1)
			ball->changeDirection(ball->getDir() == DOWNRIGHET ? UPRIGHET : UPLEFT);
		//top wall
		if (bally == 0)
			ball->changeDirection(ball->getDir() == UPRIGHET ? DOWNRIGHET : DOWNLEFT);
		//right wall
		if (ballx == width - 1)
			ScoreUp(player1);
		//left wall
		if (ballx == 0)
			ScoreUp(player2);
	}
	void Run()
	{
		int speed;
		cout << "player 1 up key - w, down key - s" << endl;
		cout << "player 2 up key - i, down key - k" << endl;
		cout << "press q to quit the game" << endl;
		cout << "enter game speed: "; cin >> speed;
		while (!quit)
		{
			Draw();
			Sleep(speed);
			Input();
			Logic();
		}
	}
};

int main()
{/*
	cBall c(0, 0);
	cout << c << endl;
	c.randomDirection();
	cout << c << endl;
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;*/
	/*cPaddle p1(0, 0), p2(10, 0);
	cout << p1 << endl;
	cout << p2 << endl;
	p1.moveUp();
	p2.moveDown();
	cout << p1 << endl;
	cout << p2 << endl;*/
	cGameManager g(40, 20);
	//g.Draw();
	g.Run();
	getchar();
	return 0;
=======
#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>

using namespace std;
enum eDir{STOP = 0, LEFT = 1, UPLEFT=2,DOWNLEFT=3,RIGHT=4,UPRIGHET=5,DOWNRIGHET=6};
class cBall
{
private:
	int x, y;
	int origionalX, origionalY;
	eDir direction;

public:
	cBall(int posX, int posY)
	{
		origionalX = posX;
		origionalY = posY;
		x = posX; y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = origionalX;	y = origionalY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDir() { return direction; }
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case RIGHT:
			x++;
			break;
		case UPRIGHET:
			x++; y--;
			break;
		case DOWNRIGHET:
			x++; y++;
			break;
		default:
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};
class cPaddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPaddle()
	{
		x = y = 0;// originalX = originalY;
	}
	cPaddle(int posX, int posY):cPaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY(){ return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
	friend ostream& operator<<(ostream& o, cPaddle c)
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}
};
class cGameManager
{
private:

	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle* player2;

public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 ='i';
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w; height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w-2, h / 2 - 3);
	}
	~cGameManager()
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle* player)
	{
		if (player == player1)score1++;
		else if (player == player2)score2++;
		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
		//Sleep(10);
		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "\xb2";
		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY();

				if (j == 0)
					cout << "\xb2";

				if (ballx == j && bally == i)
					cout << "\x6f";//ball drawing
				else if (player1x == j && player1y == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y == i)
					cout << "\xdb";//player2 paddle

				else if (player1x == j && player1y+1 == i)
					cout << "\xdb";//player1 paddle
				else if (player1x == j && player1y+2 == i)
					cout << "\xdb";//player1 paddle
				else if (player1x == j && player1y+3 == i)
					cout << "\xdb";//player1 paddle

				else if (player2x == j && player2y + 1 == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y + 2 == i)
					cout << "\xdb";//player1 paddle
				else if (player2x == j && player2y + 3 == i)
					cout << "\xdb";//player1 paddle

				else
					cout << " ";

				if (j == width - 1)
					cout << "\xb2";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;
		cout <<"Score 1: "<< score1<<"                      Score 2: "<<score2<<endl;

	}
	void Input()
	{
		ball->Move();

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		if (_kbhit())
		{
			char current = _getch();
			if (current == up1)
				if (player1y > 0)
					player1->moveUp();
			if (current == up2)
				if (player2y > 0)
					player2->moveUp();
			if (current == down1)
				if (player1y+4<height)
					player1->moveDown();
			if (current == down2)
			if (player2y+4 < height)
				player2->moveDown();

			if (ball->getDir() == STOP)
				ball->randomDirection();

			if (current == 'q')
				quit=true;
		}
	}
	void Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();
		
		//Left paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player1x + 1)
				if (bally == player1y + i)
					ball->changeDirection((eDir)((rand() % 3) + 4));

		//Right paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player2x - 1)
				if (bally == player2y + i)
					ball->changeDirection((eDir)((rand() % 3) + 1));
		//bottom wall
		if (bally == height - 1)
			ball->changeDirection(ball->getDir() == DOWNRIGHET ? UPRIGHET : UPLEFT);
		//top wall
		if (bally == 0)
			ball->changeDirection(ball->getDir() == UPRIGHET ? DOWNRIGHET : DOWNLEFT);
		//right wall
		if (ballx == width - 1)
			ScoreUp(player1);
		//left wall
		if (ballx == 0)
			ScoreUp(player2);
	}
	void Run()
	{
		int speed;
		cout << "player 1 up key - w, down key - s" << endl;
		cout << "player 2 up key - i, down key - k" << endl;
		cout << "enter game speed: "; cin >> speed;
		while (!quit)
		{
			Draw();
			Sleep(speed);
			Input();
			Logic();
		}
	}
};

int main()
{/*
	cBall c(0, 0);
	cout << c << endl;
	c.randomDirection();
	cout << c << endl;
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;*/
	/*cPaddle p1(0, 0), p2(10, 0);
	cout << p1 << endl;
	cout << p2 << endl;
	p1.moveUp();
	p2.moveDown();
	cout << p1 << endl;
	cout << p2 << endl;*/
	cGameManager g(40, 20);
	//g.Draw();
	g.Run();
	getchar();
	return 0;
>>>>>>> 4c5b27536dc1bf89920bed1b34e33bcbf1b120b4
}