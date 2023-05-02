#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[8] = { false, };
int answer;

void DFS(int currentEnergy, int count, vector<vector<int>> dungeons) {
	//현재 Energy가 0 이하면 바로 return 해서 시간 줄이기
	if (currentEnergy <= 0) {
		return;
	}
	for (int i = 0; i < dungeons.size(); i++) {
		int minEnergy = dungeons[i][0];
		int useEnergy = dungeons[i][1];
		if (!isVisited[i] && currentEnergy >= minEnergy) {
			//해당 가지에선 더이상 탐색을 안하기 위해 방문 true 처리
			isVisited[i] = true;
			//다음 깊이로 DFS 탐색
			DFS(currentEnergy - useEnergy, count + 1, dungeons);
			//리턴시 재탐색을 위해 방문 false처리
			isVisited[i] = false;
		}
	}
	answer = max(answer, count);
}

int solution(int currentEnergy, vector<vector<int>> dungeons) {
	//현재 에너지 값과 탐색 깊이 값, dungeons 벡터를 넘김 
	DFS(currentEnergy, 0, dungeons);
	return answer;
}