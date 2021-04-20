#include <iostream>
#include <queue> //queue 자료구조
#include <utility> //pair queue 사용을 위해
using namespace std;

const int MAX = 1001;//지도의 최대 크기

int row, column; // 지도의 크기(행, 열)
int map[MAX][MAX]; // 지도
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //탐색할 상하좌우 방향
queue<pair<int, int>> q; //BFS 탐색을 위한 저장소

int searchBFS(int);
void output(int);

int main() {
	//Input
	cin >> row >> column;
	for (int i = 0; i < column; i++) {//가로길이
		for (int j = 0; j < row; j++) {//세로길이
			cin >> map[i][j];
			if (map[i][j] == 1) { //1인거 모두 저장해서 한번에 늘려주려구
				q.push(make_pair(i, j));
			}
		}
	}
	//Search
	int day = 0;
	while(!q.empty()){
		day += searchBFS(q.size());
	}
	//Output
	output(day);
}

int searchBFS(int this_queue_size) {
	while(this_queue_size > 0) {// 토마토가 있는 모든 자리에서 BFS 동시수행
		int x = q.front().first;//3
		int y = q.front().second;//5
		q.pop();
		for (int i = 0; i < 4; i++) { //주변(상하좌우) 탐색
			int nx = x + direction[i][0];//2
			int ny = y + direction[i][1];//5
			if (map[nx][ny] == 0
					&& nx >= 0 && nx < column && ny >= 0 && ny < row) {//토마토가 있고 지도 범위 안이라면
				q.push(make_pair(nx, ny));//다음 BFS때 탐색하도록 queue에 차곡차곡 넣어주기
				map[nx][ny] = 1; //토마토 익게 만들었다고 표시
			}
		}
		this_queue_size--;
	}
	return 1;
}

void output(int day) {
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 0) {//한 곳이라도 안익은 토마토가 존재한다면 -1 출력
				cout << -1;
				return;
			}
		}
	}
	cout << day - 1; //탐색할 때 1을 무조건 count 하니까, 1을 빼준 값을 출력해주자.
}