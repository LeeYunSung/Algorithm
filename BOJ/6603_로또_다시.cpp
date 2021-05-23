#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SelectLotto(vector<int>);
const int LOTTO_COUNT = 6;

int main() {
	int num_count = 0;
	do {
		cin >> num_count;

		vector<int> lotto;
		int nums = 0;
		for (int i = 0; i < num_count; i++) {
			cin >> nums;
			lotto.push_back(nums);
		}
		SelectLotto(lotto);
		cout << "\n";
	} while(num_count != 0);
}

void SelectLotto(vector<int> lotto) {
	vector<int> lottoPermutation;
	for (int index = 0; index < LOTTO_COUNT; index++) {
		lottoPermutation.push_back(0);
	}
	for (int index = LOTTO_COUNT; index < lotto.size(); index++) {
		lottoPermutation.push_back(1);
	}

	do {
		for (int index = 0; index < lotto.size(); index++) {
			if (lottoPermutation[index]==0) {
				cout << lotto[index] << " ";
			}
		}
		cout << "\n";
	}while(next_permutation(lottoPermutation.begin(), lottoPermutation.end()));

}