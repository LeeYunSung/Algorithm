#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Rotation(vector<vector<int>> &v, int rotationIndex);

int main() {
	//input
	int row, col, rotationNum;
	cin >> row >> col >> rotationNum;
	vector<vector<int>> v(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> v[i][j];
		}
	}

	//rotation �ؾ��� Ƚ��
	while (rotationNum) {
	//rotation �ؾ��� �׸� ����
		for (int rotationIndex = 0; rotationIndex < min(row, col) / 2; rotationIndex++) {
			Rotation(v, rotationIndex);
		}
		rotationNum--;
	}

	//output
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void Rotation(vector<vector<int>> &v, int rotationIndex) {
	//rotation ������
	int row = rotationIndex, col = rotationIndex;
	int prevValue = v[row][col];

	//����
	while (row < v.size() - 1 - rotationIndex) { 
		int nextValue = v[row + 1][col];
		v[row + 1][col] = prevValue;
		prevValue = nextValue;
		row++;
	}
	//�Ʒ�
	while (col < v[0].size() - 1 - rotationIndex) {
		int nextValue = v[row][col + 1];
		v[row][col + 1] = prevValue;
		prevValue = nextValue;
		col++;
	}
	//������
	while (row >= rotationIndex + 1) {
		int nextValue = v[row - 1][col];
		v[row - 1][col] = prevValue;
		prevValue = nextValue;
		row--;
	}
	//��
	while (col >= rotationIndex + 1) {
		int nextValue = v[row][col - 1];
		v[row][col - 1] = prevValue;
		prevValue = nextValue;
		col--;
	}
}