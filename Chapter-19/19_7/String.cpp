#include <iostream> 
using std::cerr;
using std::cout;
using std::endl;

#include <iomanip> 
using std::setw;

#include <cstring> 
using std::strcmp;
using std::strcpy;
using std::strcat;


#include <cstdlib> 
using std::exit;

#include "String.h" 


String::String(const char* s)
	:length( (s != 0) ? strlen(s): 0 )
{
	cout << "Conversion constructor: (and default) constructor: " << s << endl;
	setString(s);
}


String::String(const String &copy) 
	:length(copy.length)
{
	cout << "Copy constructor length = : " << copy.sPtr << endl;
	setString(copy.sPtr);
}

String::~String()
{
	cout << "Destructor : " << sPtr << endl;
	delete[] sPtr;
}


const String &String::operator=(const String &right)
{
	cout << "operators called" << endl;
	if (&right != this) 
	{
		delete[] sPtr;
		length = right.length;
		setString(right.sPtr);
	}
	else
		cout << "Attempted assignment of a String to itself \n" << endl;

	return *this; 
}

bool String::operator!() const 
{ 
	return length == 0; 
}


bool String::operator==(const String &right) const
{ 
	return strcmp(sPtr, right.sPtr) == 0; 
}


//bool String::operator!= (const String &right) const
//{
//	return strcmp(sPtr, right.sPtr) != 0;
//}

bool String::operator< (const String &right) const
{
	return strcmp(sPtr, right.sPtr) < 0;
}

//bool String::operator>(const String &right) const
//{
//	return strcmp(sPtr, right.sPtr) > 0;
//}
//bool String::operator>=(const String &right) const
//{ 
//	return strcmp(sPtr, right.sPtr) >= 0; 
//}
//bool String ::operator<=(const String &right) const 
//{
//	return strcmp (sPtr, right.sPtr) <= 0; 
//}
char &String::operator [](int subscript)
{
	if (subscript < 0 || subscript >= length)
	{
		cerr << "Error: Substrict " << subscript << "out of range" << endl;
		exit(1);
	}
	return sPtr[subscript];
}
void String::setString(const char* string2)
{
	sPtr = new char[length + 1];
	if (string2 != 0)
		strcpy_s(sPtr, length + 1 ,string2);
	else
		sPtr[0] = '\0';

}

const String& String::operator+=(const String& right)
{
	size_t newLength = length + right.length;
	char* tempPtr = new char[newLength + 1];
	strcpy_s(tempPtr, length + 1 , sPtr);
	strcpy_s(tempPtr + length, newLength, right.sPtr);

	delete[] sPtr;
	sPtr = tempPtr;
	length = newLength;
	return *this;
}

int String::getLength() const 
{ 
	return length; 
}


ostream& operator<<(ostream& output, const String& s)
{
	output << s.sPtr;
	return output; 
}

istream& operator>>(istream& input, String& s)
{
	static char temp[100]; 
	input >> temp;
	s = temp; 
	return input; 
	
}


String operator+(const String &str1, const String &str2)
{

	String resultStr = String(str1);
	resultStr += str2;
	return resultStr;

}