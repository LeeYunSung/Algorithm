#include <iostream>
using namespace std;

const int SIZE = 1000001;

int makeOne(int);
int min(int, int);

int main() {
	int num = 0;
	cin >> num;
	cout << makeOne(num) << "\n";
}

int makeOne(int num) {
	int minCountArr[SIZE] = { 0, };
	for (int i = 2; i <= num; i++) {
		minCountArr[i] = minCountArr[i - 1] + 1;
		if (i % 2 == 0) minCountArr[i] = min(minCountArr[i / 2] + 1, minCountArr[i]);
		if (i % 3 == 0) minCountArr[i] = min(minCountArr[i / 3] + 1, minCountArr[i]);
	}
	return minCountArr[num];
}

int min(int a, int b) {
	return a > b ? b : a;
}