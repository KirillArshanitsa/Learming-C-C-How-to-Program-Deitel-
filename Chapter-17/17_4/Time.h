#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time(int, int, int);
	Time();

	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)

	unsigned int getHour() const; // return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second

	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format

private:
	unsigned int hour; // 0 - 23 (24-hour clock format)
	unsigned int minute; // 0 - 59
	unsigned int second; // 0 - 59
};

#endif