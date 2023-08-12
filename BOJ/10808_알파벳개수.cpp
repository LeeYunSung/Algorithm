#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int cnt[26] = { 0, };

	cin >> word;
	for (char a : word) {
		cnt[a - 'a']++;
	}
	for (int i : cnt) cout << i << " ";

	return 0;
}