#include <iostream>

using std::cout;
using std::cin;
using std::endl;


template <class T>
T min(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	else return val2;
}


int main()
{
	cout << "Result min(2, 3) = " << min(2, 3);
	cout << "\nResult min(2.3, 0.3) = " << min(2.3, 0.3);
	cout << "\nResult min('1', '0') = " << min('1', '0') << endl;
	return 0;
}