#include <iostream>
using namespace std;

void CleanArea(int, int, int);

const int direction[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //��, ��, ��, ��
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
	//1. ���� ��ġ�� û���Ѵ�.
	if (map[robot_x][robot_y] == 0) {
		map[robot_x][robot_y] = 2;
		clean_count += 1;
	}
	//2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
	for (int i = 0; i < 4; i++) {
		robot_direction = (robot_direction + 3) % 4;

		int next_x = robot_x + direction[robot_direction][0];
		int next_y = robot_y + direction[robot_direction][1];

		//a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		if (map[next_x][next_y] == 0) {
			CleanArea(next_x, next_y, robot_direction);
			return; //�ڡڡڵ��ƿͼ� �� �����¿츦 ���°� �ƴ϶� �������;� ��
		}//b. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
	}
	//c. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡�� �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
	int back_x = robot_x - direction[robot_direction][0];
	int back_y = robot_y - direction[robot_direction][1];

	if (map[back_x][back_y] != 1) {
		CleanArea(back_x, back_y, robot_direction);
	}
	//d. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
	return;
}