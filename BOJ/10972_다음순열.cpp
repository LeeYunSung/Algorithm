#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findNextPermutation(vector<int>&);

int main() {
	int N = 0, num = 0;
	vector<int> v;

	//Input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	//Output
	if (findNextPermutation(v)) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
	}
	else cout << -1;
}

bool findNextPermutation(vector<int> &v) {
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i - 1] < v[i]) {
			sort(v.begin() + i, v.end());
			for (int j = i; j < v.size(); j++) {
				if (v[i - 1] < v[j]) {
					swap(v[i - 1], v[j]);
					return true;
				}
			}
		}
	}
	return false;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0, num = 0;
	vector<int> v;

	//Input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	//Output
	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
	}
	else cout << -1;
}
*/