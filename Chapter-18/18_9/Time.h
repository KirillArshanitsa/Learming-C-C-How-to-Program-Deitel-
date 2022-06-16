#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time(int = 0, int = 0, int = 0); // default constructor
    int getHour() const; // return hour
    int getMinute() const; // return minute
    int getSecond() const; // return second

    void printUniversal() const; // print universal time
    void printStandard() const; // print standard time

    Time &setTime(int, int, int); // set hour, minute, second Time &setHour( int ); // set hour
    Time &setHour( int ); // set hour
    Time &setMinute(int); // set minute
    Time &setSecond(int); // set second

private:
//    int hour; // 0 - 23 (24-hour clock format) int minute; // 0 - 59
//    int minute; // 0 - 59
//    int second; // 0 - 59
    int allSeconds;
};
#endif