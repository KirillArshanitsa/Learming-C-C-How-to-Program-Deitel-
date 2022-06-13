#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;


#include "Date.h"
using namespace std;

#include <ctime>


const string Date::months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


Date::Date(string date)
{
	if ((date.find(" ") != string::npos) && (date.find(",") == string::npos)) {
		int dy = stoi(date.substr(0,3));
		cout << "Use default month = 1" << endl;
		month = 1;
		day = checkDay(dy);
		year = stoi(date.substr(4));
	}
	else if (date.find("/") != string::npos) {
		if (date.find("/") == 2) {
			int m = stoi(date.substr(0, 2));
			int d = stoi(date.substr(3, 5));
			int y = stoi(date.substr(6, 7));
			setDate(m, d, y);
		}
		else if (date.find("/") == 1) {
			int m = stoi(date.substr(0, 1));
			int d = stoi(date.substr(2, 4));
			int y = stoi(date.substr(5, 6));
			setDate(m, d, y);
		}
		else {
			cout << "Parse error string - " << date << " use default constructor" << endl;
			setDate();
		}
	}
	else if (date.find(",") != string::npos) {
		int monthFinishStr = date.find(" ");
		string m = date.substr(0, monthFinishStr);
		int dateFinishStr = date.find(",");
		string d; 

		if (dateFinishStr - monthFinishStr - 1 == 2)
			d = date.substr(monthFinishStr + 1, 2);
		else
			d = date.substr(monthFinishStr + 1, 1);
		string y = date.substr(dateFinishStr + 2);

		//cout << m <<endl;
		//cout << d << endl;
		//cout << y << endl;
		char i = 0;
		while (i < 12)
		{
			if (months[i] == m)
				break;
			i++;
		}
		setDate(i + 1, stoi(d), stoi(y));
	}
	else {
		cout << "Parse error string - " << date << " use default constructor" << endl;
		setDate();
	}

}

void Date::setDate(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= monthsPerYear) // validate the month
		month = mn;
	else
	{
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << mn << ") set to 1.\n";
	} // end else

	year = yr; // could validate yr
	day = checkDay(dy); // validate the day
}

Date::Date(int mn, int dy, int yr)
{
	setDate(mn, dy, yr);
	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

Date::Date()
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);

	char* tokenPtr;
	char* next_token = NULL;
	tokenPtr = strtok_s(str, " ", &next_token);
	//get month form ctime string
	tokenPtr = strtok_s(NULL, " ", &next_token);
	char i = 0;
	char tmpMonth[4];
	while(i < 12) 
	{
		strncpy_s(tmpMonth, months[i].c_str(), 3);
		if (strcmp(tmpMonth, tokenPtr) == 0)
			break;
		i++;
	}
	//int m = stoi(months[i]);
	//get day form ctime string
	tokenPtr = strtok_s(NULL, " ", &next_token);
	int d = stoi(tokenPtr);
	//get year form ctime string
	int y = stoi(next_token + (strlen(next_token) - 5)); // -5 - 4 char in year + 1
	
	setDate((int)i, d ,y);

	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;

} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
	cout << endl;
	cout << setfill('0') << setw(3) << day << " " << year << endl;
	cout << month << '/' << day << '/' << year << endl;
	cout << months[month - 1] << ' ' << day << ", " << year << endl;

} // end function print

// output Date object to show when its destructor is called
Date::~Date()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
} 
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[monthsPerYear + 1] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
} 