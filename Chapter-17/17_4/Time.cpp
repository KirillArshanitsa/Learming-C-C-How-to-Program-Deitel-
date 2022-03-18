#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setfill;
using std::setw;

#include "Time.h"
#include <ctime>

Time::Time()
{
    char buffer[32];
    char* tokenPtr;
    char* tmpPtr;
    char* next_token = NULL;
    size_t dataSize = 0;
    time_t sec = time(nullptr);
    ctime_s(buffer, 28, &sec);

    tokenPtr = strchr(buffer, ':') - 2;
    tmpPtr = strchr(tokenPtr, ' ');
    *tmpPtr = '\0';

    hour = atoi(strtok_s(tokenPtr, ":", &next_token));
    minute = atoi(strtok_s(NULL, ":", &next_token));
    second = atoi(strtok_s(NULL, ":", &next_token));

}

Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
    setHour(h); // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
} // end function setTime

// set hour value
void Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

// set minute value
void Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;

}

void Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}

// return hour value
unsigned int Time::getHour() const
{
    return hour;
} // end function getHour

// return minute value
unsigned int Time::getMinute() const
{
    return minute;
} // end function getMinute

// return second value
unsigned int Time::getSecond() const
{
    return second;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void Time::printStandard()
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << endl;
}