#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int aNum, bNum, input, sum = 0;
	int l, h, mid; // 이분탐색을 위한 변수
	vector<int> As, Bs;

	// Input
	cin >> aNum >> bNum;
	for (int i = 0; i < aNum; i++) {
		cin >> input;
		As.push_back(input);
	}
	for (int i = 0; i < bNum; i++) {
		cin >> input;
		Bs.push_back(input);
	}
	sort(As.begin(), As.end());
	sort(Bs.begin(), Bs.end());

	// Search
	for (int i = 0; i < aNum; i++) {
		l = 0;
		h = bNum;

		while (l <= h) {
			mid = (l + h) / 2;

			if (As[i] == Bs[mid]) {
				As[i] = Bs[mid] = 0;
				break;
			}
			else if (As[i] > Bs[mid]) l = mid + 1;
			else h = mid - 1;
		}
	}

	// Count & Output
	for (int i = 0; i < aNum; i++) {
		if (As[i] > 0) sum += 1;
	}
	for (int i = 0; i < bNum; i++) {
		if (Bs[i] > 0) sum += 1;
	}
	cout << sum << "\n";

	return 0;
}