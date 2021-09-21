#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ChooseCandy(char **map, int n);
void CountCandy(char **map, int n);

int candy_max;

int main() {
	int n = 0;//맵 크기. 3 ≤ n ≤ 50
	cin >> n;

	//맵 동적할당
	char **map = new char*[n];
	for (int i = 0; i < n; i++)
		map[i] = new char[n];

	//사탕정보 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	ChooseCandy(map, n);
	cout << candy_max << "\n";
}

void ChooseCandy(char **map, int n) {
	int dir[2][2] = { {0,1},{1,0} };//현재칸의 오른쪽과 아래쪽을 선택하여 색이 다른지 판단할거야.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			//1. (사탕의 색이 다른) 인접한 두 칸을 고른다.
			for (int d = 0; d < 2; d++) {
				int next_x = i + dir[d][0];
				int next_y = j + dir[d][1];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
					//2. 고른 칸에 들어있는 사탕을 서로 교환한다.
					swap(map[i][j], map[next_x][next_y]);
					//3. 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 찾는다.
					CountCandy(map, n);
					//4. 다시 사탕을 교환해서 원래대로 바꿔놓고 재탐색하며 최대값을 찾는다.
					swap(map[i][j], map[next_x][next_y]);
				}
			}
		}
	}
}

void CountCandy(char **map, int n) {
	char color;
	int count;

	//행 카운트
	for (int i = 0; i < n; i++) {//행
		count = 1;
		color = map[i][0];//각 행의 첫번째 컬러(0열)를 비교 컬러로 둔다.
		for (int j = 1; j < n; j++) {//열
			if (map[i][j] == color) count++;//옆의 컬러가 같으면 컬러 개수(count)를 1 늘려준다. 
			else {//옆의 컬러가 다르면, 현재 컬러를 다시 비교컬러로 넣어주고 컬러 개수를 1로 초기화해준다.
				color = map[i][j];
				if (candy_max < count) candy_max = count;//현재까지 구한 count와 최대값을 비교해서 갱신해준다.
				count = 1;
			}
		}
		if (candy_max < count) candy_max = count;//한 행이 끝나는 지점에 사탕 색깔이 같으면 위 else문의 최대값 갱신부분 진입을 못하므로, 마지막에 한번더 최대값을 비교갱신해준다.
	}

	//열 카운트
	for (int j = 0; j < n; j++) {//열
		count = 1;
		color = map[0][j];//각 열의 첫번째 컬러(0행)를 비교 컬러로 둔다.
		for (int i = 1; i < n; i++) {//행
			if (map[i][j] == color) count++;//아래의 컬러가 같으면 컬러 개수(count)를 1 늘려준다. 
			else {//아래의 컬러가 다르면, 현재 컬러를 다시 비교컬러로 넣어주고 컬러 개수를 1로 초기화해준다.
				color = map[i][j];
				if (candy_max < count) candy_max = count;//현재까지 구한 count와 최대값을 비교해서 갱신해준다.
				count = 1;
			}
		}
		if (candy_max < count) candy_max = count;//한 열이 끝나는 지점에 사탕 색깔이 같으면 위 else문의 최대값 갱신부분 진입을 못하므로, 마지막에 한번더 최대값을 비교갱신해준다.
	}
}