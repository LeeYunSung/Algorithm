#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 1001;
int direction[4][2] = { {0,1}, {1,0},{0,-1},{-1,0} };//�̵� ����Ű: ������, �Ʒ�, ����, ��

class Point {
public:
	int x;
	int y;
	int breakCount;//���� �μ� Ƚ��. 0 or 1�� ǥ��
	int count;//�̵� Ƚ��. ���߿� �������� ��.
	Point(int x, int y, int breakCount, int count) {
		this->x = x;
		this->y = y;
		this->breakCount = breakCount;
		this->count = count;
	}
};

int MoveByBFS(int N, int M, int map[MAX_VALUE][MAX_VALUE]);//BFS�� ���� �ִܰŸ� ã�� ����

int main() {
	int N, M;
	cin >> N >> M;
	int map[MAX_VALUE][MAX_VALUE] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	cout << MoveByBFS(N, M, map);
	return 0;
}


int MoveByBFS(int N, int M, int map[MAX_VALUE][MAX_VALUE]) {
	queue<Point> q;
	bool visited[MAX_VALUE][MAX_VALUE][2] = { false, }; 

	q.push(Point(0,0,0,1));
	visited[0][0][0] = true;//���� �μ� Ƚ���� 0�̸鼭 �ش� ��ǥ�� �湮������ ��Ÿ��
	visited[0][0][1] = true;//���� �μ� Ƚ���� 1�̸鼭 �ش� ��ǥ�� �湮������ ��Ÿ��

	while (!q.empty()) {
		Point currentPoint = q.front();
		q.pop();

		if (currentPoint.x == N - 1 && currentPoint.y == M - 1) {
			return currentPoint.count;
		}
		for (int i = 0; i < 4; i++) {
			int nx = currentPoint.x + direction[i][0];
			int ny = currentPoint.y + direction[i][1];

			if (nx < N && nx >= 0 && ny < M && ny >= 0) {
				if (!visited[nx][ny][0]) {//�� �μ� Ƚ���� 0�̸鼭 �ش� ��ǥ�� �湮�� ���� ���� ���
					if (map[nx][ny] == 0 && currentPoint.breakCount == 0
						|| (map[nx][ny] == 0 && currentPoint.breakCount == 1)){//�ش� ��ǥ�� ���� ���� �������� �� �μ� Ƚ���� 0�� ��츸 push
						visited[nx][ny][0] = true;
						q.push(Point(nx, ny, 0, currentPoint.count + 1));
					}
				}

				if (!visited[nx][ny][1]) {//�� �μ� Ƚ���� 1�̸鼭 �ش� ��ǥ�� �湮�� ���� ���� ���
					if ((map[nx][ny] == 1 && currentPoint.breakCount == 0)//�ش� ��ǥ�� ���� �ְ� �� �μ� Ƚ���� 0�� ���
							|| (map[nx][ny] == 0 && currentPoint.breakCount == 1)) {//or �ش� ��ǥ�� ���� ���� �� �μ� Ƚ���� 1�� ���
						visited[nx][ny][1] = true;
						q.push(Point(nx, ny, 1, currentPoint.count + 1));
					}
				}
			}
		}
	}
	return -1;
}