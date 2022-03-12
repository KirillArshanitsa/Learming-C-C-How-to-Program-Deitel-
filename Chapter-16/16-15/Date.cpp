#include "Date.h"
#include <iostream>

using std::cout;
using std::endl;

Date::Date(int d, int m, int y)
{
	day = d;
	setMonth(m);
	year = y;
}


void Date::displayDate()
{
	cout << day << "/" << month << "/" << year << endl;
}

void Date::setMonth(int m)
{
	if ((m > 1) && (m < 13))
		month = m;
	else
		month = 1;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setYear(int y)
{
	year = y;
}


int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

