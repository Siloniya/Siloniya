#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArr(int arr[], int size);
void resizeArray(int*& arr, int newsize, int size);
int main() {
	int len;
	cout << "Enter size of the array: ";
	cin >> len;
	int newlen;
	int* arr = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	printArr(arr, len);
	cout << "\n";
	int newVal = 8;
	newlen = len * 2;
	resizeArray(arr, newlen, len);
	arr[len++] = newVal;
	printArr(arr, len++);
}

void resizeArray(int*& arr, int newsize, int size) {
	int* temp = new int[newsize];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
void printArr(int arr[], int size) {
	cout << "Elements in dynamically allocated array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}