#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	string name; // input 이름
	int alphabet[26] = { 0, }; // 알파벳 카운트
	int oddCount = 0; // 홀수 알파벳 카운트(종료조건)

	cin >> name;
	for (int i = 0; i < name.size(); i++) {
		alphabet[name[i] - 'A']++;
	}

	// 홀수 알파벳 개수 찾기
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			if (alphabet[i] % 2 == 1) {
				oddCount++;
			}
		}
	}

	// 홀수 알파벳이 2 이상이면 팰린드롬 불가
	if (oddCount > 1) {
		cout << "I'm Sorry Hansoo\n";
	}
	else {
		string outputName = "";

		// 앞에 문자열 반 넣기
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alphabet[i] / 2; j++) {
				outputName += i + 'A';
			}
		}
		// 가온데 문자열 넣기
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 != 0) {
				outputName += i + 'A';
			}
		}
		// 뒤에 문자열 반 넣기
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alphabet[i] / 2; j++) {
				outputName += i + 'A';
			}
		}
		cout << outputName << "\n";
	}

	return 0;
}