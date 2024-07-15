#include <iostream>
#include <vector>
using namespace std;
const int MAX_NUM = 4000001;

void GetPrime(int num);
int GetPrimeCombiNum(int num);

vector<int> primes;

int main() {
	int num;

	cin >> num;
	if (num == 1) {
		cout << 0;
	}
	else {
		GetPrime(num);
		cout << GetPrimeCombiNum(num);
	}
	return 0;
}

void GetPrime(int num) {
	vector<bool> check(num + 1, false);

	//�����佺�׳׽�ü
	for (int i = 2; i <= num; i++) {
		if (!check[i]) {
			primes.push_back(i);
			for (int j = i + i; j <= num; j += i) {
				check[j] = true;
			}
		}
	}
}

//start ~ end ������ ������ ���ϱ�
//1. �������� num ���� ������ end �� ���ϰ� end �ε��� 1 �ø���
//2. �������� num ���� ũ�� start �� ���� start �ε��� 1 �ø���
//3. �������� num �� ���ٸ� primeCombiNum ���� 1 �ø���.
int GetPrimeCombiNum(int num) {
	int primeCombiNum = 0;
	int primeSum = 0;
	int start = 0, end = 0;

	while (start < primes.size()) {
		if (primeSum < num) {
			primeSum += primes[end];
			end++;
			if (end > primes.size()) break;
		}
		else if (primeSum > num) {
			primeSum -= primes[start];
			start++;
		}
		else if (primeSum == num){
			primeCombiNum++;
			primeSum -= primes[start];
			start++;
		}
	}
	return primeCombiNum;
}