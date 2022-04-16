#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int testcase_num, input_num;
	int num_arr[12] = { 0, 1, 2, 4, 0, };

	for (int i = 4; i < sizeof(num_arr) / sizeof(int); i++){
		num_arr[i] = num_arr[i-1] + num_arr[i-2] + num_arr[i-3];
	}

	scanf_s("%d", &testcase_num);
	for (int i = 0; i < testcase_num; i++) {
		scanf_s("%d", &input_num);
		printf("%d\n", num_arr[input_num]);
	}

	return 0;
}