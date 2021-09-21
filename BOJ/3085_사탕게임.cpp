#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ChooseCandy(char **map, int n);
void CountCandy(char **map, int n);

int candy_max;

int main() {
	int n = 0;//�� ũ��. 3 �� n �� 50
	cin >> n;

	//�� �����Ҵ�
	char **map = new char*[n];
	for (int i = 0; i < n; i++)
		map[i] = new char[n];

	//�������� �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	ChooseCandy(map, n);
	cout << candy_max << "\n";
}

void ChooseCandy(char **map, int n) {
	int dir[2][2] = { {0,1},{1,0} };//����ĭ�� �����ʰ� �Ʒ����� �����Ͽ� ���� �ٸ��� �Ǵ��Ұž�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			//1. (������ ���� �ٸ�) ������ �� ĭ�� ����.
			for (int d = 0; d < 2; d++) {
				int next_x = i + dir[d][0];
				int next_y = j + dir[d][1];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
					//2. �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�.
					swap(map[i][j], map[next_x][next_y]);
					//3. ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� ã�´�.
					CountCandy(map, n);
					//4. �ٽ� ������ ��ȯ�ؼ� ������� �ٲ���� ��Ž���ϸ� �ִ밪�� ã�´�.
					swap(map[i][j], map[next_x][next_y]);
				}
			}
		}
	}
}

void CountCandy(char **map, int n) {
	char color;
	int count;

	//�� ī��Ʈ
	for (int i = 0; i < n; i++) {//��
		count = 1;
		color = map[i][0];//�� ���� ù��° �÷�(0��)�� �� �÷��� �д�.
		for (int j = 1; j < n; j++) {//��
			if (map[i][j] == color) count++;//���� �÷��� ������ �÷� ����(count)�� 1 �÷��ش�. 
			else {//���� �÷��� �ٸ���, ���� �÷��� �ٽ� ���÷��� �־��ְ� �÷� ������ 1�� �ʱ�ȭ���ش�.
				color = map[i][j];
				if (candy_max < count) candy_max = count;//������� ���� count�� �ִ밪�� ���ؼ� �������ش�.
				count = 1;
			}
		}
		if (candy_max < count) candy_max = count;//�� ���� ������ ������ ���� ������ ������ �� else���� �ִ밪 ���źκ� ������ ���ϹǷ�, �������� �ѹ��� �ִ밪�� �񱳰������ش�.
	}

	//�� ī��Ʈ
	for (int j = 0; j < n; j++) {//��
		count = 1;
		color = map[0][j];//�� ���� ù��° �÷�(0��)�� �� �÷��� �д�.
		for (int i = 1; i < n; i++) {//��
			if (map[i][j] == color) count++;//�Ʒ��� �÷��� ������ �÷� ����(count)�� 1 �÷��ش�. 
			else {//�Ʒ��� �÷��� �ٸ���, ���� �÷��� �ٽ� ���÷��� �־��ְ� �÷� ������ 1�� �ʱ�ȭ���ش�.
				color = map[i][j];
				if (candy_max < count) candy_max = count;//������� ���� count�� �ִ밪�� ���ؼ� �������ش�.
				count = 1;
			}
		}
		if (candy_max < count) candy_max = count;//�� ���� ������ ������ ���� ������ ������ �� else���� �ִ밪 ���źκ� ������ ���ϹǷ�, �������� �ѹ��� �ִ밪�� �񱳰������ش�.
	}
}