#ifndef PHONENUMBER_H 
#define PHONENUMBER_H 

#include <iostream> 
using std::ostream;
using std::istream;

#include <string> 
using std::string;

class PhoneNumber
{
	friend ostream& operator<<(ostream&, const PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);
public:
	ostream& operator<<(ostream& ostream)
	{
		return ostream << *this;
	}
	//istream& operator>>(istream& istream)
	//{
	//	istream >> *this;
	//}

private:
	string areaCode; // 3 цифры регионального кода 
	string exchange; // 3 цифры кода АТС 
	string line; // 4 цифры номера линии 
}; // конец класса PhoneNumber 

#endif 
