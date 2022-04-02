#include <iostream>
#include <cmath>
using namespace std;

bool isDecimal(int num);

int main() {
	int num_count, num, sum = 0;

	cin >> num_count;
	for (int i = 0; i < num_count; i++) {
		cin >> num;
		if (isDecimal(num)) sum++;
	}
	cout << sum << "\n";
	
	return 0;
}

//�Ҽ�: 1�� �ڱ��ڽ� �ܿ��� ���������� �ʴ� ��
//pow(������), sqrt(��Ʈ)
bool isDecimal(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if(num%i == 0) return false;
	}
	return (num != 1) ? true : false;
}