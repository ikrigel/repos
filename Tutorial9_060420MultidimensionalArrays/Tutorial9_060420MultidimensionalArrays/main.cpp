#include<iostream>
#include<ctime>

using namespace std;


void print(int array[3][3][3])
{
    int i,ii,iii;
    for (i = 0; i < 3; i++)
    {
        for (ii = 0; ii < 3; ii++)
        {
            for (iii = 0; iii < 3; iii++)
            {
                if (iii == 2)
                {
                    cout << "element in position " << i << "," << ii << "," << iii << " : " << array[i][ii][iii];
                    cout << endl;
                }
                else
                {
                    cout << "element in position " << i << "," << ii << "," << iii << " : " << array[i][ii][iii]<<" , " ;
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        cout << "Element in dim " << i << " :"<<endl;
        for (ii = 0; ii < 3; ii++)
        {
            for (iii = 0; iii < 3; iii++)
            {
                if (iii == 2)
                {
                    cout << array[i][ii][iii];
                    cout << endl;
                }
                else if (iii<2)
                {
                    cout << array[i][ii][iii]<<",";
                }
            }
        }
    }
}
int main()
{
    int randNum, i, ii, iii,arr[3][3][3];
    char yn;
    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number between 1 and 100: 
    randNum = rand() % 100 + 1;*/
    while (true)
    {

        for (i = 0; i < 3; i++)
        {
            for (ii = 0; ii < 3; ii++)
            {
                for (iii = 0; iii < 3; iii++)
                {
                    randNum = rand() % 100 + 1;
                    arr[i][ii][iii] = randNum;
                }

            }
        }
        print(arr);
        cout << "for exit enter y" << endl;
        cin >> yn;
        if (yn == 'y') break;
    }
    cout << "Goodbay Maor matoki" << endl;
	system("pause");
	return 0;
}