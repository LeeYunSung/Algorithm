#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 200001;

int minTime; // 최단시간
vector<int> route; // 방문경로

void BFS(int mePos, int youPos);

int main() {
    int mePos, youPos;

    cin >> mePos >> youPos;
    BFS(mePos, youPos);

    cout << minTime - 1 << '\n';
    for (auto i : route) cout << i << " ";

    return 0;
}

void BFS(int mePos, int youPos) {
    queue<int> q;
    int visitTime[MAX_VALUE]; //방문소요시간
    int prevVisited[MAX_VALUE]; //이전에 방문한 경로 추적용 배열

    visitTime[mePos] = 1;
    q.push(mePos);

    while (!q.empty()) {
        int nowPos = q.front();
        q.pop();

        // 종료조건
        if (nowPos == youPos) {
            minTime = visitTime[youPos];
            break;
        }

        for (int nextPos : {nowPos - 1, nowPos + 1, nowPos * 2}) {
            if (0 > nextPos || nextPos >= MAX_VALUE || visitTime[nextPos]) continue;

            visitTime[nextPos] = visitTime[nowPos] + 1; // 현재까지 방문한 시간에 1초 더 추가
            prevVisited[nextPos] = nowPos; //이전 경로 추가
            q.push(nextPos);

        }
    }

    //preVisited에 이전 경로가 있으므로 추적하여 출력.
    for (int i = youPos; i != mePos; i = prevVisited[i]) {
        route.push_back(i);
    }
    route.push_back(mePos);
    reverse(route.begin(), route.end());
}