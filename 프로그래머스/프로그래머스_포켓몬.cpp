#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	unordered_map<int, int> pocketmons;

	//���ϸ� ����&���� �߰�
	for (auto num : nums) {
		pocketmons[num]++;
	}

	//�ִ� ���ϸ� ���� ���� ã��
	answer = min(pocketmons.size(), nums.size() / 2);

	return answer;
}