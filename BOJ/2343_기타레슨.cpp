#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int lectureNum, bluerayNum, input;
	int l, r = 0, mid = 0; // left, right, mid
	vector<int> lectures;

	// 1. Input
	cin >> lectureNum >> bluerayNum;
	for (int i = 0; i < lectureNum; i++) {
		cin >> input;
		lectures.push_back(input);
		r += input;
	}

	// 2. SearchByBinary
	l = *max_element(lectures.begin(), lectures.end());
	
	while (l <= r) {
		mid = (l + r) / 2;

		int sum = 0, count = 0;
		for (int i = 0; i < lectureNum; i++) {
			if (sum + lectures[i] > mid) {
				count++;
				sum = 0;
			}
			sum += lectures[i];
		}
		if (sum != 0) count++;

		if (count > bluerayNum) l = mid + 1;
		else  r = mid - 1; 
	}

	// 3. Output
	cout << l << "\n";

	return 0;
}