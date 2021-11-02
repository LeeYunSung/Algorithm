#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	string string_ab = to_string(a) + to_string(b);
	string string_ba = to_string(b) + to_string(a);
	return string_ab > string_ba;
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), compare);
	for (auto& i : numbers) {
		answer += to_string(i);
	}
	return (answer[0] == '0') ? "0" : answer;
}