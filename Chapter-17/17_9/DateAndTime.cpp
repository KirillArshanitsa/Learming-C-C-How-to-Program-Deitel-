#include <iostream>
#include "DateAndTime.h" 

using std::cout;
using std::endl;

#include <iomanip>

using std::setfill;
using std::setw;

#include <ctime>

DateAndTime::DateAndTime(int hour, int minute, int second, int mn, int dy, int yr)
{
    setDay(dy);
    setMonth(mn);
    setYear(yr);
    setTime(hour, minute, second);
}


void DateAndTime::setDay(int dy) {
    if ((dy >= 1) && (dy <= 31))
        day = dy;
    else
        if ((day < 1) || (day > 31)) //check old avlue
            day = 1;
}

void DateAndTime::setMonth(int mn) {
    if ((mn >= 1) && (mn <= 12))
        month = mn;
    else
        if ((month < 1) || (month > 12)) //check old avlue
            month = 1;
}

void DateAndTime::setYear(int yr) {
    if (yr >= 0) {
        year = yr;
        if (((yr % 4 == 0) && (yr % 100 > 0)) || (yr % 400 == 0))
            daysOfMonth[1] = 29;
        else
            daysOfMonth[1] = 28;
    }
    else
        if (year < 0)
            year = 0;
}

void DateAndTime::nextDay()
{
    if (day + 1 > daysOfMonth[month - 1]) {
        day = 1;
        if (month + 1 == 13) {
            month = 1;
            setYear(year + 1);
        }
        else
            month++;
        cout << endl;
    }
    else
        day++;

}

void DateAndTime::print() const
{
    cout << month << '/' << day << '/' << year << " ";
}


// set new Time value using universal time
void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h); // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
} // end function setTime

// set hour value
void DateAndTime::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

// set minute value
void DateAndTime::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;

}

void DateAndTime::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}

// return hour value
 int DateAndTime::getHour() const
{
    return hour;
} // end function getHour

// return minute value
int DateAndTime::getMinute() const
{
    return minute;
} // end function getMinute

// return second value
int DateAndTime::getSecond() const
{
    return second;
}

void DateAndTime::printUniversal()
{
    print();
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void DateAndTime::printStandard()
{
    print();
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << endl;
}

void DateAndTime::tick()
{
    if (second + 1 == 60) {
        second = 0;
        if (minute + 1 == 60) {
            minute = 0;
            if (hour + 1 == 24) {
                hour = 0;
                nextDay();
            }
            else
                hour++;
        }
        else
            minute++;
    }
    else
        second++;

}