#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	//갈색 노란색 개수 더하기
	int sum = brown + yellow;

	//최소 높이는 3부터 시작
	for (int height = 3; ; height++) {
		//합을 높이로 나눴을 때 나머지가 0이 아닐 때
		if ((sum % height) != 0) {
			//합을 높이로 나눈 값이 가로 값이 됨
			int width = sum / height;
			//무조건 갈색인 높이 2줄, 가로 2줄을 제외한 값을 곱했을 때 노란색 값과 같으면 그게 정답.
			if (((height - 2)*(width - 2)) == yellow) {
				answer.push_back(width);
				answer.push_back(height);
				break;
			}
		}
	}
	return answer;
}

