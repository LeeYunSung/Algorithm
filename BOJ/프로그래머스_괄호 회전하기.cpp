#include <iostream>
#include <string>
#include <stack>
using namespace std;

int findCorrectBracket(string);	//올바른 문자열인지 아닌지를 체크하는 함수
string rotateString(string);	//문자열 길이만큼 왼쪽으로 한 칸씩 회전하는 함수

int main() {
	string bracketString;
	int correctNum = 0;

	cin >> bracketString;
	for (int idx = 0; idx < bracketString.length(); idx++) {
		correctNum += findCorrectBracket(bracketString);
		bracketString = rotateString(bracketString);
	}
	cout << correctNum;
}

string rotateString(string bracketString) {
	string firstString = bracketString.substr(0, 1);
	string subString = bracketString.substr(1, bracketString.length() - 1);
	return subString + firstString;
}

int findCorrectBracket(string bracketString) {
	int correctBracketNum = 0;
	stack<char> s_openBracket;

	for (int idx = 0; idx < bracketString.length(); idx++) {
		char closedBracket;
		char currentBracket = bracketString[idx];
		//올바르지 않은 괄호의 경우를 예외처리문으로 적어주고
		//그 외의 경우를 올바른 괄호라고 처리해주자.

		//열린괄호
		if (currentBracket == '(' || currentBracket == '{' || currentBracket == '[') {
			s_openBracket.push(currentBracket);
		}
		//닫힌괄호
		else {
			if (s_openBracket.empty()) { //바로 ),},] 같은 닫힌괄호로 시작하면 그건 올바른 괄호 문자열이 아님
				return 0;
			}

			switch (currentBracket) {	// (,{,[ 열린 괄호로 시작했으면 그 다음 예외처리를 따져보자.
			case ')':
				if (s_openBracket.top() != '(') { //직전 괄호가 (이면 이번 괄호는 )여야 올바른 괄호겠지
					return 0;
				}
				break;
			case '}':
				if (s_openBracket.top() != '{') { //직전 괄호가 {이면 이번 괄호는 }여야 올바른 괄호겠지
					return 0;
				}
				break;
			case ']':
				if (s_openBracket.top() != '[') {	//직전 괄호가 [이면 이번 괄호는 ]여야 올바른 괄호겠지
					return 0;
				}
				break;
			default:
				break;
			}
			s_openBracket.pop();	//올바른 괄호이면 top() 포인터를 한칸 옮겨서 다음도 올바른 괄호인지 체크해보자.
		}
	}
	if (s_openBracket.empty()) return 1;	//마지막까지 남김없이 올바른 괄호로 판단이 되었을 때 1을 return.
	else return 0;	// ★ 마지막에 { 하나만 남았다면 올바른 괄호가 아니니깐 이런 경우도 예외처리 해주기.
}
