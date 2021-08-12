#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 3001;

int n;//�������� �־��� ���� ����
vector<int> stations[MAX];//�������� �־��� �� ����
bool visited[MAX];//BFS/DFS Ž���� ���� �湮üũ �迭
bool cycle_stations[MAX];//��ȯ�� ���θ� ������ �迭(true or false)

void Input();
void SearchCycle(int start_station, int current_station, int searchNum);//����Ŭ ���� Ž��(���ۿ�, Ž������ ���翪, Ž������)
int CalculateDistance(int start_station);//��ȯ�������� �Ÿ� ���ϱ�

int main() {
	//1. �� ���� �Է¹ޱ�
	Input();
	//2. ��ȯ�� Ž��
	for (int i = 1; i <= n; i++) {
		SearchCycle(i,i,0);
		memset(visited, false, sizeof(visited));
	}
	//3. ��ȯ������ �Ÿ� Ž�� �� ���
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
		else {//�湮�ߴ� ���̰� Ž�� ���̰� 2�̻��̸� ��ȯ���̶�� �Ǵ�
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
