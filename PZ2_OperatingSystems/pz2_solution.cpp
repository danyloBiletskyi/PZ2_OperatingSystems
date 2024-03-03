#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <sstream>
#include <string>
#include <algorithm>

//----------------------------------TASK 2.1 Method pre-declaration----------------------------------
void task2_1();
int getTheNumberOfElementsBelowAverage(int average, int length, int arr[]);
void makeAChoice(int arr[], int actualSize);
int deleteElementsHigherAverageAndReturnAvg(int arr[], int length);
void readTheElementsOfAnArray(int arr[], int length);
void readTheElementsOfAnArray(double arr[], int length);
void selectionSort(int arr[], int length);
int addElementsToTheBeginingAndReturnNewSize(int arr[], int length);

//----------------------------------TASK 2.2 Method pre-declaration----------------------------------
void Task2_2();
void selectionSortForDouble(double arr[], int length);
int binarySearch(double arr[], int length, double element);
int main() {
	/*task2_1();*/
	Task2_2();
	return 0;
}


//----------------------------------TASK 2.1----------------------------------
void task2_1() {
	using namespace std;

	//------------------------Array generation------------------------
	const int MAX_SIZE = 100;
	int arr [MAX_SIZE];
	int actualSize;
	cout << "Enter an array size that is < " << MAX_SIZE << " : ";
	cin >> actualSize;
	cout << endl;
	cout << "Array is being generated......." << endl;
	for (int i = 0; i < actualSize; i++) {
		arr[i] = rand() % 100 - 50;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Result of generating of an array: ";
	readTheElementsOfAnArray(arr, actualSize);

	//------------------------Suggesting and selecting an operation------------------------
	cout << "------------------------------------------------------------------------------------------------" << endl;
	makeAChoice(arr, actualSize);

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

int deleteElementsHigherAverageAndReturnAvg(int arr[], int length) {
	using namespace std;
	int avg = 0;
	avg = accumulate(arr, arr + length, avg) / length;
	cout << "Average is " << avg << endl;
	selectionSort(arr, length);
	return avg;
}

void readTheElementsOfAnArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (i != length - 1) {
			std::cout << arr[i] << ", ";
		}
		else {
			std::cout << arr[i] << ".";
		}
	}
	std::cout << std::endl;
}


void makeAChoice(int arr[], int actualSize) {
	using namespace std;
	string choice;
	cout << "Choose an operation: " << endl;
	cout << "1. Delete all elements > than average of an array" << endl;
	cout << "2. Add K elements to the begining" << endl;
	cout << "3. Move the M elements to the right" << endl;
	cout << "4. Search the first even element" << endl;
	cout << "5. Sort the array" << endl;
	cout << "9. Quit" << endl;
	while (true) {
		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			int avg = deleteElementsHigherAverageAndReturnAvg(arr, actualSize);
			actualSize = getTheNumberOfElementsBelowAverage(avg, actualSize, arr);
			cout << "Array after the delete: ";
			readTheElementsOfAnArray(arr, actualSize);
		}
		else if (choice == "2") {
			actualSize = addElementsToTheBeginingAndReturnNewSize(arr, actualSize);
			readTheElementsOfAnArray(arr, actualSize);
		}
		else if (choice == "3") {
			cout << "How far do you want to move the elements? ";
			int M;
			cin >> M;
			reverse(arr, arr + actualSize);
			reverse(arr, arr + M);
			reverse(arr + M, arr + actualSize);
			readTheElementsOfAnArray(arr, actualSize);
		}
		else if (choice == "4") {
			int countOfSteps = 0;
			for (int i = 0; i < actualSize; i++) {
				if (arr[i] % 2 == 0) {
					break;
				}
				countOfSteps++;
			}
			cout << "First even number was found! It is : " << arr[countOfSteps] << " and was found on " << countOfSteps + 1 << " step." << endl;
		}
		else if (choice == "5") {
			selectionSort(arr, actualSize);
		}
		else if (choice == "9") {
			break;
		}
		else {
			cout << "Wrong choice, YOU SHALL NOT PASS!!!" << endl;
		}
	}
}


int addElementsToTheBeginingAndReturnNewSize(int arr[], int length) {
	using namespace std;
	int K;
	cout << "How many integers do you want to add? ";
	cin >> K;
	for (int i = length - 1; i >= 0; i--) {
		arr[i + K] = arr[i];
	}

	for (int i = 0; i < K; i++) {
		cout << "Enter your number: ";
		cin >> arr[i];
	}

	length += K;
	return length;
}


//----------------------------------TASK 2.2----------------------------------

void Task2_2() {
	using namespace std;

	//------------------------Array generation------------------------
	const int MAX_SIZE = 100;
	double arr[MAX_SIZE];
	int actualSize;
	cout << "Enter an array size that is < " << MAX_SIZE << " : ";
	cin >> actualSize;
	cout << endl;
	cout << "Array is being generated......." << endl;
	for (int i = 0; i < actualSize; i++) {
		int multiplier = rand() % 100 - 50;
		arr[i] = ((double)rand() / RAND_MAX) * (double)multiplier;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Result of generating of an array: ";
	selectionSortForDouble(arr, actualSize);
	readTheElementsOfAnArray(arr, actualSize);

	cout << "------------------------------------------------------------------------------------------------" << endl;

	cout << "Enter an element you want to add into a sequence: ";
	
	double b;
	cin >> b;
	int position = binarySearch(arr, actualSize, b);
	int temp = arr[position];
	for (int i = actualSize - 1; i >= position; i--) {
		arr[i + 1] = arr[i];
	}
	arr[position] = b;
	actualSize += 1;
	readTheElementsOfAnArray(arr, actualSize);
}


void selectionSortForDouble(double arr[], int length) {
	for (int i = 1; i < length; i++) {
		int j = i - 1;
		double key = arr[i];

		while (arr[j] > key && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void readTheElementsOfAnArray(double arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (i != length - 1) {
			std::cout << arr[i] << ", ";
		}
		else {
			std::cout << arr[i] << ".";
		}
	}
	std::cout << std::endl;
}
int binarySearch(double arr[], int length, double element) {
	int right = length - 1;
	int left = 0;

	while (left <= right) {
		int center = left + (right - left) / 2;
		if (arr[center] == element) {
			return center;
		}
		else if (arr[center] < element) {
			left = center + 1;
		}
		else{
			right = center - 1;
		}
	}
	return left;
	
}