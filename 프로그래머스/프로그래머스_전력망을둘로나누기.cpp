#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

int wireTree[MAX_SIZE][MAX_SIZE];//�������
vector<bool> isVisited;


int DFS(int currentNode, int nodeTotalCount) {
	if (isVisited[currentNode]) return 0;

	int nodeCount = 1;
	isVisited[currentNode] = true;

	for (int i = 1; i <= nodeTotalCount; i++) {
		if (wireTree[currentNode][i]) {
			nodeCount += DFS(i, nodeTotalCount);
		}
	}
	return nodeCount;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = MAX_SIZE;
	isVisited = vector<bool>(n + 1, false);

	//������� ����
	for (int i = 0; i < wires.size(); i++) {
		int u = wires[i][0];
		int v = wires[i][1];
		wireTree[u][v] = wireTree[v][u] = 1;
	}

	//�Ѱ��� ����� Ž��
	for (int i = 0; i < wires.size(); i++) {
		//�Ѱ� ����
		int u = wires[i][0];
		int v = wires[i][1];
		wireTree[u][v] = wireTree[v][u] = 0;

		//����ž ���� ���Ϸ� DFS Ž�� gogo
		int num = DFS(i + 1, n);

		//�ּ� ���̰� ���ϱ�
		answer = min(answer, abs(2 * num - n));

		//�ٽ� ����
		wireTree[u][v] = wireTree[v][u] = 1;
	}
	return answer;
}