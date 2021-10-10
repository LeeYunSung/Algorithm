#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Calculation(int n, vector<int> dice);

int main() {
	int n = 0;
	vector<int> dice;

	cin >> n;
	
	int num = 0;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		dice.push_back(num);
	}
	sort(dice.begin(), dice.end()); // �ּұ��ϴ°Ŵϱ� �������� �����ϰ� ����
	cout << Calculation(n, dice);

	return 0;
}

long long Calculation(int n, vector<int> dice) {
	long long result = 0;

	if (n > 1) {
		long long sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += dice[i];//���� 1���϶�, ���� 2���϶�, ���� 3���϶� �ձ��ϱ�.
			switch (i) {
				case 0://��1���� ���̴� ������ŭ �����ֱ�
					result += sum * ((long long)(n - 2)*(n - 2) + ((long long)(n - 2)*(n - 1)*4));
					break;
				case 1://��2���� ���̴� ������ŭ �����ֱ�
					result += sum * ((n - 2) * 4 + (n - 1) * 4);
					break;
				case 2://��3���� ���̴� ������ŭ �����ֱ�
					result += sum*4;
					break;
			}
		}
	}
	else {//�ֻ����� 1����� �� 5���� �ձ��ؼ� ���.
		for (int i = 0; i < dice.size() - 1; i++) {
			result += dice[i];
		}
	}
	return result;
}