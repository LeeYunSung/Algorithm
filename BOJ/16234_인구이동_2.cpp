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
				BFS(j, i); // ��� ��ġ�� ���󿡼� BFS ����
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
	
	queue<pair<int, int>> q; // BFS Ž���� ���� queue
	queue<pair<int, int>> countryQ; // ���ձ����� ������ queue
	
	q.push(make_pair(x, y));
	countryQ.push(make_pair(x, y));

	int peopleSum = 0;
	peopleSum += map[y][x]; // �츮���� �ο��� �߰�

	int countrySum = 0;
	countrySum += 1; // �츮���� ���� �߰�

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0];
			int ny = yy + dir[i][1];
			int peopleGap = abs(map[yy][xx] - map[ny][nx]); // �α�����
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

	// ���ձ� �α� �� ����
	while (!countryQ.empty()) {
		int qx = countryQ.front().first;
		int qy = countryQ.front().second;

		map[qy][qx] = peopleSum / countrySum;
		
		countryQ.pop();
	}
}