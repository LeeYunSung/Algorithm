#include <iostream>
#include <algorithm>
using namespace std;

int sticker[2][100001];

int searchMaxScore(int);

int main() {
	int testcase = 0;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int column = 0;
		cin >> column;

		for (int row = 0; row < 2; row++) {
			for (int col = 1; col <= column; col++) {//�ݺ����� index 2���� �����ϱ� ����
				cin >> sticker[row][col];
			}
		}
		cout << searchMaxScore(column) << "\n";
	}
}

int searchMaxScore(int column) {
	for (int i = 2; i <= column; i++) {
		//�� ��ƼĿ�� ����� ��
		sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
		//�Ʒ� ��ƼĿ�� ����� ��
		sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
	}
	return max(sticker[0][column], sticker[1][column]);
}