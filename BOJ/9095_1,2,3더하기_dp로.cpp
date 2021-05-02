#include <iostream>
using namespace std;

int sumNum(int);

int sumArray[11] = { 1, 1, 2, 4, 0, };

int main() {
	int testcase = 0, num = 0;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> num;
		cout << sumNum(num)<< "\n";
	}
}

int sumNum(int num) {
	if (num <= 3 || sumArray[num] != 0) {
		return sumArray[num];
	}
	else {
		sumArray[num] = sumNum(num - 1) + sumNum(num - 2) + sumNum(num - 3);
		return sumArray[num];
	}
}