#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "";
	cin >> str;

	string number = "";
	int result = 0;
	bool minus_flag = false;

	for (int i = 0; i <= str.length(); i++) {//****i�� str�� ���̱��� �����ؼ� �ݺ������ ��.
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
		else number += str[i]; //*****else �Ƚ��༭ �̻��ϰ� ������ ��....
	}
	cout << result;

	return 0;
}
