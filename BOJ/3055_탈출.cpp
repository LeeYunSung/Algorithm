#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;//��,��
char map[51][51];//��������
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�̵��� ����
queue<pair<int, int>> positions;//����ġ ��ġ��
queue<pair<int, int>> waters;//�� ��ġ��
int moveTime;//�̵��ð�
bool result = false;//����

void InputMap();//�������� �ޱ�
void SprayWater();//�� �۶߸���
void MoveBFS();//����ġ �̵��ϱ�

int main() {
	InputMap();
	//����ġ�� ���̻� �̵��� �� ���� �� ����
	while (!positions.empty()) {
		SprayWater();
		MoveBFS();
		moveTime += 1;
		if (result) {
			cout << moveTime;
			return 0;
		}
	}
	cout << "KAKTUS";
	return 0;
}

void InputMap() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			switch (map[i][j]) {
				case 'S':
					positions.push(make_pair(i, j));
					break;
				case '*':
					waters.push(make_pair(i, j));
					break;
			}
		}
	}
}

void SprayWater() {
	int waterSize = waters.size();
	for (int i = 0; i < waterSize; i++) {
		int curX = waters.front().first;
		int curY = waters.front().second;
		waters.pop();

		for (int j = 0; j < 4; j++) {
			int nx = curX + dir[j][0];
			int ny = curY + dir[j][1];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*';//* �� ǥ���������ν� �湮üũ�� ������
					waters.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void MoveBFS(){
	int positionSize = positions.size();
	for (int i = 0; i < positionSize; i++) {
		int curX = positions.front().first;
		int curY = positions.front().second;
		positions.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dir[i][0];
			int ny = curY + dir[i][1];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (map[nx][ny] == 'D') {
					result = true;
					return;
				}
				if (map[nx][ny] == '.') {
					positions.push(make_pair(nx, ny));
					map[nx][ny] = 'S';//S �� ǥ���������ν� �湮üũ�� ������
				}
			}
		}
	}
}
