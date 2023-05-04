#include <vector>
#include <queue>
#include <utility> // pair queue
using namespace std;

int BFS(vector<vector<int>> maps) {
	int direction[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };//상하좌우 방향키
	queue<pair<int, int>> q;//BFS 탐색을 위한 queue

	//0,0 부터 탐색 시작
	q.push(make_pair(0, 0));

	//queue가 빌 때까지 탐색
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int nx = x + direction[k][0];
			int ny = y + direction[k][1];
			//범위체크
			if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
			//상대팀 진영에 도착했다면 바로 정답 리턴
			if (nx == maps.size() - 1 && ny == maps[0].size() - 1) return maps[x][y] + 1;
			//가는 길이 1이면 탐색 queue에 추가
			if (maps[nx][ny] == 1) {
				maps[nx][ny] = maps[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		//현재 값에 + 1 한 값을 이웃 블럭에 넣어야 하므로 map[0][0] = 2 로 맞춰두기.
		if (x == 0 && y == 0)  maps[x][y] = 2;
	}
	//queue가 빌 때 까지 탐색했는데 상대팀 진영을 못만났다면 갈 수 없는 것. return -1.
	return -1;
}

int solution(vector<vector<int>> maps) {
	return BFS(maps);
}