#include <iostream>
using namespace std;

void numarr(int arr[], int one);
void printarr(int arr[]);
void sumarray(int sumarr[], int one[], int two[]);
void fibonacci(int n, int nth[]);
void copyarray(int from[], int to[]);
int main() {
	int term;
	int nthterm[63];
	cout << "Enter index of term to be generated: ";
	cin >> term;
	fibonacci(term, nthterm);
	cout << "Did the function work?" << "\n";
	printarr(nthterm);

}

void numarr(int arr[], int one) {
	for (int i = 0; i < 63; i++) {
		arr[i] = one % 10;
		one /= 10;
	}
}
void printarr(int arr[]) {
	bool stop = false;
	for (int i = 62; i >= 0; i--) {
		if (arr[i] == 0 && !stop) {
			if (i == 0) cout << arr[i];
		}
		else if (arr[i] != 0 && !stop) {
			cout << arr[i];
			stop = true;
		}
		else { cout << arr[i]; }
	}
}
void sumarray(int sumarr[], int one[], int two[]) {
	//int sumar[63];
	int tempsum;
	int carry;
	carry = 0;
	for (int i = 0; i < 63; i++) {
		tempsum = one[i] + two[i] + carry;
		sumarr[i] = tempsum % 10;
		carry = tempsum / 10;
	}
}
void copyarray(int from[], int to[]) {
	for (int i = 0; i < 63; i++) {
		to[i] = from[i];
	}
}
//todo: take out the nth[] for final answer i.e. pass nth[] as argument
void fibonacci(int n, int nth[]) {
	//int nth[63];
	int one = 0;
	int two = 1;
	int first[63];
	int second[63];
	numarr(first, one);
	numarr(second, two);
	int temp;
	temp = n;
	if (n == 1) {
		//printarr(first);
		copyarray(first, nth);
	}
	else if (n == 2) {
		copyarray(second, nth);
	}
	else {
		//printarr(first);
		while (temp > 2) {
			sumarray(nth, first, second);
			//printarr(nth);
			copyarray(second, first);
			copyarray(nth, second);
			temp--;
		}
	}
}