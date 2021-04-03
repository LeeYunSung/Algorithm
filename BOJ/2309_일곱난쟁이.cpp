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

//0. 9명의 난쟁이들의 키값을 입력받는다.
void Input() {
	int arr[INPUT_NUM] = { 0, };
	int sum = 0;
	for (int i = 0; i < INPUT_NUM; i++) {
		cin >> arr[i];
		//1. 입력받으면서 키의 합을 구한다.
		sum += arr[i];
	}
	//2. 미리 오름차순으로 정렬한다.(나중에 정렬해도 상관은 없음)
	sort(arr, arr + 9);
	Permutation(arr, sum);
}

//3. 9명의 난쟁이 중에 2명을 골라본다.(9C2 순열)
void Permutation(int arr[INPUT_NUM], int sum) {
	for (int i = 0; INPUT_NUM; i++) {
		for (int j = 1; j < INPUT_NUM; j++) {
			//4. 전체 난쟁이 키의 합중에 2명 값을 빼본다.
			//5. 그 값이 100이 된다면 고른 2명은 가짜 난쟁이다.
			if (sum - arr[i] - arr[j] == 100) {
				Output(arr, i, j);
				return;
			}
		}
	}
}

//6. 2명을 제외한 나머지 7난쟁이들의 키를 출력한다.
void Output(int arr[INPUT_NUM], int idx1, int idx2) {
	for (int i = 0; i < INPUT_NUM; i++) {
		if (i != idx1 || i != idx2) {
			cout << arr[i] << '/n';
		}
	}
}