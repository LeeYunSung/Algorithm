#include <string>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int calculationNum, bit = 0, num;
	string calculationString;

	cin >> calculationNum;
	for (int i = 0; i < calculationNum; i++) {
		cin >> calculationString;
		if (calculationString == "add") {
			cin >> num;
			bit |= (1 << num);
		}
		else if (calculationString == "remove") {
			cin >> num;
			bit &= ~(1 << num);
		}
		else if (calculationString == "check") {
			cin >> num;
			if (bit & (1 << num)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (calculationString == "toggle") {
			cin >> num;
			bit ^= (1 << num);
		}
		else if (calculationString == "all") {
			bit = (1 << 21) - 1;
		}
		else if (calculationString == "empty") {
			bit = 0;
		}
	}
	return 0;
}