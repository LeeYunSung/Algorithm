#include <iostream>
#include <algorithm>
using namespace std;

int searchMax(int, int*);

int main() {
	int num;
	cin >> num;

	int *card = new int[num+1] {0, };
	for (int i = 1; i <= num; i++) {
		cin >> card[i];
	}
	cout << searchMax(num, card) << "\n";
}

int searchMax(int num, int *card) {
	int *dp = new int[num + 1] {0, };
	for (int i = 1; i <= num; i++) {//bottom-up ¹æ½Ä
		for (int j = 1; j <= i; j++) {
			dp[i] = max(card[j] + dp[i-j], dp[i]);
		}
	}
	return dp[num];
}