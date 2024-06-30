#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int MAX_VALUE = 100001;

int visitTime[MAX_VALUE]; //방문소요시간
int visitCount[MAX_VALUE]; //최단거리로 방문할 수 있는 횟수

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
					visitTime[nextPos] = visitTime[nowPos] + 1; // 현재까지 방문한 시간에 1초 더 추가
					visitCount[nextPos] += visitCount[nowPos]; // 방문가능 횟수 1개 추가
				}
				else if(visitTime[nextPos] == visitTime[nowPos] + 1) { // 방문했지만 최단거리 시간과 같으면
					visitCount[nextPos] += visitCount[nowPos]; // 방문가능 경우로 추가
				}
			}
		}
	}
}