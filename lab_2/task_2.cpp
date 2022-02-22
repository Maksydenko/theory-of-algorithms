#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;

    while (n > 1) {
        fact *= n;
        n--;
    }

    return fact;
}

double sinWithoutRec(double value, int accuracy = 0) {
    double const circleValue = 6.28319;
    double sinx = 0;

    if (value > circleValue || value < -circleValue) {
        while (value > circleValue) {
            value -= circleValue;
        }

        while (value < -circleValue) {
            value += circleValue;
        }
    }

    while (accuracy <= 6) {
        sinx += pow(-1, accuracy) * pow(value, 2 * accuracy + 1) / factorial(2 * accuracy + 1);
        accuracy++;
    }

    return sinx;
}

int main() {
    cout << "Write the x: ";
    double value;
    cin >> value;
    double y = (value + 3) / sinWithoutRec(value);
    cout << "sin(x) = " << sinWithoutRec(value) << "\ny = " << y;
}
