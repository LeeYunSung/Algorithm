#include <iostream>
using namespace std;
#define SIZE 9

void findMax(int arr[SIZE]);

int main() {
	int arr[SIZE] = { 0, };
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	findMax(arr);
	return 0;
}

void findMax(int arr[SIZE]) {
	int max = arr[0];
	int max_idx = 0;
	for (int i = 1; i < SIZE; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_idx = i;	
		}
	}
	cout << max << "\n";
	cout << max_idx+1;
}

/*
#include <iostream>
using namespace std;

void findMax(int *arr);

int main() {
	int length;
	cin >> length;

	int *arr = new int;
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}
	findMax(arr);
	delete[] arr;

	return 0;
}

void findMax(int *arr) {
	int max = arr[0];
	for (int i = 1; i < sizeof(arr); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
}
*/