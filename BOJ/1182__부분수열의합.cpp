#include <iostream>
#include <vector>
using namespace std;

vector<int> num_vector;
int target_sum;
int answer_count;

void CalculateSum(int index, int sum);

int main() {
	int num_count, input;
	
	cin >> num_count >> target_sum;
	for (int i = 0; i < num_count; i++) {
		cin >> input;
		num_vector.push_back(input);
	}
	CalculateSum(0, 0);

	if (target_sum == 0) answer_count--;
	cout << answer_count;

	return 0;
}

void CalculateSum(int index, int sum) {
	if (index == num_vector.size()) {
		if (sum == target_sum) {
			answer_count += 1;
		}
		return;
	}
	CalculateSum(index + 1, sum + num_vector[index]);
	CalculateSum(index + 1, sum);
}