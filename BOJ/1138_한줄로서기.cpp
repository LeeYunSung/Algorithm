#include <iostream>
#include <vector>
using namespace std;

int main() {
	int personNum, tallPersonNum;
	cin >> personNum;
	vector<int> peopleLine(personNum, 0);

	for (int i = 0; i < personNum; i++) {
		cin >> tallPersonNum;

		int tallPersonPositionNum = -1;
		for (int j = 0; j < personNum; j++) {

			// �ڱ⺸�� Űū ��� ���ܵ� �ڸ� ���� ���ϱ�
			if (peopleLine[j] == 0) {
				tallPersonPositionNum++;
			}

			// Űū ���(0��)�� tallPersonNum �̻� ���Դ��� üũ
			if (tallPersonPositionNum == tallPersonNum) {
				peopleLine[j] = i + 1; // �ټ���
				break;
			}
		}
	}
	
	for (int i = 0; i < personNum; i++) {
		cout << peopleLine[i] << " ";
	} cout << "\n";

	return 0;
}