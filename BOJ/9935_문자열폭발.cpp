#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


//폭발, 짝짓기 => stack

int main() {
	string origin_str, bumb_str, answer_str = ""; //Input 문자열, 폴발 문자열, 정답 문자열
	stack<char> stk; // 폭발 문자열과의 비교를 위한 stack

	cin >> origin_str >> bumb_str;

	//stack 을 이용한 문자열비교
	for (char s : origin_str) {
		stk.push(s); // 일단 stack 에 문자열 차례로 넣기
		
		if (stk.size() >= bumb_str.size()) { //stack 크기가 폭발 문자열 크기보다 커졌으면 비교 시작
			char stack_end = stk.top(); // stack 의 맨 위 글자와
			char bumb_end = bumb_str[bumb_str.size() - 1]; // 폭발 문자열의 맨 끝자가 같은지 확인

			if (stack_end == bumb_end) { // 같다면 폭발 문자열 길이만큼 빼서 stack 앞의 문자열 비교
				string compare_str = "";
				for (char i : bumb_str) {
					compare_str += stk.top();
					stk.pop();
				}
				reverse(compare_str.begin(), compare_str.end()); // stack 문자열은 뒤집어져 있으니까 한번 뒤집기
				if (bumb_str != compare_str) { //다르면 다시 집어넣기 같으면 뺀 상태임
					for (int i : compare_str) {
						stk.push(i);
					}
				}
			}
		}
	}

	//출력
	if (stk.size() == 0) cout << "FRULA";
	else {
		while (stk.size()) {
			answer_str += stk.top(); stk.pop();
		}
		reverse(answer_str.begin(), answer_str.end());// stack 문자열은 뒤집어진 상태니까 한번 뒤집기
		cout << answer_str;
	}

	return 0;
}