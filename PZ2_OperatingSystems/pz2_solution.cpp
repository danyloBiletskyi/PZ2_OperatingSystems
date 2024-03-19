#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>  
#include <cstdlib> 
#include <climits> 
//----------------------------------TASK 2.1 Method pre-declaration----------------------------------
void Task2_1();
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

//----------------------------------TASK 2.3 Method pre-declaration----------------------------------
void Task2_3();
int findMinPositiveOnSecondaryDiagonal(int matrix[][100], int n);


//----------------------------------TASK 2.4(1) Method pre-declaration----------------------------------

void Task2_4p1();

//----------------------------------TASK 2.4(2) Method pre-declaration----------------------------------
void Task2_4p2();

//----------------------------------TASK 2.5(1) Method pre-declaration----------------------------------
void Task2_5p1();
int countWords(const std::string& str);


//----------------------------------TASK 2.5(2) Method pre-declaration----------------------------------
void Task2_5p2();
void stringMatrix(const std::string strings[], int rows);




//----------------------------------METHOD ACTIVATION----------------------------------
int main() {
	Task2_2();
	return 0;
}




//----------------------------------TASK 2.1----------------------------------
void Task2_1() {
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
			readTheElementsOfAnArray(arr, actualSize);
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


//----------------------------------TASK 2.3----------------------------------
int findMinPositiveOnSecondaryDiagonal(int matrix[][100], int n) {
	using namespace std;
    int minPositive = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (matrix[i][n - i - 1] > 0 && matrix[i][n - i - 1] < minPositive) {
            minPositive = matrix[i][n - i - 1];
        }
    }

    return minPositive;
}

void Task2_3() {
	using namespace std;
	int n;


	cout << "Enter the size of the square matrix: ";
	cin >> n;


	srand(time(nullptr));

	int matrix[100][100];


	cout << "Matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 201 - 100;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	int minPositive = findMinPositiveOnSecondaryDiagonal(matrix, n);


	if (minPositive != INT_MAX) {
		cout << "The minimum positive number on the side diagonal: " << minPositive << endl;
	}
	else {
		cout << "There are no positive numbers on the side diagonal." << endl;
	}
}


//----------------------------------TASK 2.4(1)----------------------------------
void Task2_4p1() {
	using namespace std;
	srand(time(nullptr));

	int n;
	cout << "Enter an array size: ";
	cin >> n;

	int* arr = new int[n];


	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 100;
	}


	cout << "Array at the begining: ";
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;


	int newSize = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) {
			arr[newSize++] = arr[i];
		}
	}


	cout << "After odd elements were deleted: ";
	for (int i = 0; i < newSize; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;


	delete[] arr;
}


//----------------------------------TASK 2.4(2)----------------------------------
void Task2_4p2() {
	using namespace std;
	srand(time(nullptr));

	int rows, cols;
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns: ";
	cin >> cols;


	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}


	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = rand() % 100;
		}
	}


	cout << "Matrix at the begining:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	int k;
	cout << "Enter the K number of rows to add:  ";
	cin >> k;

	int newRows = rows + k;
	int** newMatrix = new int* [newRows];


	for (int i = 0; i < newRows; ++i) {
		newMatrix[i] = new int[cols];
		if (i < k) {

			for (int j = 0; j < cols; ++j) {
				newMatrix[i][j] = rand() % 100;
			}
		}
		else {

			for (int j = 0; j < cols; ++j) {
				newMatrix[i][j] = matrix[i - k][j];
			}
		}
	}


	cout << "Final matrix:" << endl;
	for (int i = 0; i < newRows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << newMatrix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	for (int i = 0; i < newRows; ++i) {
		delete[] newMatrix[i];
	}
	delete[] newMatrix;
}


//----------------------------------TASK 2.5(1)----------------------------------
int countWords(const std::string& str) {
    std::istringstream iss(str);
    std::string word;
    int count = 0;

    while (iss >> word) {
        ++count;
    }

    return count;
}

void Task2_5p1() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int wordCount = countWords(input);
    std::cout << "Count of words in string: " << wordCount << std::endl;
}


//----------------------------------TASK 2.5(2)----------------------------------
const int MAX_ROWS = 100; // Максимальна кількість рядків
const int MAX_COLS = 100; // Максимальна кількість символів у рядку

void stringMatrix(const std::string strings[], int rows) {
	int cols = rows > 0 ? strings[0].size() : 0; // Кількість стовпців залежно від першого рядка
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			char c = strings[i][j]; // Отримання символу у відповідній позиції
			std::cout << static_cast<int>(c) << ' '; // Виведення ASCII-коду символу
		}
		std::cout << "| "; // Розділювач між рядками
		std::cout << "\n";
	}
}

void Task2_5p2() {
	int n;
	std::cout << "Enter a number of strings: ";
	std::cin >> n;

	std::string strings[MAX_ROWS]; // Масив рядків
	std::cin.ignore(); // Пропустити символ нового рядка

	std::cout << "Enter strings: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::getline(std::cin, strings[i]); // Зчитування рядка у відповідну позицію масиву
	}

	std::cout << "Symbol Matrix (ASCII code):" << std::endl;
	stringMatrix(strings, n);
}






