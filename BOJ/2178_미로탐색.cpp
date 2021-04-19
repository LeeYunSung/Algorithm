#include <iostream>
#include <queue> //queue 자료구조
#include <utility> //pair queue 사용을 위해
using namespace std;

const int MAX = 101;//지도의 최대 크기

int row, column; // 지도의 크기(행, 열)
int map[MAX][MAX]; // 지도
bool visited[MAX][MAX]; //방문체크
int direction[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} }; //탐색할 상하좌우 방향

void searchBFS(int, int);

int main() {
	//Input
	cin >> row >> column;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			scanf_s("%1d", &map[i][j]); // 공백없는 숫자를 한줄씩 입력받는 법
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