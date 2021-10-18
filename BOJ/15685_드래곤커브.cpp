#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x;//x좌표
	int y;//y좌표
	int direction;//방향
	int generation;//세대수
	vector<int> dragon_curves_vector;//세대수만큼 그려진 드래곤 커브
}Dragon;

const int MAX_VALUE = 101;//***** 지도의 최대값
vector<Dragon> dragon_vector;//문제에서 주어진 드래곤 커브들
int direction_key[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };//방향: 0 1 2 3
bool map[MAX_VALUE][MAX_VALUE];//드래곤커브가 이동할 수 있는 지도

void MakeDragonCurve();//드래곤 커브의 세대 수 만큼 그려질 드래곤커브들을 구합니다.
void DrawDragonCurve();//드래곤 커브의 수만큼 드래곤 커브들을 지도에 true로 표시합니다.
int CountRectangle();//지도에 표시된 것 중 4꼭지점이 true로 체크된 개수를 찾아서 반환합니다.

int main() {
	int curve_num;
	cin >> curve_num;

	for (int i = 0; i < curve_num; i++) {
		Dragon dragon;
		cin >> dragon.y >> dragon.x >> dragon.direction >> dragon.generation; //***** x축은 → 방향, y축은 ↓ 방향 이므로 x와 y를 바꿔서 받아줘야 함
		dragon.dragon_curves_vector.push_back(dragon.direction);
		dragon_vector.push_back(dragon);
	}
	MakeDragonCurve();
	DrawDragonCurve();
	cout << CountRectangle();
}

void MakeDragonCurve() {
	for (int i = 0; i < dragon_vector.size(); i++) {
		vector<int> temp_vector;
		for (int j = 1; j <= dragon_vector[i].generation; j++) {
			temp_vector.assign(dragon_vector[i].dragon_curves_vector.begin(), dragon_vector[i].dragon_curves_vector.begin() + dragon_vector[i].dragon_curves_vector.size());
			for (int k = temp_vector.size()-1; k >= 0; k--) {
				dragon_vector[i].dragon_curves_vector.push_back((temp_vector[k]+1)%4);
			}
		}
	}
}

void DrawDragonCurve() {
	for (int i = 0; i < dragon_vector.size(); i++) {
		map[dragon_vector[i].x][dragon_vector[i].y] = true;//***** 맨 첨에도 맵에 체크 해줘야 함
		for (int j = 0; j < dragon_vector[i].dragon_curves_vector.size(); j++) {
			int x = dragon_vector[i].x + direction_key[dragon_vector[i].dragon_curves_vector[j]][0];
			int y = dragon_vector[i].y + direction_key[dragon_vector[i].dragon_curves_vector[j]][1];
			if (x >= 0 && x < MAX_VALUE && y >= 0 && y < MAX_VALUE) {
				map[x][y] = true;
				dragon_vector[i].x = x;
				dragon_vector[i].y = y;
			}
		}
	}
}

//***** 사각형 찾는 법: 4면이 true이면 사각형으로 판단하고 count 1 늘려줌
int CountRectangle() {
	int count = 0;
	for (int i = 0; i < MAX_VALUE-1; i++) {
		for (int j = 0; j < MAX_VALUE-1; j++) {
			if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) {
				count += 1;
			}
		}
	}
	return count;
}