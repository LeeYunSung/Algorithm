/*
[입출력 예]
rows
3

columns
4

max_virus
2

queries
[[3,2],[3,2],[2,2],[3,2],[1,4],[3,2],[2,3],[3,1]]

result
[[0,2,1,1],[2,2,2,1],[2,2,2,1]]
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> solution(int rows, int columns, int max_virus, vector<vector<int>> queries) {
	vector<vector<int>> answer(rows, vector<int>(columns, 0));
	int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

	for (auto& querie : queries) {
		vector<vector<bool>> visited(rows, vector<bool>(columns, false));
		queue<pair<int, int>> q;

		if (answer[querie[0] - 1][querie[1] - 1] == max_virus) {
			q.push(make_pair(querie[0] - 1, querie[1] - 1));
			visited[querie[0] - 1][querie[1] - 1] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int current_x = x + direction[i][0];
					int current_y = y + direction[i][1];
					if (current_x >= 0 && current_x < rows && current_y >= 0 && current_y < columns
						&& !visited[current_x][current_y]) {
						if (answer[current_x][current_y] == max_virus) {
							q.push(make_pair(current_x, current_y));
						}
						visited[current_x][current_y] = true;
					}
				}
			}
		}
		else {
			answer[querie[0] - 1][querie[1] - 1] += 1;
			continue;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (visited[i][j] && answer[i][j] < max_virus) {
					answer[i][j] += 1;
				}
			}
		}
	}
	return answer;
}