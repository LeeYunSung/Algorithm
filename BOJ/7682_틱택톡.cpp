/*
틀린코드... 33%에서 계쏙 틀림ㅠㅠ 나중에 다시보쟈!
*/

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
				(game_state[0] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			if (game_state[3] == game_state[4] && game_state[4] == game_state[5]) {
				(game_state[3] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			if (game_state[6] == game_state[7] && game_state[7] == game_state[8]) {
				(game_state[6] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			//세로
			if (game_state[0] == game_state[3] && game_state[3] == game_state[6]) {
				(game_state[0] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			if (game_state[1] == game_state[4] && game_state[4] == game_state[7]) {
				(game_state[1] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			if (game_state[2] == game_state[5] && game_state[5] == game_state[8]) {
				(game_state[2] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			//대각선
			if (game_state[0] == game_state[4] && game_state[4] == game_state[8]) {
				(game_state[0] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}
			if (game_state[2] == game_state[4] && game_state[4] == game_state[6]) {
				(game_state[2] == 'X') ? x_bingo_count++ : o_bingo_count++;
			}

			if (x_count + o_count == 9) {
				if ((x_bingo_count >= 1 && o_bingo_count >= 1) 
					|| (x_bingo_count < o_bingo_count)) cout << "invalid" << "\n";
				else cout << "valid" << "\n";
			}
			else if(x_count + o_count < 9){
				if ((x_bingo_count >= 1 && o_bingo_count >= 1) 
					|| (x_bingo_count == 0 && o_bingo_count == 0)
					|| (o_bingo_count >= 1 && x_count > o_count)) cout << "invalid" << "\n";
				else cout << "valid" << "\n";
			}
		}
		else cout << "invalid" << "\n";
		//9개 전부 놓은 상황일 때, x 와 o 둘다 빙고를 만족하면 안됨. 둘중 하나만 만족해야 함. 혹은 둘다 빙고 만족안해야 함.
		//						 XXOXOOOXX 처럼 O가 이기면 안됨. 이길거면 X가 이겨야 함.
		//9개 미만으로 놓은 상황일 때, x와 o중 하나가 빙고를 만족해야 함. 빙고를 만족한게 없거나 빙고를 둘다 만족하면 안됨.
		//							근데 .XXX.XOOO 처럼 OOO를 3개 놓았는데 X를 하나 더 놓은 상황이면 안됨
		//							그리고 X가 3개 미만 or o가 2개 미만이면 안됨.
	}
	return 0;
}