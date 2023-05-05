#include <string>
#include <vector>
using namespace std;


bool isNetwork(vector<vector<int>>& computers, int n) {
	if (!computers[n][n]) return false;
	computers[n][n] = 0;

	for (int i = 0; i < computers[i].size(); i++) {
		if (computers[n][i] == 1) isNetwork(computers, i);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (isNetwork(computers, i)) answer++;
	}

	return answer;
}