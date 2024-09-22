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

	// �̺�Ž��
	if (moneySum > maxMoney) {
		int start = 0; // ������ 0
		int end = moneyList[num - 1]; // ���� ���� ū ��
		int budget = 0; // ���� ������ ����

		while (start <= end) {
			moneySum = 0;
			int mid = (start + end) / 2;
			for (int i = 0; i < num; i++) {
				moneySum += min(moneyList[i], mid);
			}

			if (maxMoney >= moneySum) { // ���� ���� ���� �ȿ� ������
				budget = mid; // �������� üũ�ϰ� �� ū ���� �Ҵ�� �� �ִ� �� Ž��
				start = mid + 1;
			}
			else { // ���� ���� ���� �ȿ� �ȵ�����
				end = mid - 1; // �� ���� ���� �Ҵ�� �� �ִ��� üũ
			}
		}
		cout << budget;
	}
	else {
		cout << moneyList[num-1] << "\n";
	}
	

	return 0;
}