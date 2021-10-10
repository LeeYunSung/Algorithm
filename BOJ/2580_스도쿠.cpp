#include <iostream>
#include <vector>
using namespace std;

void Input();
void Stocoo(int blank_index);
bool CheckNumber(int x, int y, int num);
void Output();

int map[9][9];
vector<pair<int, int>> blank_position;

int main() {
	Input();
	Stocoo(0);
	Output();
	return 0;
}

void Input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank_position.push_back(make_pair(i, j));
			}
		}
	}
}

void Stocoo(int blank_index) {
	if (blank_index == blank_position.size()) {
		Output();
		exit(0); //��ΰ� 0���� �̷���� ������ó�� ���� �������� ���� �ִµ�,
				//�׷� �� ���� ù��°�� ������ ���� �������� ó���ϰ� ���̻� ������ �ʵ���. �����Ų��.
	}
	int x = blank_position[blank_index].first;
	int y = blank_position[blank_index].second;

	for (int num = 1; num < 10; num++) { // 1, 2, 3, 4, 5, 6, 7, 8, 9 �ϳ��� �־��
		//���ǿ� �´��� üũ
		if (CheckNumber(x, y, num)) {
			//���ǿ� ������ ���� blank ä�췯����
			map[x][y] = num;
			Stocoo(blank_index+1);//*****����: blank_index++�� ������ �ȵ鰡��
			//������ ������ ��� return ���� ��!
			//Backtracking���� �ٽ� gogo!
			map[x][y] = 0;//???????? �� ������ ������ �� �ȵɱ�......

		}
		//���ǿ� ���� ������ ���� ���� �־��
	}
}

bool CheckNumber(int x, int y, int num) {
	//����
	for (int col = 0; col < 9; col++) {
		if (y != col && map[x][col] == num) {
			return false;
		}
	}
	//����
	for (int row = 0; row < 9; row++) {
		if (x != row && map[row][y] == num) {
			return false;
		}
	}
	//3x3
	for (int row = x / 3 * 3; row < x / 3 * 3 + 3; row++) {//0,1,2,3,4,5,6,7,8,9 �������� ����
		for (int col = y / 3 * 3; col < y / 3 * 3 + 3; col++) {
			if (x != row && y != col && map[row][col] == num) {
				return false;
			}
		}
	}
	return true;
}

void Output() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}