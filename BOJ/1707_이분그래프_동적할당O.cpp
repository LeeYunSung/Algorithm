#include <iostream>
#include <vector>
using namespace std;

void SearchBinaryGraph(int index, vector<int> graph[], int *visited); //DFS
bool CheckBinaryGraph(int nodeNum, vector<int> graph[], int *visited);

int main() {
	int testcaseNum, nodeNum, edgeNum, node1, node2;
	cin >> testcaseNum;
	while (testcaseNum--) {
		cin >> nodeNum >> edgeNum;
		
		//동적할당
		vector<int> *graph = new vector<int>[nodeNum + 1];
		int *visited = new int[nodeNum + 1];
		
		//갑 입력&저장
		for (int i = 0; i < edgeNum; i++) {
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		} for (int i = 1; i <= nodeNum; i++) visited[i] = 0;
		
		//알고리즘 시작
		for (int i = 1; i <= nodeNum; i++) {
			if (visited[i] == 0) SearchBinaryGraph(i, graph, visited);
		}
		
		//정답출력
		if (CheckBinaryGraph(nodeNum, graph, visited)) cout << "YES\n";
		else cout << "NO\n";

		//동적할당 해제
		for (int i = 0; i < nodeNum; i++) { graph[i].clear(); }
		delete[] visited;
	}
	return 0;
}

//DFS
void SearchBinaryGraph(int index, vector<int> graph[], int *visited) {
	if(visited[index] == 0) visited[index] = 1;
	for (int i = 0; i < graph[index].size(); i++) {
		int nextIndex = graph[index][i];
		if (visited[nextIndex] == 0) {
			visited[nextIndex] = (visited[index] == 1) ? 2 : 1;
			SearchBinaryGraph(nextIndex, graph, visited);
		}
	}
}

//BFS
bool CheckBinaryGraph(int nodeNum, vector<int> graph[], int *visited) {
	for (int i = 1; i <= nodeNum; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (visited[i] == visited[graph[i][j]]) return false;
		}
	}
	return true;
}