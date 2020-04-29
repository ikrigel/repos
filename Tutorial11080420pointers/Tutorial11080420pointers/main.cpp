#include<iostream>
#include<ctime>

using namespace std;
int main()
{
	int *p;
	int n = 0,b=0;
	p = &n;
	char yn='n';
	while (yn!='y')
	{
		cout << "enter value for n: "; cin >> n; cout << endl;
		cout << "the value of n is: " << n << " ; the location of n is " << p << " ; the location of p is: " << &p<<endl;
		p = &b;
		cout << "the value of b is: " << b << " ; the location of b is " << p << " ; the value of p is: " << *p << endl;
		p = &n;
		//*p=*p+1;
		(*p)++;
		cout << "the value of p after incrementation of 1 is: " << *p << " ; the location of p is " << p << endl;
		cout << "the value of n is: " << n << " ; the location of n is " << p << " ; the location of p is: " << &p << endl;
		cout << "To exit enter 'y' "; cin >> yn;cout << endl;
	}
	/*cout << "enter value for n :"; cin >> n; cout << endl;
	cout << "the value of n is:" << n << " ; the location of n is " << p << " ; the location of p is: " << &p;*/
	system("pause");
	return 0;
}