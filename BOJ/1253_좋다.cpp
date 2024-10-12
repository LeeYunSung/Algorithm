#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, goodNumCount = 0;
	cin >> num;
	vector<int> numList(num, 0);

	for (int i = 0; i < num; i++) {
		cin >> numList[i];
	}
	sort(numList.begin(), numList.end());

	for (int i = 0; i < numList.size(); i++) {
		num = numList[i]; // 찾을 숫자
		
		// 이분탐색
		int left = 0;
		int right = numList.size()-1;
		int sum = 0;
		while (left < right) {
			sum = numList[left] + numList[right];

			// 좋은 수
			if (sum == num) {
				if (left != i && right != i) {
					goodNumCount++;
					break;
				}
				// 다른 수를 사용해도 sum 과 같은지 확인
				else if (left == i) left++;
				else if (right == i) right--;
			}
			else if (sum < num) left++; // 더 큰 수 더하기
			else if (sum > num) right--; // 더 작은 수 더하기
		}
	}
	cout << goodNumCount << "\n";

	return 0;
}