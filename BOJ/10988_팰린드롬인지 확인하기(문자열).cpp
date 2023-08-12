#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string word, r_word;
	
	cin >> word;
	r_word = word;

	reverse(r_word.begin(), r_word.end());

	cout << (word == r_word) ? 1 : 0;
	cout << "\n";

	return 0;
}