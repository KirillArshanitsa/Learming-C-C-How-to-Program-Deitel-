#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int = 1, int = 1, int = 2000); // default constructor
	void print() const; // print date in month/day/year format
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void nextDay();

private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}; 

#endif