#include <iostream>
#include <queue>
using namespace std;

void dijkstra();

int M, N;//M: 열, N: 행
int map[101][101];//문제에서 주어진 map정보
int cost[101][101];//map의 비용을 저장할 배열
int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//오른쪽, 아래, 왼쪽, 위
const int INF = 987654321;

int main() {
	cin >> M >> N;//★★★주의: 행, 열이 아니라 열, 행으로 받아짐!
	for (int n = 0; n < N; n++) {//행
		for (int m = 0; m < M; m++) {//열
			scanf_s("%1d", &map[n][m]);
			cost[n][m] = INF;//모든 자리의 비용을 INF로 초기화해놓고 최소비용 찾을거임.
		}
	}
	dijkstra();
	cout << cost[N - 1][M - 1];//미로의 끝인 N행 M열 값 출력
}

void dijkstra() {
	queue<pair<int, int>> q;//BFS 탐색을 위한 queue. x,y좌표를 담아야 하므로 pair_queue 사용.

	q.push(make_pair(0, 0));//탐색은 (0,0)좌표에서 시작
	cost[0][0] = 0;//(0,0)좌표 비용은 0이지

	while (!q.empty()) {
		int cur_x = q.front().first;//x
		int cur_y = q.front().second;//y
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + direction[i][0];//다음x
			int next_y = cur_y + direction[i][1];//다음y

			//다음에 탐색하려는 장소가 맵의 범위를 넘어서면 다른 방향 탐색
			if (next_x >= N || next_y >= M || next_x < 0 || next_y < 0) continue;

			//다음에 탐색하려는 장소가 벽일 때, 벽을 뚫고 지나가는 비용은 1
			if (map[next_x][next_y] == 1) {
				//현재까지의 비용에 벽의 비용(1)을 더한 한 값과 다음 장소의 비용을 비교한다.
				//"현재까지의 비용 + 벽의 비용(1) > 다음 장소가 가진 비용" 이라면
				//다음 장소는 INF 값이거나 더 큰 비용이 들어 있던 것이므로
				//다음 장소의 비용을 더 작은 값인 "현재까지의 비용 + 벽의 비용(1) > 다음 장소가 가진 비용"으로 갱신한다 !
				//이렇게 최소 비용을 계속 갱신해주니까 방문체크 배열은 따로 안만들어도 된다!
				//(방문안했던 자리이면 INF값을 갖고 있겟지~. 그리구 방문했어도 더 작은 값으로 갱신해줘야지~)
				if (cost[next_x][next_y] > cost[cur_x][cur_y] + 1) {
					cost[next_x][next_y] = cost[cur_x][cur_y] + 1;
					q.push(make_pair(next_x, next_y));
				}
			}
			//다음에 탐색하려는 장소가 벽이 아닐 때, 지나가는 비용은 0
			else if (map[next_x][next_y] == 0) {
				if (cost[next_x][next_y] > cost[cur_x][cur_y]) {
					cost[next_x][next_y] = cost[cur_x][cur_y];
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}