#include <iostream>
using namespace std;

int findCombination(int, int);

int main() {
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int sum = 0, count = 0;
		cin >> sum;
		cout << findCombination(0, sum) << "\n";
	}
}

int findCombination(int currentSum, int sum) {
	if (currentSum == sum) return 1;
	if (currentSum > sum) return 0;

	int count = 0;
	for (int i = 1; i <= 3; i++) {//1, 2, 3
		count += findCombination(currentSum + i, sum);

	}
	return count;
}