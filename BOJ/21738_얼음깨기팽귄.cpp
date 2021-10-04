#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void SearchBFS(int, int);

const int MAX = 328001;//node는 1부터 시작하므로 최대개수에 +1을 해줘야 한다ㅠㅠ
vector<int> map[MAX];
vector<int> min_depths;

int main() {
	int block = 0, support_block = 0, penguin = 0;
	cin >> block >> support_block >> penguin;

	int n = 0, m = 0;
	for (int i = 0; i < block-1; i++) {
		cin >> n >> m;
		map[n].push_back(m);
		map[m].push_back(n);
	}
	SearchBFS(penguin, support_block);
	cout << block - min_depths[0] - min_depths[1] - 1;
	return 0;
}

void SearchBFS(int penguin, int support_block) {
	queue<int> q;
	bool visited[MAX] = { false, };
	int depth[MAX] = { 0, };

	q.push(penguin);
	visited[penguin] = true;

	while (!q.empty()) {
		int block = q.front();
		q.pop();
		for (int i = 0; i < map[block].size(); i++) {
			if (!visited[map[block][i]]) {
				visited[map[block][i]] = true;
				if (map[block][i] <= support_block) {
					min_depths.push_back(depth[block] + 1);
					if (min_depths.size() == 2) {
						return;
					}
					continue;
				}
				q.push(map[block][i]);
				depth[map[block][i]] = depth[block] + 1;
			}
		}
	}
}