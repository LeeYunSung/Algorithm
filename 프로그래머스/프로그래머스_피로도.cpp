#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[8] = { false, };
int answer;

void DFS(int currentEnergy, int count, vector<vector<int>> dungeons) {
	//���� Energy�� 0 ���ϸ� �ٷ� return �ؼ� �ð� ���̱�
	if (currentEnergy <= 0) {
		return;
	}
	for (int i = 0; i < dungeons.size(); i++) {
		int minEnergy = dungeons[i][0];
		int useEnergy = dungeons[i][1];
		if (!isVisited[i] && currentEnergy >= minEnergy) {
			//�ش� �������� ���̻� Ž���� ���ϱ� ���� �湮 true ó��
			isVisited[i] = true;
			//���� ���̷� DFS Ž��
			DFS(currentEnergy - useEnergy, count + 1, dungeons);
			//���Ͻ� ��Ž���� ���� �湮 falseó��
			isVisited[i] = false;
		}
	}
	answer = max(answer, count);
}

int solution(int currentEnergy, vector<vector<int>> dungeons) {
	//���� ������ ���� Ž�� ���� ��, dungeons ���͸� �ѱ� 
	DFS(currentEnergy, 0, dungeons);
	return answer;
}