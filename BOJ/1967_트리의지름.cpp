/*
�ڷᱸ�� - ��������Ʈ
�ð����⵵ - O(n)

Ǯ�� 1) 2���� �����ؼ� ����ġ ���� ���ذ��� ���� �� ����ġ�� ã�´�. => O(n!)�� �ð��ʰ�
Ǯ�� 2) Ž�� �� ����ġ�� �� �������� �̵��ϸ� ã�´�.
Ǯ�� 3) ���� �� �ڽ� ������ ã�´�. leaf node. �� ���鳢�� ���̸� ���ؼ� ���� �ָ� ������ �ִ� �ڽĳ����� ���̸� ���Ѵ�.
Ǯ�� 4) ���� �ָ� �ִ� �ڽ� ��带 ã�´�. �� ��忡�� ���� �� ��带 ã�´�. dfs 2�� ���.
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

	//�Է�
	for (int i = 1; i < nodeNum; i++) {
		cin >> parent >> child >> weight;
		tree[parent].push_back(make_pair(child, weight));
		tree[child].push_back(make_pair(parent, weight));
		visited[i] = false;
	}

	//��Ʈ�� ���� �ָ��ִ� ��� ã��.
	SearchFarthestNodeByDFS(1, 0, tree, visited);

	//�ʱ�ȭ �� ã�� �� ���� ���� �� ���&���� ã��.
	maxLength = 0;
	for (int i = 1; i <= nodeNum; i++) visited[i] = false;
	SearchFarthestNodeByDFS(farthestNode, 0, tree, visited);

	//�� ���
	cout << maxLength << "\n";

	return 0;
}

void SearchFarthestNodeByDFS(int currentNode, int length, vector<pair<int, int>> *tree, bool *visited) {
	visited[currentNode] = true;

	if (length > maxLength) {//�������� �� ��� ����
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
