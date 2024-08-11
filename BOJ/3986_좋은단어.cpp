#include <iostream>
#include <stack>
using namespace std;

int main() {
	int word_num, good_word_count = 0;

	cin >> word_num;

	while(word_num--) {
		stack<char> stack;
		string word;

		cin >> word;

		for (int i = 0; i < word.length(); i++) {
			if (stack.empty()) {
				stack.push(word[i]);
			}
			else {
				// 현재 문자가 stack 의 top 과 같으면 pop
				if (stack.top() == word[i]) {
					stack.pop();
				}
				// 현재 문자가 stack 의 top 과 다르면 push
				else {
					stack.push(word[i]);
				}
			}
		}

		// 모두 비워졌으면 good word 로 추가
		if (stack.empty()) {
			good_word_count++;
		}
	}

	cout << good_word_count << "\n";

	return 0;
}