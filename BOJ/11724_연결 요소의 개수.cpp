#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void searchDFS(int, vector<int>[], bool *);

int main() {
	int vertex = 0, edge = 0;
	cin >> vertex >> edge;

	vector<int> *graph = new vector<int>[vertex + 1];//★벡터를 이용한 그래프 동적할당 방법
	bool * visited = new bool[vertex + 1];

	//그래프 입력받기
	for (int edge_idx = 0; edge_idx < edge; edge_idx++) {
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	//방문배열도 초기화 해주기
	for (int i = 0; i <= vertex; i++) {
		visited[i] = false;
	}

	//DFS로 연결 요소 찾기
	int connected_element = 0;
	for (int vertex_idx = 1; vertex_idx <= vertex; vertex_idx++) {
		if (!visited[vertex_idx]) {
			searchDFS(vertex_idx, graph, visited);
			++connected_element;
		}
	}
	cout << connected_element;
	delete[] visited;
}

void searchDFS(int vertex, vector<int> graph[], bool *visited) {
	visited[vertex] = true;

	for (int i = 0; i < graph[vertex].size(); i++) {
		if (!visited[graph[vertex][i]]) {
			searchDFS(graph[vertex][i], graph, visited);
		}
	}
}
