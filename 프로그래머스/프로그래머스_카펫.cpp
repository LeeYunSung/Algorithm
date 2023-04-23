#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	//갈색 노란색 개수 더해서 넓이 구하기
	int sum = brown + yellow;

	//최소 높이는 3부터 시작
	for (int height = 3; ; height++) {
		int width = sum / height;
		//무조건 갈색인 높이 2줄, 가로 2줄을 제외한 값을 곱했을 때 노란색 값과 같으면 그게 정답.
		if (((height - 2)*(width - 2)) == yellow) {
			answer.push_back(width);
			answer.push_back(height);
			break;
		}
	}
	return answer;
}