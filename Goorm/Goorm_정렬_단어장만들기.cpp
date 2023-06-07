#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	//answer값 구하기 쉽게 내림차순 정렬. 6 5 3 1 0
	sort(citations.begin(), citations.end(), greater<int>());

	// 최대값이 0이면 0 출력
	if (!citations[0]) { return 0; }

	//citations 벡터 돌면서 h번 이상 인용되었는지 체크
	for (int h = 0; h < citations.size(); h++) {
		if (citations[h] > h) answer++;
		else break;
	}

	return answer;
}