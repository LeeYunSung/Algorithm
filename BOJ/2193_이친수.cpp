#include<iostream>
using namespace std;

int main() {
	int num;
	long long num_arr[91] = { 0, 1, 1, };
	cin >> num;
	
	for (int i = 3; i <= num; i++) {
		num_arr[i] = num_arr[i - 1] + num_arr[i - 2];
	}
	cout << num_arr[num] << "\n";

	return 0;
}