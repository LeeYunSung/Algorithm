#include <iostream>
#include <vector>
#include <limits.h>//INT_MAX
using namespace std;

void Input();
void DivideTeam(int, int);
void CalculateTeamPower(vector<int>, vector<int>);

const int MAX_PLAYER = 20;

int player_num;
int player_map[MAX_PLAYER][MAX_PLAYER];
bool player[MAX_PLAYER];//팀원 선택할 때 사용할 변수
int minimum = INT_MAX;//answer

int min(int a, int b) {
	return (a > b) ? b : a;
}

int abs(int a) {
	return (a < 0) ? a * -1 : a;
}

int main() {
	//시간초과 방지
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//인원수, 능력치 입력받기
	Input();

	//인원수 2/n 씩 팀 나누기
	DivideTeam(0, 0);
	
	//능력치 출력
	cout << minimum;

	return 0;
}

void Input() {
	cin >> player_num;
	for (int i = 0; i < player_num; i++) {
		for (int j = 0; j < player_num; j++) {
			cin >> player_map[i][j];
		}
	}
}

void DivideTeam(int current_player, int count) {
	if (count == player_num / 2) {
		vector<int> start_team, link_team;

		for (int i = 0; i < player_num; i++) {
			if(player[i]) start_team.push_back(i);
			else link_team.push_back(i);
		}
		//팀 능력치 차이 구하기(최소 갱신)
		CalculateTeamPower(start_team, link_team);
		return;
	}

	for (int i = current_player; i < player_num; i++) {
		if (player[i] == false) {
			player[i] = true;
			DivideTeam(i, count + 1);
			player[i] = false;
		}
	}
}

void CalculateTeamPower(vector<int> start_team, vector<int> link_team) {
	int start_team_power = 0, link_team_power = 0;

	for (int i = 0; i < player_num/2; i++) {
		for (int j = i + 1; j < player_num/2; j++) {
			int start_x = start_team[i];
			int start_y = start_team[j];
			int link_x = link_team[i];
			int link_y = link_team[j];

			start_team_power += player_map[start_x][start_y] + player_map[start_y][start_x];
			link_team_power += player_map[link_x][link_y] + player_map[link_y][link_x];
		}
	}
	minimum = min(abs(start_team_power - link_team_power), minimum);
}