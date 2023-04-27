#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

int wireTree[MAX_SIZE][MAX_SIZE];//인접행렬
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

	//인접행렬 연결
	for (int i = 0; i < wires.size(); i++) {
		int u = wires[i][0];
		int v = wires[i][1];
		wireTree[u][v] = wireTree[v][u] = 1;
	}

	//한개씩 끊어가며 탐색
	for (int i = 0; i < wires.size(); i++) {
		//한개 끊기
		int u = wires[i][0];
		int v = wires[i][1];
		wireTree[u][v] = wireTree[v][u] = 0;

		//송전탑 개수 구하러 DFS 탐색 gogo
		int num = DFS(i + 1, n);

		//최소 차이값 구하기
		answer = min(answer, abs(2 * num - n));

		//다시 연결
		wireTree[u][v] = wireTree[v][u] = 1;
	}
	return answer;
}