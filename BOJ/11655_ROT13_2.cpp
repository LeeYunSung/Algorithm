#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;	

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] += (str[i] - 'a' < 13) ? 13 : -13;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += (str[i] - 'A' < 13) ? 13 : -13;
		}
	}

	cout << str << "\n";

	return 0;
}