#include <iostream>
using namespace std;

long long a, b, c, k;

long long power(long long b);

/*
	������Ģ : a^(n+m) = a^n * a^m
	��ⷯ ���� : (a*b) % c = (a%c * b%c) % c
*/

int main() {

	cin >> a >> b >> c;
	cout << power(b);

	return 0;
}

long long power(long long b) {

	if (b == 0) return 1;
	if (b == 1) return a % c;

	k = power(b / 2) % c; // ������Ģ�� Ȱ���Ͽ� ���� b�� �������� ����

	// b�� ¦���� ��
	// a^b = a^(b/2) * a^(b/2)
	if (b % 2 == 0) {
		return k * k % c;
	}

	// b�� Ȧ�� �� ��
	// a^b = a^(b/2) * a^(b/2 + 1)
	else {
		return (k * k % c) * (a % c);
	}
}