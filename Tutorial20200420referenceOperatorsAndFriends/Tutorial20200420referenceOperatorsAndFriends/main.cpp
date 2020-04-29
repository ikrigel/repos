#include<iostream>
//void increase(int* p)
//{
//	(*p)++;//instead of pointers I'll use the same function with reference
//}
void increase(int &p)
{
	p++;
}
using namespace std;
int main()
{
	int a = 10;
	cout << a << endl;
	//increase(&a); //this is for a function with pointer
	increase(a); //this is for function with reference
	cout <<"a after increament: "<< a << endl;
	cout << "Hello" << endl;
	getchar();
	system("pause");
	return 0;
}