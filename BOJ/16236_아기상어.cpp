#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x;
	int y;
	int size;
	int eating_num;
	int time;
}Shark;

typedef struct {
	int x;
	int y;
	int distance;
}Fish;

const int MAX_SIZE = 21;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ����Ű
int map_size;
int map[MAX_SIZE][MAX_SIZE];

Shark shark;
vector<Fish> fish_vector;//���� �� �ִ� �������� ������ �迭(������ ���� ���Ϳ� ����)

int SearchBFS();//����� Ž��
void eatFish();//����� �Ա�

//����� ����
bool sortFish(Fish fish1, Fish fish2) {
	//1. distance�� ���� ���� ��.
	if (fish1.distance < fish2.distance) {
		return true;
	}
	else if (fish1.distance > fish2.distance) {
		return false;
	}
	else {//���� ��
		//2. ���� ���� �ִ� ��. i�� ���� ���� ��.
		if (fish1.x < fish2.x) {
			return true;
		}
		else if (fish1.x > fish2.x) {
			return false;
		}
		else {//���� ��
			//3. ���� ���ʿ� �ִ� ��. j�� ���� ���� ��.
			if (fish1.y < fish2.y) {
				return true;
			}
			else if (fish1.y > fish2.y) {
				return false;
			}
			else return false;
		}
	}
}

int main() {
	int fish_num = 0;
	cin >> map_size;
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {//9�� ��� ��ġ. ����ʱ�ȭ.
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.eating_num = 0;
				shark.time = 0;
			}
			//�� ���� �� �ִ�(�ڱ⺸�� ���� �����) ����� �� ����
			if (map[i][j] > 0 && map[i][j] < 2) {
				fish_num++;
			}
		}
	}
	while (fish_num > 0) {//�ϳ��� �ִٸ� ������ ����
		fish_num = SearchBFS();
	} cout << shark.time;

	return 0;
}

//BFS�� ���� �� �ִ� ���� ����� ����� ã��(�ڽ��� ũ�⺸�� ���� �����)
int SearchBFS() {
	queue<pair<pair<int,int>,int>> move_q;//BFS �̵��� ���� ť(x,y, distance)
	bool visited[MAX_SIZE][MAX_SIZE] = { false, };//�湮üũ �迭
	fish_vector.clear();//����� �ٽ� ��ƾ��ϴϱ� clear

	move_q.push(make_pair(make_pair(shark.x, shark.y),0));//���� ��ġ���� Ž�� ����
	map[shark.x][shark.y] = 0;//���� ��ġ���� �̵��ҰŴϱ� 0���� ǥ��
	visited[shark.x][shark.y] = true;//���� ��ġ �湮üũ

	while(!move_q.empty()){//Ž���� ��ġ�� ���� ������ �ݺ�
		int cur_x = move_q.front().first.first;
		int cur_y = move_q.front().first.second;
		int dist = move_q.front().second;
		move_q.pop();

		for (int i = 0; i < 4; i++) {//�����¿� Ž��
			int next_x = cur_x + direction[i][0];
			int next_y = cur_y + direction[i][1];
			if (next_x >= 0 && next_x < map_size && next_y >= 0 && next_y < map_size ) {
				//�� �̵��� �� �ִ� ��: �ڽ��� ũ�⺸�� ���� ĭ & �湮�� �� ���� ĭ
				if (map[next_x][next_y] <= shark.size && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					move_q.push(make_pair(make_pair(next_x, next_y), dist+1));
					//�� �ڸ��� 0�� �ƴϰ�(���ڸ�X) �ڱ⺸�� ���� ����Ⱑ �ִٸ�, ����� ���Ϳ� �־��ֱ�. 
					if (map[next_x][next_y] != 0 && map[next_x][next_y] < shark.size) {
						Fish fish = {next_x, next_y, dist+1};
						fish_vector.push_back(fish);
					}
				}
			}
		}
	}
	//Ž���� �� �ִ� ���� �� �ôٸ�, ����� �����ؼ� ������ ����.
	if (fish_vector.size() >= 1) {
		//����� ���� �� �Ա�
		sort(fish_vector.begin(), fish_vector.end(), sortFish);
		eatFish();
		return fish_vector.size() - 1;
	}
	return 0;
}

//�� ù��° ����� �Ա�
void eatFish() {
	shark.x = fish_vector.front().x;
	shark.y = fish_vector.front().y;
	shark.eating_num += 1;
	shark.time += fish_vector.front().distance;
	map[shark.x][shark.y] = 9;

	if (shark.eating_num == shark.size) { 
		shark.size += 1;
		shark.eating_num = 0;
		SearchBFS();//����� ũ�Ⱑ �ø� ����� �ٽ� ã�ƾ� ��
	}
}