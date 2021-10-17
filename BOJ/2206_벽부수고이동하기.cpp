#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 1001;
int direction[4][2] = { {0,1}, {1,0},{0,-1},{-1,0} };//이동 방향키: 오른쪽, 아래, 왼쪽, 위

class Point {
public:
	int x;
	int y;
	int breakCount;//벽을 부순 횟수. 0 or 1로 표현
	int count;//이동 횟수. 나중에 출력해줘야 함.
	Point(int x, int y, int breakCount, int count) {
		this->x = x;
		this->y = y;
		this->breakCount = breakCount;
		this->count = count;
	}
};

int MoveByBFS(int N, int M, int map[MAX_VALUE][MAX_VALUE]);//BFS를 통한 최단거리 찾기 수행

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
	visited[0][0][0] = true;//벽을 부순 횟수가 0이면서 해당 좌표에 방문했음을 나타냄
	visited[0][0][1] = true;//벽을 부순 횟수가 1이면서 해당 좌표에 방문했음을 나타냄

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
				if (!visited[nx][ny][0]) {//벽 부순 횟수가 0이면서 해당 좌표에 방문한 적이 없는 경우
					if (map[nx][ny] == 0 && currentPoint.breakCount == 0
						|| (map[nx][ny] == 0 && currentPoint.breakCount == 1)){//해당 좌표에 벽이 없고 이전까지 벽 부순 횟수도 0일 경우만 push
						visited[nx][ny][0] = true;
						q.push(Point(nx, ny, 0, currentPoint.count + 1));
					}
				}

				if (!visited[nx][ny][1]) {//벽 부순 횟수가 1이면서 해당 좌표에 방문한 적이 없는 경우
					if ((map[nx][ny] == 1 && currentPoint.breakCount == 0)//해당 좌표에 벽이 있고 벽 부순 횟수가 0인 경우
							|| (map[nx][ny] == 0 && currentPoint.breakCount == 1)) {//or 해당 좌표에 벽이 없고 벽 부순 횟수가 1인 경우
						visited[nx][ny][1] = true;
						q.push(Point(nx, ny, 1, currentPoint.count + 1));
					}
				}
			}
		}
	}
	return -1;
}