#include <iostream>
#include <cstring>
using namespace std;

void searchIsland(int, int);

const int MAX = 50;

int width, height; //���� ����, ����
int map[MAX][MAX]; //����
bool visited[MAX][MAX]; //�湮üũ �迭

typedef struct
{
	int dx, dy;

}dir;

dir direction[8] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1} };//�� �� �� �� �밢��

int main() {
	while (1) {
		//1. ���� ����, ���� ���� �Է¹ޱ�
		cin >> width >> height;
		if (width == 0 && height == 0) break;

		//2. ������ ������
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> map[y][x];
			}
		}
		//3. �� Ž�� ����
		int islandCount = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (map[y][x] == 1 && visited[y][x] == 0) {
					searchIsland(y, x);
					islandCount++;
				}
			}
		}
		//4. ���� ���
		cout << islandCount << "\n";

		//5. �湮�迭, count ���� �ʱ�ȭ
		memset(visited, false, sizeof(visited));
	}
}

void searchIsland(int y, int x) {
	if (map[y][x] == 0 || visited[y][x]) return;
	else {
		visited[y][x] = true;
		for (int i = 0; i < 8; i++) {
			int next_y = y + direction[i].dy;
			int next_x = x + direction[i].dx;
			if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height) {
				searchIsland(next_y, next_x);
			}
		}
	}
}