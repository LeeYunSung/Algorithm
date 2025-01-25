#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void Input();
void DivideTeam(int, int);
void CalculateTeamPower(vector<int>, vector<int>);

const int MAX_PLAYER = 20;

int playerNum;
int playerMap[MAX_PLAYER][MAX_PLAYER];
bool player[MAX_PLAYER];
int minimum = INT_MAX;

int main() {
	
	cin >> playerNum;
	for (int i = 0; i < playerNum; i++) {
		for (int j = 0; j < playerNum; j++) {
			cin >> playerMap[i][j];
		}
	}

	DivideTeam(0, 0);
	
	cout << minimum;

	return 0;
}

//인원수 2/n 씩 팀 나누기
void DivideTeam(int currentPlayer, int count) {
	if (count == playerNum / 2) {
		vector<int> startTeam, linkTeam;

		for (int i = 0; i < playerNum; i++) {
			if (player[i]) startTeam.push_back(i);
			else linkTeam.push_back(i);
		}
		CalculateTeamPower(startTeam, linkTeam);
		return;
	}

	for (int i = currentPlayer; i < playerNum; i++) {
		if (player[i] == false) {
			player[i] = true;
			DivideTeam(i, count + 1);
			player[i] = false;
		}
	}
}

//팀 능력치 차이 구하기(최소 갱신)
void CalculateTeamPower(vector<int> startTeam, vector<int> linkTeam) {
	int startTeamPower = 0, linkTeamPower = 0;

	for (int i = 0; i < playerNum / 2; i++) {
		for (int j = i + 1; j < playerNum / 2; j++) {
			int startX = startTeam[i];
			int startY = startTeam[j];
			int linkX = linkTeam[i];
			int linkY = linkTeam[j];

			startTeamPower += playerMap[startX][startY] + playerMap[startY][startX];
			linkTeamPower += playerMap[linkX][linkY] + playerMap[linkY][linkX];
		}
	}
	minimum = min(abs(startTeamPower - linkTeamPower), minimum);
}