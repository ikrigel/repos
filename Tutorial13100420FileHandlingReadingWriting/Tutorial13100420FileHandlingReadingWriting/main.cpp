#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
	ofstream writer("file1.txt"), iWrite("file2.txt"),iwrite3("file3.txt");
	string fileName= "file3.txt";
	ifstream reader(fileName);
	int a, b,c,d;
	if (writer.is_open() && iWrite.is_open()&& iwrite3.is_open())
	{
		int children = 4;
		cout << "enter number of children : "; cin >> children;
		writer << "Hello file!!!" << endl;
		iWrite << "Love C++!!!" << endl;
		writer << "Maor matoki!!" << endl;
		writer << "There are " << children << " children" << endl;
		iWrite << "Maor matoki!!" << endl;
		iWrite << "There are " << children << " children" << endl;
		a = 8; b = 5;
		iwrite3 << a<<endl; iwrite3 << b<<endl;
		iwrite3 << "9 90" << endl;
		cout << "files where written succecfully!!!" << endl;
	}
	else
	{
		cout << "error writing into files" << endl;
	}
	if (reader.is_open())
	{
		reader >> a >> b;
		reader >> c >> d;
		cout << "reading file "<<fileName <<" was succesful" << endl;
		cout << "Sum of variables a and b is: " << a + b << endl;
		cout << "Sum of C + D = " << c + d << endl;
		if (iwrite3.is_open())
		{
			iwrite3 << "Sum of C + D = " << c + d << endl;
		}
		else
		{
			cout << "error opening file: " << fileName << endl;
		}
	}
	else
	{
		cout << "Problem reading file " << fileName << endl;
	}
	reader.close();
	writer.close();
	iWrite.close();
	iwrite3.close();


	system("pause");
	return 0;
}