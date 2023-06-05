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
	// �ּ� �Ÿ�
	int answer = 0;
	// ĳ���Ϳ� ��������ǥ �� 2��� �ø���
	characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
	// 101*101 ũ���� ���� ����
	vector<vector<int>> board(101, vector<int>(101));
	// ���簢���� ���۰� �� ��ǥ
	int x1, y1, x2, y2;

	// ���簢������ board �迭�� ����
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

	// ���簢�� ���θ� 0���� ä���
	for (int i = 0; i < rectangle.size(); i++) {
		x1 = rectangle[i][0], y1 = rectangle[i][1];
		x2 = rectangle[i][2], y2 = rectangle[i][3];

		for (int y = y1 + 1; y < y2; y++) {
			for (int x = x1 + 1; x < x2; x++) {
				board[y][x] = 0;
			}
		}
	}

	// BFS�� ĳ���� ��ǥ���� ������ ��ǥ������ �ִܰŸ� Ž��
	answer = BFS(board, characterX, characterY, itemX, itemY);

	return answer;
}