#include <iostream>
#include <vector>
using namespace std;

int main() {
	int coin_num, value; //1 ¡Â coin_num ¡Â 100, 1 ¡Â value ¡Â 10,000
	vector<int> coins;

	cin >> coin_num >> value;
	for (int i = 0; i < coin_num; i++) {
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	int *dp = new int[value + 1]();
	dp[0] = 1;
	for (int coin_idx = 0; coin_idx < coin_num; coin_idx++) { //1,2,5
		for (int i = 1; i <= value; i++) { //1~10
			if (i - coins[coin_idx] >= 0) {//1-1 >=0, 2-1>=0, 2-2>=0, 3-1>=0, 3-2>=0, 4-1>=0, 4-2>=0
				dp[i] += dp[i - coins[coin_idx]];
			}
		}
	}
	cout << dp[value] << "\n";

	delete[] dp;
	return 0;
}