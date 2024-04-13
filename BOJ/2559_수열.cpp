#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

	int totalDay, continueDay, max = INT_MIN;

	cin >> totalDay >> continueDay;

	vector<int> temperates(totalDay + 1, 0);
	for (int i = 1; i < totalDay + 1; i++) {
		cin >> temperates[i];
		temperates[i] += temperates[i - 1]; //prefix sum
	}


	for (int i = 1; i < totalDay + 1; i++) {
		if (i + continueDay > totalDay) break;

		int sum = temperates[continueDay + (i - 1)] - temperates[i - 1];
		if (sum > max) max = sum;
	}

	cout << max;

	return 0;
}