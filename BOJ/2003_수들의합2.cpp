//투포인터

#include <iostream>
using namespace std;

int main() {
	int num_size, target_sum, answer = 0;
	cin >> num_size >> target_sum;

	int *arr = new int[num_size]();
	for (int i = 0; i < num_size; i++) {
		cin >> arr[i];
	}

	int start_pointer = 0, end_pointer = 0;
	while (end_pointer < num_size) {
		int sum = 0;
		for (int i = start_pointer; i <= end_pointer; i++) {
			sum += arr[i];
		}
		if (sum < target_sum) end_pointer++;
		else if (sum > target_sum) start_pointer++;
		else if (sum == target_sum) {
			answer++;
			start_pointer++;
			end_pointer++;
		}
	}
	cout << answer;

	return 0;
}
