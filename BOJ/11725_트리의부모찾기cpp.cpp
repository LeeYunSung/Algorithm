#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void SearchParentByBFS(vector<int> tree[], int edgeNum);

int main() {
	int nodeNum, inputNode1, inputNode2;
	cin >> nodeNum;
	vector<int> *tree = new vector<int>[nodeNum + 1];

	//Input
	for (int i = 0; i < nodeNum - 1; i++) {//edge의 개수는 node의 개수 - 1.
		cin >> inputNode1 >> inputNode2;
		tree[inputNode1].push_back(inputNode2);
		tree[inputNode2].push_back(inputNode1);
	}
	//Algorithm
	SearchParentByBFS(tree, nodeNum);

	delete[] tree;
	return 0;
}

void SearchParentByBFS(vector<int> tree[], int nodeNum) {
	queue<int> q;
	bool* visited = new bool[nodeNum + 1];
	int* parentTree = new int[nodeNum + 1];

	//동적할당 배열 초기화
	for (int i = 0; i <= nodeNum; i++) {
		visited[i] = false;
		parentTree[i] = 0;
	}

	//BFS 탐색
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		
		for (int i = 0; i < tree[parent].size(); i++) {
			if (!visited[tree[parent][i]]) {
				visited[tree[parent][i]] = true;
				parentTree[tree[parent][i]] = parent;
				q.push(tree[parent][i]);
			}
		}
	}

	//Output
	for (int i = 2; i <= nodeNum; i++) {
		cout << parentTree[i] << "\n";
	}

	//동적할당 해제
	delete[] visited;
	delete[] parentTree;
}