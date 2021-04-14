#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(int, bool[], vector<int>[]);
void BFS(int, bool[], vector<int>[]);

int main() {
	int node = 0, edge = 0, start_node = 0;
	vector<int> graph[1001];
	bool visited[1001] = { false, };

	cin >> node >> edge >> start_node;

	int x = 0, y = 0;
	for (int m = 0; m < edge; m++) {
		cin >> x >> y;
		graph[x].push_back(y);//양방향이므로 양쪽으로 간선 이어주기.
		graph[y].push_back(x);
	}
	for (int i = 0; i < node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	DFS(start_node, visited, graph);
	cout << "\n";
	for (int i = 0; i <= node; i++) {//방문노드 초기화
		visited[i] = false;
	}
	BFS(start_node, visited, graph);
}

void DFS(int current_node, bool visited[1001], vector<int> graph[]) {
	visited[current_node] = true;
	cout << current_node << " ";

	for (int i = 0; i < graph[current_node].size(); i++) {
		int neighbor_node = graph[current_node][i];
		if (!visited[neighbor_node]) {
			DFS(neighbor_node, visited, graph);
		}
	}
}

void BFS(int current_node, bool visited[1001], vector<int> graph[]) {
	queue<int> q;

	visited[current_node] = true;
	q.push(current_node);

	while (!q.empty()) {
		int next_node = q.front();
		q.pop();
		cout << next_node << " ";
		for (int i = 0; i < graph[next_node].size(); i++) {
			int neighbor_node = graph[next_node][i];
			if (!visited[neighbor_node]) {
				q.push(neighbor_node);
				visited[neighbor_node] = true;
			}
		}
	}
}