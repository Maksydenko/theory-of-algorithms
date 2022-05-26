#include <iostream>
using namespace std;

int factorial(int n) {
    if (n < 2)
        return 1;
    return n * factorial(n - 1);
}

double sinWithRec(double value, int accuracy = 0) {
    double const circleValue = 6.28319;

    if (value > circleValue || value < -circleValue) {
        while (value > circleValue)
            value -= circleValue;
        while (value < -circleValue)
            value += circleValue;
    }
    if (accuracy == 6)
        return 0;
    double res = pow(-1, accuracy) * pow(value, 2 * accuracy + 1) / factorial(2 * accuracy + 1);
    return res + sinWithRec(value, accuracy + 1);
}

int main() {
    cout << "Write the x: ";
    double value;
    cin >> value;
    double y = (value + 3) / sinWithRec(value);
    cout << "sin(x) = " << sinWithRec(value) << "\ny = " << y;
}
