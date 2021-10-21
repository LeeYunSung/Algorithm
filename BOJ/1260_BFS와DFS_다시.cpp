#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>//BFS
#include <stack>//DFS
using namespace std;

void SearchDFS(vector<vector<int>>, vector<bool>&, int);
void SearchBFS(vector<vector<int>>, vector<bool>&, int);

int main() {
	int vertex_num, edge_num, start_vertex;
	cin >> vertex_num >> edge_num >> start_vertex;

	vector<vector<int>> graph(vertex_num+1);
	vector<bool> visited(graph.size(), false);

	int v1, v2;
	for (int i = 0; i < edge_num; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	SearchDFS(graph, visited, start_vertex);
	cout << "\n";
	SearchBFS(graph, visited, start_vertex);

	return 0;
}

void SearchDFS(vector<vector<int>> graph, vector<bool>& visited, int vertex) {//stack
	visited[vertex] = true;
	cout << vertex << " ";
	for (int i = 0; i < graph[vertex].size(); i++) {
		if (!visited[graph[vertex][i]]) {
			visited[graph[vertex][i]] = true;
			SearchDFS(graph, visited, graph[vertex][i]);
		}
	}
}

void SearchBFS(vector<vector<int>> graph, vector<bool>& visited, int vertex) {//queue
	queue<int> q;
	visited.assign(visited.size(), false);

	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty()) {
		int current_vertex = q.front();
		cout << current_vertex << " ";
		q.pop();
		for (int i = 0; i < graph[current_vertex].size(); i++) {
			if (!visited[graph[current_vertex][i]]) {
				visited[graph[current_vertex][i]] = true;
				q.push(graph[current_vertex][i]);
			}
		}
	}
}