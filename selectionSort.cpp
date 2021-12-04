#include <iostream>
using namespace std;

void swap(int* a, int* b);
void selection(int arr[], int size);
int minimum(int arr[], int low, int high);
int main() {
	int arr[] = { 19, 2, 20, 1, 0, 18 };
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	selection(arr, 6);
	cout << "After sorting\n";
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
}

void selection(int arr[], int size) {
	int index;
	for (int i = 0; i < size; i++) {
		index = minimum(arr, i, size - 1);
		swap(&arr[i], &arr[index]);
	}
}

int minimum(int arr[], int low, int high) {
	int mini;
	mini = low;
	for (int i = low; i <= high; i++) {
		if (arr[i] <= arr[mini]) {
			mini = i;
		}
		else;
	}
	return mini;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}