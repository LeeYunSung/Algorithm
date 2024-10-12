#include <iostream>
#include<queue>
using namespace std;

void fastIO();

int main() {
	fastIO();

	int calNum;
	priority_queue<int, vector<int>, greater<int>> p_queue;

	cin >> calNum;

	for (int i = 0; i < calNum; i++) {
		int cal;
		cin >> cal;

		if (cal == 0) {
			if (p_queue.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << p_queue.top() << "\n";
				p_queue.pop();
			}
		}
		else {
			p_queue.push(cal);
		}
	}
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}