#include<iostream>
#include<string>

using namespace std;
class point
{
public:
	int x, y;
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
	void set(int c, int d)
	{
		a = c;
		b = d;
	}
	void printCordinates(string name)
	{
		cout << "the cordinate of "<<name<< " are (" << a << "," << b << ")" << endl;
	}
private:
	int a, b;
};
int main()
{
	string name1="p1",name2="p2";
	point p1, p2;
	p1.x = 3; p1.y = 4;
	p2.x = 5; p2.y = 6;
	cout <<"p1.x + p2.y = " <<p1.x + p2.y << endl;
	cout << "p1.y + p2.x = " << p1.y + p2.x << endl;
	p1.set(8, 9);
	cout << p1.getA() << " * " << p1.getB() << " = " << p1.getA() * p1.getB() << endl;
	
	p1.printCordinates(name1);
	p2.set(3, 6);
	p2.printCordinates(name2);
	p1 = p2;
	p1.printCordinates(name1);


	system("pause");
	return 0;
}