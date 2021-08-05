#include <iostream>
using namespace std;

void N_Queen(int);

int N;//문제에서 주어지는 게임판의 크기
int queen_col[15];//퀸의 열위치를 저장할 배열(queen_col의 인덱스는 자연스레 행을 의미하게 된다)
int answer;//퀸을 놓을 수 있는 개수

bool isEmpty(int);//행, 대각선에 Queen이 있는지 탐색하는 함수

int main() {
	cin >> N;

	N_Queen(0);//1. 0행부터 탐색 및 Queen 놓기 시작
	cout << answer;//7. 정답 출력

	return 0;
}

void N_Queen(int row) {
	if (row == N) {//2. 현재 탐색하는 행이 마지막 행에 도달했다면 queen을 모두 배치했다는 뜻이므로 answer + 1 해주기
		answer++;
		return;//★더이상 탐색하지 않고 리턴(bounding function)
	}
	for (int col = 0; col < N; ++col) {//3. queen을 놓을 수 있는지 열 탐색
		queen_col[row] = col;//4. 넣을 수 있는 queen의 자리를 저장함
		if (isEmpty(row)) {//5. 아래와 대각선이 비어있는지 탐색
			N_Queen(row + 1);//6. Queen 놓고 다음 행 탐색하러 gogo
		}
	}
}

bool isEmpty(int row) {
	for (int col = 0; col < row; col++) {//5-1. 0행부터 현재 행까지 겹치는 Queen이 있는지 탐색한다.
		if (queen_col[row] == queen_col[col] //5-2. 같은 열에 있는지 탐색
			|| abs(queen_col[row] - queen_col[col]) == (row - col)) {//5-3. 대각선에 있는지 탐색
				return false;//★Queen을 놓을 수 없다면 더이상 탐색하지 않고 return(bounding function)
		}
	}
	return true;
}


/*
[조건문 설명]
1. queen_col[col] == queen_col[row]

0 1 2 3 <- 행을 의미
ㅁㅁㅁㅁ <- 열의 위치를 의미

queen은 같은 열/행 상에 놓이면 안되므로
col을 +1 해주며 돌면서 queen_col에 같은 값이 저장되어 있는지를 확인한다.(같은 값이 있다면, 같은 열에 있다는 의미니깐)


2. abs(queen_col[row] - queen_col[col]) == (row - col)

0 1 2 3 <- 행을 의미
ㅁㅁㅁㅁ <- 열의 위치를 의미

queen_col[]는 queen_col에 들어있는 값이므로 열을 의미하고
row, col은 inxex이므로 행을 의미한다.
현재좌표와 대각선 좌표의 열의 차와 행의 차가 같다면 대각선에 위치한 것을 의미한다.

예를 들어 현재 좌표는 0,0 이고, 현재 좌표의 대각선 좌표는 1,1 일 때,
각각 열은 열값대로, 행은 행값대로 빼면 0 - 1 == 0 - 1 이 성립함을 알 수 있다.
*/