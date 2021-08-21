#include <string>
using namespace std;

int solution(string s) {
	string numString = "";

	for (int i = 0; i < s.size(); i++) {
		//숫자 일 때: 바꿀 필요 없이 그대로 출력하면 됨
		if (s[i] >= '0' && s[i] <= '9') {
			numString += s[i];
			continue;
		}
		//문자일 때: 숫자로 바꿔야 함
		else {
			switch (s[i]) {
			case 'z'://zero
				i += 3;
				numString += '0';
				break;
			case 'o'://one
				i += 2;
				numString += '1';
				break;
			case 't'://two or three
				if (s[i + 1] == 'w') {
					i += 2;
					numString += '2';
				}
				else if (s[i + 1] == 'h') {
					i += 4;
					numString += '3';
				}
				break;
			case 'f'://four or five
				if (s[i + 1] == 'o') {
					i += 3;
					numString += '4';
				}
				else if (s[i + 1] == 'i') {
					i += 3;
					numString += '5';
				}
				break;
			case 's'://six or seven
				if (s[i + 1] == 'i') {
					i += 2;
					numString += '6';
				}
				else if (s[i + 1] == 'e') {
					i += 4;
					numString += '7';
				}
				break;
			case 'e'://eight
				i += 4;
				numString += '8';
				break;
			case 'n'://nine
				i += 3;
				numString += '9';
				break;
			}
		}
	}
	return atoi(numString.c_str());
}