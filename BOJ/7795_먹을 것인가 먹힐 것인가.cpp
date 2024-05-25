#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, aNum, bNum, input, count = 0;
	vector<int> As, Bs;

	cin >> T;
	while (T--) {
		cin >> aNum >> bNum;
		for (int i = 0; i < aNum; i++) {
			cin >> input;
			As.push_back(input);
		}
		for (int j = 0; j < bNum; j++) {
			cin >> input;
			Bs.push_back(input);
		}
		sort(As.begin(), As.end(), greater<int>());
		sort(Bs.begin(), Bs.end(), greater<int>());

		for (int i = 0; i < aNum; i++) {
			for (int j = 0; j < bNum; j++) {
				if (As[i] > Bs[j]) {
					count += bNum - j;
					break;
				}
			}
		}
		cout << count << "\n";

		count = 0;
		As.clear();
		Bs.clear();
	}

	return 0;
}