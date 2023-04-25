#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	//1. ���� ������ ���� �������� ����
	sort(dungeons.begin(), dungeons.end());

	//2. ���� ������� Ž���ϸ� �ִ� ���� Ž�� ���� �� ���ϱ�.
	do {
		int count = 0;
		int currentEnergy = k;
		for (const auto& dungeon : dungeons) {
			int minEnergy = dungeon[0];
			int useEnergy = dungeon[1];
			if (minEnergy <= currentEnergy) {
				currentEnergy -= useEnergy;
				count++;
			}
			else break;
		}
		answer = max(count, answer);
	} while (next_permutation(dungeons.begin(), dungeons.end()));

	return answer;
}