#include <iostream>

using std::cout;
using std::cin;
using std::endl;


template <class T>
T max(T val1, T val2, T val3)
{
	T maxVal = val1;
	if (maxVal < val2)
		maxVal = val2;
	if (maxVal < val3)
		maxVal = val3;
	return maxVal;
}


int main()
{
	cout << "Result max(2, 3, 0) = " << max(2, 3, 0);
	cout << "\nResult max(2.3, 0.3, -1.2) = " << max(2.3, 0.3, -1.2);
	cout << "\nResult max('1', '0', '8') = " << max('1', '0', '8') << endl;
	return 0;
}