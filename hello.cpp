#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>
using namespace std;

// main: generate some simple output

void printLogarithm (double x) {
    if (x <= 0.0) {
        cout << "Positive numbers only, please." << endl;
        return;
    }
    double result = log (x);
    cout << "The log of x is " << result << endl;
}

void nLines (int n) {
    if (n > 0) {
        cout << endl;
        nLines (n-1);
    }
}

double area (double radius) {
    double pi = acos (-1.0);
    double area = pi * radius * radius;
    return area;
}

double absoluteValue (double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

double distance (double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dsquared = dx*dx + dy*dy;
    double result = sqrt (dsquared);
    return result;
}

double fred (double xc, double yc, double xp, double yp) {
    double radius = distance (xc, yc, xp, yp);
    double result = area (radius);
    return result;
}

bool isSingleDigit (int x)
{
    return (x >=0 && x < 10);
}

int factorial (int n)
{
    if (n == 0) {
        return 1;
    } else {
        int recurse = factorial (n-1);
        int result = n * recurse;
        return result;
    }
}

int fibonacci (int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int countdown (int n) {
    while (n > 0) {
        cout << n << endl;
        n = n - 1;
    }
    cout << "Blastoff!" << endl;
    return 0;
}

void printMultiples (int n, int high)
{
    int i = 1;
    while (i <= high) {
        cout << n*i << "\t";
        i += 1;
    }
    cout << endl;
}

void printMultTable (int high) {
    int i = 1;
    while (i <= high) {
        printMultiples (i, i);
        i += 1;
    }
}

int find (string s, char c, int i)
{
    while (i<s.length()) {
        if (s[i] == c) return i;
        i += 1;
    }
    return -1;
}

int countLetters (string s, char c)
{
    int oldindex = 0;
    int count = 0;
    while (oldindex < s.length()) {
        int index = find(s, c, oldindex);
        if (index >= 0) {
            count += 1;
            oldindex = index + 1;
        } else {
            return count;
        }
    }
    return count;
}

void stringToUpper (string s)
{
    int index = 0;
    int length = s.length();
    while (index < length) {
        char upperchar = toupper (s[index]);
        s[index] = upperchar;
        index++;
    }
    cout << s << endl;
}

int main ()
{
    string fruit = "baNana";
    stringToUpper (fruit);
    return 0;
}
