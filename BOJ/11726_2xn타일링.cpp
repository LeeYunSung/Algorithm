#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int *d = new int[num + 1]{1, 1, };//momorization.

	for (int i = 2; i < num + 1; i++) {// ���� ������ Ȱ���ؼ� ū ���� ���ϴ� ����� top-down ���
		d[i] = (d[i - 1] + d[i - 2]) % 10007; //d[n-1] = �������(n-1)�� �����ʿ� | ����� ���� ����. d[n-2] = �������(n-2)�� �����ʿ� = ����� ���� ����
	}
	cout << d[num];

	delete[] d;
}
