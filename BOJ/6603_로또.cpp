#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lotto(vector<int>&);

int main() {
	int k = 0;
	vector<int> nums;

	do {
		cin >> k;
		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			nums.push_back(num);
		}
		lotto(nums);
		cout << "\n";
		nums.clear();
	} while (k != 0);
}

void lotto(vector<int> &nums) {
	vector<int> selected_num;// 0, 1로 표현한 대체 수열
	for (int i = 0; i < 6; i++) {
		selected_num.push_back(0);
	}
	for (int j = 6; j < nums.size(); j++) {
		selected_num.push_back(1);
	}

	do {
		for (int i = 0; i < nums.size(); i++) {
			if (selected_num[i] == 0) {
				cout << nums[i] << " ";
			} else continue;
		}cout << "\n";
	} while (next_permutation(selected_num.begin(), selected_num.end()));
}