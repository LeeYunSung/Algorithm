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
				// ���� ���ڰ� stack �� top �� ������ pop
				if (stack.top() == word[i]) {
					stack.pop();
				}
				// ���� ���ڰ� stack �� top �� �ٸ��� push
				else {
					stack.push(word[i]);
				}
			}
		}

		// ��� ��������� good word �� �߰�
		if (stack.empty()) {
			good_word_count++;
		}
	}

	cout << good_word_count << "\n";

	return 0;
}