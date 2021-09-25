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
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향키
int map_size;
int map[MAX_SIZE][MAX_SIZE];

Shark shark;
vector<Fish> fish_vector;//먹을 수 있는 물고기들을 저장할 배열(정렬을 위해 벡터에 저장)

int SearchBFS();//물고기 탐색
void eatFish();//물고기 먹기

//물고기 정렬
bool sortFish(Fish fish1, Fish fish2) {
	//1. distance가 가장 작은 것.
	if (fish1.distance < fish2.distance) {
		return true;
	}
	else if (fish1.distance > fish2.distance) {
		return false;
	}
	else {//같을 때
		//2. 가장 위에 있는 것. i가 가장 작은 것.
		if (fish1.x < fish2.x) {
			return true;
		}
		else if (fish1.x > fish2.x) {
			return false;
		}
		else {//같을 때
			//3. 가장 왼쪽에 있는 것. j가 가장 작은 것.
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
			if (map[i][j] == 9) {//9가 상어 위치. 상어초기화.
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.eating_num = 0;
				shark.time = 0;
			}
			//상어가 먹을 수 있는(자기보다 작은 물고기) 물고기 수 갱신
			if (map[i][j] > 0 && map[i][j] < 2) {
				fish_num++;
			}
		}
	}
	while (fish_num > 0) {//하나라도 있다면 먹으러 가기
		fish_num = SearchBFS();
	} cout << shark.time;

	return 0;
}

//BFS로 먹을 수 있는 가장 가까운 물고기 찾기(자신의 크기보다 작은 물고기)
int SearchBFS() {
	queue<pair<pair<int,int>,int>> move_q;//BFS 이동을 위한 큐(x,y, distance)
	bool visited[MAX_SIZE][MAX_SIZE] = { false, };//방문체크 배열
	fish_vector.clear();//물고기 다시 담아야하니깐 clear

	move_q.push(make_pair(make_pair(shark.x, shark.y),0));//현재 위치부터 탐색 시작
	map[shark.x][shark.y] = 0;//현재 위치에서 이동할거니까 0으로 표시
	visited[shark.x][shark.y] = true;//현재 위치 방문체크

	while(!move_q.empty()){//탐색할 위치가 없을 때까지 반복
		int cur_x = move_q.front().first.first;
		int cur_y = move_q.front().first.second;
		int dist = move_q.front().second;
		move_q.pop();

		for (int i = 0; i < 4; i++) {//상하좌우 탐색
			int next_x = cur_x + direction[i][0];
			int next_y = cur_y + direction[i][1];
			if (next_x >= 0 && next_x < map_size && next_y >= 0 && next_y < map_size ) {
				//상어가 이동할 수 있는 곳: 자신의 크기보다 작은 칸 & 방문한 적 없는 칸
				if (map[next_x][next_y] <= shark.size && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					move_q.push(make_pair(make_pair(next_x, next_y), dist+1));
					//그 자리가 0이 아니고(빈자리X) 자기보다 작은 물고기가 있다면, 물고기 벡터에 넣어주기. 
					if (map[next_x][next_y] != 0 && map[next_x][next_y] < shark.size) {
						Fish fish = {next_x, next_y, dist+1};
						fish_vector.push_back(fish);
					}
				}
			}
		}
	}
	//탐색할 수 있는 곳을 다 봤다면, 물고기 정렬해서 먹으러 가기.
	if (fish_vector.size() >= 1) {
		//물고기 정렬 후 먹기
		sort(fish_vector.begin(), fish_vector.end(), sortFish);
		eatFish();
		return fish_vector.size() - 1;
	}
	return 0;
}

//맨 첫번째 물고기 먹기
void eatFish() {
	shark.x = fish_vector.front().x;
	shark.y = fish_vector.front().y;
	shark.eating_num += 1;
	shark.time += fish_vector.front().distance;
	map[shark.x][shark.y] = 9;

	if (shark.eating_num == shark.size) { 
		shark.size += 1;
		shark.eating_num = 0;
		SearchBFS();//물고기 크기가 늘면 물고기 다시 찾아야 함
	}
}