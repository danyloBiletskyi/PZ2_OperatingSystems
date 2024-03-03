#include <iostream>
#include <stdlib.h>
#include <numeric>

void task2_1();
int getTheNumberOfElementsBelowAverage(int average, int length, int arr[]);
void selectionSort(int arr[], int length);
int main() {
	task2_1();
	return 0;
}


//----------------------------------TASK 2.1----------------------------------
void task2_1() {
	using namespace std;

	//TASK 1----------------------------------
	const int MAX_SIZE = 100;
	int arr [MAX_SIZE];
	int actualSize;
	cout << "Enter an array size that is < " << MAX_SIZE << " : ";
	cin >> actualSize;

	for (int i = 0; i < actualSize; i++) {
		arr[i] = rand() % 100 + 1;
	}

	//TASK 2----------------------------------
	for (int i = 0; i < actualSize; i++) {
		cout << arr[i] << endl;
	}

	//TASK 3----------------------------------
	int avg = 0;
	avg = accumulate(arr, arr + actualSize, avg) / actualSize;
	cout << "Average is " << avg << endl;
	selectionSort(arr, actualSize);
	actualSize = getTheNumberOfElementsBelowAverage(avg, actualSize, arr);

	//TASK 4----------------------------------
	cout << "Array after the delete: " << endl;
	for (int i = 0; i < actualSize; i++) {
		cout << arr[i] << endl;
	}
}

int getTheNumberOfElementsBelowAverage(int average, int length, int arr[]) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] <= average) {
			count++;
		}
	}

	return count;
}

void selectionSort(int arr[], int length) {

	for (int i = 1; i < length; i++) {
		int j = i - 1;
		int key = arr[i];

		while (arr[j] > key && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}