#include<iostream>

using namespace std;
char arr[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';// , player2 = 'O';
int n;

void initArr()
{
	/*int length = 9;
	int letter = 1;
	char a = '1';
	
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			a ='0'+ letter;
			arr[i][j] = { a };
			letter++;
		}
	}*/
	arr[0][0] = '1'; arr[0][1] = '2'; arr[0][2] = '3';
	arr[1][0] = '4'; arr[1][1] = '5'; arr[1][2] = '6';
	arr[2][0] = '7'; arr[2][1] = '8'; arr[2][2] = '9';
}
void printArr()
{
	system("cls");
	cout << "Tic Tac Toe v1.0" << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			if (j < 2 && i < 2)
			{
				cout << "_" << arr[i][j] << "_ |" << " ";
			}
			if (i < 2 && j == 2)
			{
				cout << "_" << arr[i][j] << "_";
			}
			if (i == 2 && j < 2)
			{
				cout << " " << arr[i][j] << "  |" << " ";
			}
			if (i == 2 && j == 2)
			{
				cout << " " << arr[i][j];
			}
			/*if( i==2 )
			{
				cout<<" "<< arr[i][j]<<" |" ;
			}*/
		}
		cout << endl;
		//if (i % module(3) == 0) endl;
	}

}
void input()
{
	int number;
	cout <<"Player '"<<player <<"' press the number of the field you want to select" << endl;
	cin >> number;
	if (number == 1)
	{
		if (arr[0][0] == '1')
		{
			arr[0][0] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}
		
	}
	
	else if (number == 2)
	{
		if (arr[0][1] == '2')
		{
			arr[0][1] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
	else if (number == 3)
	{
		if (arr[0][2] == '3')
		{
			arr[0][2] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
		
	else if (number == 4)
	{
		if (arr[1][0] == '4')
		{
			arr[1][0] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
		
	else if (number == 5)
	{
		if (arr[1][1] == '5')
		{
			arr[1][1] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
	else if (number == 6)
	{
		if (arr[1][2] == '6')
		{
			arr[1][2] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
	else if (number == 7)
	{
		if (arr[2][0] == '7')
		{
			arr[2][0] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
	else if (number == 8)
	{
		if (arr[2][1] == '8')
		{
			arr[2][1] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
	else if (number == 9)
	{
		if (arr[2][2] == '9')
		{
			arr[2][2] = player;
		}
		else
		{
			cout << "select a different number" << endl;
			input();
		}

	}
}
void togglePlayer()
{
	if (player == 'X')
		player = 'O';
	else (player = 'X');
}
char win()
{
	if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')
		return 'O';
	if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')
		return 'O';
	if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')
		return 'O';
	if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')
		return 'O';
	if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')
		return 'O';
	if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')
		return 'O';
	if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
		return 'O';
	if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
		return 'O';
	if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')
		return 'X';
	if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')
		return 'X';
	if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')
		return 'X';
	if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')
		return 'X';
	if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')
		return 'X';
	if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')
		return 'X';
	if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
		return 'X';
	if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
		return 'X';
	return '/';
}
//void cleanArr()
//{
//	char arr[3][3] = { '1','2','3','4','5','6','7','8','9' };
//}
int main()
{
	n = 0;
	//char arr[3][3] = { '1','2','3','4','5','6','7','8','9' };
	char t = 'q', out = 'q';
	printArr();
	while (true)
	{


		while (true)
		{
			n++;
			input();
			printArr();
			t = win();
			if (t == 'X' || t == 'O')
			{
				cout << t << " is the winner" << endl;
				//cout << "If you would like to play again write 'y' " << endl;
				//cin >> out;
				//if (out != 'y')break;
				//cleanArr();
				break;
			}
			else if (win() == '/' && n == 9)
			{
				cout << "It's a draw!!!" << endl;
				break;
			}

			togglePlayer();
		}
		cout << "If you would like to play again type y" << endl;
		cin >> t;
		if (t != 'y')break;
		else
		initArr();
		printArr();
		n = 0;
	}
	system("pause");
	return 0;
}