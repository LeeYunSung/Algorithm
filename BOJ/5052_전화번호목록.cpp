//�����ؼ� �� ���ڿ��� �������ڿ��� ���λ簡 �Ǵ����� Ȯ���ϸ��.
//���λ簡 �Ǹ� �ϰ��� NO ��ȯ�ϰ� Ž������.
//Ž�� �� �������� �ϰ��� NO�� ��ȯ���� �ʾҴٸ� �ϰ��� YES ��ȯ�ϰ� ����.

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