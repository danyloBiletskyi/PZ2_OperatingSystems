#include <iostream>
#include <stdlib.h>
#include <numeric>

void task2_1();

int main() {
	task2_1();
	return 0;
}


//----------------------------------TASK 2.1----------------------------------
void task2_1() {
	using namespace std;

	//TASK 1----------------------------------
	int arraySize;
	cout << "Enter an array size: ";
	cin >> arraySize;
	int *arr = new int[arraySize];

	for (int i = 0; i < arraySize; i++) {
		arr[i] = rand() % 100 + 1;
	}

	//TASK 2----------------------------------
	for (int i = 0; i < arraySize; i++) {
		cout << arr[i] << endl;
	}

	//TASK 3----------------------------------
	int avg = 0;
	avg = accumulate(arr, arr + arraySize, avg) / arraySize;
	cout << "Average is " << avg << endl;
	
	int newArrSize = 0;
	for (int i = 0; i < arraySize; i++) {
		if (arr[i] <= avg) {
			newArrSize++;
		}
	}

	int* newArr = new int[newArrSize];
	int i_arr = 0;
	int i_newArr = 0;
	while (i_arr < arraySize) {
		if (arr[i_arr] <= avg) {
			newArr[i_newArr] = arr[i_arr];
			i_newArr++;
		}
		i_arr++;
	}

	delete arr;

	//TASK 4
	cout << "New array after the delete of integers > the average" << endl;
	for (int i = 0; i < newArrSize; i++) {
		cout << newArr[i] << endl;
	}
}