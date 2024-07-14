#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int numSize, targetSum, num, combiCount = 0;
	vector<int> nums;

	cin >> numSize;
	for (int i = 0; i < numSize; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	cin >> targetSum;

	int left = 0;
	int right = numSize - 1;
	while (left < right) {
		if (nums[left] + nums[right] == targetSum) {
			combiCount++;
			right--;
		}
		else if (nums[left] + nums[right] > targetSum) {
			right--;
		}
		else if (nums[left] + nums[right] < targetSum) {
			left++;
		}
	}

	cout << combiCount;

	return 0;
}