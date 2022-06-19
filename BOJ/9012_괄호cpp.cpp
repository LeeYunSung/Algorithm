#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCaseNum = 0, sum = 0;
	string PS = "";

	cin >> testCaseNum;
	while (testCaseNum--) {
		cin >> PS;
		sum = 0;
		for (char s : PS) {
			if (s == '(') {
				sum += 1;
			}
			else {
				sum -= 1;
			}
			if (sum < 0) break;
		}
		if (sum == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}