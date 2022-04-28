#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
        cout << i * i << endl;

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
