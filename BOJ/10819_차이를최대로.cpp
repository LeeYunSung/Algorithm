/*차이를 최대로*/
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
	sort(arr, arr + N);// 순열구하기 쉽게 오름차순 정렬하기
}

void Permutation() {
	CalculateSum();

	for (int i = N - 1; i > 0; i--) {
		if (arr[i-1] < arr[i]) {// > 부등호가 성립하지 않는 부분 찾기. > 부등호가 다 성립한다면(=내림차순 정렬되어 있다면) 다음순열 탐색 종료
			sort(arr + i, arr + N);// arr[i]부터 마지막 원소까지 오름차순 정렬하기
			for (int j = i; j < N; j++) {
				if (arr[i-1] < arr[j]) {// 자리 바꿀 값 찾아서 바꾸기
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