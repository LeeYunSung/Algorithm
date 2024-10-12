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
		num = numList[i]; // ã�� ����
		
		// �̺�Ž��
		int left = 0;
		int right = numList.size()-1;
		int sum = 0;
		while (left < right) {
			sum = numList[left] + numList[right];

			// ���� ��
			if (sum == num) {
				if (left != i && right != i) {
					goodNumCount++;
					break;
				}
				// �ٸ� ���� ����ص� sum �� ������ Ȯ��
				else if (left == i) left++;
				else if (right == i) right--;
			}
			else if (sum < num) left++; // �� ū �� ���ϱ�
			else if (sum > num) right--; // �� ���� �� ���ϱ�
		}
	}
	cout << goodNumCount << "\n";

	return 0;
}