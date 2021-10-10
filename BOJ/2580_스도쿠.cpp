#include <iostream>
#include <vector>
using namespace std;

void Input();
void Stocoo(int blank_index);
bool CheckNumber(int x, int y, int num);
void Output();

int map[9][9];
vector<pair<int, int>> blank_position;

int main() {
	Input();
	Stocoo(0);
	Output();
	return 0;
}

void Input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank_position.push_back(make_pair(i, j));
			}
		}
	}
}

void Stocoo(int blank_index) {
	if (blank_index == blank_position.size()) {
		Output();
		exit(0); //모두가 0으로 이루어진 스도쿠처럼 답이 여러개일 수도 있는데,
				//그럴 때 제일 첫번째로 구해진 답을 정답으로 처리하고 더이상 구하지 않도록. 종료시킨다.
	}
	int x = blank_position[blank_index].first;
	int y = blank_position[blank_index].second;

	for (int num = 1; num < 10; num++) { // 1, 2, 3, 4, 5, 6, 7, 8, 9 하나씩 넣어보기
		//조건에 맞는지 체크
		if (CheckNumber(x, y, num)) {
			//조건에 맞으면 다음 blank 채우러가기
			map[x][y] = num;
			Stocoo(blank_index+1);//*****주의: blank_index++로 넣으면 안들가짐
			//다음걸 넣을게 없어서 return 됐을 때!
			//Backtracking으로 다시 gogo!
			map[x][y] = 0;//???????? 이 구문이 없으면 왜 안될까......

		}
		//조건에 맞지 않으면 다음 숫자 넣어보기
	}
}

bool CheckNumber(int x, int y, int num) {
	//가로
	for (int col = 0; col < 9; col++) {
		if (y != col && map[x][col] == num) {
			return false;
		}
	}
	//세로
	for (int row = 0; row < 9; row++) {
		if (x != row && map[row][y] == num) {
			return false;
		}
	}
	//3x3
	for (int row = x / 3 * 3; row < x / 3 * 3 + 3; row++) {//0,1,2,3,4,5,6,7,8,9 구역으로 나눔
		for (int col = y / 3 * 3; col < y / 3 * 3 + 3; col++) {
			if (x != row && y != col && map[row][col] == num) {
				return false;
			}
		}
	}
	return true;
}

void Output() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}