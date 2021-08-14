#include <iostream>
#include <queue>
using namespace std;

void dijkstra();

int M, N;//M: ��, N: ��
int map[101][101];//�������� �־��� map����
int cost[101][101];//map�� ����� ������ �迭
int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//������, �Ʒ�, ����, ��
const int INF = 987654321;

int main() {
	cin >> M >> N;//�ڡڡ�����: ��, ���� �ƴ϶� ��, ������ �޾���!
	for (int n = 0; n < N; n++) {//��
		for (int m = 0; m < M; m++) {//��
			scanf_s("%1d", &map[n][m]);
			cost[n][m] = INF;//��� �ڸ��� ����� INF�� �ʱ�ȭ�س��� �ּҺ�� ã������.
		}
	}
	dijkstra();
	cout << cost[N - 1][M - 1];//�̷��� ���� N�� M�� �� ���
}

void dijkstra() {
	queue<pair<int, int>> q;//BFS Ž���� ���� queue. x,y��ǥ�� ��ƾ� �ϹǷ� pair_queue ���.

	q.push(make_pair(0, 0));//Ž���� (0,0)��ǥ���� ����
	cost[0][0] = 0;//(0,0)��ǥ ����� 0����

	while (!q.empty()) {
		int cur_x = q.front().first;//x
		int cur_y = q.front().second;//y
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + direction[i][0];//����x
			int next_y = cur_y + direction[i][1];//����y

			//������ Ž���Ϸ��� ��Ұ� ���� ������ �Ѿ�� �ٸ� ���� Ž��
			if (next_x >= N || next_y >= M || next_x < 0 || next_y < 0) continue;

			//������ Ž���Ϸ��� ��Ұ� ���� ��, ���� �հ� �������� ����� 1
			if (map[next_x][next_y] == 1) {
				//��������� ��뿡 ���� ���(1)�� ���� �� ���� ���� ����� ����� ���Ѵ�.
				//"��������� ��� + ���� ���(1) > ���� ��Ұ� ���� ���" �̶��
				//���� ��Ҵ� INF ���̰ų� �� ū ����� ��� �ִ� ���̹Ƿ�
				//���� ����� ����� �� ���� ���� "��������� ��� + ���� ���(1) > ���� ��Ұ� ���� ���"���� �����Ѵ� !
				//�̷��� �ּ� ����� ��� �������ִϱ� �湮üũ �迭�� ���� �ȸ��� �ȴ�!
				//(�湮���ߴ� �ڸ��̸� INF���� ���� �ְ���~. �׸��� �湮�߾ �� ���� ������ �����������~)
				if (cost[next_x][next_y] > cost[cur_x][cur_y] + 1) {
					cost[next_x][next_y] = cost[cur_x][cur_y] + 1;
					q.push(make_pair(next_x, next_y));
				}
			}
			//������ Ž���Ϸ��� ��Ұ� ���� �ƴ� ��, �������� ����� 0
			else if (map[next_x][next_y] == 0) {
				if (cost[next_x][next_y] > cost[cur_x][cur_y]) {
					cost[next_x][next_y] = cost[cur_x][cur_y];
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}