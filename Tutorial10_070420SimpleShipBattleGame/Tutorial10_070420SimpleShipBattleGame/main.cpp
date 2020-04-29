#include<iostream>
#include<ctime>
using namespace std;

const int row = 10, column = 10, maxShips = 10;
int arr[row][column];
//int** arr;
int shipsLocation[10];
int mapSize,num;
bool valid = false;
//char yn ='q';



void cleanArr()
{
	for (int i = 0; i < row; i++)
	{
		for (int ii = 0; ii < column; ii++)
		{
			arr[i][ii] = 0;
		}
	}
	//return arr[][];
}
void showArr()
{
	for (int i = 0; i < row; i++)
	{
		cout << " _ _ _ _ _ _ _ _ _ _ " << endl;
		for (int j = 0; j < column; j++)
		{
			if (j == 0)
			{
				cout << "|"<<arr[i][j]<<"|";
			}
			else
			{
				cout << arr[i][j] << "|";
			}
			if (j == (column - 1))cout << endl;
		}
		
	}
	cout << " _ _ _ _ _ _ _ _ _ _" << endl;
	//cout<<

}
void showArrHits()
{
	for (int i = 0; i < row; i++)
	{
		cout << " _ _ _ _ _ _ _ _ _ _ " << endl;
		for (int j = 0; j < column; j++)
		{
			if (j == 0 && arr[i][j]==2)
			{
				cout << "|" << arr[i][j] << "|";
			}
			if (j == 0 && arr[i][j] != 2)
			{
				cout << "|" << " " << "|";
			}
			if (j != 0 && arr[i][j] == 2)
			{
				cout << arr[i][j] << "|";
			}
			if (j != 0 && arr[i][j] != 2)
			{
				cout << " " << "|";
			}
			if (j == (column - 1))cout << endl;
		}

	}
	cout << " _ _ _ _ _ _ _ _ _ _" << endl;
	//cout<<

}
void setShips()
{
	int randNum,s=0;
	/* initialize random seed: */
	srand(time(NULL));
	//int randAmount = mapSize * mapSize;
	
	/* generate secret number between 1 and 10: */
	randNum = rand() % 100;
	while (s<maxShips)
	{
		int x = rand() % row;
		int y = rand() % column;
		if ((arr[x][y]) != 1)
		{
			arr[x][y] = 1;
			s++;
		}
	}
	for (int i = 0; i < maxShips; i++)
	{

	}
}
bool attack(int x,int y)
{
	if (arr[x][y] == 1)
	{
		arr[x][y] = 2;
		cout << "You sunk a ship" << endl;
		return true;
	}
	else
	{
		cout << "you missed" << endl;
		return false;
	}

}
int numberOfShips()
{
	int c = 0;
	for (int i = 0; i < row; i++)
	{
		for (int ii = 0; ii < column; ii++)
		{
			if (arr[i][ii] == 1) c++;
		}
	}
	return c;
}
char checkCharExit()
{
	char yn='n';
	while (!valid)
	{
		valid = true; //Assume the cin will be an integer.
		cout << "if you want to exit type 'y' : " << endl;
		cin >> yn;

		if (cin.fail()) //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter char only." << endl;
			valid = false; //The cin was not an integer so try again.
		}

	}
	valid = false;
	return yn;
}
char checkCharPlayAgain()
{
	char yn='n';
	while (!valid)
	{
		valid = true; //Assume the cin will be an integer.
		cout << "if you want to play again type 'y' : " << endl;
		cin >> yn;

		if (cin.fail()) //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter char only." << endl;
			valid = false; //The cin was not an integer so try again.
		}

	}
	valid = false;
	return yn;
}

int checkInt()
{
	bool flag = 'true';
	int cordinate=0;
	while (!valid)
	{
		valid = true; //Assume the cin will be an integer.

		if (flag == true)cout << "enter cordinate : " << endl;
		cin >> cordinate;

		if (cin.fail() || cordinate>9 || cordinate<0) //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			if (flag == true)cout << "Please enter an Integer only." << endl;
			flag = false;
			valid = false; //The cin was not an integer so try again.
		}

	}
	valid = false;
	return cordinate;
}
void game()
{
	int s = 0,x = 0,y = 0;
	bool attackResult = 0;
	char yn='q';
	while (s<maxShips )
	{
		cout << "enter coordinate x :" << endl;
		x=checkInt();
		//cin >> x;
		//cin >> x;
		cout << "enter coordinate y :" << endl;
		y = checkInt();
		//cin >> y;
		attackResult = attack(x, y);
		if (attackResult == true)
		{
			s++;
			cout << "attack on coordinate " << x << " , " << y << " was succesful"<<endl;
			cout << "number of ships left : " << numberOfShips() << endl;
			//showArr();
			showArrHits();
			/*cout << "if you want to exit type 'y' ";
			cin >> yn;*/
			yn=checkCharExit();
			if (yn == 'y')break;
		}
		if (attackResult == false)
		{
			yn = 'q';
			//showArr();
			cout << "attack on coordinate " << x << " , " << y << " wasn't succesful. Please try again" << endl;
			/*cout << "if you want to exit type 'y' ";
			cin >> yn;*/
			yn=checkCharExit();
			if (yn == 'y')break;
		}
	}

}

int main()
{
	char yn='y';
	while (yn =='y')
	{
			
		//cout << "Enter Max ships : "; cin >> maxShips;
		//cout << "Enter map size : "; cin >> mapSize;
		//row = mapSize; column = mapSize;
		//int *arr = new int[row*column];
		cleanArr();
		//showArr();
		setShips();
		//showArr();
		game();
		//cout << "If you would like to play again write 'y' : ";
		//executes loop if the input fails (e.g., no characters were read)
		//while (cout << "If you would like to play again write 'y' : "&& !(cin >> yn)) {
		//	cin.clear(); //clear bad input flag
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		//	cout << "Invalid input; please re-enter.\n";
		yn=checkCharPlayAgain();
	}
	system("pause");
	return 0;
}