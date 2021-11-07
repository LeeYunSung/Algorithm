#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_VALUE = 2000000000;

int main() {
	int liquid_num, input;
	vector<long long> liquid_vector;

	cin >> liquid_num;
	for (int i = 0; i < liquid_num; i++) {
		cin >> input;
		liquid_vector.push_back(input);
	}
	sort(liquid_vector.begin(), liquid_vector.end());

	int start_pointer = 0, end_pointer = liquid_num-1;

	long long near_zero = MAX_VALUE;
	long long near_liquid1, near_liquid2;

	while (start_pointer < end_pointer) {
		long long sum = liquid_vector[start_pointer] + liquid_vector[end_pointer];

		if (abs(sum) < near_zero) {
			near_zero = abs(sum);
			near_liquid1 = liquid_vector[start_pointer];
			near_liquid2 = liquid_vector[end_pointer];
		}
		if (sum > 0) end_pointer--;
		else if (sum < 0) start_pointer++;
		else break;
	}
	cout << near_liquid1 << " " << near_liquid2;
	return 0;
}

// 0에 가장 가까운 용액을 어떻게 정의해야 할지...
// 탐색 종료조건을 못정하게뜸...