#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mergesort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void printArr(int arr[], int size);

int main() {
	int sort[] = { 9, 4, 7, 6, 3, 1 };
	int sortn[] = { 2, 5, 5, 7, 0, 6, 4 };
	cout << "Before sorting: ";
	printArr(sort, 6);
	mergesort(sort, 0, 5);
	cout << "After sorting: ";
	printArr(sort, 6);
	cout << "\n";
	cout << "Before sorting: ";
	printArr(sortn, 7);
	cout << "After sorting: ";
	mergesort(sortn, 0, 6);
	printArr(sortn, 7);
}

void mergesort(int arr[], int low, int high) {
	int mid = (low + high) / 2;
	if (low < high) {
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
void merge(int arr[], int low, int mid, int high) {
	int* sorted = new int[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else {
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}
	while (j <= high) {
		sorted[k] = arr[j];
		k++;
		j++;
	}
	while (i <= mid) {
		sorted[k] = arr[i];
		k++;
		i++;
	}
	for (int in = low; in <= high; in++) {
		arr[in] = sorted[in - low];
	}
	delete[] sorted;
}
void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}





