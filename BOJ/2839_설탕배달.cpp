#include <iostream>
using namespace std;


int main() {
	int sugarWeight, sugarNum;
	cin >> sugarWeight;

	for (int fiveSugarNum = sugarWeight / 5; fiveSugarNum >= 0; fiveSugarNum--) {
		if ((sugarWeight - (5 * fiveSugarNum)) % 3 == 0) {
			cout << fiveSugarNum +  ((sugarWeight - (5 * fiveSugarNum)) / 3);
			return 0;
		}
	}
	cout << "-1";
	return 0;
}