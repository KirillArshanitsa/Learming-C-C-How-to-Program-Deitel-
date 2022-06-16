#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time( int hr, int min, int sec )
{
    setTime( hr, min, sec );
}

Time &Time::setTime( int h, int m, int s )
{
    allSeconds = 0;
    setHour( h );
    setMinute( m );
    setSecond( s );
    return *this;
}

Time &Time::setHour( int h )
{
    //hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
    allSeconds += ( h >= 0 && h < 24 ) ?h * 3600: 0;
    return *this;
}

Time &Time::setMinute( int m ) // note Time & return
{
    //minute=(m>=0 && m<60) ? m:0;
    allSeconds += (m >= 0 && m < 60) ?m * 60 :0;
    return *this;
}

Time &Time::setSecond( int s ) // note Time & return
{
    //second = ( s>=0 && s<60) ?s:0 ;
    allSeconds += (s >= 0 && s < 60) ? s : 0;
    return *this; // enables
}

int Time::getHour() const
{
    return allSeconds / 3600;
}

int Time::getMinute() const
{
    int h = allSeconds / 3600;
    return (allSeconds - h * 3600) / 60;
}

int Time::getSecond() const
{
    if (allSeconds < 60)
        return allSeconds;

    int h = allSeconds / 3600;
    int m = (allSeconds - h * 3600) / 60;
    int s = allSeconds - h * 3600 - m * 60;
    return s;
}

void Time::printUniversal() const
{
    cout << setfill( '0' ) << setw( 2 ) << getHour()  << ":"
         << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
}
// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
    cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
         << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
         << ":" << setw( 2 ) << getSecond() << ( getHour() < 12 ? " AM" : " PM" );
} // end fu