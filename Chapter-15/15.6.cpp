#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int tripleCallByValue(int count)
{
	return count * 3;
}

void tripleByReference(int & count) 
{
	count = count * 3;
}


int main() 
{
	int count;
	cout << "Enter num:";
	cin >> count;
	cout << "Result count before tripleCallByValue = " << count;
	tripleCallByValue(count);
	cout << "\nResult count after run tripleCallByValue = " << count;
	cout << "\nResult count before tripleByReference = " << count;
	tripleByReference(count);
	cout << "\nResult count after run tripleByReference = " << count << endl;
	return 0;
}