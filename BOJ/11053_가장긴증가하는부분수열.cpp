#include <iostream>
using namespace std;

int main() {
	int arr_size;
	cin >> arr_size;

	int *arr = new int[arr_size]; // 입력된 숫자들이 저장된 배열
	int *dp = new int[arr_size]; // 최대길이를 저장할 배열

	//Input
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	//Algorithm
	for (int j = 1; j < arr_size; j++) {
		for (int i = 0; i < j; i++) {
			if (arr[i] < arr[j]) {
				if (dp[i] + 1 > dp[j]) {
					dp[j] = dp[i] + 1;
				}
			}
		}
	}
	
	//Output
	int max_num_count = 0;
	for (int i = 0; i < arr_size; i++) {
		if (max_num_count < dp[i]) max_num_count = dp[i];
	}
	cout << max_num_count;

	delete arr;
	delete dp;

	return 0;
}
