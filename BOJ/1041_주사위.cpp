#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long FindMinCase(int n, vector<int> &dice);

int main() {
	int n = 0;
	vector<int> dice;

	cin >> n;

	int num = 0;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		dice.push_back(num);
	}
	//sort(dice.begin(), dice.end()); //*****�ֻ��� �� ��ġ�� ������ �־ ������ �����ϸ� �ȵ�!!
	if (n > 1) {
		cout << FindMinCase(n, dice);//�ֻ��� ���ڰ� �ּҷ� ���� �� �ִ� ��� ã��
	}
	else {
		sort(dice.begin(), dice.end());
		int sum = 0;
		for (int i = 0; i < dice.size() - 1; i++) {
			sum += dice[i];
		}
		cout << sum;
	}
	return 0;
}

long long FindMinCase(int n, vector<int> &dice) {
	int sum1 = 50;//���� 1���� �� �ּ���
	int sum2 = 100;//���� 2���� �� �ּ���
	int sum3 = 150;//���� 3���� �� �ּ���

	for (int i = 0; i < dice.size(); i++) {
		if (sum1 > dice[i]) sum1 = dice[i];
		for (int j = i + 1; j < dice.size(); j++) {
			if (i + j == 5) continue;//���ֺ��� ���� �Բ� ���� �� ����
			if (sum2 > dice[i] + dice[j]) sum2 = dice[i] + dice[j];
			for (int k = j + 1; k < dice.size(); k++) {
				if (j + k == 5 || i + k == 5) continue;//���ֺ��� ���� �Բ� ���� �� ����
				if (sum3 > dice[i] + dice[j] + dice[k]) sum3 = dice[i] + dice[j] + dice[k];
			}
		}
	}
	long long result = 0;
	//��1���� ���̴� ������ŭ �����ֱ�
	result += sum1 * ((long long)(n - 2)*(n - 2) + ((long long)(n - 2)*(n - 1) * 4));
	//��2���� ���̴� ������ŭ �����ֱ�
	result += sum2 * ((n - 2) * 4 + ((n - 1) * 4));
	//��3���� ���̴� ������ŭ �����ֱ�
	result += sum3 * 4;

	return result;
}
