#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (!progresses.empty()) {

		//�Ϸ�� �翡 �۾��� ���ϱ�
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}

		//�� �տ� progress�� 100�Ȱ� �� ����
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