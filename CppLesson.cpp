//The program shows the implementation of dynamic array and append process
//for one element. The resizeArr() function is of prime focus to understand 
//runtime resizing process and modifying addresses contained in pointers.

#include <iostream>

using namespace std;

void printArr(int arr[], int size);			//prints the array elements with tab separation
void resizeArray(int*& arr, int newsize, int size);	//resizes the dynamically allocated array, passes pointer as reference
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
	int newVal;
	cout << "Enter value to be appended: ";
	cin >> newVal;
	newlen = len * 2;
	resizeArray(arr, newlen, len);
	arr[len++] = newVal;
	printArr(arr, len++);
}

void resizeArray(int*& arr, int newsize, int size) {
	int* temp = new int[newsize];			//temporary pointer array to copy data from initial array
	for (int i = 0; i < size; i++) {		//copying data to temp pointer array
		temp[i] = arr[i];
	}
	delete[] arr;					//memory free'd from useless pointer
	arr = temp;					//referncing new memory using the old pointer
}
void printArr(int arr[], int size) {
	cout << "Elements in dynamically allocated array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}
