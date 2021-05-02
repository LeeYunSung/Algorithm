#include <iostream>
#include <queue>
using namespace std;

int findSister(int, int);

int main() {
	int subin, sister = 0;
	cin >> subin >> sister;
	cout << findSister(subin, sister);
}

int findSister(int subin, int sister) {
	queue<int> q; //BFS Ž���� ����� ���Լ��� ������ ���� queue
	bool visited[100001] = { false, }; //�湮�ߴ��� ���θ� �����ϴ� �迭
	int dist[100001] = { 0, }; //���������� �ɸ� �ð��� ��� �迭. sister�� �ִµ� ���� �󸶳� �ɸ����� ������ �� ����

	q.push(subin);
	visited[subin] = true;
	
	while (subin != sister) {
		subin = q.front();
		int nextPosition[3] = { subin - 1, subin + 1, subin * 2 }; //subin�̰� �̵��� �� �ִ� 3���� ���

		q.pop();
		for (int i = 0; i < 3; i++) {
			if (nextPosition[i] >= 0 && nextPosition[i] < sizeof(visited)) {
				if (!visited[nextPosition[i]]) {
					visited[nextPosition[i]] = true;
					q.push(nextPosition[i]);
					dist[nextPosition[i]] = dist[subin] + 1;
				}
			}
		}
	}
	return dist[sister];
}