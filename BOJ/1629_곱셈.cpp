#include <iostream>
using namespace std;

long long a, b, c, k;

long long power(long long b);

/*
	지수법칙 : a^(n+m) = a^n * a^m
	모듈러 성질 : (a*b) % c = (a%c * b%c) % c
*/

int main() {

	cin >> a >> b >> c;
	cout << power(b);

	return 0;
}

long long power(long long b) {

	if (b == 0) return 1;
	if (b == 1) return a % c;

	k = power(b / 2) % c; // 지수법칙을 활용하여 지수 b를 절반으로 나눔

	// b가 짝수일 때
	// a^b = a^(b/2) * a^(b/2)
	if (b % 2 == 0) {
		return k * k % c;
	}

	// b가 홀수 일 때
	// a^b = a^(b/2) * a^(b/2 + 1)
	else {
		return (k * k % c) * (a % c);
	}
}