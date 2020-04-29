#include"cat.h"

using namespace std;
cat::cat(string na, int ag)
{
	name = na;
	age = ag;
	n = 5;
}
cat::cat()
{
	name = "Eitan";
	age = 10;
	n = 10;
}
/*void cat::init(string na, int ag)
//{
	name = na;	initializing without constructor!!!
	age = ag;
}*/
int cat::getAge()
{
	return age;
}
string cat::getName()
{
	return name;
}
void cat::meow()
{
	cout << "meow!" << endl;
}
void cat::introduce()
{
	meow();
	cout << "My name is " << name << " and I'm " << age << " years old" << endl;
}
