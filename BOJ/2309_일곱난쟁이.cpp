#include <iostream>
#include <algorithm>
using namespace std;
#define INPUT_NUM 9

void Input();
void Permutation(int arr[], int sum);
void Output(int arr[], int idx1, int idx2);

int main() {
	Input();
	return 0;
}

//0. 9���� �����̵��� Ű���� �Է¹޴´�.
void Input() {
	int arr[INPUT_NUM] = { 0, };
	int sum = 0;
	for (int i = 0; i < INPUT_NUM; i++) {
		cin >> arr[i];
		//1. �Է¹����鼭 Ű�� ���� ���Ѵ�.
		sum += arr[i];
	}
	//2. �̸� ������������ �����Ѵ�.(���߿� �����ص� ����� ����)
	sort(arr, arr + 9);
	Permutation(arr, sum);
}

//3. 9���� ������ �߿� 2���� ��󺻴�.(9C2 ����)
void Permutation(int arr[INPUT_NUM], int sum) {
	for (int i = 0; INPUT_NUM; i++) {
		for (int j = 1; j < INPUT_NUM; j++) {
			//4. ��ü ������ Ű�� ���߿� 2�� ���� ������.
			//5. �� ���� 100�� �ȴٸ� �� 2���� ��¥ �����̴�.
			if (sum - arr[i] - arr[j] == 100) {
				Output(arr, i, j);
				return;
			}
		}
	}
}

//6. 2���� ������ ������ 7�����̵��� Ű�� ����Ѵ�.
void Output(int arr[INPUT_NUM], int idx1, int idx2) {
	for (int i = 0; i < INPUT_NUM; i++) {
		if (i != idx1 || i != idx2) {
			cout << arr[i] << '/n';
		}
	}
}