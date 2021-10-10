#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "";
	cin >> str;

	string number = "";
	int result = 0;
	bool minus_flag = false;

	for (int i = 0; i <= str.length(); i++) {//****i를 str의 길이까지 포함해서 반복해줘야 함.
		if (str[i] == '+' || str[i] == '-' || i == str.length()) {
			if (minus_flag) {
				result -= stoi(number);
			}
			else {
				result += stoi(number);
			}
			minus_flag = (str[i] == '-') ? true : false;
			number = "";
		}
		else number += str[i]; //*****else 안써줘서 이상하게 연산한 것....
	}
	cout << result;

	return 0;
}
