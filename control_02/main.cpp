#include <iostream>
using namespace std;

int main()
{
    // Task 1
    for (int i = 0; i < 10; i++)
        cout << pow(i, 2) << endl;

    // Task 2
    const int size = 10;
    int arr[size];
    int num_negative = 0;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 200 - 100;

    for (int a : arr)
    {
        cout << a << " ";
        if (a < 0)
            num_negative++;
    }
    cout << endl << "The number of negative numbers in the array: " << num_negative;
}
