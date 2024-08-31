#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int MAX_SIZE = 126;

int mapSize;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE]; // visited 배열에 최소이동비용 적어가며 탐색
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };


int SearchMinCostByBFS();

int main() {

	for (int index = 1; ; index++) {

		cin >> mapSize;
		if (mapSize == 0) break;

		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				cin >> map[i][j];
				visited[i][j] = INT_MAX;
			}
		}
		cout << "Problem " << index << ": " << SearchMinCostByBFS() << "\n";
	}

	return 0;
}


int SearchMinCostByBFS() {
	queue<pair<int, int>> q;
	
	q.push(make_pair( 0,0 ));
	visited[0][0] = map[0][0];

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dir[i][0];
			int nextY = curY + dir[i][1];
			if (nextX >= 0 && nextX < mapSize && nextY >= 0 && nextY < mapSize) {
				if (visited[nextX][nextY] > visited[curX][curY] + map[nextX][nextY]) {
					visited[nextX][nextY] = visited[curX][curY] + map[nextX][nextY];
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
	return visited[mapSize - 1][mapSize - 1];
}