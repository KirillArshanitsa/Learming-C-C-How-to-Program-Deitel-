#include"RationalNumber.h"
#include<iostream>

using namespace::std;

int main()
{
	//cout << 38 % 3 << endl;
	//cout << 2 % 3 << endl;
	//RationalNumber r1(18, 30);
	RationalNumber r1(5, 7);
	RationalNumber r2(5, 7);
	//r1 * r2;
	//r1.print();
	bool a = r1 >= r2;
	//bool b = r1 < r2;

	cout << a << endl;
	//cout << b << endl;
	return 0;
}