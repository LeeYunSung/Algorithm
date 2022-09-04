/*
자료구조 - 인접리스트
시간복잡도 - O(n)

풀이 1) 2개씩 선택해서 가중치 값을 더해가며 가장 긴 가중치를 찾는다. => O(n!)로 시간초과
풀이 2) 탐색 시 가중치가 긴 방향으로 이동하며 찾는다.
풀이 3) 가장 끝 자식 노드들을 찾는다. leaf node. 그 노드들끼리 길이를 구해서 가장 멀리 떨어져 있는 자식노드들의 길이를 구한다.
풀이 4) 가장 멀리 있는 자식 노드를 찾는다. 그 노드에서 가장 먼 노드를 찾는다. dfs 2번 사용.
*/

#include <iostream>
#include <vector>
using namespace std;

void SearchFarthestNodeByDFS(int currentNode, int length, vector<pair<int, int>> *tree, bool *visited);
int maxLength;
int farthestNode;

int main() {
	int nodeNum, parent, child, weight;
	cin >> nodeNum;
	vector<pair<int, int>> *tree = new vector<pair<int, int>> [nodeNum + 1];
	bool *visited = new bool[nodeNum + 1];

	//입력
	for (int i = 1; i < nodeNum; i++) {
		cin >> parent >> child >> weight;
		tree[parent].push_back(make_pair(child, weight));
		tree[child].push_back(make_pair(parent, weight));
		visited[i] = false;
	}

	//루트와 가장 멀리있는 노드 찾기.
	SearchFarthestNodeByDFS(1, 0, tree, visited);

	//초기화 및 찾은 끝 노드와 가장 먼 노드&지름 찾기.
	maxLength = 0;
	for (int i = 1; i <= nodeNum; i++) visited[i] = false;
	SearchFarthestNodeByDFS(farthestNode, 0, tree, visited);

	//답 출력
	cout << maxLength << "\n";

	return 0;
}

void SearchFarthestNodeByDFS(int currentNode, int length, vector<pair<int, int>> *tree, bool *visited) {
	visited[currentNode] = true;

	if (length > maxLength) {//길이합이 더 길면 갱신
		maxLength = length;
		farthestNode = currentNode;
	}
	for (int i = 0; i < tree[currentNode].size(); i++) {
		int nextNode = tree[currentNode][i].first;
		int nextLength = tree[currentNode][i].second + length;
		if (!visited[nextNode]) {
			SearchFarthestNodeByDFS(nextNode, nextLength, tree, visited);
			visited[nextNode] = false;
		}
	}
}
