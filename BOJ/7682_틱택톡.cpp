#include <iostream>
#include <string>
using namespace std;

int main() {
	string game_state = "";
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
		if ((x_count - o_count == 1 || x_count - o_count == 0) && x_count >= 3 && o_count >= 2) {
			int x_bingo_count = 0, o_bingo_count = 0;
			//가로
			if (game_state[0] == game_state[1] && game_state[1] == game_state[2]) {
				if (game_state[0] == 'X') x_bingo_count++;
				else if(game_state[0] == 'O') o_bingo_count++;
			}
			if (game_state[3] == game_state[4] && game_state[4] == game_state[5]) {
				if (game_state[3] == 'X') x_bingo_count++;
				else if (game_state[3] == 'O') o_bingo_count++;
			}
			if (game_state[6] == game_state[7] && game_state[7] == game_state[8]) {
				if (game_state[6] == 'X') x_bingo_count++;
				else if (game_state[6] == 'O') o_bingo_count++;
			}
			//세로
			if (game_state[0] == game_state[3] && game_state[3] == game_state[6]) {
				if (game_state[0] == 'X') x_bingo_count++;
				else if (game_state[0] == 'O') o_bingo_count++;
			}
			if (game_state[1] == game_state[4] && game_state[4] == game_state[7]) {
				if (game_state[1] == 'X') x_bingo_count++;
				else if (game_state[1] == 'O') o_bingo_count++;
			}
			if (game_state[2] == game_state[5] && game_state[5] == game_state[8]) {
				if (game_state[2] == 'X') x_bingo_count++;
				else if (game_state[2] == 'O') o_bingo_count++;
			}
			//대각선
			if (game_state[0] == game_state[4] && game_state[4] == game_state[8]) {
				if (game_state[0] == 'X') x_bingo_count++;
				else if (game_state[0] == 'O') o_bingo_count++;
			}
			if (game_state[2] == game_state[4] && game_state[4] == game_state[6]) {
				if (game_state[2] == 'X') x_bingo_count++;
				else if (game_state[2] == 'O') o_bingo_count++;
			}

			if (x_count + o_count == 9) {
				if ((x_bingo_count >= 1 && o_bingo_count >= 1)
					|| !(x_count == o_count + 1)
						|| (x_bingo_count < o_bingo_count)) cout << "invalid" << "\n";
				else cout << "valid" << "\n";
			}
			else if(x_count + o_count < 9){
				if ((x_bingo_count >= 1 && o_bingo_count >= 1) 
					|| (x_bingo_count == 0 && o_bingo_count == 0)
						|| (x_bingo_count >=1 && x_count != o_count + 1)
							|| (o_bingo_count >= 1 && x_count != o_count)) cout << "invalid" << "\n";
				else cout << "valid" << "\n";
			}
		}
		else cout << "invalid" << "\n";
	}
	return 0;
}