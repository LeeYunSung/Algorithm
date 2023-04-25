#include <string>
#include <vector>
#include <cmath>
using namespace std;

int needEnergy[8];
int useEnergy[8];
bool isVisited[8] = { false, };
int dungeonSize;
int result = 0;

void dfs(int cnt, int currentEnergy) {
	for (int i = 0; i < dungeonSize; i++) {
		if (!isVisited[i] && needEnergy[i] <= currentEnergy) {
			isVisited[i] = true;
			dfs(cnt + 1, currentEnergy - useEnergy[i]);
			isVisited[i] = false;
		}
	}
	result = max(result, cnt);
	return;
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	dungeonSize = dungeons.size();
	for (int i = 0; i < num; i++) {
		needEnergy[i] = dungeons[i][0];
		useEnergy[i] = dungeons[i][1];
	}
	dfs(0, k);
	return answer = result;
}