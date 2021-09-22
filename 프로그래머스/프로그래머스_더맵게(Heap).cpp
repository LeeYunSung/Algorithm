#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) { // scoville: 2 이상 1,000,000 이하
	int answer = 0;

	int first_low_scoville = 0;
	int second_low_scoville = 0;

	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.top() < K) {
		if (pq.size() <= 1) return -1;

		first_low_scoville = pq.top();
		pq.pop();
		second_low_scoville = pq.top();
		pq.pop();

		pq.push(first_low_scoville + second_low_scoville * 2);
		answer++;
	}
	return answer;
}