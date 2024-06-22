#include <iostream>
using namespace std;

int main() {
	int screenSize = 0, bucketSize = 0, minDistance = 0;
	int appleNum = 0, applePosition = 0, left = 0, right = 0, moveCount = 0;
	
	cin >> screenSize >> bucketSize >> appleNum;
	
	left = 1;
	for (int i = 0; i < appleNum; i++) {
		cin >> applePosition;
		right = left + bucketSize - 1;

		// ����� �ٱ��� ��ġ�� ���� ��
		if (applePosition >= left && applePosition <= right) 
			continue;

		else {
			// ����� �ٱ��Ϻ��� ���ʿ� ���� ��
			if (applePosition < left) {
				moveCount += left - applePosition; // move to left
				left = applePosition;
			}
			// ����� �ٱ��Ϻ��� �����ʿ� ���� ��
			else if (applePosition > right) {
				moveCount += applePosition - right; // move to right
				left += applePosition - right;
			}
		}
	}
	cout << moveCount << "\n";

	return 0;
}