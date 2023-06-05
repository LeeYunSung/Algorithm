#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int BFS(vector<vector<int>> board, int characterX, int characterY, int itemX, int itemY) {
	int direction[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
	queue<pair<int, int>> q;

	q.emplace(characterY, characterY);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == itemY && x == itemX) break;

		for (int i = 0; i < 4; i++) {
			int nextY = y + direction[i][1];
			int nextX = x + direction[i][0];

			if (board[nextY][nextX] == 1) {
				q.emplace(nextY, nextX);
				board[nextY][nextX] = board[y][x] + 1;
			}
		}
	}
	return board[itemY][itemX] / 2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	// 최소 거리
	int answer = 0;
	// 캐릭터와 아이템좌표 값 2배로 늘리기
	characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
	// 101*101 크기의 보드 생성
	vector<vector<int>> board(101, vector<int>(101));
	// 직사각형의 시작과 끝 좌표
	int x1, y1, x2, y2;

	// 직사각형들을 board 배열에 놓기
	for (int i = 0; i < rectangle.size(); i++) {
		for (int j = 0; j < rectangle[i].size(); j++) {
			rectangle[i][j] = rectangle[i][j] * 2;
		}
		x1 = rectangle[i][0], y1 = rectangle[i][1];
		x2 = rectangle[i][2], y2 = rectangle[i][3];

		for (int y = y1; y <= y2; y++) {
			for (int x = x1; x <= x2; x++) {
				board[y][x] = 1;
			}
		}
	}

	// 직사각형 내부를 0으로 채우기
	for (int i = 0; i < rectangle.size(); i++) {
		x1 = rectangle[i][0], y1 = rectangle[i][1];
		x2 = rectangle[i][2], y2 = rectangle[i][3];

		for (int y = y1 + 1; y < y2; y++) {
			for (int x = x1 + 1; x < x2; x++) {
				board[y][x] = 0;
			}
		}
	}

	// BFS로 캐릭터 좌표부터 아이템 좌표까지의 최단거리 탐색
	answer = BFS(board, characterX, characterY, itemX, itemY);

	return answer;
}