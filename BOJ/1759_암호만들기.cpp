#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void findPassword(int, string, vector<char>&, int);
bool countMoumJaum(string&);

int main() {
	int length, count;
	vector<char> alpha;
	string answer_arr = "";

	cin >> length >> count;

	for (int i = 0; i < count; i++) {
		char x;
		cin >> x;
		alpha.push_back(x); // a t c i s w
	}
	sort(alpha.begin(), alpha.end()); // a c i s t w
	findPassword(length, answer_arr, alpha, 0);
}

void findPassword(int length, string answer, vector<char> &alpha, int alpha_index) {
	if (answer.length() == length && countMoumJaum(answer)) {
		cout << answer << "\n";
		return;
	}
	if (alpha_index >= alpha.size()) return;

	findPassword(length, answer + alpha[alpha_index], alpha, alpha_index+1);
	findPassword(length, answer, alpha, alpha_index+1);
}

bool countMoumJaum(string &answer) {
	int moum_count = 0, jaum_count = 0;

	for (char x : answer) {
		(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') ? moum_count += 1 : jaum_count += 1;
	}
	return moum_count >= 1 && jaum_count >= 2;
}