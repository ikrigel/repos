#include<iostream>

using namespace std;
int main()
{
	int a, *p;
	a = 10;
	p = &a;
	int* b = new int;//Dynamic memory reserved on the hip when we use the *new* word. 
	*b = (*p) * 10;
	
	cout << "The value of b: " << *b << endl;
	cout << "The value of p: " << *p<<endl;
	cout << "The adress of p is: " << p << endl;
	//cout << "The adress of p after deleteing is: " << p << endl;//will cause an exception
	//cout << "The value of p after deleteing is: " << *p << endl;//will cause an exception
	cout << "size of bool: " << sizeof(bool) << endl;
	cout <<"size of int: " <<sizeof(int) << endl;
	cout << "size of int a: " << sizeof(a) << endl;
	cout << "size of double: " << sizeof(double) << endl;
	cout << "size of char: " << sizeof(char) << endl;
	cout << "size of string: " << sizeof(string) << endl;
	//delete p;//Delete pointers on the hip when I stop using them, in order to avoide memory licks.
	getchar();
	system("pause");
	return 0;
}