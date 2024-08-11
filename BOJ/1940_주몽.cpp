#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int materialNum, conditionNum;
	vector<int> materialList;

	cin >> materialNum >> conditionNum;

	// Input
	int input;
	for (int i = 0; i < materialNum; i++) {
		cin >> input;
		materialList.push_back(input);
	}

	// 투포인터 돌리기 쉽게 정렬
	int start = 0, end = 1, makingCount = 0;
	sort(materialList.begin(), materialList.end());

	// 투포인터 탐색
	while (start <= end && end < materialNum) {
		if (materialList[start] + materialList[end] == conditionNum) {
			makingCount++;
		}

		if (end == materialNum - 1) {
			start++;
			end = start + 1;
		}
		else {
			end++;
		}
	}

	cout << makingCount << "\n";

	return 0;
}