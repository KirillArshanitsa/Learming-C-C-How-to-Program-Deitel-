#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

class Date
{
public:
	static const int monthsPerYear = 12; // number of months in a year
	//Date(int = 1, int = 1, int = 1900);
	Date();
	Date(int, int, int);
	Date(string);
	void print() const; // print date in month/day/year format
	void setDate(int = 1, int = 1, int = 1900);
	~Date();
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	static const string months[12];// = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int checkDay(int) const;
}; 

#endif;