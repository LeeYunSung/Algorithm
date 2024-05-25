#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int day, outNum, input;
	int l = 0, h = 0, mid;
	vector<int> moneys;

	cin >> day >> outNum;
	for (int i = 0; i < day; i++) {
		cin >> input;
		h += input;
		l = max(l, input);
		moneys.push_back(input);
	}

	while (l <= h) {
		mid = (l + h) / 2;

		int leftMoney = mid;
		int outCount = 1;

		for (int i = 0; i < moneys.size(); i++) {
			if (moneys[i] > leftMoney) {
				leftMoney = mid;
				outCount += 1;
			}
			leftMoney -= moneys[i];
		}
		if (outCount > outNum) l = mid + 1;
		else h = mid - 1;
	}
	cout << mid << "\n";

	return 0;
}