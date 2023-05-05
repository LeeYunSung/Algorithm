#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> visited;
int networkCount;

void DFS(vector<vector<int>>& computers, int computer) {
	computers[computer][computer] = 0;
	for (int i = 0; i < computers[computer].size(); i++) {
		if (computers[computer][i] == 1) {
			DFS(computers, i);
		}
	}
	networkCount++;
}

int solution(int n, vector<vector<int>> computers) {
	DFS(computers, 0);
	return networkCount;
}