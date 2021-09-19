#include <iostream>
#include <vector>
using namespace std;

int map[1001][1001];
int row, col, time;
int robot_location;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우

void Spray();
void Machine();
int PrintGrayNum();

int main() {
	cin >> row >> col >> time;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				robot_location = i;
			}
		}
	}
	for (int i = 0; i < time; i++) {
		Spray();
		Machine();
	}
	cout << PrintGrayNum();
}

void Spray() {
	int cal_map[1001][1001] = { {0,0}, };
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) {
				int count = 0;
				for (int d = 0; d < 4; d++) {
					int next_x = i + direction[d][0];
					int next_y = j + direction[d][1];
					if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col && map[next_x][next_y] != -1) {
						cal_map[next_x][next_y] += map[i][j] / 5;
						count++;
					}
				}
				cal_map[i][j] += (map[i][j] - (map[i][j] / 5) * count);
			}

		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (cal_map[i][j] != 0 && cal_map[i][j] != -1) {
				map[i][j] = cal_map[i][j];
			}
		}
	}
}

void Machine() {
	//공기청정기 위아래를 0으로 표시해두고 위쪽은 반시계방향, 아래쪽은 시계방향으로 돌리기
	map[robot_location - 2][0] = 0;
	map[robot_location + 1][0] = 0;

	//위쪽 반시계 방향으로 회전하는 부분
	for (int i = robot_location - 2; i > 0; i--) {
		int temp = map[i][0];
		map[i][0] = map[i - 1][0];
		map[i - 1][0] = temp;
	}
	for (int j = 0; j < col - 1; j++) {
		int temp = map[0][j];
		map[0][j] = map[0][j + 1];
		map[0][j + 1] = temp;
	}
	for (int i = 0; i < robot_location - 1; i++) {
		int temp = map[i][col - 1];
		map[i][col - 1] = map[i + 1][col - 1];
		map[i + 1][col - 1] = temp;
	}
	for (int j = col - 1; j > 1; j--) {
		int temp = map[robot_location - 1][j];
		map[robot_location - 1][j] = map[robot_location - 1][j - 1];
		map[robot_location - 1][j - 1] = temp;
	}

	//아래쪽 시계 방향으로 회전하는 부분
	for (int i = robot_location + 1; i < row - 1; i++) {
		int temp = map[i][0];
		map[i][0] = map[i + 1][0];
		map[i + 1][0] = temp;
	}
	for (int j = 0; j < col - 1; j++) {
		if (j + 1 < col) {
			int temp = map[row - 1][j];
			map[row - 1][j] = map[row - 1][j + 1];
			map[row - 1][j + 1] = temp;
		}
	}
	for (int i = row - 1; i > robot_location; i--) {
		int temp = map[i][col - 1];
		map[i][col - 1] = map[i - 1][col - 1];
		map[i - 1][col - 1] = temp;
	}
	for (int j = col - 1; j > 1; j--) {
		int temp = map[robot_location][j];
		map[robot_location][j] = map[robot_location][j - 1];
		map[robot_location][j - 1] = temp;
	}
}

int PrintGrayNum() {
	int gray_num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != -1 && map[i][j] != 0) {
				gray_num += map[i][j];
			}
		}
	}
	return gray_num;
}