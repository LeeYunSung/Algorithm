#include <iostream>
#include <cmath>
using namespace std;

void MakePrimeTable();
bool canGoldbach(int num);

const int MAX_SIZE = 1000000;
bool primeTable[MAX_SIZE + 1];

int main() {
	int num;
	bool answer = true;

	MakePrimeTable();

	while (true) {
		cin >> num;
		if (num == 0) break;
		if (!canGoldbach(num)) cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}

void MakePrimeTable() {//�����佺�׳׽��� ü
	for (int i = 0; i < 1000001; i++) primeTable[i] = true;

	for (int i = 2; i <= sqrt(MAX_SIZE); i++) {//2���� �Ҽ��Ǻ��Ϸ� gogo
		if (primeTable[i] == 0) {
			for (int j = 2; i*j <= MAX_SIZE; j++) {//�� ����� ��� false�� �ٲ�
				primeTable[i*j] = false;
			}
		}
	}
}

bool canGoldbach(int num) {
	for (int i = 3; i <= num / 2; i++) {//3���� �Ҽ� �Ǻ�
		if (primeTable[i] && primeTable[num - i]) {
			cout << num << " = " << i << " + " << num - i << "\n";
			return true;
		}
	}
	return false;
}