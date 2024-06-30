# include <iostream>
# include <queue>
# include <cstring>
using namespace std;

const int MAX_VALUE = 301;

void BFS(int startX, int startY);

int classX, classY, startX, startY, targetX, targetY;
char map[MAX_VALUE][MAX_VALUE];
int searchCount; //탐색횟수
bool isFound;

int main() {
    cin >> classX >> classY;
    cin >> startX >> startY >> targetX >> targetY;

    for (int i = 1; i <= classX; i++) {
        for (int j = 1; j <= classY; j++) {
            cin >> map[i][j];
        }
    }

    while (1) {
        searchCount++;
        BFS(startX, startY);
        if (isFound) break;
    }
    cout << searchCount;

    return 0;
}

void BFS(int startX, int startY) {
    queue<pair<int, int>> q;
    bool isVisited[MAX_VALUE][MAX_VALUE]; //방문체크
    memset(isVisited, false, sizeof(isVisited));
    int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; //방향키

    isVisited[startX][startY] = true;
    q.push({ startX, startY });

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];

            // 종료조건. 초코바 발견.
            if (map[nextX][nextY] == '#') {
                isFound = true;
                return;
            }

            if (0 >= nextX || nextX > classX || 0 >= nextY || nextY > classY || isVisited[nextX][nextY]) continue;

            isVisited[nextX][nextY] = true;
            if (map[nextX][nextY] == '1') { //사람 있으면 쓰러뜨리기
                map[nextX][nextY] = '0';
            }
            else if (map[nextX][nextY] == '0') {
                q.push({ nextX, nextY });
            }
        }
    }
}