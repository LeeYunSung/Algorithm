#include <iostream>
#include <string>
using namespace std;

int main() {
	int personNum, alphabet[26] = { 0, };
	string name = "", answer = "";

	cin >> personNum;
	for (int i = 0; i < personNum; i++) {
		cin >> name;
		alphabet[name[0] - 'a']++;
	}
	
	for (int i = 0; i < sizeof(alphabet)/sizeof(int); i++) {
		if (alphabet[i] >= 5) {
			answer += (i + 'a');
		}
	}
	if (answer.size()) cout << answer <<"\n";
	else cout << "PREDAJA" << "\n";

	return 0;
}