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
    if (setHour(h) == 0)
        cout << "Error setHour() val = " << h << endl;
    if (setMinute(m) == 0)
        cout << "Error setMinute() val = " << m << endl;
    if (setSecond(s) == 0)
        cout << "Error setSecond() val = " << s << endl;
       

} 

int Time::setHour(int h)
{
    if (h >= 0 && h < 24) {
        hour = h;
        return 1;
    }
    else {
        hour = 0;
        return 0;
    }
}

// set minute value
int Time::setMinute(int m)
{
    if (m >= 0 && m < 60) {
        minute = m;
        return 1;
    }
    else {
        minute = 0;
        return 0;
    }

}

int Time::setSecond(int s)
{
    if (s >= 0 && s < 60) {
        second = s;
        return 1;
    }
    else {
        second = 0;
        return 0;
    }
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

void Time::tick()
{
    if (second + 1 == 60) {
        second = 0;
        if (minute + 1 == 60) {
            minute = 0;
            if (hour + 1 == 24) {
                hour = 0;
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