#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime
{
public:
	DateAndTime(int = 0, int = 0, int = 0, int = 1, int = 1, int = 2000);
	DateAndTime();

	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)

	int getHour() const; // return hour
	int getMinute() const; // return minute
	int getSecond() const; // return second

	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void nextDay();
	void tick();

private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	void print() const; // print date in month/day/year format
};

#endif