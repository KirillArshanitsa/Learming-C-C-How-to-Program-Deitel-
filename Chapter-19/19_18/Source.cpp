#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

#include "PhoneNumber.h" 

int main()
{
	PhoneNumber phone; // создать объект phone 

	cout << "Enter phone number in the form (123) 456-7890:" << endl;

	cin >> phone;
	cout << "The phone number entered was: ";
	phone << cout << endl;
	//cout << phone << endl;
	return 0;
} // конец main 
