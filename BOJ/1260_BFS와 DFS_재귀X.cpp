#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(int, vector<int>[]);
void BFS(int, vector<int>[]);

int main() {
	int node = 0, edge = 0, start_node = 0;
	vector<int> graph[1001];

	cin >> node >> edge >> start_node;

	int x = 0, y = 0;
	for (int m = 0; m < edge; m++) {
		cin >> x >> y;
		graph[x].push_back(y);//������̹Ƿ� �������� ���� �̾��ֱ�.
		graph[y].push_back(x);
	}
	// ���� ������ ũ�Ⱑ ���� ��带 ���� Ž���ؾ� �ؼ� ����� �̿� ������ ������������ ��������.
	for (int i = 0; i < node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	DFS(start_node, graph);
	cout << "\n";
	BFS(start_node, graph);
}

void DFS(int current_node, vector<int> graph[]) {
	stack<int> stk;
	bool visited[1001] = { false, };

	visited[current_node] = true;
	stk.push(current_node);
	cout << current_node << " ";

	while (!stk.empty()) {
		int next_node = stk.top();
		stk.pop();
		for (int i = 0; i < graph[next_node].size(); i++) {
			int neighbor_node = graph[next_node][i];
			if (!visited[neighbor_node]) {
				cout << neighbor_node << " ";
				visited[neighbor_node] = true;
				stk.push(next_node);
				stk.push(neighbor_node);
				break;
			}
		}
	}
}

void BFS(int current_node, vector<int> graph[]) {
	queue<int> q;
	bool visited[1001] = { false, };

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