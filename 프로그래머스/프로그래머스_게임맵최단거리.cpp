#include <vector>
#include <queue>
#include <utility>
using namespace std;

int BFS(vector<vector<int>> maps) {
	int direction[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
	queue<pair<int, int>> q;

	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = maps[x][y] + direction[k][0];
			int ny = maps[x][y] + direction[k][1];
			if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps.size()) continue;
			if (maps[nx][ny] == 1) {
				maps[nx][ny] = maps[x][y] + 1;
				if (x == 0 && y == 0) maps[x][y]++;
				q.push(make_pair(nx, ny));
			}
		}
	}
	if (maps[maps.size() - 1][maps[0].size() - 1] == 1) { return -1; }
	else return maps[maps.size() - 1][maps[0].size() - 1];
}

int solution(vector<vector<int>> maps) {
	return BFS(maps);
}