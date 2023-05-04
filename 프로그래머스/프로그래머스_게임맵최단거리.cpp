#include <vector>
#include <queue>
#include <utility> // pair queue
using namespace std;

int BFS(vector<vector<int>> maps) {
	int direction[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };//�����¿� ����Ű
	queue<pair<int, int>> q;//BFS Ž���� ���� queue

	//0,0 ���� Ž�� ����
	q.push(make_pair(0, 0));

	//queue�� �� ������ Ž��
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//�����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int nx = x + direction[k][0];
			int ny = y + direction[k][1];
			//����üũ
			if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
			//����� ������ �����ߴٸ� �ٷ� ���� ����
			if (nx == maps.size() - 1 && ny == maps[0].size() - 1) return maps[x][y] + 1;
			//���� ���� 1�̸� Ž�� queue�� �߰�
			if (maps[nx][ny] == 1) {
				maps[nx][ny] = maps[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		//���� ���� + 1 �� ���� �̿� ���� �־�� �ϹǷ� map[0][0] = 2 �� ����α�.
		if (x == 0 && y == 0)  maps[x][y] = 2;
	}
	//queue�� �� �� ���� Ž���ߴµ� ����� ������ �������ٸ� �� �� ���� ��. return -1.
	return -1;
}

int solution(vector<vector<int>> maps) {
	return BFS(maps);
}