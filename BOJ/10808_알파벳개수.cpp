#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int FIRST_NUM = 97;

int main() {
	string word;
	vector<int> v(26);
	long long idx;

	cin >> word;	
	for (int i = 0; i < word.size(); i++) {
		int wordNum = (int)word[i] - FIRST_NUM;
		v[wordNum]++;
	}
	for (int i : v) cout << i << " ";

	return 0;
}