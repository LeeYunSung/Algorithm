#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int testcaseNum, west, east;
	int dp[31][31] = { 0, };

	for (int i = 1; i <= 30; i++) {
		dp[i][1] = i;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			for (int k = j - 1; k >= i - 1; k--) {
				dp[j][i] += dp[k][i - 1];
			}
		}
	}

	cin >> testcaseNum;
	for (int i = 0; i < testcaseNum; i++) {
		cin >> west >> east;
		cout << dp[east][west] << "\n";
	}
	return 0;
}