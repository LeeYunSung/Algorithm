#include <iostream>
#include <climits>
using namespace std;

int row, col, maxMoveCount;
char map[21][21];
bool visited[26] = { false, }; // alphabet 방문체크
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

void DFS(int x, int y, int moveCount);

int main() {

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	visited[map[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << maxMoveCount << "\n";

	return 0;
}


void DFS(int x, int y, int moveCount) {
	maxMoveCount = max(maxMoveCount, moveCount);

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < row && nx >= 0 && ny < col && ny >= 0) {
			if (!visited[map[nx][ny] - 'A']) {
				visited[map[nx][ny] - 'A'] = true;
				DFS(nx, ny, moveCount + 1);
				visited[map[nx][ny] - 'A'] = false; // 다른 경로에서 재탐색해야하므로 false 로 풀어주기
			}
		}
	}
}