#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll greenOnionNum, chickenNum;
	ll length, lengthSum = 0;
	ll maxLengh = 0; // answer
	
	vector<int> greenOnions;

	// input
	cin >> greenOnionNum >> chickenNum;
	for (int i = 0; i < greenOnionNum; i++) {
		cin >> length;
		greenOnions.push_back(length);
		lengthSum += length;
	}

	//이분탐색
	ll low = 1, high = 1e9, mid;
	while (low <= high) {
		mid = (low + high) / (1ll *2); // int to long long

		// chicken 개수 세기
		ll count = 0;
		for (int i = 0; i < greenOnionNum; i++) {
			count += greenOnions[i] / mid;
		}

		if (count >= chickenNum) {
			low = mid + 1;
			maxLengh = mid;
		}
		else {
			high = mid - 1;
		}
	}

	// 나머지 파 출력
	cout << lengthSum - maxLengh * chickenNum;

	return 0;
}