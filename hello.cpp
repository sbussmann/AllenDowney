#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>
using namespace std;

// Difference from python: use an "&" symbol after declaring the type of a
// parameter to pass an argument by reference.  Note that reference arguments
// must be variables, not expressions.  So j works, but j+1 does not.

// Structures

// An example of structures: Point objects

struct Point {
    double x, y;
};

void printPoint (Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

double distance (Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt (dx*dx + dy*dy);
}

void reflect (Point& p)
{
    double temp = p.x;
    p.x = p.y;
    p.y = temp;
}

// Another example of structures: Rectangles

struct Rectangle {
    Point corner;
    double width, height;
};

Point findCenter (Rectangle& box)
{
    double x = box.corner.x + box.width/2;
    double y = box.corner.y + box.height/2;
    Point result = {x, y};
    return result;
}

void swap (int& x, int&y)
{
    int temp = x;
    x = y;
    y = temp;
}

struct Time {
    int hour, minute;
    double second;
};

void printTime (Time& t) {
    cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}

bool after (Time& time1, Time& time2) {
    if (time1.hour > time2.hour) return true;
    if (time1.hour < time2.hour) return false;

    if (time1.minute > time2.minute) return true;
    if (time1.minute < time2.minute) return false;

    if (time1.second > time2.second) return true;
    return false;
}

Time addTime (const Time& t1, const Time& t2) {
    double seconds = convertToSeconds (t1) + convertToSeconds (t2);
    return makeTime (seconds);
}

double convertToSeconds (const Time& t) {
    int minutes = t.hour * 60 + t.minute;
    double seconds = minutes * 60 + t.second;
    return seconds;
}

Time makeTime (double secs) {
    Time time;
    time.hour = int (secs / 3600.0);
    secs -= time.hour * 3600.0;
    time.minute = int (secs / 60.0);
    secs -= time.minute * 60.0;
    time.seconds = secs;
    return time;
}

void increment (Time& time, double secs) {
    time.second += secs % 60.0;
}

int main ()
{

    Time currentTime = { 9, 14, 30.0 };
    Time breadTime = { 3, 35, 0.0 };
    Time doneTime = addTime (currentTime, breadTime);
    printTime (doneTime);
    
    increment (doneTime, 20.0);

    printTime (doneTime);

    return 0;
}
