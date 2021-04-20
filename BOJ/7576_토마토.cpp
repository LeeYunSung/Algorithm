#include <iostream>
#include <queue> //queue �ڷᱸ��
#include <utility> //pair queue ����� ����
using namespace std;

const int MAX = 1001;//������ �ִ� ũ��

int row, column; // ������ ũ��(��, ��)
int map[MAX][MAX]; // ����
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //Ž���� �����¿� ����
queue<pair<int, int>> q; //BFS Ž���� ���� �����

int searchBFS(int);
void output(int);

int main() {
	//Input
	cin >> row >> column;
	for (int i = 0; i < column; i++) {//���α���
		for (int j = 0; j < row; j++) {//���α���
			cin >> map[i][j];
			if (map[i][j] == 1) { //1�ΰ� ��� �����ؼ� �ѹ��� �÷��ַ���
				q.push(make_pair(i, j));
			}
		}
	}
	//Search
	int day = 0;
	while(!q.empty()){
		day += searchBFS(q.size());
	}
	//Output
	output(day);
}

int searchBFS(int this_queue_size) {
	while(this_queue_size > 0) {// �丶�䰡 �ִ� ��� �ڸ����� BFS ���ü���
		int x = q.front().first;//3
		int y = q.front().second;//5
		q.pop();
		for (int i = 0; i < 4; i++) { //�ֺ�(�����¿�) Ž��
			int nx = x + direction[i][0];//2
			int ny = y + direction[i][1];//5
			if (map[nx][ny] == 0
					&& nx >= 0 && nx < column && ny >= 0 && ny < row) {//�丶�䰡 �ְ� ���� ���� ���̶��
				q.push(make_pair(nx, ny));//���� BFS�� Ž���ϵ��� queue�� �������� �־��ֱ�
				map[nx][ny] = 1; //�丶�� �Ͱ� ������ٰ� ǥ��
			}
		}
		this_queue_size--;
	}
	return 1;
}

void output(int day) {
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 0) {//�� ���̶� ������ �丶�䰡 �����Ѵٸ� -1 ���
				cout << -1;
				return;
			}
		}
	}
	cout << day - 1; //Ž���� �� 1�� ������ count �ϴϱ�, 1�� ���� ���� ���������.
}