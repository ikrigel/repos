#include<iostream>

using namespace std;
int main()
{
	int  N,b=0;//A[100]
	cout << "enter number of elements: ";
		cin >> N;
		int * A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cout << "--------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		b++;
		cout<<"Element #"<<b<<": "<< A[i]<<endl;
	}
	delete[] A;
	getchar();
	system("pause");
	return 0;
}