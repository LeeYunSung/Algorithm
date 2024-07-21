#include <iostream>
#include <limits.h>
using namespace std;
typedef long long ll;

ll goGame(ll gameNum, ll winNum);

int main() {
	ll gameNum, winNum;

	cin >> gameNum >> winNum;
	cout << goGame(gameNum, winNum) << "\n";
	
	return 0;
}

ll goGame(ll gameNum, ll winNum) {
	ll low = 0, high = LONG_MAX, mid;
	ll currentWinPercent, newWinPercent;
	ll result = -1;

	cout << high << "\n";

	currentWinPercent = winNum * 100 / gameNum;
	if (currentWinPercent >= 99) return -1;

	while (low <= high) {
		mid = (low + high) / 2;
		newWinPercent = (winNum + mid) * 100 / (gameNum + mid);

		if (currentWinPercent < newWinPercent) {
			high = mid - 1;
			result = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}