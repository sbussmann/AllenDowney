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

int main ()
{

    string name;
    cout << "What's your name? ";
    getline (cin, name);
    cout << name << endl;

    return 0;
}
