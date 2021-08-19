#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

bool checkSeat(vector<string>, vector<pair<int, int>>);

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < 5; i++) {//���ǽ� 5��
		vector<pair<int, int>> person_seats;
		for (int row = 0; row < 5; row++) {//�� ���ǽ� ���� �� ��
			for (int col = 0; col < 5; col++) {//�� ���ǽ� ���� �� ��
				if (places[i][row][col] == 'P') {
					person_seats.push_back(make_pair(row, col));
				}
			}
		}
		checkSeat(places[i], person_seats) ? answer.push_back(1) : answer.push_back(0);
	}
	return answer;
}


bool checkSeat(vector<string> classroom, vector<pair<int, int>> person_seats) {//BFS
	int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; //��, ������, �Ʒ�, ����

	for (int i = 0; i < person_seats.size(); i++) {
		int visited[5][5] = { 0, };
		queue<pair<int, int>> q;

		q.push(make_pair(person_seats[i].first, person_seats[i].second));
		visited[person_seats[i].first][person_seats[i].second] = 1;

		while (!q.empty()) {
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			if (abs(person_seats[i].first - curX) + abs(person_seats[i].second - curY) == 2) break;

			for (int i = 0; i < 4; i++) {
				int nextX = curX + direction[i][0];
				int nextY = curY + direction[i][1];
				if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5 && visited[nextX][nextY] == 0) {
					if (classroom[nextX][nextY] == 'P') return false;
					else if (classroom[nextX][nextY] == 'O') {
						visited[nextX][nextY] = 1;
						q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
	}
	return true;//�Ÿ��α⸦ ��Ű�� ���� ��츦 �� ����ߴٸ�, �Ÿ��α⸦ �� ��Ų ��.
}