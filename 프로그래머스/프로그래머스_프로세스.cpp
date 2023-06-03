#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int priority_index = 0;

	//인덱스를 저장하고 있는 벡터 생성
	vector<int> index_vector;
	for (int i = 0; i < priorities.size(); i++) {
		index_vector.push_back(i);
	}

	//프로세스 꺼내기
	while (1) {
		//가장 처음 빼낼 우선순위 인덱스 저장
		priority_index = max_element(priorities.begin(), priorities.end()) - priorities.begin();
		//우선순위 인덱스의 값 전까지 다 뒤로 보내기
		for (int i = 0; i < priority_index; i++) {
			priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());

			//인덱스 벡터 값도 뒤로 보내기
			index_vector.push_back(index_vector.front());
			index_vector.erase(index_vector.begin());
		}
		//우선순위 인덱스 빼내기
		priorities.erase(priorities.begin());
		//빼낼때마다 카운트 세기
		answer++;

		//location값과 맞으면 프로세스 종료
		if (location == index_vector.front()) break;
		//location값이 아니면 다음 프로세스 실행
		index_vector.erase(index_vector.begin());
	}

	return answer;
}