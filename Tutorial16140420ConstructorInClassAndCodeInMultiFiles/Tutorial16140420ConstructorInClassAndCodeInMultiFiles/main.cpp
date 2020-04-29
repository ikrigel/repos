#include<iostream>
#include<string>
#include"cat.h"

using namespace std;
//class cat
//{
//private:
//	int age,n;
//	string name;
//	void meow();
//public:
//	cat(string na, int ag);
//	cat();
//	int getAge();
//	string getName();
//	//void init(string na, int ag); ///moved to the header file named "cat .h"
//	void introduce();
//	int getN() { return n; };
//};
//int cat::getN()
//{
//	return n;
//}
//cat::cat(string na, int ag)
//{
//	name = na;
//	age = ag;
//	n = 5;
//}
//cat::cat()
//{
//	name = "Eitan";				///moved to the cpp file named "cat"
//	age = 10;
//	n = 10;
//}
///*void cat::init(string na, int ag)
////{
//	name = na;	initializing without constructor!!!
//	age = ag;
//}*/
//int cat::getAge()
//{
//	return age;
//}
//string cat::getName()
//{
//	return name;
//}
//void cat::meow()
//{
//	cout << "meow!" << endl;
//}
//void cat::introduce()
//{
//	meow();
//	cout << "My name is "<<name<<" and I'm "<<age<<" years old" << endl;
//}
int main()
{
	cat cat1("Maor", 7);
	cat cat2("Nir", 5);
	cat cat3;
	//cat cat1;
	//cat1.init("Maor", 7); - This is a way to initialize the class without constructor
	cat1.introduce();
	cat2.introduce();
	cat3.introduce();
	cout << cat2.getN() << endl;
	system("pause");
	return 0;
}