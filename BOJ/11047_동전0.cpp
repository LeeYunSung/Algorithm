#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cashNum, targetCashValue, cash, minCashNum = 0;
	vector<int> cashVector;
	cin >> cashNum >> targetCashValue;

	for (int i = 0; i < cashNum; i++) {
		cin >> cash;
		cashVector.push_back(cash);
	}
	
	for (int i = cashVector.size() - 1; i >= 0; i--) {
		if (targetCashValue == 0) break;
		if (cashVector[i] <= targetCashValue) {
			minCashNum += (targetCashValue / cashVector[i]);
			targetCashValue -= cashVector[i] * (targetCashValue / cashVector[i]);
		}
	}
	cout << minCashNum << "\n";
	return 0;
}