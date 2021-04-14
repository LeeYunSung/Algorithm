#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 50;

void SearchMap(int, int);

int width, height;		 //�������� �־����� ������ ���μ��� ũ��
int map[MAX][MAX];		//��������
int visited[MAX][MAX];	//�湮�ߴ��� üũ�ϴ� ����
int direction[8][2] = { {0,-1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1} }; //��, ��, ��, ��, �밢��

int main() {
	while(1) {
		cin >> width >> height;
		
		if (width == 0 && height == 0) break;		//0, 0 �̸� ������ ���̹Ƿ� ����

		//���� �Է¹ޱ�
		for (int i = 0; i < height; i++) {			//��
			for (int j = 0; j < width; j++) {		//��
				cin >> map[i][j];
			}
		}

		//Ž�� gogo. ��Ž���� ������ �ʱ�ȭ
		int count = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < height; i++) {	//��
			for (int j = 0; j < width; j++) {//��
				if (map[i][j] && !visited[i][j]) { //����ġ�� ���̰�, �湮�� ���� ������ ����ġ���� Ž�� ����
					SearchMap(i, j);
					count += 1;
				}
			}
		}
		cout << count << "\n";
	} 
}

void SearchMap(int x, int y) {
	if (!map[x][y] || visited[x][y]) { //��Ž�� �ϴٰ� ���� �ƴϰų� �̹� �湮�� ���� ������, ���̻� Ž���� �ʿ� �����ϱ� �ٷ� ����������
		return;
	}
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {		//�����¿�밢�� Ž��
		int dx = x + direction[i][0];	//x��ǥ
		int dy = y + direction[i][1];	//y��ǥ
		if (dx >= 0 && dx < height && dy >= 0 && dy < width) {// �����¿�� �̵��� ���� ������ ������ �Ѵ��� üũ
			SearchMap(dx, dy);
		}
	}
}