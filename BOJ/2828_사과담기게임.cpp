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

		// 사과가 바구니 위치에 있을 때
		if (applePosition >= left && applePosition <= right) 
			continue;

		else {
			// 사과가 바구니보다 왼쪽에 있을 때
			if (applePosition < left) {
				moveCount += left - applePosition; // move to left
				left = applePosition;
			}
			// 사과가 바구니보다 오른쪽에 있을 때
			else if (applePosition > right) {
				moveCount += applePosition - right; // move to right
				left += applePosition - right;
			}
		}
	}
	cout << moveCount << "\n";

	return 0;
}