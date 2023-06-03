#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int index = 0;
	do {
		index = max_element(priorities.begin(), priorities.end()) - priorities.begin();
		for (int i = 0; i < index; i++) {
			int front = priorities.front();
			priorities.erase(priorities.begin());
			priorities.push_back(front);
		}
		priorities.erase(priorities.begin());
		answer++;
	} while (location == priorities[index]);


	return answer;
}