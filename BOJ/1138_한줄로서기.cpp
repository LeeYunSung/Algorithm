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

			// 자기보다 키큰 사람 남겨둔 자리 개수 구하기
			if (peopleLine[j] == 0) {
				tallPersonPositionNum++;
			}

			// 키큰 사람(0값)이 tallPersonNum 이상 나왔는지 체크
			if (tallPersonPositionNum == tallPersonNum) {
				peopleLine[j] = i + 1; // 줄서기
				break;
			}
		}
	}
	
	for (int i = 0; i < personNum; i++) {
		cout << peopleLine[i] << " ";
	} cout << "\n";

	return 0;
}