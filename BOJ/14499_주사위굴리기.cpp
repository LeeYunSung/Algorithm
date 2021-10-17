#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dice[7];//�ֻ��� 6��
int direction[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };//�����ϳ�

void MoveDice(int*, int*, int, vector<vector<int>>&);
void swapDiceNumber(int);

int main() {
	int N, M, dice_x, dice_y, moveCount, input;
	cin >> N >> M;
	cin >> dice_x >> dice_y;
	cin >> moveCount;

	vector<vector<int>> map(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}

	for (int i = 0; i < moveCount; i++) {
		cin >> input;
		MoveDice(&dice_x, &dice_y, input, map);
	}

	//�����Ҵ� ����
	for (int i = 0; i < N; i++) {
		map[i].clear();//���κ��� ����
	}
	map.clear();//���� ����

	return 0;
}

void MoveDice(int *dice_x, int *dice_y, int moveDirection, vector<vector<int>> &map) {
	int moved_dice_x = *dice_x + direction[moveDirection-1][0];
	int moved_dice_y = *dice_y + direction[moveDirection-1][1];

	if (moved_dice_x >= 0 && moved_dice_x < map.size()
		&& moved_dice_y >= 0 && moved_dice_y < map[0].size()) {

		swapDiceNumber(moveDirection);

		if (map[moved_dice_x][moved_dice_y] != 0) {
			dice[6] = map[moved_dice_x][moved_dice_y];
			map[moved_dice_x][moved_dice_y] = 0;
		}
		else if (map[moved_dice_x][moved_dice_y] == 0) {
			map[moved_dice_x][moved_dice_y] = dice[6];
		}

		*dice_x = moved_dice_x;
		*dice_y = moved_dice_y;

		cout << dice[1] << "\n";//***���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� �����ؾ� �ϸ�, ��µ� �ϸ� �� �ȴ�.
	}
}

void swapDiceNumber(int moveDirection) {
	int tempDice[7];
	copy(dice, dice + 7, tempDice);//�迭�� ����

	switch (moveDirection) {
		case 1://��
			dice[1] = tempDice[4];
			dice[3] = tempDice[1];
			dice[4] = tempDice[6];
			dice[6] = tempDice[3];
			break;
		case 2://��
			dice[1] = tempDice[3];
			dice[3] = tempDice[6];
			dice[4] = tempDice[1];
			dice[6] = tempDice[4];
			break;
		case 3://��
			dice[1] = tempDice[5];
			dice[2] = tempDice[1];
			dice[5] = tempDice[6];
			dice[6] = tempDice[2];
			break;
		case 4://��
			dice[1] = tempDice[2];
			dice[2] = tempDice[6];
			dice[5] = tempDice[1];
			dice[6] = tempDice[5];
			break;
	}
}