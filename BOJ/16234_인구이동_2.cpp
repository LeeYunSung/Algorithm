#include <iostream>
#include <queue>
#include <cmath> // abs
#include <cstring> // memset
using namespace std;

const int MAX_SIZE = 51;
const int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };

int mapSize, minGap, maxGap, moveCount;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool isMoved = false;

void BFS(int x, int y);

int main() {
	cin >> mapSize >> minGap >> maxGap;

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		isMoved = false;
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				BFS(j, i); // 모든 위치의 나라에서 BFS 수행
			}
		}
		if (!isMoved) {
			break;
		}
		else {
			moveCount++;
			memset(visited, false, sizeof(visited));
		}
	}

	cout << moveCount << "\n";

	return 0;
}

void BFS(int x, int y) {
	if (visited[y][x]) return;

	visited[y][x] = true;
	
	queue<pair<int, int>> q; // BFS 탐색을 위한 queue
	queue<pair<int, int>> countryQ; // 연합국들을 저장할 queue
	
	q.push(make_pair(x, y));
	countryQ.push(make_pair(x, y));

	int peopleSum = 0;
	peopleSum += map[y][x]; // 우리나라 인원수 추가

	int countrySum = 0;
	countrySum += 1; // 우리나라 개수 추가

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0];
			int ny = yy + dir[i][1];
			int peopleGap = abs(map[yy][xx] - map[ny][nx]); // 인구차이
			if (nx >= 0 && nx < mapSize && ny >= 0 && ny < mapSize) {
				if (peopleGap >= minGap && peopleGap <= maxGap && !visited[ny][nx]) {
					visited[ny][nx] = true;
					countrySum++;
					peopleSum += map[ny][nx];
					isMoved = true;
					q.push(make_pair(nx, ny));
					countryQ.push(make_pair(nx, ny));
				}
			}
		}
	}

	// 연합국 인구 수 통일
	while (!countryQ.empty()) {
		int qx = countryQ.front().first;
		int qy = countryQ.front().second;

		map[qy][qx] = peopleSum / countrySum;
		
		countryQ.pop();
	}
}