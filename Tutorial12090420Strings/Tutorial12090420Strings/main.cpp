#include<iostream>
#include<ctime>
#include<string>

using namespace std;
int main()
{
	//C style strings - 
	const char *str = "Hello world!";//In C++ you need to add "const" before the "char *str", since it not allowed to be "unsafe"
	char str2[512] = "Hello Maor matoki!";
	//end of c style strings-
	cout << "C style string pointer to char : "<<endl<<str << endl;
	cout << "C style string array of char : " <<endl<<str2 << endl;
	// C++ strings
	cout << "C++ strings (string librarry) : " << endl;
	string str3 = "Hellow C++ string", str4=" Nice to meet you";
	cout << "string output : " << str3 << endl;
	char a, b, c;
	cout << "string at position 0 : " << str3.at(0) << endl;
	a = str3.at(0);
	b = str3.at(1);
	str3.at(0) = str3.at(2);
	str3.at(1) = a;
	str3.at(2) = b;
	cout << str3 << endl;
	cout << "string at position 0 : "<<str3.at(0) << endl;
	cout << "Appending two strings : " << str3 + str4 << endl;
	cout << "Enter string A and B: " << endl; cin >> str3; cin >> str4;
	str3+= " ";
	cout<< "Appending two strings : " << str3 + str4 << endl;
	cout << "The length of string A is : " << str3.length()<<endl;
	cout << "The length of string B is : " << str4.length() << endl;
	cout << "Appending two strings using append function: " << str3.append(str4) << endl;
	cout << "Insert string in the seconed string character location using insert function: " << str3.insert(2, str4) << endl;
	cout << "replace string character 0 to 3 using replace function: " << str3.replace(0,3,str4) << endl;
	str4 = " Nice to meet you";
	cout << "find -you- string location using find function: " << str4.find("you") << endl;
	cout << "create substring using substring of 5 chars from the 2 char function: " << str4.substr(3,5) << endl;

	system("pause");
	return 0;
}