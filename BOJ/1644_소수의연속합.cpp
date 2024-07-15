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

	//에라토스테네스체
	for (int i = 2; i <= num; i++) {
		if (!check[i]) {
			primes.push_back(i);
			for (int j = i + i; j <= num; j += i) {
				check[j] = true;
			}
		}
	}
}

//start ~ end 사이의 구간합 구하기
//1. 구간합이 num 보다 작으면 end 값 더하고 end 인덱스 1 올리기
//2. 구간합이 num 보다 크면 start 값 빼고 start 인덱스 1 늘리기
//3. 구간합이 num 과 같다면 primeCombiNum 개수 1 늘리기.
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