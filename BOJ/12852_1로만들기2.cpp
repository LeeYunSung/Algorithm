#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_INT = 1000000;

int main() {
	int num;
	vector<vector<int>> numHistorys;

	cin >> num;

	// Bottom-Up ���� ���ϱ� ���� 1,2,3 ���� �̸� ���س���
	numHistorys.push_back({ 0 });
	numHistorys.push_back({ 1 });
	numHistorys.push_back({ 1, 2 });
	numHistorys.push_back({ 1, 3 });

	for (int i = 4; i <= num; i++) {
		// ���� ���� count ���ϱ�
		int dividedByTwo = MAX_INT;
		int dividedByThree = MAX_INT;
		int minusOne = MAX_INT;

		if (i % 2 == 0) {
			dividedByTwo = numHistorys[i / 2].size();
		}
		if (i % 3 == 0) {
			dividedByThree = numHistorys[i / 3].size();
		}
		minusOne = numHistorys[i - 1].size();
		

		// ���Ϳ� ���� history ä���
		if (dividedByTwo < dividedByThree) {
			if (dividedByTwo < minusOne) {
				numHistorys.push_back(numHistorys[i / 2]);
			}
			else {
				numHistorys.push_back(numHistorys[i - 1]);
			}
		}
		else {
			if (dividedByThree < minusOne) {
				numHistorys.push_back(numHistorys[i / 3]);
			}
			else {
				numHistorys.push_back(numHistorys[i - 1]);
			}
		}
		numHistorys[i].push_back(i);
	}

	// ���
	// count
	cout << numHistorys[num].size() - 1 << "\n";
	// history
	reverse(numHistorys[num].begin(), numHistorys[num].end());
	for (int i = 0; i < numHistorys[num].size(); i++) {
		cout << numHistorys[num][i] << " ";
	}

	return 0;
}