#include <iostream>
using namespace std;

int main() {
	int row, col; // ��, �� ���ǽ� ũ��
	int intervalCol, intervalRow; // ������ �־���� ��, �� ����
	int rowCount = 0, colCount = 0; // ��, �� ���� ������ �� ���ؼ� ���� ����

	cin >> row >> col >> intervalRow >> intervalCol;

	// ¦���� ��, Ȧ���� ���� �ٸ�
	rowCount = row / (intervalRow + 1);
	if (row % (intervalRow + 1) != 0) rowCount += 1;

	// �������� ������ ¦��, Ȧ�� �����ؼ� ���ϱ�
	colCount = col / (intervalCol + 1);
	if (col % (intervalCol + 1) != 0) colCount += 1;

	cout << rowCount * colCount << "\n";

	return 0;
}