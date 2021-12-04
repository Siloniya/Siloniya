#include <iostream>

using namespace std;

int binar(int arr[], int high, int low, int val, int &step);

int main() {
	int size;
	int val = 11;
	int steps = 0;
	int srtArr[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	size = 10;
	/*for (int i = 0; i < size; i++) {
		cout << binar(srtArr, size - 1, 0, srtArr[i]) << "\n";
	}*/
	cout << binar(srtArr, size - 1, 0, 11, steps) << "\n";              //modify the fourth argument to search a different element
	cout << "Number of steps done to search 11 in given array are " << steps << "\n";
}

//int sortedSearch(int arr[], int size, int val) {
//	int start = 0;
//	int end = size - 1;
//	int mid = (start + end) / 2;
//	while (start <= end) {
//		if (arr[mid] == val) return mid;
//		else if (arr[mid] < val) {
//			start = mid + 1;
//			mid = (start + end) / 2;
//		}
//		else {
//			end = mid - 1;
//			mid = (start + end) / 2;
//		}
//	}
//	return -1;
//}
int binar(int arr[], int high, int low, int val, int &step) {
	int mid = (high + low) / 2;
	step++;
	if (arr[mid] == val) return mid;
	else if (low <= high) {
		if (arr[mid] < val) {
			return binar(arr, high, mid + 1, val, step);
		}
		else {
			return binar(arr, mid - 1, low, val, step);
		}
	}
	else { return -1; }
}
