#include <string>
#include <iostream>
using namespace std;

bool isCorrectString(string balanace_string) {
	if (balanace_string == "") return true;

	int check = 0; // ( 는 +1로 )는 -1로 표현해서 괄호개수확인을 통해 올바른 괄호문자열인지를 판단한다.
	for (int i = 0; i < balanace_string.length(); i++) {
		if (check < 0) return false; //한번이라도 음수가 되면 )괄호가 먼저 열린 것이므로 false를 리턴한다.
		check += (balanace_string[i] == '(') ? 1 : -1;
	}return check == 0 ? true : false; //마지막에 check 변수가 0이 되면 올바른 괄호문자열인 것!
}

int returnBalanceStringIndex(string original_string) {
	int check = 0; // ( 는 +1로 )는 -1로 표현해서 괄호개수확인을 통해 올바른 괄호문자열인지를 판단한다.
	for (int i = 0; i < original_string.length(); i++) {
		check += (original_string[i] == '(') ? 1 : -1;
		if (check == 0) return i;
	}return original_string.length();
}

string solution(string original_string) {	
	//1. 입력이 빈 문자열이거나 올바른 문자열인 경우, 그대로 반환
	if (original_string == "" || isCorrectString(original_string)) {
		return original_string; 
	}

	//입력 문자열이 올바른 문자열이 아니라서 괄호 변환이 필요한 경우
	//2. 문자열을 두 "균형잡힌 괄호 문자열" balance_string1, balance_string2로 분리
	string balance_string1 = "", balance_string2 = "";
	balance_string1 = original_string.substr(0, returnBalanceStringIndex(original_string) + 1);
	balance_string2 = original_string.substr(balance_string1.length());

	//3. 문자열 balance_string1가 "올바른 괄호 문자열" 이라면 문자열 balance_string2에 대해 1단계부터 다시 수행
	if (isCorrectString(balance_string1)) {
		//3-1. 수행한 결과 문자열을 balance_string1에 이어 붙인 후 반환
		balance_string1 += solution(balance_string2);
		return balance_string1;
	}
	
	//4. 문자열 balance_string1가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행
	else {
		string correct_string = "";

		//4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙임
		correct_string += "(";

		//4 - 2. 문자열 balance_string2에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙임
		correct_string += solution(balance_string2);

		//4 - 3. ')'를 다시 붙임
		correct_string += ")";

		//★ 4 - 4. balance_string1의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙임
		balance_string1 = balance_string1.substr(1, balance_string1.length() - 2);

		for (int i = 0; i < balance_string1.length(); i++) {
			balance_string1[i] = (balance_string1[i] == '(') ? ')' : '(';
		}
		correct_string += balance_string1;

		//4 - 5. 생성된 문자열을 반환
		return correct_string;
	}
}

//test용 코드 추가..
int main() {
	string original_string = "";
	cin >> original_string;
	cout << solution(original_string);
}