#include <iostream>
using namespace std;

int main() {
	int costs[4], counts[101] = { 0, }, costSum = 0;

	//요금 입력받기
	for (int i = 1; i <= 3; i++) {
		cin >> costs[i];
	}

	//구간체크
	int in, out;
	for (int i = 0; i < 3; i++) {
		cin >> in >> out;
		for (int j = in; j < out; j++) {
			counts[j]++;
		}
	}

	//요금 계산
	for (int count : counts) {
		if (count != 0) {
			costSum += (count * costs[count]);
		}
	}
	cout << costSum << "\n";

	return 0;
}