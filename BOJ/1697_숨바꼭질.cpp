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
	queue<int> q; //BFS 탐색에 사용할 선입선출 구조를 갖는 queue
	bool visited[100001] = { false, }; //방문했는지 여부를 저장하는 배열
	int dist[100001] = { 0, }; //목적지까지 걸린 시간을 담는 배열. sister가 있는데 까지 얼마나 걸리는지 저장할 수 있음

	q.push(subin);
	visited[subin] = true;
	
	while (subin != sister) {
		subin = q.front();
		int nextPosition[3] = { subin - 1, subin + 1, subin * 2 }; //subin이가 이동할 수 있는 3가지 경우

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