#include <iostream>
using namespace std;

void N_Queen(int);

int N;//�������� �־����� �������� ũ��
int queen_col[15];//���� ����ġ�� ������ �迭(queen_col�� �ε����� �ڿ����� ���� �ǹ��ϰ� �ȴ�)
int answer;//���� ���� �� �ִ� ����

bool isEmpty(int);//��, �밢���� Queen�� �ִ��� Ž���ϴ� �Լ�

int main() {
	cin >> N;

	N_Queen(0);//1. 0����� Ž�� �� Queen ���� ����
	cout << answer;//7. ���� ���

	return 0;
}

void N_Queen(int row) {
	if (row == N) {//2. ���� Ž���ϴ� ���� ������ �࿡ �����ߴٸ� queen�� ��� ��ġ�ߴٴ� ���̹Ƿ� answer + 1 ���ֱ�
		answer++;
		return;//�ڴ��̻� Ž������ �ʰ� ����(bounding function)
	}
	for (int col = 0; col < N; ++col) {//3. queen�� ���� �� �ִ��� �� Ž��
		queen_col[row] = col;//4. ���� �� �ִ� queen�� �ڸ��� ������
		if (isEmpty(row)) {//5. �Ʒ��� �밢���� ����ִ��� Ž��
			N_Queen(row + 1);//6. Queen ���� ���� �� Ž���Ϸ� gogo
		}
	}
}

bool isEmpty(int row) {
	for (int col = 0; col < row; col++) {//5-1. 0����� ���� ����� ��ġ�� Queen�� �ִ��� Ž���Ѵ�.
		if (queen_col[row] == queen_col[col] //5-2. ���� ���� �ִ��� Ž��
			|| abs(queen_col[row] - queen_col[col]) == (row - col)) {//5-3. �밢���� �ִ��� Ž��
				return false;//��Queen�� ���� �� ���ٸ� ���̻� Ž������ �ʰ� return(bounding function)
		}
	}
	return true;
}


/*
[���ǹ� ����]
1. queen_col[col] == queen_col[row]

0 1 2 3 <- ���� �ǹ�
�������� <- ���� ��ġ�� �ǹ�

queen�� ���� ��/�� �� ���̸� �ȵǹǷ�
col�� +1 ���ָ� ���鼭 queen_col�� ���� ���� ����Ǿ� �ִ����� Ȯ���Ѵ�.(���� ���� �ִٸ�, ���� ���� �ִٴ� �ǹ̴ϱ�)


2. abs(queen_col[row] - queen_col[col]) == (row - col)

0 1 2 3 <- ���� �ǹ�
�������� <- ���� ��ġ�� �ǹ�

queen_col[]�� queen_col�� ����ִ� ���̹Ƿ� ���� �ǹ��ϰ�
row, col�� inxex�̹Ƿ� ���� �ǹ��Ѵ�.
������ǥ�� �밢�� ��ǥ�� ���� ���� ���� ���� ���ٸ� �밢���� ��ġ�� ���� �ǹ��Ѵ�.

���� ��� ���� ��ǥ�� 0,0 �̰�, ���� ��ǥ�� �밢�� ��ǥ�� 1,1 �� ��,
���� ���� �������, ���� �ప��� ���� 0 - 1 == 0 - 1 �� �������� �� �� �ִ�.
*/