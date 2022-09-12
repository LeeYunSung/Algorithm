//정렬해서 현 문자열이 다음문자열의 접두사가 되는지만 확인하면됨.
//접두사가 되면 일관성 NO 반환하고 탐색종료.
//탐색 전 범위까지 일관성 NO를 반환하지 않았다면 일관성 YES 반환하고 종료.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isConsistency(vector<string>& phoneNumbers);

int main() {
	int testCase = 0, numCount;
	string inputNumber = "";
	vector<string> phoneNumbers;

	//input
	cin >> testCase;
	for(int i = 0; i<testCase; i++){
		cin >> numCount;
		for (int j = 0; j < numCount; j++) {
			cin >> inputNumber;
			phoneNumbers.push_back(inputNumber);
		}
		//output
		if (isConsistency(phoneNumbers)) cout << "YES\n";
		else cout << "NO\n";

		phoneNumbers.clear();
	}

	return 0;
}

bool isConsistency(vector<string>& phoneNumbers) {
	sort(phoneNumbers.begin(), phoneNumbers.end());

	for (int i = 0; i < phoneNumbers.size() - 1; i++) {
		if (phoneNumbers[i] == phoneNumbers[i + 1].substr(0, phoneNumbers[i].length())) {
			return false;
		}
	}
	return true;
}