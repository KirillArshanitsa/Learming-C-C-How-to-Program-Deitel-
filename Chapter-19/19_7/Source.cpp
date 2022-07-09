#include "String.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	String str1("2");
	String str2("_1");

	cout <<"\nResult + : "<< endl;
	cout << str1 + str2 << endl;

	return 0;
}