#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 26;

void SearchHouse(int, int);

int map[MAX][MAX];
bool visited[MAX][MAX];

int map_size;
int direction[4][2] = { {0,-1}, {1,0}, {-1,0}, {0,1}, }; //상하좌우
int houseGroupNum;
int houseNum;

int main() {
	//Input
	cin >> map_size;
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf_s("%1d", &map[i][j]); // 공백없는 숫자를 한줄씩 입력받는 법
		}
	}

	//Search
	vector<int> houseGroup;
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				SearchHouse(i,j);
				houseGroup.push_back(houseNum);
				houseGroupNum++;
				houseNum = 0;
			}
		}
	}

	//Output
	cout << houseGroupNum << "\n";
	sort(houseGroup.begin(), houseGroup.end());
	for (int i = 0; i < houseGroup.size(); i++) {
		cout << houseGroup[i] << "\n";
	}
}

void SearchHouse(int x, int y) {
	if (map[x][y] == 0 || visited[x][y]) {
		return;
	}

	visited[x][y] = 1;
	houseNum++;

	for (int i = 0; i < 4; i++) {
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];
		if (dx >= 0 && dx < map_size && dy >= 0 && dy < map_size) {
			SearchHouse(dx, dy);
		}
	}
}
