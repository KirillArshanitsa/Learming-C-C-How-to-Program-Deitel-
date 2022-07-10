#ifndef HUGEINT_H 
#define HUGEINT_H 

#include <iostream> 
using std::ostream;

class Hugelnt
{
	friend ostream &operator<<(ostream&, const Hugelnt&);
public:
	Hugelnt(long = 0); 
	Hugelnt(const char*); 

	Hugelnt operator+(const Hugelnt&) const;
	Hugelnt operator+(int) const;
	Hugelnt operator+(const char*) const;

	Hugelnt operator*(const Hugelnt&) const;
	bool operator==(const Hugelnt&) const;
	bool isEmpty();

private:
	short integer[30];
}; 

#endif 
