#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int MAX_VALUE = 100001;

int visitTime[MAX_VALUE]; //�湮�ҿ�ð�
int visitCount[MAX_VALUE]; //�ִܰŸ��� �湮�� �� �ִ� Ƚ��

void BFS(int mePos, int youPos);

int main() {
	int mePos, youPos;

	cin >> mePos >> youPos;

	if (mePos == youPos) {
		cout << 0 << '\n' << 1 << '\n';
	}
	else {
		BFS(mePos, youPos);
		cout << visitTime[youPos] - 1 << '\n';
		cout << visitCount[youPos] << '\n';
	}

	return 0;
}

void BFS(int mePos, int youPos) {
	queue<int> q;

	visitTime[mePos] = 1;
	visitCount[mePos] = 1;
	q.push(mePos);

	while (!q.empty()) {
		int nowPos = q.front();
		q.pop();
		
		for (int nextPos : {nowPos - 1, nowPos + 1, nowPos * 2}) {
			if (0 <= nextPos && nextPos <= MAX_VALUE) {
				if (!visitTime[nextPos]) {
					q.push(nextPos);
					visitTime[nextPos] = visitTime[nowPos] + 1; // ������� �湮�� �ð��� 1�� �� �߰�
					visitCount[nextPos] += visitCount[nowPos]; // �湮���� Ƚ�� 1�� �߰�
				}
				else if(visitTime[nextPos] == visitTime[nowPos] + 1) { // �湮������ �ִܰŸ� �ð��� ������
					visitCount[nextPos] += visitCount[nowPos]; // �湮���� ���� �߰�
				}
			}
		}
	}
}