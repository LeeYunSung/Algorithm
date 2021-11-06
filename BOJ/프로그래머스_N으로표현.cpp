#include <unordered_set>
#include <cmath>
using namespace std;

int solution(int N, int number) {
	int answer = 0;
	unordered_set<int> dp[9];

	int value = 0;
	for (int i = 1; i <= 8; i++) {
		value += pow(10, i - 1) * N;
		dp[i].insert(value);
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto& op1 : dp[j]) {
				for (auto& op2 : dp[i - j]) {
					dp[i].insert(op1 + op2);
					dp[i].insert(op1 - op2);
					dp[i].insert(op1 * op2);
					if (op2 != 0) dp[i].insert(op1 / op2);
				}
			}
		}
		if (dp[i].count(number) > 0) {
			return i;
		}
	}
	return -1;
}