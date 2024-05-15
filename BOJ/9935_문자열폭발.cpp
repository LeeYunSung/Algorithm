#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


//����, ¦���� => stack

int main() {
	string origin_str, bumb_str, answer_str = ""; //Input ���ڿ�, ���� ���ڿ�, ���� ���ڿ�
	stack<char> stk; // ���� ���ڿ����� �񱳸� ���� stack

	cin >> origin_str >> bumb_str;

	//stack �� �̿��� ���ڿ���
	for (char s : origin_str) {
		stk.push(s); // �ϴ� stack �� ���ڿ� ���ʷ� �ֱ�
		
		if (stk.size() >= bumb_str.size()) { //stack ũ�Ⱑ ���� ���ڿ� ũ�⺸�� Ŀ������ �� ����
			char stack_end = stk.top(); // stack �� �� �� ���ڿ�
			char bumb_end = bumb_str[bumb_str.size() - 1]; // ���� ���ڿ��� �� ���ڰ� ������ Ȯ��

			if (stack_end == bumb_end) { // ���ٸ� ���� ���ڿ� ���̸�ŭ ���� stack ���� ���ڿ� ��
				string compare_str = "";
				for (char i : bumb_str) {
					compare_str += stk.top();
					stk.pop();
				}
				reverse(compare_str.begin(), compare_str.end()); // stack ���ڿ��� �������� �����ϱ� �ѹ� ������
				if (bumb_str != compare_str) { //�ٸ��� �ٽ� ����ֱ� ������ �� ������
					for (int i : compare_str) {
						stk.push(i);
					}
				}
			}
		}
	}

	//���
	if (stk.size() == 0) cout << "FRULA";
	else {
		while (stk.size()) {
			answer_str += stk.top(); stk.pop();
		}
		reverse(answer_str.begin(), answer_str.end());// stack ���ڿ��� �������� ���´ϱ� �ѹ� ������
		cout << answer_str;
	}

	return 0;
}