#include <iostream>
#include "Time.h"
using namespace std;


// Downey Chapter 11: Member functions

// constructor: make a time structure given hours, minutes, and seconds
Time::Time (int h, int m, double s)
{
    hour = h; minute = m; second = s;
}

// constructor: make a time structure given a number of seconds
Time::Time (double secs) {
    hour = int (secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int (secs / 60.0);
    secs -= minute * 60.0;
    second = secs;
}

// modifier: add a number of seconds to a given time structure
void Time::increment (double secs) {
    double seconds = convertToSeconds ();
    seconds += secs;
    Time time1 (seconds);
    hour = time1.hour;
    minute = time1.minute;
    second = time1.second;
}

// function: print the time
void Time::print () const {
    cout << hour << ":" << minute << ":" << second << endl;
}

// function: check if one time is after another
bool Time::after (const Time& time2) const {
    if (hour > time2.hour) return true;
    if (hour < time2.hour) return false;

    if (minute > time2.minute) return true;
    if (minute < time2.minute) return false;

    if (second > time2.second) return true;
    return false;
}

// function: add two time structures together to make a new time structure
// Time addTime (const Time& t1, const Time& t2) {
//     double seconds = convertToSeconds (t1) + convertToSeconds (t2);
//     return makeTime (seconds);
// }
Time Time::add (const Time& t2) const {
    double seconds = convertToSeconds () + t2.convertToSeconds ();
    Time time (seconds);
    return time;
}

// function: convert a time structure to seconds
double Time::convertToSeconds () const {
    int minutes = hour * 60 + minute;
    double seconds = minutes * 60 + second;
    return seconds;
}

int main ()
{

    Time currentTime ( 9, 14, 30.0 );
    currentTime.print ();
    currentTime.increment(500.0);
    currentTime.print ();

    Time breadTime (3, 35, 0.0);
    Time doneTime = currentTime.add (breadTime);
    doneTime.print ();

    if (doneTime.after (currentTime)) {
        cout << "The bread will be done after it starts." << endl;
    }

    return 0;
}
