#include <iostream>
#include <vector>
using namespace std;

const int MAP_SIZE = 100;

int main() {
	int paperNum, inputX, inputY, area = 0;
	int map[MAP_SIZE][MAP_SIZE] = { {0,0}, };

	cin >> paperNum;
	for (int i = 0; i < paperNum; i++) {
		cin >> inputY >> inputX;
		for (int x = inputX; x < inputX + 10; x++) {
			for (int y = inputY; y < inputY + 10; y++) {
				map[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == 1) {
				area += 1;
			}
		}
	}

	cout << area;

	return 0;
}