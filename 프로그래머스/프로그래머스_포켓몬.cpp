#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	unordered_map<int, int> pocketmons;

	//포켓몬 종류&개수 추가
	for (auto num : nums) {
		pocketmons[num]++;
	}

	//최대 포켓몬 선택 개수 찾기
	answer = min(pocketmons.size(), nums.size() / 2);

	return answer;
}