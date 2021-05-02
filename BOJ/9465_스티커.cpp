#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int testcase = 0;

	cin >> testcase;
	while (testcase > 0) {
		int column = 0;
		int sticker[2][100001] = { {0,0}, };

		//Input
		cin >> column;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < column+1; j++) {
				cin >> sticker[i][j];
			}
		}

		//DP algorithm
		for (int i = 2; i < column+1; i++) {
			sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
			sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
		}

		//Output
		cout << max(sticker[0][column], sticker[1][column]) << "\n";
		testcase--;
	}
}