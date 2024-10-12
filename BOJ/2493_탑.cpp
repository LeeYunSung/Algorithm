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

		if (stk.empty()) {	// stack 이 비어 있다면 push 후 0 출력(ex. 0번 index top)
			stk.push({ i, topHeight });
			cout << "0 ";
		}
		else {
			while (!stk.empty()) {
				if (stk.top().second > topHeight) {	// 수신 가능 시
					cout << stk.top().first << " ";	// index 출력
					break;
				}
				else {
					stk.pop();	// 수신 불가 시 pop. 현재 top 보다 낮으면 다음 top도 수신될 일 없음.
				}
			}
			if (stk.empty()) {	// 앞에 수신 가능한 top 이 없으면 0 출력.
				cout << "0 ";
			}

			stk.push({ i,topHeight });	// stack 에 push
		}
	}
	return 0;
}