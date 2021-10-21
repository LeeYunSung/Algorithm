#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int count, input;
	cin >> count;

	vector<int> v;
	for (int i = 0; i < count; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < count; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}