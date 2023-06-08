#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cardGroup, peopleGroup;

void DFS(int cur, vector<int> cardInfo, vector<int> *relations, vector<bool> visited) {
	cardGroup.push_back(cardInfo[cur]);
	peopleGroup.push_back(cur);
	for (int i = 0; i < relations[cur].size(); i++) {
		int nx = relations[cur][i];
		if (!visited[nx]) {
			visited[nx] = true;
			DFS(nx, cardInfo, relations, visited);
		}
	}
}

int main() {
	int personNum, relationNum, answer = 0;

	cin >> personNum >> relationNum;
	vector<int> cardInfo(personNum + 1);
	vector<int> *relations = new vector<int>[personNum + 1];

	for (int i = 1; i <= personNum; i++) cin >> cardInfo[i];

	int friend1, friend2;
	for (int i = 0; i < relationNum; i++) {
		cin >> friend1 >> friend2;
		relations[friend1].push_back(friend2);
		relations[friend2].push_back(friend1);
	}

	vector<bool> visited(personNum + 1);
	for (int i = 1; i <= personNum; i++) {

		if (visited[i]) continue;

		cardGroup.clear();
		peopleGroup.clear();

		visited[i] = true;
		DFS(i, cardInfo, relations, visited);

		sort(cardGroup.begin(), cardGroup.end());
		sort(peopleGroup.begin(), peopleGroup.end());

		for (int j = 0; j < cardGroup.size(); j++) {
			answer += abs(cardGroup[j] - peopleGroup[j]);
		}
	}

	cout << answer;

	delete[] relations;
	return 0;
}