#ifndef STRING_H
#define STRING_H

#include <iostream>
using std::ostream;
using std::istream;

class String {
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	friend String operator+(const String&, const String&);

public:
	String(const char* = "");
	String(const String&);
	~String();

	const String& operator=(const String&);
	const String& operator+=(const String&);

	bool operator!() const;
	bool operator==(const String&) const;
	bool operator!=(const String &right) const
	{
		return !(*this == right);
	}
	bool operator<(const String&) const;
	bool operator>(const String &right) const
	{
		return right < *this;
	}
	bool operator>=(const String & right) const
	{
		return !(*this < right);
	}
	bool operator<=(const String &right) const
	{
		return !(right < *this);
	}
	char &operator[](int);
	char operator()(int) const;
	String operator()(int, int = 0) const;
	int getLength() const;


private:
	char* sPtr;
	int length;
	void setString(const char*);
};

#endif
