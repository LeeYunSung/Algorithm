#include <iostream>
using namespace std;

void Input();
void CalculateYear(int E, int S, int M);

int main() {
	Input();
	return 0;
}

void Input() {
	int E, S, M;
	cin >> E >> S >> M;
	CalculateYear(E, S, M);
}

void CalculateYear(int E, int S, int M) {
	int e = 1, s = 1, m = 1;
	for (int year = 1; ; year++) {
		if (e % 15 == E % 15 &&
			s % 28 == S % 28 &&
			m % 19 == M % 19){
			cout << year;
			break;
		}e++, s++, m++;
	}
}