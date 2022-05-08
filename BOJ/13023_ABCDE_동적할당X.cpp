#include <iostream>
#include<cstring>
#include <vector>
using namespace std;

const int MAX_SIZE = 2001;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
int answer;

void DFS(int person, int relationDepth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int personNum, relationNum, person1, person2;

	cin >> personNum >> relationNum;
	for (int i = 0; i < relationNum; i++) {
		cin >> person1 >> person2;
		graph[person1].push_back(person2);
		graph[person2].push_back(person1);
	}
	for (int i = 0; i < personNum; i++) {
		for (int j = 0; j < personNum; j++) visited[j] = false;
		DFS(i, 0);
		if (answer) break;
	}
	cout << answer << "\n";
	return 0;
}

void DFS(int person, int relationDepth) {
	if (relationDepth == 4) {
		answer = 1;
		return;
	}
	visited[person] = true;
	for (int i = 0; i < graph[person].size(); i++) {
		if (!visited[graph[person][i]]) {
			DFS(graph[person][i], relationDepth + 1);
		}
	}
	visited[person] = false;
}