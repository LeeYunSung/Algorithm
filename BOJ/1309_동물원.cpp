#include <iostream>
using namespace std;

void DP_function(int);

const int MAX_SIZE = 100000;
const int MOD = 9901;
int dp[MAX_SIZE][3];

int main() {
	int column = 0;
	cin >> column;
	DP_function(column);
}

void DP_function(int column) {
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= column; i++) {
		//i-1��° �ٿ� ���ڰ� ���� ���
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2]) % MOD;
		//i-1��° �� ���ʿ� ���ڰ� �ִ� ���
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		//i-1��° �� �����ʿ� ���ڰ� �ִ� ���
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	cout << (dp[column][0] + dp[column][1] + dp[column][2]) % MOD;
}
