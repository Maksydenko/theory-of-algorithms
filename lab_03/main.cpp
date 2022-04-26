#include <iostream>
using namespace std;

int num_comparisons = 0;
int lineSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		num_comparisons++;

		if (arr[i] == key)
			return i;
	}
	return -1;
}
int biSearch(int arr[], int L, int R, int key) {
	int mid;

	do {
		mid = L + (R - L) / 2;
		num_comparisons++;

		if (key < arr[mid])
			R = --mid;
		else {
			if (key > arr[mid])
				L = ++mid;
			else
				return mid;
		}
		if (L > R)
			return -1;
	} while (1);
}

void mySort(int arr[], int number) {
	for (int i = 0; i < number - 1; i++)
		for (int j = i + 1; j < number; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

int main() {
	const int number = 500;
	int B[number];
	int lnum = 0;
	int bnum = 0;

	for (int i = 0; i < number; i++) {
		B[i] = rand() % 1000;
	}
	mySort(B, number);
	cout << "Array B:" << endl;

	for (int b : B)
		cout << b << " ";
	cout << endl << "Elements 0 to 999 in array B (linear search):" << endl;

	for (int b : B) {
		if (0 <= b <= 999)
			if (lineSearch(B, number, b) >= 0)
				lnum++;
		cout << b << " ";
	}
	cout << endl << "Number of elements from 0 to 999 in array B (linear search): " << lnum;
	cout << endl << "Number of comparisons(linear search): " << num_comparisons << endl;
	cout << endl << "Elements 0 to 999 in array B (binary search):" << endl;

	for (int b : B) {
		if (0 <= b <= 999)
			if (biSearch(B, 0, number - 1, b) >= 0)
				bnum++;
		cout << b << " ";
	}

	cout << endl << "Number of elements from 0 to 999 in array B (binary search): " << bnum;
	cout << endl << "Number of comparisons(linear search): " << num_comparisons;
}
