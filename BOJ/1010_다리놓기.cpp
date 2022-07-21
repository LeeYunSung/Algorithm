#include <iostream>
using namespace std;

int main() {
	int testcase, left, right;
	long long answer = 1;

	cin >> testcase;
	while (testcase--) {
		cin >> left >> right;
		answer = 1;
		if (left > right / 2) left = right - left;//5C4 -> 5C1
		for (int i = 0; i < left; i++) {
			answer *= right - i;
			answer /= 1 + i;
		}
		cout << answer << "\n";
	}
	return 0;
}