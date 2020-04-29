#include<iostream>
using namespace std;
class Dummy
{
private:
	int value;
public:
	Dummy()
	{
		value = 0;
	}
	Dummy(int val)
	{
		value = val;
	}
	Dummy operator+(Dummy a)
	{
		cout << "Addition occurd!" << endl;
		return Dummy(this->value+a.value);
	}
	Dummy operator-(Dummy a)
	{
		cout << "Subtruction occurd!" << endl;
		return Dummy(this->value - a.value);
	}
	Dummy operator*(Dummy a)
	{
		cout << "Multiplication occurd!" << endl;
		return Dummy(this->value * a.value);
	}
	friend ostream& operator<<(ostream& o, Dummy a)
	{
		o << a.value;
		return o;
	}
	friend istream & operator>>(istream& o, Dummy & a)
	{
		o >> a.value;
		return o;
	}
	inline int getValue() { return value; }
};


int main()
{
	Dummy a(5);
	Dummy b = 10;
	Dummy c = a + b;
	cout << c.getValue() << endl;
	c = a - b;
	cout << c.getValue() << endl;
	c = a.operator*(b);
	cout << c.getValue() << endl;
	cout << "using friend for printing: " << c<<endl;
	cout << "using friend for inserting value: " << c<<endl;
	cin >> c;
	//c = a.getValue();
	cout << "using friend for printing after inserting value: " << c<<endl;

	getchar();
	system("pause");
	return 0;
}