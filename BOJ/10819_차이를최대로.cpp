/*���̸� �ִ��*/
#include <iostream>
#include <algorithm>
using namespace std;

void Input();
void Permutation();
void CalculateSum();
void Output();

int N;
int arr[9];
int maxVal = 0;

int main() {
	Input();
	Permutation();
	Output();

	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);// �������ϱ� ���� �������� �����ϱ�
}

void Permutation() {
	CalculateSum();

	for (int i = N - 1; i > 0; i--) {
		if (arr[i-1] < arr[i]) {// > �ε�ȣ�� �������� �ʴ� �κ� ã��. > �ε�ȣ�� �� �����Ѵٸ�(=�������� ���ĵǾ� �ִٸ�) �������� Ž�� ����
			sort(arr + i, arr + N);// arr[i]���� ������ ���ұ��� �������� �����ϱ�
			for (int j = i; j < N; j++) {
				if (arr[i-1] < arr[j]) {// �ڸ� �ٲ� �� ã�Ƽ� �ٲٱ�
					swap(arr[i-1], arr[j]);
					Permutation();
					return;
				}
			}
		}
	}
}

void CalculateSum() {
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]);
	}
	if (sum > maxVal) maxVal = sum;
}

void Output() {
	cout << maxVal;
}