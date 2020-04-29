#include<iostream>
using namespace std;
class parent
{
private:
	int varS;
	void printVarS();


public:
	int varP;
	void printVarP();
	parent() { varS = 5; varP = 8; varX = 9; };
protected:
	int varX;
	void PrintVarX() { cout << "varX is " << varP << endl; };
	void SetX(int b) { varX = b; }
};
void parent::printVarS() { cout << "varS is " << varS << endl; }
void parent::printVarP() { cout << "varP is " << varP << endl; }
//void parent::PrintVarX() { cout << "varP is " << varP << endl; }

class child:public parent
{
public:
	void setP(int a) { varP = a; SetX(a); PrintVarX(); };

private:

};
int main()
{
	parent p;
	p.printVarP();
	child c;
	c.printVarP();
	c.setP(3);
	c.printVarP();
	p.printVarP();
	system("pause");
	return 0;
}