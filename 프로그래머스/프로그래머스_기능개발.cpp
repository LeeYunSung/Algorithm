#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (!progresses.empty()) {

		//완료된 양에 작업량 더하기
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}

		//맨 앞에 progress가 100된거 싹 빼기
		int count = 0;
		while (!progresses.empty() && progresses.front() >= 100) {
			count++;
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
		}
		if (count != 0) answer.push_back(count);
	}
	return answer;
}