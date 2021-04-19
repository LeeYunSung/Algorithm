#include <iostream>
#include <queue> //queue �ڷᱸ��
#include <utility> //pair queue ����� ����
using namespace std;

const int MAX = 101;//������ �ִ� ũ��

int row, column; // ������ ũ��(��, ��)
int map[MAX][MAX]; // ����
bool visited[MAX][MAX]; //�湮üũ
int direction[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} }; //Ž���� �����¿� ����

void searchBFS(int, int);

int main() {
	//Input
	cin >> row >> column;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			scanf_s("%1d", &map[i][j]); // ������� ���ڸ� ���پ� �Է¹޴� ��
		}
	}
	//Search
	searchBFS(0, 0);

	//Output
	cout << map[row-1][column-1];
}

void searchBFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = cur_x + direction[i][0];
			int dy = cur_y + direction[i][1];
			if (map[dx][dy] == 1 && !visited[dx][dy] 
					&& dx >= 0 && dx < row && dy >= 0 && dy < column) {
				visited[dx][dy] = true;
				q.push(make_pair(dx, dy));
				map[dx][dy] = map[cur_x][cur_y]+1;
			}
		}
	}
}