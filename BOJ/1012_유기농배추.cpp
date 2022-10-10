#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAP_SIZE = 51;//맵의 최대 크기

int SearchBFS(int row, int col, int(&map)[MAP_SIZE][MAP_SIZE], vector<pair<int, int>> &cabbages);

int main() {
	int testcase;//사용자 input: 테스트 케이스 수
	int row, col, cabbageNum;//사용자 input: row(행 크기), col(열 크기), cabbageNum(양배추 개수)
	int x, y;//사용자 input: 양배추 x, y 좌표

	int map[MAP_SIZE][MAP_SIZE]{};//밭의 정보가 담길 map배열
	vector<pair<int, int> > cabbages;//양배추들의 위치 정보 저장

	//input
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> row >> col >> cabbageNum;
		for (int j = 0; j < cabbageNum; j++) {
			cin >> x >> y;
			cabbages.push_back(make_pair(x, y));
			map[x][y] = 1;
		}
		//output
		cout << SearchBFS(row, col, map, cabbages) << "\n";

		//재탐색을 위한 초기화
		memset(map, 0, sizeof(map));
		cabbages.clear();
	}

	return 0;
}

//배추그룹 개수 탐색
int SearchBFS(int row, int col, int (&map)[MAP_SIZE][MAP_SIZE], vector<pair<int, int>> &cabbages) {

	int answer = 0;
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pair<int, int> > q;

	//양배추 위치를 모두 알고 있으므로, 맵 전체 탐색이 아닌 양배추 위치만 탐색하면 된다.
	for (int i = 0; i < cabbages.size(); i++) {
		
		int x = cabbages[i].first;
		int y = cabbages[i].second;

		if (map[x][y] == 1) {
			//맵에 방문체크
			map[x][y] = -1;

			//양배추 1개 위치를 잡고 BFS로 해당 양배추의 그룹을 모두 찾기
			q.push(make_pair(x, y));

			while (!q.empty()) {
				for (int j = 0; j < 4; j++) {//4방향 탐색
					int nx = q.front().first + dir[j][0];
					int ny = q.front().second + dir[j][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
						if (map[nx][ny] == 1) {
							map[nx][ny] = -1;
							q.push(make_pair(nx, ny));
						}
					}
				}
				q.pop();
			}
			answer += 1;//양배추 그룹 한개를 찾았으면 answer + 1
		}
	}
	return answer;
}

