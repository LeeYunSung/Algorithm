#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	if (!arr.empty()) answer.push_back(arr.front());
	for (auto& i : arr) {
		if (answer.back() != i) {
			answer.push_back(i);
		}
	}

	return answer;
}