#include <iostream>
#include<algorithm>
#define SIZE 500
using namespace std;

void Input();
void StartCalculation(int arr[SIZE][SIZE], int N, int M);

int main() {
	Input();
}

void Input() {
	int N, M;
	int arr[SIZE][SIZE] = { {0,0}, };

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	StartCalculation(arr, N, M);
}

void StartCalculation(int arr[SIZE][SIZE], int N, int M) {
	int tetro[19][4][2] = {
		// □□□□
		{{0,0}, {0,1}, {0,2}, {0,3}},
		{{0,0}, {1,0}, {2,0}, {3,0}},
		// □□
		// □□
		{{0,0}, {1,0}, {0,1}, {1,1}}, 
		// □
		// □
		// □□
		{{0,0}, {1,0}, {2,0}, {2,1}},
		{{0,0}, {1,0}, {0,1}, {0,2}},
		{{0,0}, {0,1}, {1,1}, {2,1}},
		{{0,0}, {1,0}, {2,0}, {2,-1}},
		{{0,0}, {0,1}, {0,2}, {-1,2}},
		{{0,0}, {1,0}, {2,0}, {0,1}},
		{{0,0}, {1,0}, {1,1}, {1,2}},
		{{0,0}, {0,1}, {0,2}, {1,2}},
		// □
		// □□
		//  □
		{{0,0}, {1,0}, {1,1}, {2,1}},
		{{0,0}, {1,0}, {-1,1} , {0,1}},
		{{0,0}, {0,1}, {-1,1}, {-1,2}},
		{{0,0}, {0,1}, {1,1}, {1,2}},
		// □□□
		//  □
		{{0,0}, {0,1}, {0,2}, {1,1}},
		{{0,0}, {1,-1}, {1,0}, {1,1}},
		{{0,0}, {1,0}, {2,0}, {1,1}},
		{{0,0}, {1,0}, {2,0}, {1,-1}},
	};

	int answer = 0;
	for (int i = 0; i < N; i++) {//N행
		for (int j = 0; j < M; j++) {//M열
			for (int k = 0; k < 19; k++) {//모양 19개 하나씩 선택하기
				int sum = 0;
				for (int l = 0; l < 4; l++) {//선택한 블럭모양 한 칸씩 값 더하기
					int x = i + tetro[k][l][0];//현재 위치의 x값 + k모양 1칸에 해당하는 x값
					int y = j + tetro[k][l][1];//현재 위치의 y값 + k모양 1칸에 해당하는 y값
					if (0 <= x && N > x && 0 <= y && M > y) {//x,y값이 범위를 벗어나는지 확인
						sum += arr[x][y];//범위안에 있으면 sum값으로 더하기
					}
					else {//범위를 벗어나버리면 바로 나와서 다음 모양 탐색하기
						break; 
					}
				}
				answer = max(answer, sum);//정상적으로 더한 값이 현재까지의 max 값보다 크면 값 체인지
			}
		}
	}
	cout << answer << '\n';
}