#include<iostream>
#include<string>
using namespace std;
class cat
{
private:
	int age, n;
	string name;
	void meow();
public:
	cat(string na, int ag);
	cat();
	int getAge();
	string getName();
	//void init(string na, int ag);
	void introduce();
	int getN() { return n; };
};