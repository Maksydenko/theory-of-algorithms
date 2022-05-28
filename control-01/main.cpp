#include <iostream>
using namespace std;

double myModule(double value) {
    if (value < 0)
        return -value;
    return value;
}

int myFactorial(int n) {
    if (n < 2)
        return 1;
    return n * myFactorial(n - 1);
}

double myCos(double value, int accuracy = 0) {
    double const circleValue = 6.28319;

    if (value > circleValue || value < -circleValue) {
        while (value > circleValue)
            value -= circleValue;
        while (value < -circleValue)
            value += circleValue;
    }
    if (accuracy == 7)
        return 0;
    double res = pow(-1, accuracy) * pow(value, 2 * accuracy) / myFactorial(2 * accuracy);
    return res + myCos(value, accuracy + 1);
}

double mySin(double value, int accuracy = 0) {
    double const circleValue = 6.28319;

    if (value > circleValue || value < -circleValue) {
        while (value > circleValue)
            value -= circleValue;
        while (value < -circleValue)
            value += circleValue;
    }
    if (accuracy == 7)
        return 0;
    double res = pow(-1, accuracy) * pow(value, 2 * accuracy + 1) / myFactorial(2 * accuracy + 1);
    return res + mySin(value, accuracy + 1);
}

int main() {
    double x = 0.4 * pow(10, 4), y = -0.875, z = -0.475 * pow(10, -3);
    //double w = 1.9873;
    cout << "w = " << pow(myModule(myCos(x) - myCos(y)), 1 + 2 * pow(mySin(y), 2)) * (1 + z + pow(z, 2) / 2 + pow(z, 4) / 4);
}
