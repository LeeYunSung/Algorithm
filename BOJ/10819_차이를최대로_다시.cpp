#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int length = 0;
	cin >> length;

	int *num_array = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> num_array[i];
	}
	sort(num_array, num_array + length);

	int maxSum = 0;
	do {
		int sum = 0;
		for (int i = 0; i < length-1; i++) {
			sum += abs(num_array[i] - num_array[i+1]);
		}
		maxSum = max(sum, maxSum);
	} while (next_permutation(num_array, num_array + length));

	cout << maxSum;
	delete[] num_array;
}