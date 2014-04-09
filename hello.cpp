#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>
#include <vector>
#include <cstdlib>
using namespace std;


// Vectors, random numbers, histograms

vector<int> randomVector (int n, int upperBound) {
    vector<int> vec (n);
    for (int i = 0; i<vec.size(); i++) {
        vec[i] = random () % upperBound;
    }
    return vec;
}

void printVector (const vector<int>& vec) {
    for (int i = 0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

int howMany (const vector<int>& vec, int value) {
    int count = 0;
    for (int i=0; i < vec.size(); i++) {
        if (vec[i] == value) count++;
    }
    return count;
}

vector<int> histogram (vector<int>& vec, int upperBound) {
    vector<int> result (upperBound, 0);
    int numValues = vec.size();
    for (int i = 0; i < numValues; i++) {
        int index = vec[i];
        result[index]++;
    }
    return result;
}

int main ()
{

    //vector<int> values;
    //int c,i,len;
    //cin>>c;

    //while(c != -1) {
        //values.push_back(c);
        //cin >> c;
    //}
    //len = values.size();
    //for(i = 0; i < len; i++) {
        //cout << values[i] << endl;
    //}

    //for (int i = 0; i < 4; i++) {
    //    int x = random ();
    //    cout << x << endl;
    //}

    int numValues = 100000;
    int upperBound = 10;
    vector<int> rvector = randomVector (numValues, upperBound);
    vector<int> hist = histogram (rvector, upperBound);

    cout << "value\thowMany" << endl;

    for (int i = 0; i < upperBound; i++) {
        cout << hist[i] << endl;
    }
    //printVector (vector);

    return 0;
}
