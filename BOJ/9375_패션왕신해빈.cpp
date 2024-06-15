#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int testcase;

	cin >> testcase;
	
	while (testcase--) {
		unordered_map<string, int> clothes;
		string name, type;
		int clothesNum, caseSum = 1;

		cin >> clothesNum;

		while (clothesNum--) {
			cin >> name >> type;
			clothes[type]++;
		}
		
		for (auto i : clothes) {
			caseSum *= (i.second + 1);
		}

		caseSum -= 1;
		cout << caseSum << "\n";
	}

	return 0;
}