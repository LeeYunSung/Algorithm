#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int num, money, maxMoney, moneySum = 0;
	vector<int> moneyList;

	// Input
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> money;
		moneyList.push_back(money);
		moneySum += money;
	}
	sort(moneyList.begin(), moneyList.end());
	cin >> maxMoney;

	// 이분탐색
	if (moneySum > maxMoney) {
		int start = 0; // 시작점 0
		int end = moneyList[num - 1]; // 끝점 가장 큰 돈
		int budget = 0; // 최종 선정된 예산

		while (start <= end) {
			moneySum = 0;
			int mid = (start + end) / 2;
			for (int i = 0; i < num; i++) {
				moneySum += min(moneyList[i], mid);
			}

			if (maxMoney >= moneySum) { // 돈의 합이 예산 안에 들어오면
				budget = mid; // 정답으로 체크하고 더 큰 돈이 할당될 수 있는 지 탐색
				start = mid + 1;
			}
			else { // 돈의 합이 예산 안에 안들어오면
				end = mid - 1; // 더 작은 돈이 할당될 수 있는지 체크
			}
		}
		cout << budget;
	}
	else {
		cout << moneyList[num-1] << "\n";
	}
	

	return 0;
}