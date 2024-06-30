#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 200001;

int minTime; // �ִܽð�
vector<int> route; // �湮���

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
    int visitTime[MAX_VALUE]; //�湮�ҿ�ð�
    int prevVisited[MAX_VALUE]; //������ �湮�� ��� ������ �迭

    visitTime[mePos] = 1;
    q.push(mePos);

    while (!q.empty()) {
        int nowPos = q.front();
        q.pop();

        // ��������
        if (nowPos == youPos) {
            minTime = visitTime[youPos];
            break;
        }

        for (int nextPos : {nowPos - 1, nowPos + 1, nowPos * 2}) {
            if (0 > nextPos || nextPos >= MAX_VALUE || visitTime[nextPos]) continue;

            visitTime[nextPos] = visitTime[nowPos] + 1; // ������� �湮�� �ð��� 1�� �� �߰�
            prevVisited[nextPos] = nowPos; //���� ��� �߰�
            q.push(nextPos);

        }
    }

    //preVisited�� ���� ��ΰ� �����Ƿ� �����Ͽ� ���.
    for (int i = youPos; i != mePos; i = prevVisited[i]) {
        route.push_back(i);
    }
    route.push_back(mePos);
    reverse(route.begin(), route.end());
}