#include <iostream>
#include <string>
using namespace std;

string game_state = "";

//가로, 세로, 대각선 빙고 확인
int isBingo(int i, char str) {
	if ((game_state[i * 3] == str && game_state[i * 3 + 1] == str && game_state[i * 3 + 2] == str)
		|| (game_state[i] == str && game_state[i + 3] == str && game_state[i + 6] == str)
		|| (game_state[0] == str && game_state[4] == str && game_state[8] == str)
		|| (game_state[2] == str && game_state[4] == str && game_state[6] == str)) {
		return 1;
	}
	return 0;
}

int main() {
	while (1) {
		cin >> game_state;

		if (game_state == "end") break;

		int x_count = 0, o_count = 0;
		for (int i = 0; i < game_state.size(); i++) {
			if (game_state[i] == 'O') {
				o_count++;
			}
			else if (game_state[i] == 'X') {
				x_count++;
			}
		}
		int x_bingo_count = 0, o_bingo_count = 0;

		for (int i = 0; i < 3; i++) {
			if (isBingo(i, 'X')) x_bingo_count++;
			if (isBingo(i, 'O')) o_bingo_count++;
		}

		if (x_count + o_count == 9) {
			if ((x_bingo_count >= 1 && o_bingo_count >= 1)
				|| (x_count != o_count + 1)
				|| (x_bingo_count < o_bingo_count)) cout << "invalid" << "\n";
			else cout << "valid" << "\n";
		}
		else if (x_count + o_count < 9) {
			if ((x_bingo_count >= 1 && o_bingo_count >= 1)
				|| (x_bingo_count == 0 && o_bingo_count == 0)
				|| (x_bingo_count >= 1 && x_count != o_count + 1)
				|| (o_bingo_count >= 1 && x_count != o_count)) cout << "invalid" << "\n";
			else cout << "valid" << "\n";
		}
	}
	return 0;
}