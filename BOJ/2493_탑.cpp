#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int topNum, topHeight;
	stack<pair<int, int>> stk;

	cin >> topNum;

	for (int i = 1; i <= topNum; i++) {
		cin >> topHeight;

		if (stk.empty()) {	// stack �� ��� �ִٸ� push �� 0 ���(ex. 0�� index top)
			stk.push({ i, topHeight });
			cout << "0 ";
		}
		else {
			while (!stk.empty()) {
				if (stk.top().second > topHeight) {	// ���� ���� ��
					cout << stk.top().first << " ";	// index ���
					break;
				}
				else {
					stk.pop();	// ���� �Ұ� �� pop. ���� top ���� ������ ���� top�� ���ŵ� �� ����.
				}
			}
			if (stk.empty()) {	// �տ� ���� ������ top �� ������ 0 ���.
				cout << "0 ";
			}

			stk.push({ i,topHeight });	// stack �� push
		}
	}
	return 0;
}