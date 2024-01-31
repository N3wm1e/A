#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
using namespace std;
double radius(double);
int main()
{
    double length = 0;
    cout << "Circle length: ";
    do {
        cin >> length;
    } while (length < 0);
    cout << "Circle radius: " << radius(length);
    return 0;
}


double radius(double length)
{
    return length / (2 * M_PI);
}
