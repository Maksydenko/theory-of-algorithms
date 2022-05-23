#include <iostream>
using namespace std;

const int num = 1000;
int i, j, num_comparisons, num_permutations;

void generateArray(int arr_01[], int arr_02[], int arr_03[])
{
	arr_01[0] = 0;
	arr_02[0] = rand() % 1000;
	arr_03[0] = 9999;

	for (i = 1; i < num; i++)
	{
		arr_01[i] = arr_01[i - 1] + rand() % 10;
		arr_02[i] = rand() % 1000;
		arr_03[i] = arr_03[i - 1] - rand() % 5;
	}
}

void bubbleSort(int arr[], int num)
{
	int flag = 1, i = 0;

	while (flag)
	{
		flag = 0;

		for (j = num - 2; j >= i; j--)
		{
			num_comparisons++;

			if (arr[j] > arr[j + 1])
			{
				num_permutations++;
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		i++;
	};
}

void selectionSort(int arr[], int num)
{
	for (i = 0; i < num - 1; i++)
	{
		int min = i;

		for (j = i + 1; j < num; j++)
		{
			num_comparisons++;

			if (arr[min] > arr[j])
				min = j;
		}
		num_permutations++;
		swap(arr[i], arr[min]);
	}
}

int sortShell(int arr[], int num)
{
	const int size = num;
	int step = size / 2;

	while (step > 0)
	{
		for (i = 0; i < (size - step); i++)
		{
			num_comparisons++;
			j = i;

			while (j >= 0 && arr[j] > arr[j + step])
			{
				num_permutations++;
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
				j--;
			}
		}
		step = step / 2;
	}
	return 0;
}

int main()
{
	int array_01[num], array_02[num], array_03[num];
	generateArray(array_01, array_02, array_03);

	cout << "Array 1:" << endl;

	for (int a : array_01)
		cout << a << " ";

	cout << endl << "Array 2:" << endl;

	for (int a : array_02)
		cout << a << " ";

	cout << endl << "Array 3:" << endl;

	for (int a : array_03)
		cout << a << " ";

	cout << endl << "Bubble sort:" << endl;

	num_comparisons = 0;
	num_permutations = 0;
	bubbleSort(array_01, num);
	cout << "Best: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	bubbleSort(array_02, num);
	cout << "Average: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	bubbleSort(array_03, num);
	cout << "Worst: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	generateArray(array_01, array_02, array_03);
	cout << endl << "Selection sort:" << endl;

	num_comparisons = 0;
	num_permutations = 0;
	selectionSort(array_01, num);
	cout << "Best: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	selectionSort(array_02, num);
	cout << "Average: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	selectionSort(array_03, num);
	cout << "Worst: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	generateArray(array_01, array_02, array_03);
	cout << endl << "Shell sort:" << endl;

	num_comparisons = 0;
	num_permutations = 0;
	sortShell(array_01, num);
	cout << "Best: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	sortShell(array_02, num);
	cout << "Average: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;

	num_comparisons = 0;
	num_permutations = 0;
	sortShell(array_03, num);
	cout << "Worst: number of comparisons: " << num_comparisons << "; number of permutations: " << num_permutations << endl;
}
