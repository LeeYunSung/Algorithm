#include <iostream>
using namespace std;

void CleanArea(int, int, int);

const int direction[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //북, 동, 남, 서
int map[51][51];
int height, width;
int clean_count;

int main() {
	cin >> height >> width;

	int robot_x = 0, robot_y = 0, robot_direction = 0;
	cin >> robot_x >> robot_y >> robot_direction;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];
		}
	}
	CleanArea(robot_x, robot_y, robot_direction);
	cout << clean_count;
}

void CleanArea(int robot_x, int robot_y, int robot_direction) {
	//1. 현재 위치를 청소한다.
	if (map[robot_x][robot_y] == 0) {
		map[robot_x][robot_y] = 2;
		clean_count += 1;
	}
	//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	for (int i = 0; i < 4; i++) {
		robot_direction = (robot_direction + 3) % 4;

		int next_x = robot_x + direction[robot_direction][0];
		int next_y = robot_y + direction[robot_direction][1];

		//a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (map[next_x][next_y] == 0) {
			CleanArea(next_x, next_y, robot_direction);
			return; //★★★돌아와서 또 상하좌우를 보는게 아니라 빠져나와야 함
		}//b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	}
	//c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	int back_x = robot_x - direction[robot_direction][0];
	int back_y = robot_y - direction[robot_direction][1];

	if (map[back_x][back_y] != 1) {
		CleanArea(back_x, back_y, robot_direction);
	}
	//d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
	return;
}