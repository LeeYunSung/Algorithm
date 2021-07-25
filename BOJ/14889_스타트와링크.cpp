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
bool player[MAX_PLAYER];//���� ������ �� ����� ����
int minimum = INT_MAX;//answer

int min(int a, int b) {
	return (a > b) ? b : a;
}

int abs(int a) {
	return (a < 0) ? a * -1 : a;
}

int main() {
	//�ð��ʰ� ����
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//�ο���, �ɷ�ġ �Է¹ޱ�
	Input();

	//�ο��� 2/n �� �� ������
	DivideTeam(0, 0);
	
	//�ɷ�ġ ���
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
		//�� �ɷ�ġ ���� ���ϱ�(�ּ� ����)
		CalculateTeamPower(start_team, link_team);
		return;
	}

	for (int i = current_player; i < player_num; i++) {
		if (player[i] == false) {
			player[i] = true;
			DivideTeam(current_player, count + 1);
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