#include <iostream>
using namespace std;

int main() {
	int row, col; // 행, 열 강의실 크기
	int intervalCol, intervalRow; // 떨어져 있어야할 행, 열 간격
	int rowCount = 0, colCount = 0; // 행, 열 별로 참가자 수 구해서 곱할 변수

	cin >> row >> col >> intervalRow >> intervalCol;

	// 짝수일 때, 홀수일 때가 다름
	rowCount = row / (intervalRow + 1);
	if (row % (intervalRow + 1) != 0) rowCount += 1;

	// 열에서의 개수도 짝수, 홀수 구분해서 구하기
	colCount = col / (intervalCol + 1);
	if (col % (intervalCol + 1) != 0) colCount += 1;

	cout << rowCount * colCount << "\n";

	return 0;
}