#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX_SIZE = 1000000;

int main() {
	vector<int> primeTable;
	bool primeNoCheckTable[MAX_SIZE + 1];
	for (int i = 2; i*i <= MAX_SIZE; i++) {//2부터 소수판별하러 gogo
		if (!primeNoCheckTable[i]) {
			if(i != 2) primeTable.push_back(i);
			for (int j = i + i; j <= MAX_SIZE; j += i) {//그 배수를 모두 소수 확인을 끝냈다는 의미로 true로 바꿈
				primeNoCheckTable[j] = true;
			}
		}
	}

	int num;
	bool answer;
	while (true) {
		scanf("%d", &num);
		if (num == 0) break;
		for (int prime : primeTable) {
			if (!primeNoCheckTable[num - prime]) {
				printf("%d = %d + %d\n", num, prime, num - prime);
				answer = true;
				break;
			}
		}
		if (!answer) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}