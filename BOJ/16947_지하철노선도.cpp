#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 3001;

int n;//문제에서 주어진 역의 개수
vector<int> stations[MAX];//문제에서 주어진 역 정보
bool visited[MAX];//BFS/DFS 탐색을 위한 방문체크 배열
bool cycle_stations[MAX];//순환역 여부를 저장할 배열(true or false)

void Input();
void SearchCycle(int start_station, int current_station, int searchNum);//사이클 여부 탐색(시작역, 탐색중인 현재역, 탐색깊이)
int CalculateDistance(int start_station);//순환역까지의 거리 구하기

int main() {
	//1. 역 정보 입력받기
	Input();
	//2. 순환역 탐색
	for (int i = 1; i <= n; i++) {
		SearchCycle(i,i,0);
		memset(visited, false, sizeof(visited));
	}
	//3. 순환역과의 거리 탐색 및 출력
	for (int i = 1; i <= n; i++) {
		 cout << CalculateDistance(i) << " ";
	}
	return 0;
}

void Input() {
	cin >> n;
	int station1, station2;
	for (int i = 0; i < n; i++) {
		cin >> station1 >> station2;
		stations[station1].push_back(station2);
		stations[station2].push_back(station1);		
	}
}

void SearchCycle(int start_station, int current_station, int searchNum) {//DFS
	visited[current_station] = true;
	for (int i = 0; i < stations[current_station].size(); i++) {
		int next_station = stations[current_station][i];
		if (!visited[next_station]) {
			SearchCycle(start_station, next_station, searchNum + 1);
		}
		else {//방문했던 역이고 탐색 깊이가 2이상이면 순환역이라고 판단
			if (next_station == start_station && searchNum >= 2) {
				cycle_stations[start_station] = true;
			}
		}
		if (cycle_stations[start_station]) return;
	}
}

int CalculateDistance(int start_station) {//BFS
	queue<pair<int,int>> q;
	memset(visited, false, sizeof(visited));
	visited[start_station] = true;
	q.push(make_pair(start_station,0));

	while (!q.empty()) {
		int current_station = q.front().first;
		int current_distance = q.front().second;
		q.pop();

		if (cycle_stations[current_station]) { return current_distance; }

		for (int i = 0; i < stations[current_station].size(); i++) {
			int next_station = stations[current_station][i];
			if (!visited[next_station]) {
				visited[next_station] = true;
				q.push(make_pair(next_station, current_distance + 1));
			}
		}
	}
}
