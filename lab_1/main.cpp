#include <iostream>
using namespace std;

int main()
{
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 5;
    double x3 = 4;
    double y3 = 0;

    double x12 = x2 - x1;
    double y12 = y2 - y1;
    double x23 = x3 - x2;
    double y23 = y3 - y2;
    double x31 = x1 - x3;
    double y31 = y1 - y3;

    double side1 = sqrt(pow(x12, 2) + pow(y12, 2));
    double side2 = sqrt(pow(x23, 2) + pow(y23, 2));
    double side3 = sqrt(pow(x31, 2) + pow(y31, 2));

    if (pow(side1, 2) == pow(side2, 2) + pow(side3, 2))
        cout << ("Triangle rectangular");
    else if (pow(side2, 2) == pow(side1, 2) + pow(side3, 2))
        cout << ("Triangle rectangular");
    else if (pow(side3, 2) == pow(side1, 2) + pow(side2, 2))
        cout << ("Triangle rectangular");
    else
        cout << ("Triangle not rectangular");
}