#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x;//x��ǥ
	int y;//y��ǥ
	int direction;//����
	int generation;//�����
	vector<int> dragon_curves_vector;//�������ŭ �׷��� �巡�� Ŀ��
}Dragon;

const int MAX_VALUE = 101;//***** ������ �ִ밪
vector<Dragon> dragon_vector;//�������� �־��� �巡�� Ŀ���
int direction_key[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };//����: 0 1 2 3
bool map[MAX_VALUE][MAX_VALUE];//�巡��Ŀ�갡 �̵��� �� �ִ� ����

void MakeDragonCurve();//�巡�� Ŀ���� ���� �� ��ŭ �׷��� �巡��Ŀ����� ���մϴ�.
void DrawDragonCurve();//�巡�� Ŀ���� ����ŭ �巡�� Ŀ����� ������ true�� ǥ���մϴ�.
int CountRectangle();//������ ǥ�õ� �� �� 4�������� true�� üũ�� ������ ã�Ƽ� ��ȯ�մϴ�.

int main() {
	int curve_num;
	cin >> curve_num;

	for (int i = 0; i < curve_num; i++) {
		Dragon dragon;
		cin >> dragon.y >> dragon.x >> dragon.direction >> dragon.generation; //***** x���� �� ����, y���� �� ���� �̹Ƿ� x�� y�� �ٲ㼭 �޾���� ��
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
		map[dragon_vector[i].x][dragon_vector[i].y] = true;//***** �� ÷���� �ʿ� üũ ����� ��
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

//***** �簢�� ã�� ��: 4���� true�̸� �簢������ �Ǵ��ϰ� count 1 �÷���
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