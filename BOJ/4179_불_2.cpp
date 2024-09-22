#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAP_SIZE = 1001;
const int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };

int row, col, moveTime;
char map[MAP_SIZE][MAP_SIZE];
int fireMap[MAP_SIZE][MAP_SIZE]; // 불 번지는 BFS
int personMap[MAP_SIZE][MAP_SIZE]; // 지훈 이동하는 BFS

void FireMapByBFS(queue<pair<int, int>> firePos);
void PersonMapByBFS(queue<pair<int, int>> jihoonPos);
bool canMove(int x, int y);

int main() {
	queue<pair<int, int>> firePos;
	queue<pair<int, int>> jihoonPos;

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'J') {
				jihoonPos.push(make_pair(i, j));
				personMap[i][j] = 1;
			}
			if (map[i][j] == 'F') {
				firePos.push(make_pair(i, j));
				fireMap[i][j] = 1;
			}
		}
	}

	FireMapByBFS(firePos);
	PersonMapByBFS(jihoonPos);

	if (moveTime != 0) {
		cout << moveTime << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}

void FireMapByBFS(queue<pair<int, int>> firePos) {
	while (!firePos.empty()) {
		int x = firePos.front().first;
		int y = firePos.front().second;
		firePos.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (canMove(x, y) && fireMap[nx][ny] == 0) {
				fireMap[nx][ny] = fireMap[x][y] + 1;
				firePos.push({ nx, ny });
			}
		}
	}
}

void PersonMapByBFS(queue<pair<int, int>> jihoonPos) {
	while (!jihoonPos.empty()) {
		int x = jihoonPos.front().first;
		int y = jihoonPos.front().second;
		jihoonPos.pop();

		// 탈출조건
		if (x == row - 1 || y == col - 1 || x == 0 || y == 0) {
			moveTime = personMap[x][y];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (canMove(nx, ny) && personMap[nx][ny] == 0) {
				if (fireMap[nx][ny] > personMap[x][y] + 1 || fireMap[nx][ny] == 0) {
					personMap[nx][ny] = personMap[x][y] + 1;
					jihoonPos.push({ nx, ny });
				}
			}
		}
	}
}

bool canMove(int x, int y) {
	if (x >= 0 && x < row && y >= 0 && y < col) {
		if (map[x][y] != '#') {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}