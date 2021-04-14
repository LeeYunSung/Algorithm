#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 50;

void SearchMap(int, int);

int width, height;		 //문제에서 주어지는 지도의 가로세로 크기
int map[MAX][MAX];		//지도변수
int visited[MAX][MAX];	//방문했는지 체크하는 변수
int direction[8][2] = { {0,-1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1} }; //상, 하, 좌, 우, 대각선

int main() {
	while(1) {
		cin >> width >> height;
		
		if (width == 0 && height == 0) break;		//0, 0 이면 마지막 값이므로 종료

		//지도 입력받기
		for (int i = 0; i < height; i++) {			//행
			for (int j = 0; j < width; j++) {		//열
				cin >> map[i][j];
			}
		}

		//탐색 gogo. 재탐색할 때마다 초기화
		int count = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < height; i++) {	//행
			for (int j = 0; j < width; j++) {//열
				if (map[i][j] && !visited[i][j]) { //현위치가 섬이고, 방문한 적이 없으면 현위치에서 탐색 시작
					SearchMap(i, j);
					count += 1;
				}
			}
		}
		cout << count << "\n";
	} 
}

void SearchMap(int x, int y) {
	if (!map[x][y] || visited[x][y]) { //★탐색 하다가 섬이 아니거나 이미 방문한 곳을 만나면, 더이상 탐색할 필요 없으니까 바로 빠져나가자
		return;
	}
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {		//상하좌우대각선 탐색
		int dx = x + direction[i][0];	//x좌표
		int dy = y + direction[i][1];	//y좌표
		if (dx >= 0 && dx < height && dy >= 0 && dy < width) {// 상하좌우로 이동한 값이 지도의 범위를 넘는지 체크
			SearchMap(dx, dy);
		}
	}
}