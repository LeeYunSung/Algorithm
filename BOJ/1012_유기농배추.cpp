#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAP_SIZE = 51;//���� �ִ� ũ��

int SearchBFS(int row, int col, int(&map)[MAP_SIZE][MAP_SIZE], vector<pair<int, int>> &cabbages);

int main() {
	int testcase;//����� input: �׽�Ʈ ���̽� ��
	int row, col, cabbageNum;//����� input: row(�� ũ��), col(�� ũ��), cabbageNum(����� ����)
	int x, y;//����� input: ����� x, y ��ǥ

	int map[MAP_SIZE][MAP_SIZE]{};//���� ������ ��� map�迭
	vector<pair<int, int> > cabbages;//����ߵ��� ��ġ ���� ����

	//input
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> row >> col >> cabbageNum;
		for (int j = 0; j < cabbageNum; j++) {
			cin >> x >> y;
			cabbages.push_back(make_pair(x, y));
			map[x][y] = 1;
		}
		//output
		cout << SearchBFS(row, col, map, cabbages) << "\n";

		//��Ž���� ���� �ʱ�ȭ
		memset(map, 0, sizeof(map));
		cabbages.clear();
	}

	return 0;
}

//���߱׷� ���� Ž��
int SearchBFS(int row, int col, int (&map)[MAP_SIZE][MAP_SIZE], vector<pair<int, int>> &cabbages) {

	int answer = 0;
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pair<int, int> > q;

	//����� ��ġ�� ��� �˰� �����Ƿ�, �� ��ü Ž���� �ƴ� ����� ��ġ�� Ž���ϸ� �ȴ�.
	for (int i = 0; i < cabbages.size(); i++) {
		
		int x = cabbages[i].first;
		int y = cabbages[i].second;

		if (map[x][y] == 1) {
			//�ʿ� �湮üũ
			map[x][y] = -1;

			//����� 1�� ��ġ�� ��� BFS�� �ش� ������� �׷��� ��� ã��
			q.push(make_pair(x, y));

			while (!q.empty()) {
				for (int j = 0; j < 4; j++) {//4���� Ž��
					int nx = q.front().first + dir[j][0];
					int ny = q.front().second + dir[j][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
						if (map[nx][ny] == 1) {
							map[nx][ny] = -1;
							q.push(make_pair(nx, ny));
						}
					}
				}
				q.pop();
			}
			answer += 1;//����� �׷� �Ѱ��� ã������ answer + 1
		}
	}
	return answer;
}

